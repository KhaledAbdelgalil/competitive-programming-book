#include<bits/stdc++.h>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int pal(string s)
{
    
    if(s.size()==1)return 1;
    for(int i=0;i<s.size()/2;i++)
        if(tolower(s[i])!=tolower(s[s.size()-i-1]) )return 0;
    return 1;
}
bool IsPunc(const char & s)
{
    // ‘.’, ‘,’, ‘!’, ‘?’.
    if (s==',')return true;
    else if(s=='.')return true;
    else if(s=='!')return true;
    else if(s=='?')return true;
    else if(s==')')return true;
    else if(s=='(')return true;
    return false;
}
int main()
{
    
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    string st;
    int t;
    cin>>t;
    cin.ignore();
   for(int i=1;i<=t;i++)
    {
        getline(cin,st);
        cout<<"Case #"<<i<<":"<<endl;
        //cout<<st;
       	st.erase(remove_if(st.begin(), st.end(), ::isspace), st.end());
        st.erase(remove_if(st.begin(), st.end(), IsPunc), st.end());
        //cout<<st<<endl;
        int paln=pal(st);
        if(paln && sqrt(st.size())*sqrt(st.size())==st.size())cout<<sqrt(st.size())<<endl;
        else cout<<"No magic :("<<endl;
    }
    return 0;
}


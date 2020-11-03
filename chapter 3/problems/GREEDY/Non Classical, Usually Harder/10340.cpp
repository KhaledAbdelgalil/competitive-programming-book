#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    string s,t;
    while(cin>>s>>t){

    int i=0;
    int j=0;
    while(i<s.size()&&j<t.size()){
        if(s[i]==t[j])i++,j++;
        else j++;
    }
    if(i==s.size())cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    }
    return 0;
}


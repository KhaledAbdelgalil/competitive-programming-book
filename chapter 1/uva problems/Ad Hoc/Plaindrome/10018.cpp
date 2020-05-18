#include<bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;

int pal(string s)
{
    
    if(s.size()==1)return 1;
    for(int i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-i-1])return 0;
    return 1;
}

int main()
{

   /* std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!*/
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int cnt=0;
        while(1)
        {
            if(pal(s)){cout<<cnt<<" "<<s<<endl;break;}
            stringstream ss(s);
            string s2(s.begin(),s.end());
            reverse(s2.begin(),s2.end());
            unsigned long long v;
            unsigned long long v2;
            ss>>v;//contains s
            stringstream ss2(s2);
            ss2>>v2;
            v=v+v2;
            s=to_string(v);
            cnt++;
            //cout<<s;
            //cout<<v;
            
        }
    }
    return 0;
}


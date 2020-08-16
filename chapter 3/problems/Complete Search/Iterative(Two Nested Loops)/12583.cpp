#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++){
        cout<<"Case "<<tt+1<<": ";
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int cnt=0;
        map<char,int>mp;
        mp[s[0]]=k;
        for(int i=1;i<n;i++){
            if(mp.find(s[i])!=mp.end()&&mp[s[i]]>0)cnt++;
            for(char f='A';f<='Z';f++){
                if(mp.find(f)!=mp.end()&&mp[f]>0)mp[f]--;
            }
            mp[s[i]]=k;
        }
        cout<<cnt<<endl;
    }
    return 0;
}


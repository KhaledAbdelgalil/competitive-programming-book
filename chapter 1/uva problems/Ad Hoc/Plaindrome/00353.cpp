#include<bits/stdc++.h>

using namespace std;
map<string,bool>mp;
int pal(string s)
{
    mp[s]=1;
    if(s.size()==1)return 1;
    for(int i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-i-1])return 0;
    return 1;
}
int main()
{
    
    
    
    string in;
    while(cin>>in)
    {
        mp.clear();
        long long out=0;
        for(int i=0;i<in.size();i++)
        {
            for(int j=i;j<in.size();j++)
            {
                if(mp[in.substr(i,j-i+1)]==0)
                out+=pal(in.substr(i,j-i+1));
            }
        }
        cout<<"The string "<<"'"<<in<<"' contains "<<out<<" palindromes."<<endl;
        
    }
    return 0;
}


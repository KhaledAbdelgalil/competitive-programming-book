#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n;
    while(cin>>n){
        map<int,int>mp;
        std::vector<int>v1(n),v2(n);
        for(int i=0;i<n;i++)cin>>v1[i],mp[v1[i]]=i;
        for(int i=0;i<n;i++)cin>>v2[i];
        int overtakes=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(mp[v2[i]]<mp[v2[j]])overtakes++;//i was smaller in v1(start) then comes after j in v2(end)=>overtake
            }
        }
        cout<<overtakes<<endl;
    }

    return 0;
}


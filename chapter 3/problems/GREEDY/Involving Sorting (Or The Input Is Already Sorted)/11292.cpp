#include <bits/stdc++.h>
using namespace std;
vector<int>heads,knights;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int n,m;
    while(cin>>n>>m){
        if(n==0&&m==0)break;
        heads.resize(n);
        for(int i=0;i<n;i++)cin>>heads[i];
        knights.resize(m);
        for(int i=0;i<m;i++)cin>>knights[i];
        sort(heads.begin(),heads.end());
        sort(knights.begin(),knights.end());
        
        int pointer1=0;
        int pointer2=0;
        int killed=0;
        int coins=0;
        while(pointer1<n&&pointer2<m){
            if(knights[pointer2]>=heads[pointer1]){
                pointer1++;
                coins+=knights[pointer2];
                pointer2++;
                killed++;
            }
            else pointer2++;
        }
        if(killed==n)cout<<coins<<endl;
        else cout<<"Loowater is doomed!"<<endl;
    }
    return 0;
}


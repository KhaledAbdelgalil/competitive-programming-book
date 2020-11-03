#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int prices[25][25];
int models[25];
int m,g;
int memo[205][25];//0-200 * 20 g
int solve(int money,int gg){
    if(money>m)return -1e9;
    if(memo[money][gg]!=-1)return memo[money][gg];
    if(g==gg)return money;
    int ans=-2;
    for(int i=0;i<models[gg];i++)
    ans=max(ans,solve(money+prices[gg][i],gg+1));
    
    return memo[money][gg]=ans;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin>>t;
    while(t--){
        
        cin>>m>>g;
        for(int i=0;i<g;i++){
            cin>>models[i];
            for(int j=0;j<models[i];j++)cin>>prices[i][j];
        }
        memset(memo,-1,sizeof memo);
        int ans=solve(0,0);//I didn't spend any mony yet / I am now choosing first model
        if(ans<0)cout<<"no solution"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}


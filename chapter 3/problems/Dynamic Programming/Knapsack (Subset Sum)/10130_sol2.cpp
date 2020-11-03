#include <bits/stdc++.h>
using namespace std;
int values[1005],weights[1005];
int n;
int MW,G;
int dp[2][35];//space trick weight   2=>items    35=>weight
int solve(int mw){
    int pv=0,curr=1;
    //consider only first item(base case)
    for(int i=0;i<=mw;i++)
    if(i>=weights[0])dp[0][i]=values[0];
    else dp[0][i]=0;
    
    for(int i=1;i<n;i++){
        for(int w=0;w<=mw;w++){
            //if I can take this weight
            if(w>=weights[i]){
                dp[curr][w]=max(dp[pv][w-weights[i]]+values[i],dp[pv][w]);
            }
            else dp[curr][w]=dp[pv][w];
        }
        pv=curr,curr^=1;
    }
    return dp[pv][mw];
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
           cin>>values[i]>>weights[i];            
        }
        cin>>G;
        int ans=0;
        while(G--){
            cin>>MW;
            ans+=solve(MW);
        }
        cout<<ans<<endl;
    }

    return 0;
}


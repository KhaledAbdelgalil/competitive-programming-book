#include <bits/stdc++.h>
using namespace std;
int coins[105];
int dp[25000+5];
int n;
int solve_knapSack(int MW){
    
    for(int i=0;i<=MW;i++)dp[i]=0;//you haven't take coins yet
    
    for(int i=0;i<n;i++)//loop on coins let's take it and form MW
     for(int j=MW;j>=0;j--){
         if(j>=coins[i])//if I can take that coin let's take it and not take it 
         dp[j]=max(dp[j],dp[j-coins[i]]+coins[i]);
     }
     return dp[MW];//this what I have 
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    while(t--){
        int sum=0;
        cin>>n;
        for(int i=0;i<n;i++)cin>>coins[i],sum+=coins[i];
        
        // we want to take as much coins as half sum of coins or near to it to decrease difference
        cout<<sum-2*solve_knapSack(sum/2)<<endl;
    }
    return 0;
}


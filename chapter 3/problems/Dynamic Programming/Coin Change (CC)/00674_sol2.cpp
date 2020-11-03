#include <bits/stdc++.h>
using namespace std;
long long dp[6][8005];//the coins_considered(row0 consider no coins) total_money
long long coins[5]={1,5,10,25,50};


int main(){
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n;
    memset(dp,0,sizeof dp);
    
    //base cases
    //if you have 0 money so 1 way to make 0 money despite what coins you have
    dp[0][0]=dp[1][0]=dp[2][0]=dp[3][0]=dp[4][0]=dp[5][0]=1;
    
    //if you have x money where x>0 and you don't have coins you cannot make x so 0 ways
    for(int i=1;i<8005;i++)dp[0][i]=0;
    
    //let's build other dps as knapsack problem
    for(int i=1;i<6;i++){
        for(int j=1;j<8005;j++){
            if(j>=coins[i-1])dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    while(cin>>n){
        cout<<dp[5][n]<<endl;
    }

    return 0;
}


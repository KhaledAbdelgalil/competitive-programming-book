#include <bits/stdc++.h>
using namespace std;


long long dp[6][30001]={0};

int coins[6]={0,1,5,10,25,50};
void init(){
    for(int i=0;i<30001;i++)dp[0][i]=0;
    for(int i=0;i<6;i++)dp[i][0]=1;
    
    for(int i=1;i<6;i++)
        for(int j=1;j< 30001;j++){
            int coin=coins[i];
            if(j-coins[i]<0)dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]];
        }    
}
int main()
{
    init();
    int n;
    while(cin>>n){
        if(dp[5][n]>1)
        cout<<"There are "<<dp[5][n]<<" ways to produce "<<n<<" cents change."<<endl;
        else cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
    }
    return 0;
}


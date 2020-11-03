#include <bits/stdc++.h>
using namespace std;
long long dp[22][10001]={};
int main(){
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    //coins 1 8 27 ......
    
    //base cases of dp:
    //1-if you have 0 money despite type of coins ways you can form 0 money is not to take any coins so ways=1
   for(int i=0;i<22;i++)dp[i][0]=1;
   //2-if you have 0 coins so number of ways to form 1 money 2 money .....  x money is 0 ways
   for(int i=1;i<10001;i++)dp[0][i]=0;
   
   //lets build other dps
   for(int j=1;j<22;j++)
   {
       for(int i=1;i<10001;i++){
          if(i>=(j*j*j)){
              dp[j][i]=dp[j][i-j*j*j]+dp[j-1][i];
          } 
          else dp[j][i]=dp[j-1][i];
       }
   }
   int n;
   while(cin>>n)cout<<dp[21][n]<<endl;
    return 0;
}


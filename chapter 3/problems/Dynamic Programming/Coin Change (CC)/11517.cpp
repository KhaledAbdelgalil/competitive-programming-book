#include <bits/stdc++.h>
using namespace std;
//we want in this problem to pay least money that equal or more the item price taking in consideration least number of coins to pay
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    
    int t;
    cin>>t;
    while(t--){
        int n;
        int price;
        cin>>price>>n;
        int coins[n];
        int sum=0;//you cannot pay more than sum(sum of coins you have)
        for(int i=0;i<n;i++)cin>>coins[i],sum+=coins[i];
        
        int dp[sum+1];//lets have say money=10 how you can form 10 from coins you have the answer is dp[10]
        
        for(int i=0;i<=sum;i++)dp[i]=1e7;//if for say dp[10]=1e7 so we cannot form exactly 10 from coins we have we may form more or less 
        
        //base case if we have money=0 we need 0 coins to form 0 money
        dp[0]=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=sum;j>=0;j--)
            {
                if(j>=coins[i])dp[j]=min(dp[j-coins[i]]+1,dp[j]);
            }
        }
        
        int ans;
        for(int i=price;i<=sum;i++){
            if(dp[i]!=1e7){
                ans=i;
                break;
            }
        }
        cout<<ans<<" "<<dp[ans]<<endl;
        
    }
    
    
    return 0;
}


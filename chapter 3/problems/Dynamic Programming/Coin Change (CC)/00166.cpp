#include <bits/stdc++.h>
using namespace std;
int coins[6]={5,10,20,50,100,200};
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    /*This is for all testcases as the shopkeeper is same for them also shopkeeper has unlimited number of coins*/
    int get_dp[5005];
    for(int i=0;i<5005;i++)get_dp[i]=1e7;
    get_dp[0]=0;//I have 0 money which is made of 0 coins(base case)
    
    for(int i=0;i<6;i++){
        for(int j=1;j<5005;j++){
            for(int k=1;;k++){
                if(j-coins[i]*k<0)break;
                else get_dp[j]=min(get_dp[j],get_dp[j-coins[i]*k]+k);
            }
        }
    }
    
    int count_coins[6];
    while(1){
        int sum=0;//maximum you can pay 
        for(int i=0;i<6;i++)cin>>count_coins[i],sum+=count_coins[i]*coins[i];
        
        if(sum==0)break;//you have no more testcases
        
        int a,b;
        char temp;
        cin>>a>>temp>>b;
        a=a*100+b;//you need to pay a
        int pay_dp[sum+1];//pay_dp[100] if you pay money=100 what are min coins you need to pay answer is pay_dp[100]    
    
        //DP 
        for(int i=0;i<=sum;i++)pay_dp[i]=1e7;
        pay_dp[0]=0;//I have 0 money which is made of 0 coins(base case)
    
        for(int i=0;i<6;i++){
            for(int j=1;j<=sum;j++){
                for(int k=1;k<=count_coins[i];k++){
                    if(j-coins[i]*k<0)break;
                    else pay_dp[j]=min(pay_dp[j],pay_dp[j-coins[i]*k]+k);
                }
            }
        }
        
        int ans=1e8;
        for(int i=a;i<=sum;i++)//minimum you pay is a and maximum you pay all you have which is sum
        ans=min(ans,pay_dp[i]+get_dp[i-a]);//pay i and get i-a(reminder)
    
       printf("%3d\n",ans);
    }
    return 0;
}


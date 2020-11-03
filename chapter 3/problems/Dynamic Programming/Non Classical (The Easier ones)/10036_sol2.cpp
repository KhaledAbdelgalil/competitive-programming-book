#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[10005];
bool dp[2][105];//memory size trick
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>arr[i],arr[i]=abs(arr[i]);
        
        //let's solve dp problem you have k mod numbers from 0->k-1 if we found sum % k ==0 so we it's divisible
        for(int i=0;i<k;i++)
          dp[0][i]=false;
        
        //base case that we have only one number so let's set number%k with TRUE
        dp[0][arr[0]%k]=true;
        
        //let's recurse on other numbers
        for(int i=1;i<n;i++){
            //previous dp
            int prev=(i-1)%2;
            //current dp we solve
            int curr=i%2;
            int num=arr[i]%k;
            //let's recurse on all remindars            
            for(int j=0;j<k;j++)
            dp[curr][j]=dp[prev][(j-num+k)%k]||dp[prev][(j+num)%k];
            
        }
            
         if(dp[(n-1)%2][0]==1)cout<<"Divisible"<<endl;
         else cout<<"Not divisible"<<endl;
    }

    return 0;
}


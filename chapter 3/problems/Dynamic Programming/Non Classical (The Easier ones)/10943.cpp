#include <bits/stdc++.h>
using namespace std;
#define mod 1000000
int mem[105][105];
int solve(int n,int k){
    if(k==1)return 1;//if k=1 there is just one way to make n is to take the last number as n
    int &ans=mem[n][k];
    if(ans!=-1)return ans;
    
    // if K > 1, we can choose one number from [0..N] to be one of the number and recursively
    ans=0;
    for(int i=0;i<=n;i++){
        ans=(ans+solve(n-i,k-1)%mod)%mod;//you take one number of value=i so remaining is n-i
    }
    return ans;
}

int main(){
    
     
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n,k;
    memset(mem,-1,sizeof mem);
    while(cin>>n>>k){
        if(n==0&&k==0)break;
        cout<<solve(n,k)<<endl;
    }
    return 0;
}


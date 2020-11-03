#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[10005];
int mem[250][10005];//sum index
int solve(int index,int sum){
    if(index==n){
        if(sum==0)return 1;
        return 0;
    }
    if(index>n)return 0;
    int &ans=mem[sum+100][index];
    if(ans!=-1)return ans;
    ans=solve(index+1,(sum-arr[index])%k)||solve(index+1,(sum+arr[index])%k);
    return ans;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>arr[i];
        memset(mem,-1,sizeof mem);
        int ans=solve(1,arr[0]%k);
        if(ans==1)cout<<"Divisible"<<endl;
        else cout<<"Not divisible"<<endl;
    }

    return 0;
}


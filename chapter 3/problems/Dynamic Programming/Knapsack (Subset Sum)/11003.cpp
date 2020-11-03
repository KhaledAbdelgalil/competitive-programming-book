#include <bits/stdc++.h>
using namespace std;

int weights[1005],loads[1005];
int n;
int mem[1005][3005];
int solve(int index,int maxLoad){
    if(index>=n)return 0;
    
    if(maxLoad==-1){
        return max(1+solve(index+1,loads[index]),solve(index+1,maxLoad));
    }
    int &ans=mem[index][maxLoad];
    if(ans!=-1)return ans;
    if(weights[index]<=maxLoad)
        ans=max(1+solve(index+1,min(maxLoad-weights[index],loads[index])),solve(index+1,maxLoad));
    else ans=solve(index+1,maxLoad);
    
    return ans;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    while(cin>>n&&n){
        for(int i=0;i<n;i++)cin>>weights[i]>>loads[i];
        memset(mem,-1,sizeof mem);
        cout<<solve(0,-1)<<endl;
    }
    return 0;
}


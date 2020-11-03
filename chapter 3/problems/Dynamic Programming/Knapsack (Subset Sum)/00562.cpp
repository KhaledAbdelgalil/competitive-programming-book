#include <bits/stdc++.h>
using namespace std;
int n;
int coins[505];
int mem[105][105*505];
//no matters -ve difference or +ve difference 2 persons are treated the same way
int solve(int index,int diff){
    if(index==n)return diff;
    int &ans=mem[index][diff];
    if(ans!=-1)return ans;
    
    return ans=min(solve(index+1,diff+coins[index]),solve(index+1,abs(diff-coins[index])));
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>coins[i];
        memset(mem,-1,sizeof mem);
        cout<<solve(0,0)<<endl;//index difference
    }
    return 0;
}


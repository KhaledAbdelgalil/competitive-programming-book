#include <bits/stdc++.h>
using namespace std;

int x[25],y[25];
int n;
//mem 
int mem[25][1025];//number of cities ,2^10-1
int solve_TSP(int index,int vis){
    if(vis==(1<<n)-1)return abs(x[0]-x[index])+abs(y[0]-y[index]);//return to first city
    if(mem[index][vis]!=-1)return mem[index][vis];
    int ans=1e9;
    for(int i=0;i<n;i++){
        if(index!=i&&!(vis&(1<<i)))
        ans=min(ans,abs(x[index]-x[i])+abs(y[index]-y[i])+solve_TSP(i,vis|(1<<i)));
    }
    return mem[index][vis]=ans;
}
int main(){
    
     
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    while(t--){
        cin>>n>>n;//I don't want to know the size of grid i just want to know the number of peppers and treat them as cities(TSP problem)
        cin>>x[0]>>y[0];
        cin>>n;
        for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
        n++;
        memset(mem,-1,sizeof mem);
        cout<<"The shortest path has length "<<solve_TSP(0,1);//start from index=0 and we have visited city0
        cout<<endl;
    }
    
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int values[1005],weights[1005];
int n;
//state is id and remaining weight
int mem[35][1005];//rem weight id

int solve(int MW,int id){
    if(MW<=0)return 0;//we cannot carry more weights
    if(id>=n)return 0;//no more objects
    int &ans=mem[MW][id];
    if(ans!=-1)return ans;
    if(MW<weights[id])//we need to leave this weight
    ans=solve(MW,id+1);
    //can be left or taken
    else ans=max(solve(MW,id+1),solve(MW-weights[id],id+1)+values[id]);
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
        cin>>n;
        for(int i=0;i<n;i++){
           cin>>values[i]>>weights[i];            
        }
        int G,MW;
        memset(mem,-1,sizeof mem);
        cin>>G;
        int ans=0;
        while(G--){
            cin>>MW;
            ans+=solve(MW,0);
        }
        cout<<ans<<endl;
    }

    return 0;
}


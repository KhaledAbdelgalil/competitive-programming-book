#include <bits/stdc++.h>
using namespace std;
#define lock 0
#define unlock 1
typedef long long ll;

ll mem[2][70][70];

ll solution(int top,int remDrawers,int remSecure){
    
    if(remDrawers<0||remSecure<0||top<0)return 0;
    else if(remDrawers==0&&remSecure==0){
        return 1;
    }
    ll &ans=mem[top][remDrawers][remSecure];
    if(ans!=-1)return ans;
    if(top==lock)ans=solution(lock,remDrawers-1,remSecure-1)+solution(unlock,remDrawers-1,remSecure);
    else ans=solution(lock,remDrawers-1,remSecure)+solution(unlock,remDrawers-1,remSecure);
    return ans;
    
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    memset(mem,-1,sizeof mem);   
    int n,s;
    while(cin>>n>>s){
        if(n<0)break;
        cout<<(ll)solution(lock,n,s)<<endl;//top remainingdrawer remaining need to check secure
    }
    return 0;
}


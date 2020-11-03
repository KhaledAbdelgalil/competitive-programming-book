#include <bits/stdc++.h>
using namespace std;
vector<int>v;
vector<int>ans;
int N,n,minn;
void solve(int index,int sum,bool taken[]){
if(sum>N)return;
if(index==n){
    if(N-sum<minn){
    ans.clear();
    minn=N-sum;
    for(int i=0;i<n;i++)if(taken[i])ans.push_back(v[i]);
    ans.push_back(sum);
    }
return;
}
taken[index]=1;
solve(index+1,sum+v[index],taken);
taken[index]=0;
solve(index+1,sum,taken);
}
int main()
{

    while(cin>>N){
    cin>>n;
    v.resize(n);
    ans.clear();
    minn=INT_MAX;
    for(int i=0;i<n;i++)cin>>v[i];
    bool taken[n]={0};
    solve(0,0,taken);
    for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<" ";
    cout<<"sum:"<<ans[ans.size()-1]<<endl;
    }
   return 0;
}


#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int N,n;
    while(cin>>N){
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];

    int minn_diff=INT_MAX,sum_ans;
    vector<int>ans;
    for(int i=0;i<(1<<n);i++){
        int sum=0;
        vector<int>curr;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sum+=v[j];
                curr.push_back(v[j]);
            }
        }
        if(sum<=N){
            if(N-sum<minn_diff)minn_diff=N-sum,sum_ans=sum,ans=curr;
        }
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<"sum:"<<sum_ans<<endl;
    }
   return 0;
}


#include <bits/stdc++.h>
using namespace std;


bool isRunRound(int n){
    int digits[10];
    bool visited[10]={false};
    int sz=log10(n)+1;
    for(int i=sz-1;i>=0;i--){
        digits[i]=n%10;
        if(digits[i]==0)return 0;
        n/=10;
    }
    for(int i=0;i<sz;i++)
        for(int j=i+1;j<sz;j++)
            if(digits[i]==digits[j])return 0;
            
    int pos=0;
    int temp=digits[0];
    while(true){
        while(temp--){
            pos++;
            if(pos>=sz)pos=0;
        }
        if(pos==0){visited[0]=1;break;}
        if(visited[pos]){return 0;}
        visited[pos]=1;
        temp=digits[pos];
    }
    for(int i=0;i<sz;i++)if(visited[i]==0)return 0;
    
    return 1;
}
int main()
{
    std::vector<int>ans ;
    for(int i=11;i<10000000;i++)
        if(isRunRound(i))ans.push_back(i);
    int cases=0;
    int n;
    while(cin>>n&&n){
        for(int i=0;i<ans.size();i++){
            if(ans[i]>=n){cout<<"Case "<<++cases<<": "<<ans[i]<<endl;break;}
        }
    }
   
    return 0;
}


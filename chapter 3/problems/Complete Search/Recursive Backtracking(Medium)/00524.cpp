#include <bits/stdc++.h>
using namespace std;
int n;
int curr_ans[20];
map<int,vector< vector<int> > >mp_answers;
bool isPrime(int num){
if(num==2||num==3||num==5||num==7||num==11||num==13||num==17||num==19||num==23||num==29||num==31)return 1;
return 0;
}

void solve(int c,bool visited[]){
    if(c==n){
        if(!isPrime(curr_ans[n-1]+curr_ans[0]))return;
        vector<int>v;
        for(int  i=0;i<n;i++)v.push_back(curr_ans[i]);
        mp_answers[n].push_back(v);
        return;
    }
    for(int i=1;i<=n;i++){
    if(visited[i]==0){
       if(c!=0){
        if(isPrime(curr_ans[c-1]+i))visited[i]=1,curr_ans[c]=i,solve(c+1,visited),visited[i]=0;
       }
       else {
        curr_ans[c]=i;
        visited[i]=1;
        solve(c+1,visited);
       }
    }
    }
}
int main()
{
    int test=1;
   //pre-processing
   bool visited[20];
   bool first=1;
   for(int i=2;i<=16;i+=2)memset(visited,0,sizeof visited),n=i,solve(0,visited);
    while(cin>>n){
    if(!first)cout<<endl;
    first=0;
    cout<<"Case "<<test++<<":"<<endl;
    vector<vector<int>>ans_n=mp_answers[n];
    for(int i=0;i<ans_n.size();i++){
        cout<<ans_n[i][0];
        for(int j=1;j<ans_n[i].size();j++)cout<<" "<<ans_n[i][j];
        cout<<endl;
    }
    }
   return 0;
}


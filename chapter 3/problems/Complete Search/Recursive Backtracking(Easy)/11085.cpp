#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >answers;
int rows[8];
bitset<30>rws,ld,rd;
void solve(int c){
if(c==8){
    vector<int>curr(8);
    for(int i=0;i<8;i++)curr[i]=rows[i];
    answers.push_back(curr);
    return;
}
for(int r=0;r<8;r++){
    if(rws[r]==0&&ld[r-c+7]==0&&rd[r+c]==0){
    rws[r]=1;
    ld[r-c+7]=1;
    rd[r+c]=1;
    rows[c]=r;
    solve(c+1);
    rws[r]=0;
    ld[r-c+7]=0;
    rd[r+c]=0;
    }
}
}
int main()
{
   //pre-processing
   solve(0);//solve from column 0
   //cout<<"sda"<<endl;
   int v[8];
   int test=1;
   while(cin>>v[0]){
   v[0]--;
   for(int i=1;i<8;i++){cin>>v[i];v[i]--;}
   int minn=INT_MAX;
   for(int i=0;i<answers.size();i++){
        int steps=0;
        for(int j=0;j<8;j++){
            steps+=answers[i][j]-v[j]!=0?1:0;
        }
        if(steps<minn)minn=steps;

   }
    cout<<"Case "<<test++<<":"<<" "<<minn<<endl;
   }

   return 0;
}


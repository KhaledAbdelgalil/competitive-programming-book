#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>ans;
bool adj_mat[104][104];
bool valid_to_take_this_node(int node,vector<bool> taken){
    for(int i=1;i<node;i++){
        if(taken[i]&&adj_mat[i][node])return false;
    }
    return true;
}
void solve(int node,vector<bool>taken){
    if(node==n+1){
        vector<int>curr;
        for(int i=1;i<=n;i++)if(taken[i])curr.push_back(i);
        if(curr.size()>ans.size())ans=curr;
        return;
    }
    taken[node]=1;
    if(valid_to_take_this_node(node,taken))solve(node+1,taken);
    taken[node]=0;
    solve(node+1,taken);
}
int main(){
    
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
   
    int t;
    cin>>t;
    while(t--){
        ans.clear();
        memset(adj_mat,0,sizeof adj_mat);
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            adj_mat[x][y]=1;
            adj_mat[y][x]=1;
        }
        vector<bool>taken(n+1,0);
        solve(1,taken);
        cout<<ans.size()<<endl;
        cout<<ans[0];
        for(int i=1;i<ans.size();i++)cout<<" "<<ans[i];
        cout<<endl;
    }
    
    return 0;
}


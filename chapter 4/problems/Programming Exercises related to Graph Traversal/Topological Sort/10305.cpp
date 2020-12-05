#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int>ans;
vector< vector <int> >adj_list ;
bool vis[105];

void dfs_topoSort(int curr){
    
    for(int i = 0; i < adj_list[curr].size(); i++){
        int next = adj_list[curr][i];
        if(vis[next])continue;
        vis[next] = true;
        dfs_topoSort(next);
    }
    ans.push_back(curr);
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    while(cin  >> n >> m && (n || m)){
        ans.clear();
        adj_list.clear();
        adj_list.resize(n + 1);
        while(m--){
            int u,v;
            cin >> v >> u;
            adj_list[u].push_back(v);
        }
        memset(vis, false, sizeof vis);
        
        for(int i = 1; i <= n; i++)
            if(!vis[i])vis[i] = true,dfs_topoSort(i);
        cout << ans[0];
        for(int i = 1; i <= n - 1; i++)
            cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}

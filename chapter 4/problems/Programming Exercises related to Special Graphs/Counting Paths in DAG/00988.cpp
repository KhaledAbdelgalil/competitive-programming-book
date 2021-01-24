#include <bits/stdc++.h>
using namespace std;
vector< vector <int> > adj;
stack < int > toposort;
vector<int>cnt_paths;
vector<bool>vis;
void dfs(int src){
    
    for(int i = 0; i < adj[src].size(); i++){
        int v = adj[src][i];
        if(vis[v] == 0){
            vis[v] = 1;
            dfs(v);
        }
    }
    toposort.push(src);
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    bool first = 1;
    while(cin >> n){
        if(!first)cout << endl;
        first = 0;
        adj.clear();
        cnt_paths.clear();
        vis.clear();
        adj.resize(n);
        cnt_paths.resize(n, 0);
        vis.resize(n, 0);
        for(int i = 0; i < n; i++){
            int f;
            cin >> f;
            while(f--){
                int v;
                cin >> v;
                adj[i].push_back(v);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vis[i] = 1;
                dfs(i);
            }
        }
        int ans = 0;
        cnt_paths[0] = 1;
        while(!toposort.empty()){
            int u = toposort.top();
            toposort.pop();
            for(int i = 0; i < adj[u].size(); i++){
                int v = adj[u][i];
                cnt_paths[v] += cnt_paths[u];
            }
        }
        for(int i = 0; i < n; i++){
            if(adj[i].size() == 0)//death event
                ans += cnt_paths[i];
        }
        cout << ans << endl;
    }
    return 0;
}

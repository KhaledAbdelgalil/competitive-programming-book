#include <bits/stdc++.h>
using namespace std;
vector< vector <int> > adj;
stack < int > toposort;
int dist[30];
bool vis[30];
bool used[30];
int weight[30];
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
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    bool first = 1;
    while(t--){
        if(!first)cout << endl;
        first = 0;
        memset(used, 0, sizeof used);
        adj.clear();
        adj.resize(30);
        string s;
        while(getline(cin, s) && s != ""){
            stringstream ss(s);
            char u;
            int w;
            string v;
            ss >> u >> w >> v;
            weight[u - 'A'] = dist[u - 'A'] = w;
            used[u - 'A'] = 1;
            for(int i = 0; i < v.size(); i++){
                adj[v[i] - 'A'].push_back(u - 'A');
                used[v[i] - 'A'] = 1;
            }
        }
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < 26; i++){
            if(used[i] && !vis[i]){
                vis[i] = 1;
                dfs(i);
            }
        }
        int ans = 0;
        while(!toposort.empty()){
            int u = toposort.top();
            toposort.pop();
            for(int i = 0; i < adj[u].size(); i++){
                int v = adj[u][i];
                dist[v] = max(dist[v], weight[v] + dist[u]);
                ans = max(dist[v], ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

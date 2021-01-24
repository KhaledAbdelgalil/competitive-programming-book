#include <bits/stdc++.h>
using namespace std;
vector< vector <int > > adj;
map < int, int> mp;

int bfs(int src , int t){
    std::queue< pair<int, int > >q;
    q.push({src, t});
    vector < bool > vis(mp.size(), 0);
    vis[src] = 1;
    int total_nodes_reached = 0;
    while(!q.empty()){
        pair< int, int >front = q.front();
        q.pop();
        total_nodes_reached++;
        if(front.second == 0)continue;
        for(int i = 0; i < adj[front.first].size(); i++){
            int v = adj[front.first][i];
            if(vis[v] == 0){
                vis[v] = 1;
                q.push({v, front.second - 1});
            }
        }
    }
    return mp.size() - total_nodes_reached;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int m;
    int test = 1;
    while(cin >> m && m){
        adj.clear();
        adj.resize(35);
        mp.clear();
        int index = 0;
        while(m--){
            int u, v;
            cin >> u >> v;
            if(mp.find(u) == mp.end()){
                mp[u] = index++;
            }
            if(mp.find(v) == mp.end()){
                mp[v] = index++;
            }
            adj[mp[u]].push_back(mp[v]);
            adj[mp[v]].push_back(mp[u]);
        }
        int q, tt;
        while(cin >> q >> tt){
            if(q == 0 && tt == 0){
                break;
            }
            int cnt = bfs(mp[q], tt);
            cout << "Case " << test++ << ": " << cnt <<" nodes not reachable from node " << q <<" with TTL = ";
            cout << tt << "." << endl; 
        }
    }
    return 0;
}


#include <bits/stdc++.h>
#define NINF INT_MIN
using namespace std;

vector< vector < int > >adj;
stack < int > topsort;
vector < int > dist;
vector < bool > vis;
void dfs(int src){
    
    for(int i = 0; i < adj[src].size(); i++){
        int v = adj[src][i];
        if(vis[v] == 0){
            vis[v] = 1;
            dfs(v);
        }
    }
    topsort.push(src);
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    int test = 1;
    while(cin >> n && n){
        adj.clear();
        adj.resize(n + 1);
        dist.clear();
        dist.resize(n + 1, INT_MIN);
        vis.clear();
        vis.resize(n + 1, 0);
        int s;
        cin >> s;
        int u, v;
        while(cin >> u >> v){
            if(u == 0 && v == 0)break;
            adj[u].push_back(v);
        }
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0)vis[i] = 1,dfs(i);
        }
        dist[s] = 0;
        while(!topsort.empty()){
            int u = topsort.top();
            topsort.pop();
            for(int i  = 0; i < adj[u].size(); i++){
                int v = adj[u][i];
                if(dist[v] < dist[u] + 1){
                    dist[v] = dist[u] + 1;
                }
            }
        }
        int length = 0;
        int node_vertex;
        for(int i = 1; i <= n; i++){
            if(dist[i] > length){
                length = dist[i];
                node_vertex = i;
            }
        }
        cout << "Case " << test++ << ": The longest path from " << s << " has length " << length;
        cout <<", finishing at " << node_vertex << "." << endl << endl;
    }
    return 0;
}

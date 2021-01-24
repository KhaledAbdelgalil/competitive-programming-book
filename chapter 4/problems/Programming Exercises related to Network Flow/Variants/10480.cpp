#include <bits/stdc++.h>
using namespace std;
int graphR[55][55];
int n, m;
int  originalGraph[55][55];
int parent[55];
bool vis[55];
bool bfs(int s, int t){
    memset(vis, 0, sizeof vis);
    vis[s] = 1;
    parent[s] = -1;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(graphR[top][i] > 0 && vis[i] == 0){
                vis[i] = 1;
                parent[i] = top;
                q.push(i);
            }
        }
    }
    return vis[t] == 1;
}
void dfs(int src){
    vis[src] = 1;
    for(int i = 1; i <= n; i++){
        if(graphR[src][i] > 0 && vis[i] == 0){
            vis[i] = 1;
            dfs(i);
        }
    }
}
void fordFulkerson(int s, int t){

    while(bfs(s, t)){
        int u, v;
        int min_flow_on_path = 1e9;
        for(v = t; v != s; v = parent[v]){
            u = parent[v];
            min_flow_on_path = min(graphR[u][v], min_flow_on_path);
        }
        for(v = t; v != s; v = parent[v]){
            u = parent[v];
            graphR[u][v] -= min_flow_on_path;
            graphR[v][u] += min_flow_on_path;
        }
    }
    memset(vis, 0, sizeof vis);
    dfs(s);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(vis[i] && !vis[j] && originalGraph[i][j]){
                cout << i << " " << j << endl;
            }
        }
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        memset(graphR, 0, sizeof graphR);
        memset(originalGraph, 0, sizeof originalGraph);
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            originalGraph[u][v] = originalGraph[v][u] = graphR[u][v] = graphR[v][u] = w;
        }
        fordFulkerson(1,2);
        cout << endl;
    }

    return 0;
}

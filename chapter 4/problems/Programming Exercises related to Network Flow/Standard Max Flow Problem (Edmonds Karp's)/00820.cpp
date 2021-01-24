#include <bits/stdc++.h>
using namespace std;
int adjMat[105][105];
int parent[105];
bool vis[105];
int n;
bool bfs(int graph[105][105], int s, int t){
    queue<int> q;
    parent[s] = -1;
    vis[s] = 1;
    memset(vis, 0, sizeof vis);
    q.push(s);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(graph[top][i] > 0 && vis[i] == 0)//i.e there is capacity in the edge and not visited 
            {
                q.push(i);
                vis[i] = 1;
                parent[i] = top;
            }
        }
    }
    return vis[t] == 1;//there is a path between s,t
}
int fordFulkerson(int graphR[105][105], int s, int t){
    int maxFlow = 0;
    while(bfs(graphR, s, t)){//while there is still residual path(augmented) between s, t
        int min_flow_in_path = 1e9;
        int v, u;
        for(v = t; v != s; v = parent[v]){
            u = parent[v];
            min_flow_in_path = min(min_flow_in_path, adjMat[u][v]);
        }
        for (v=t; v != s; v=parent[v]) 
        { 
            u = parent[v]; 
            graphR[u][v] -= min_flow_in_path; 
            graphR[v][u] += min_flow_in_path; 
        } 
        maxFlow += min_flow_in_path;
  
    }
    return maxFlow;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int s, t, m;
    int test = 1;
    while(cin >> n && n){
        cin >> s >> t >> m;
        memset(adjMat, 0, sizeof adjMat);
        
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adjMat[u][v] += w;
            adjMat[v][u] += w;
        }
        
        cout << "Network " << test++ << endl;
        cout << "The bandwidth is " << fordFulkerson(adjMat, s, t) << "." << endl;
        cout << endl;
    }
    return 0;
}

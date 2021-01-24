#include <bits/stdc++.h>
using namespace std;
//In any network flow problem, please draw relations and the graph on a paper to be able to solve it correctly
int graphR[1050][1050];
int n, m;
bool vis[1050];
int parent[1050];
bool bfs(int s, int t){
    memset(vis, 0, sizeof vis);
    vis[s] = 1;
    parent[s] = -1;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i = 0; i <= n + m + 1; i++){
            if(graphR[top][i] > 0 && vis[i] == 0){
                vis[i] = 1;
                parent[i] = top;
                q.push(i);
            }
        }
    }
    return vis[t] == 1;
}
int fordFulkerson(int s, int t){
    int maxFlow = 0;
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
        maxFlow += min_flow_on_path;
    }
    return maxFlow;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    int test = 1;
    while(t--)// n: number of bolts, m: number of nuts
    {
        cin >> n >> m;
        //the problem is max flow on a bipartite graph
        //building residual graph(total number of graphVertices = n + m + 2)
        memset(graphR, 0, sizeof graphR);
        
        for(int i = 1; i <= n ; i++){
            for(int j = 1; j <= m; j++){
                cin >> graphR[i][n + j];
            }
        }
        //add source to the residual graph
        for(int i = 1; i <= n; i++)
            graphR[0][i] = 1;
        //add target to the residual graph
        for(int i = 1; i <= m; i++){
            graphR[i + n][n + m + 1] = 1;
        }
        //till here, you have built the residual graph
        int maxFlow = fordFulkerson(0, n + m + 1);
        cout << "Case " << test++ << ": a maximum of " << maxFlow << " nuts and bolts can be fitted together" << endl;
    }
    return 0;
}

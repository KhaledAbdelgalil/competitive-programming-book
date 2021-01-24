#include <bits/stdc++.h>
using namespace std;
//In any network flow problem, please draw relations and the graph on a paper to be able to solve it correctly
int graphR[500][500];
int n, m, k;
bool vis[500];
int parent[500];

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
   
    while(cin >> n && n)// n: number of modes(nodes) in machine one, m: .... in machine 2
    {
        cin >> m >> k;
        bool firstX = 1;
        bool firstY = 1;
        memset(graphR, 0, sizeof graphR);
        int maxFlow = 0;
        for(int i = 0; i < k; i++){
            int numJob, x, y;
            cin >> numJob >> x >> y;
            if(x > 0 && y > 0){//already job is covered , we don't need to consider it in graph
            graphR[0][x] = 1;//put machine 1 on source
            graphR[y + n][n + m + 1] = 1;//put machine 2 on target
            graphR[x][y + n] = 1;//machine 1 mode=x, can cover machine 2 mode=y
            //graphR[y+n][x] = 1;
            }
        }
        //the problem is max flow on a bipartite graph (Machine 1 on left, and Machine 2 on right)
        //calculate MCBM (which is MVC), actually MVC is solution
        //building residual graph(total number of graphVertices = n + M+ 2)
        //till here, you have built the residual graph
        maxFlow += fordFulkerson(0, n + m + 1);
        cout << maxFlow << endl;
    }
    return 0;
}

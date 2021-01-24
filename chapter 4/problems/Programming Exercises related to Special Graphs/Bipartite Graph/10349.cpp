#include <bits/stdc++.h>
using namespace std;
//In any network flow problem, please draw relations and the graph on a paper to be able to solve it correctly
char orignialGrid[50][15];
int mapGridCellsToNodesNumbers[50][15];
int graphR[750][750];//15*50
int n, m;
bool vis[750];//15*50
int parent[750];
int size;
bool bfs(int s, int t){
    memset(vis, 0, sizeof vis);
    vis[s] = 1;
    parent[s] = -1;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i = 0; i <= size; i++){
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
    while(t--)
    {
        size = 1;//we have source node of number = 0
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> orignialGrid[i][j];
                mapGridCellsToNodesNumbers[i][j] = size++;
            }
        }
        
        //the problem is max flow on a bipartite graph to calculate MCBM, then calculate MIS = V - MCBM
        //building residual graph(total number of graphVertices = n * m + 2)
        //the idea is to consider the cells of interest as nodes of graph ( if row + col is odd put it on left)
        //(if row + col is even put it on right, then you have bipartite graph), apply on it maxFlow
        //you got the number of cells that are covered by adding anntenas on other cells, subtract V - maxFlow,
        //you got solution to that problem
        memset(graphR, 0, sizeof graphR);
        int cnt_stars = 0;
        for(int i = 1; i <= n ; i++){
            for(int j = 1; j <= m; j++){
                if(orignialGrid[i][j] == '*' && (i + j) % 2){
                    int nodeNumber = mapGridCellsToNodesNumbers[i][j];
                    graphR[0][nodeNumber] = 1;//put between it and source edge of lenght = 1;
                    cnt_stars++;
                    if(i + 1 <= n && orignialGrid[i + 1][j] == '*')
                        graphR[nodeNumber][ mapGridCellsToNodesNumbers[i + 1][j] ] = 1;
                    if(i - 1 >= 1 && orignialGrid[i - 1][j] == '*')
                        graphR[nodeNumber][ mapGridCellsToNodesNumbers[i - 1][j] ] = 1;
                    if(j + 1 <= m && orignialGrid[i][j + 1] == '*')
                        graphR[nodeNumber][ mapGridCellsToNodesNumbers[i][j + 1] ] = 1;
                    if(j - 1 >= 1 && orignialGrid[i][j - 1] == '*')
                        graphR[nodeNumber][ mapGridCellsToNodesNumbers[i][j - 1] ] = 1;
                }else if(orignialGrid[i][j] == '*'){//sink 
                    graphR[ mapGridCellsToNodesNumbers[i][j] ][size] = 1;
                    cnt_stars++;
                }
            }
        }
        
        //till here, you have built the residual graph
        int maxFlow = fordFulkerson(0, size);
        cout << cnt_stars - maxFlow << endl;
    }
    return 0;
}

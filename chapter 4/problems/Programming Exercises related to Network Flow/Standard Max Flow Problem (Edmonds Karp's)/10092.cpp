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
    
    while(cin >> n >> m)// n: number of categories, m: number of problems
    {
        if(n == 0 && m == 0)break;
        //building residual graph(total number of graphVertices = n + m + 2)
        memset(graphR, 0, sizeof graphR);
        int totalNumberOfProblemsNeeded = 0;
        for(int i = 1; i <= n; i++){
             cin >> graphR[0][i];//you need to have graphR[0][i] of category i
             totalNumberOfProblemsNeeded += graphR[0][i];
        }
        for(int i = 1; i <= m; i++){
            int problemVertex = n + i;
            int f;
            cin >> f;
            while(f--){
                int category;
                cin >> category;
                //you can take this problem as this category, you have flow from here to here
                graphR[category][problemVertex] = 1;
            }
            graphR[problemVertex][n + m + 1] = 1;
        }
        
        //till here, you have built the residual graph
        int maxFlow = fordFulkerson(0, n + m + 1);
        if(maxFlow == totalNumberOfProblemsNeeded){//you must have maxflow equal to sum of categories problems
           // cout << "ok" << endl;
           vector< vector<int> >ans(n + 1);
           for(int i = 1; i <= n; i++){
               //let get answer for each category
               for(int j = n + 1; j <= m + n; j++)//loop on problems, find which belong to this category
               if(graphR[j][i]){//if you have backward edge from problem to category, this means that in your flow you take forward edge from category to flow, i.e this problem belong to this category
                    ans[i].push_back(j - n);                   
               }
           }
           cout << 1 << endl;
           for(int i = 1; i <= n; i++){
               cout << ans[i][0];
               for(int j = 1; j < ans[i].size(); j++){
                   cout << " " << ans[i][j];
               }
               cout << endl;
           }
        }else cout << 0 << endl;
    }
    return 0;
}

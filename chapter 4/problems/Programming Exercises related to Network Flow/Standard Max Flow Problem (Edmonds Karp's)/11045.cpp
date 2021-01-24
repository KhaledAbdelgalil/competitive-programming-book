#include <bits/stdc++.h>
using namespace std;
int graphR[55][55];//there are 6 + m + 2 nodes = m + 8
int n, m;//n: total number of tshirts, m: number of people
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
    map < string, int >mp;
    mp["XS"] = 1;
    mp["S"]  = 2;
    mp["M"] = 3;
    mp["L"] = 4;
    mp["XL"] = 5;
    mp["XXL"] = 6;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        //building residual graph
        int eachTshirt = n / 6;
        memset(graphR, 0, sizeof graphR);
        for(int i = 1; i <= 6; i++){
            //we can distribute from each tshirt this number
            graphR[0][i] = eachTshirt;
        }
        //for this children we need to give 1 tshirt
        for(int i = 7; i < 7 + m; i++){
            graphR[i][m + 7] = 1;    
        }
        for(int i = 7; i < 7 + m; i++){
            string tshirt1, tshirt2;
            cin >> tshirt1 >> tshirt2;
            graphR[mp[tshirt1]][i] = 1;//we can flow this path because we can give this tshirt to this boy
            graphR[mp[tshirt2]][i] = 1; 
        }
        //applying algorithm
        int numberOfPersonsthatTakeTshirts = fordFulkerson(0, m + 7);
        if(numberOfPersonsthatTakeTshirts >= m)//at least all take one tshirt, this what we want
         cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}

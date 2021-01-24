#include <bits/stdc++.h>
using namespace std;
int grid[105][105];
int dist[10005];
bool vis[10005];
stack <int> toposort;
vector < vector <int> > adj;
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
    while(t--){
        string caseName;
        int n, m;
        cin >> caseName >> n >> m;
        cout << caseName <<": ";
        adj.clear();
        adj.resize(n * m + 5);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> grid[i][j]; 
            }
        }
        //build graph
        int num = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(i + 1 <= n && grid[i][j] > grid[i + 1][j])//next row and you can slide, so you have an edge between i -> i+1
                    adj[num].push_back(num + m);
                if(i - 1 >= 1 && grid[i][j] > grid[i - 1][j])
                    adj[num].push_back(num - m);
                if(j + 1 <= m && grid[i][j] > grid[i][j + 1])
                    adj[num].push_back(num + 1);
                if(j - 1 >= 1 && grid[i][j] > grid[i][j - 1])
                    adj[num].push_back(num - 1);
                num++;
              
            }
        }
     
        for(int i = 1; i < num; i++)dist[i] = 1;
        memset(vis, 0, sizeof vis);
        for(int i = 1; i < num; i++)
            if(!vis[i])vis[i] = 1,dfs(i);
        
        int ans = 1;
        //apply algorithm
        while(!toposort.empty()){
            int u = toposort.top();
            toposort.pop();
            for(int i = 0; i < adj[u].size(); i++){
                int v = adj[u][i];
                dist[v] = max(dist[v], dist[u] + 1);//slide through u to v
                ans = max(dist[v], ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

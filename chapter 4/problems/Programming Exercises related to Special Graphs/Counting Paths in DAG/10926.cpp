#include <bits/stdc++.h>
using namespace std;
vector < vector < int > > adj;
vector < int > cnt_paths;
vector < bool > vis;
int mem[105];
int dfs(int src){
    int ans = 0;
    for(int i = 0; i < adj[src].size(); i++){
        int v = adj[src][i];
        if(vis[v] == 0){
            vis[v] = 1;
            ans++;
            //see dependencies of v
            ans += dfs(v);
        }
    }
    return ans;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    while(cin >> n && n){
        adj.clear();
        adj.resize( n + 1 );
        for(int i = 1; i <= n; i++){
            int f;
            cin >> f;
            while(f--){
                int u;
                cin >> u;
                adj[i].push_back(u);
            }
        }
        cnt_paths.clear();
        cnt_paths.resize(n + 1, 0);
        vis.clear();
        vis.resize(n + 1, 0);
        int maxx = -1;
        int index;
        for(int i = 1; i <= n; i++){
          for(int j = 1; j <= n; j++)vis[j] = 0;
          int ans = dfs(i);
          if(ans > maxx){
              maxx =ans;
              index = i;
          }
        }
        cout << index << endl;
    }
    return 0;
}

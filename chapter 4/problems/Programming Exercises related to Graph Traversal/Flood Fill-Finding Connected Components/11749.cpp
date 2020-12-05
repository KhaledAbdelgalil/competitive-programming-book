#include <bits/stdc++.h>
using namespace std;
vector< vector< pair <int, int> > > adj_list;
bool vis[505];
int maxx;
int n,e;
int dfs(int index){
    
    int cnt = 1;
    for(int i = 0; i < adj_list[index].size(); i++){
        int v = adj_list[index][i].first;
        int w = adj_list[index][i].second;
        if(vis[v] || w != maxx)continue;
        vis[v] = true;
        cnt += dfs(v);
    }
    return cnt;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   /*
   The idea to find the largest connected component that has all roads between cities have weight = maxx
   */
   
    while(cin >> n >> e){
        if(n == 0 && e == 0)break;
        adj_list.clear();
        adj_list.resize(n + 1);
        maxx = INT_MIN;
        while(e--){
            int u, v, w;
            cin >> u >> v >> w;
            adj_list[u].push_back({v, w});
            adj_list[v].push_back({u, w});
            maxx = max(maxx, w);
        }
        int cnt = 0;
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; i++){
            if(vis[i] == false){
                vis[i] = true;
                cnt = max(cnt, dfs(i));
            }
        }
        cout << cnt << endl;
    }
    
   
    return 0;
}

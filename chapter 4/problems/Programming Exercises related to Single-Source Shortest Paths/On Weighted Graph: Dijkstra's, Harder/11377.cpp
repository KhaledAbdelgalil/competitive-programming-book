#include <bits/stdc++.h>
using namespace std;
#define oo INT_MAX
bool hasAirport[2005];
vector < vector<int> > adj;
vector < int > dist;
int dijkstra(int src, int target){
    if(hasAirport[src] == 0)
        dist[src] = 1;//the plane is leaving from airport , so build here an airport
    else dist[src] = 0;
    std::priority_queue< pair <int, int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({dist[src], src});
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        if(top.second == target)return top.first;
        int u = top.second;
        int d = top.first;
        if(d > dist[u])continue;
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            int w;
            if(hasAirport[v] == 0)w = 1;//you need to build airport here
            else w = 0;
            if(w + d < dist[v]){
                dist[v] = w + d;
                pq.push({dist[v], v});
            }
        }
    }
    return -1;
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        cout << "Case " << tt << ":" << endl;
        int n, m, k;
        cin >> n >> m >> k;
        memset(hasAirport, false, sizeof hasAirport);
        adj.clear();
        adj.resize(n + 1);
        while(k--){
            int u;
            cin >> u;
            hasAirport[u] = true;
        }
        
        while(m--){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int q;
        cin >> q;
        while(q--){
         int u, v;
         cin >> u >> v;
         if(u == v)cout << 0 << endl;
         else{
             dist.clear();
             dist.resize(n + 1, oo);
             int ans = dijkstra(u, v);
             cout << ans << endl;
         }
        }
        cout << endl;
    }
    
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
vector < vector< pair< int,int > > > adj;
vector < int > dist;
int totalWeights;
int dijkstra(int src, int target){
    dist[src] = 0;
    priority_queue < pair<int, int >, vector < pair<int,int> >, greater < pair<int,int> > > pq;
    pq.push({0, src});
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        int u = p.second;
        int d = p.first;
        if(d > dist[u]) //you have found another shortest path to u
            continue;
        for(int j = 0; j < adj[u].size(); j++){
            pair<int,int> v = adj[u][j];
            if(dist[u] + v.second < dist[v.first]){
                //this is another better path for v.first
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    return dist[target];
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        cout << "Case #" << tt << ": ";
        int n, m;
        int s, t;//source-target;
        cin >> n >> m >> s >> t;
        adj.clear();
        adj.resize(n);
        dist.clear();
        totalWeights = 0;
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            totalWeights += 2 * w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dist.resize(n , totalWeights);//INF = totalWeights
        int ans = dijkstra(s, t);
        if(ans == totalWeights)cout << "unreachable" << endl;
        else cout << ans << endl;
    }
    return 0;
}


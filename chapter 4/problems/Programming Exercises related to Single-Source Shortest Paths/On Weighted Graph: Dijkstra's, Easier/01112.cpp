#include <bits/stdc++.h>
using namespace std;
#define oo 100000000000

long long n, tle, e, m;
vector <long long> dist;
long long total_weight;
vector< vector< pair<long long, long long> > >adj;

long long dijkstra(long long src){
    dist[src] = 0;
    priority_queue < pair<long long, long long >, vector < pair<long long,long long> >, greater < pair<long long,long long> > > pq;
    pq.push({0, src});
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        long long u = p.second;
        long long d = p.first;
        if(d > dist[u]) //you have found another shortest path to u
            continue;
        for(int j = 0; j < adj[u].size(); j++){
            pair<long long, long long> v = adj[u][j];
            if(dist[u] + v.second < dist[v.first]){
                //this is another better path for v.first
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
   long long cnt = 0;
   for(int i = 1; i <= n; i++){
       if(dist[i] <= tle)cnt++;
   }
   return cnt;
}

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    bool first = true;
    while(t--){
       
        first = false;
        cin >> n >> e >> tle;
        cin >> m;
        adj.clear();
        adj.resize(n + 1);
        total_weight = 0;
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            adj[v].push_back({u, w});//I swapped , as I will run dijkstra from destination to get shortest paths to other nodes.
            total_weight += 2 * w;
        }
        dist.clear();
        dist.resize(n + 1, tle + 3);
        long long ans = dijkstra(e);
        cout << ans << endl;
        if(t)cout << endl;
    }
    return 0;
}


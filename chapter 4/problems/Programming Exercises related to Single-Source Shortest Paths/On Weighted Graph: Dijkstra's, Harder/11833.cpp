#include <bits/stdc++.h>
using namespace std;
#define oo INT_MAX
vector < vector<pair<int, int>> > adj;
map < pair<int, int>, int > mp;
vector < int > dist;
int n, m, c, k;
void dijkstra(int src){
 dist[src] = 0;
 priority_queue < pair<int, int>, vector < pair<int, int> > , greater < pair<int, int> > > pq;
 pq.push({dist[src], src});
 while(!pq.empty()){
     pair<int, int> top = pq.top();
     pq.pop();
     int u = top.second;
     int d = top.first;
     if(d > dist[u])continue;
     //stop dijkstra you reached service route continue your service
     if(u < c){
         for(int i = u + 1; i < c; i++){
             dist[i] = min(dist[i], dist[i - 1] + mp[{i - 1, i}]);
         }
         continue;
     }
     for(int i = 0; i < adj[u].size(); i++){
         pair < int, int > v = adj[u][i];
         if(d + v.second < dist[v.first]){
             dist[v.first] = d + v.second;
             pq.push({dist[v.first], v.first});
         }
     }
 }
    
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    while(cin >> n >> m >> c >> k){
        if(n == 0 && m == 0 && k == 0){
            break;
        }
        adj.clear();
        adj.resize(n);
        dist.clear();
        dist.resize(n, oo);
        mp.clear();
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            mp[{u, v}] = mp[{v, u}] = w;
        }
        dijkstra(k);
        cout << dist[c - 1] << endl;
    }
    
    return 0;
}

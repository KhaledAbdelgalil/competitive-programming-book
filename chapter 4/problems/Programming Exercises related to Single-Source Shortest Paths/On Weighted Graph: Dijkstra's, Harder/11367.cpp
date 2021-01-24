#include <bits/stdc++.h>
using namespace std;
#define oo INT_MAX
int prices[1005];
vector< pair< int,int > > adj[1005];
int n, m;
int dist[1005][105];
int dijkstra(int src, int target, int c){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= c; j++){
            dist[i][j] = oo;
        }
    }
    
    dist[src][0] = 0;
    priority_queue < pair<int, pair<int,int> > , vector < pair<int, pair<int,int> > >, greater < pair<int, pair<int,int> > > > pq;
    pq.push({0, {src, 0} });//weight till now source/gallons
    while(!pq.empty()){
        pair<int, pair<int,int> > p = pq.top();
        pq.pop();
        int u = p.second.first;
        int d = p.first;
        int gallons = p.second.second;
        if(u == target)return d;
        if(d > dist[u][gallons]) //you have found another shortest path to u
            continue;
            
      
        if(gallons < c && d + prices[u] < dist[u][gallons + 1]){
            //so stay here and add a gallon
            dist[u][gallons + 1] = d + prices[u];
            pq.push({dist[u][gallons + 1], {u, gallons + 1}});
        }
        //reach other vertices
        for(int j = 0; j < adj[u].size(); j++){
            pair<int,int> v = adj[u][j];
            if(gallons >= v.second){
                int newGas = gallons - v.second;
                if(d < dist[v.first][newGas]){
                    dist[v.first][newGas] = d;
                    pq.push({dist[v.first][newGas],{v.first, newGas}});
                }
            }
        }
    }
   
    return oo;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    while(cin >> n >> m){
        for(int i = 0; i < n; i++){
            cin >> prices[i];
            adj[i].clear();
        }
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int q;
        cin >> q;
        while(q--){
            int u, v, c;
            cin >> c >> u >> v;
            int ans = dijkstra(u, v, c);
            if(ans == oo)cout <<"impossible"<<endl;
            else cout << ans << endl;
        }
    }
    return 0;
}


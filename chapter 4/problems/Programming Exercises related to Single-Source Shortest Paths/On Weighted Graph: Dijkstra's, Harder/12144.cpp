#include <bits/stdc++.h>
using namespace std;
#define oo INT_MAX
vector < vector<pair<int, int>> > adj;
vector < int> parents[505];
vector<int>dist;
int n, m;
void init(){
    dist.clear();
    dist.resize(n, oo);
    for(int i = 0; i < n; i++){
        parents[i].clear();
    }
}
void dijkstra(int src, int target){
    dist[src] = 0;
    priority_queue< pair < int, int>, vector < pair<int,int> > , greater< pair < int, int> > >pq;
    pq.push({dist[src], src});
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        int d = top.first;
        if(d > dist[u])continue;
        for(int i = 0; i < adj[u].size(); i++){
            pair<int, int> v = adj[u][i];
            int newD = d + v.second;
            if(dist[v.first] > newD){
                dist[v.first] = newD;
                parents[v.first].clear();
                parents[v.first].push_back(u);
                pq.push({dist[v.first], v.first});
            }
            else if(dist[v.first] == newD){
                parents[v.first].push_back(u);
            }
        }
        
    }
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        adj.clear();
        adj.resize(n);
        int src, des;
        cin >> src >> des;
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }
        init();
        dijkstra(src, des);
        if(dist[des] == oo)cout << -1 << endl;
        else{
            //remove all paths from shortest_path then run dijkstra again
            std::queue<int>q;
            q.push(des);
            while(!q.empty()){
                int currVertex = q.front();
                q.pop();
                for(int i = 0; i< parents[currVertex].size(); i++){
                    int to = currVertex;
                    int from = parents[currVertex][i];
                    if(from != src)//as src doesn't have parents no need to continue
                        q.push(from);
                    for(int i = 0; i < adj[from].size(); i++){
                        if(adj[from][i].first == to){
                            adj[from].erase(adj[from].begin() + i);
                            break;
                        }
                    }
                }
            }
            init();
            dijkstra(src, des);
            if(dist[des] == oo )cout << -1 << endl;
            else cout << dist[des] << endl;
        }
    }
    return 0;
}

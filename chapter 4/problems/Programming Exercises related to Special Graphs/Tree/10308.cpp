#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
vector < vector < pair< int, long long > > >adj; 
map <int, int> mp;
int main()
{  
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        int u, v;
        long long w;
        adj.clear();
        adj.resize(10005);
        ss >> u >> v >> w;
        int minn = min(u, v);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        while(getline(cin, s) && s != ""){
            stringstream ff(s);
            ff >> u >> v >> w;
            minn = min(minn, min(v, u));
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        //apply bfs and get farthest node
        int dist_max = 0;
        vector<long long>dist(10005,INF);
        priority_queue< pair<long long, int> > pq;
        int node_farthest = -1;
        pq.push({0,minn});
        dist[minn] = 0;
        
        while(!pq.empty()){
            pair < long long, int > top = pq.top();
            pq.pop();
            u = top.second;
            long long d = top.first;
            if(d > dist[u])continue;//you already found a shorter distance
            if(d > dist_max){
                dist_max = d;
                node_farthest = u;
            }
            for(int i = 0; i < adj[u].size(); i++){
                v = adj[u][i].first;
                w = adj[u][i].second;
                if(d + w < dist[v]){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        //apply bfs from node_farthest and got max_dist
        dist_max = 0;
        dist.clear();
        dist.resize(10005, INF);
        dist[node_farthest] = 0;
        pq.push({0,node_farthest});
            
        while(!pq.empty()){
            pair < long long, int > top = pq.top();
            pq.pop();
            u = top.second;
            long long  d = top.first;
            if(d > dist[u])continue;//you already found a shorter distance
            if(d > dist_max){
                dist_max = d;
                node_farthest = u;
            }
            for(int i = 0; i < adj[u].size(); i++){
                v = adj[u][i].first;
                w = adj[u][i].second;
                if(d + w < dist[v]){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        cout << dist_max << endl;
    }
    return 0;
}


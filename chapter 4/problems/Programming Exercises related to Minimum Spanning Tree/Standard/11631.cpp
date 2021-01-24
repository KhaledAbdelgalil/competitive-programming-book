#include <bits/stdc++.h>
using namespace std;
vector < vector < pair<int,int> > > adj;
vector <bool> taken;
priority_queue < pair<int,int> > pq;

void process(int u){
    taken[u] = 1;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        int w = adj[u][i].second;
        if(!taken[v]){
            pq.push({-w, -v});
        }
    }
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        adj.clear();
        adj.resize(n);
        taken.clear();
        taken.resize(n, 0);
        int total_cost = 0;
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            total_cost += w;
            adj[u].push_back({v, w});
            adj[v].push_back({u,w});
        }
        process(0);
        int min_cost = 0;
        while(!pq.empty()){
            pair<int, int> f = pq.top();
            pq.pop();
            int v = -f.second;
            int w = -f.first;
            if(!taken[v]){
                min_cost += w;
                process(v);
            }
        }
        cout << total_cost - min_cost << endl;
    }
    return 0;
}


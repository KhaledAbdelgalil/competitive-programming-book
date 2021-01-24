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
    int n, m, wplane;
    int t;
    cin >> t;
    int test = 1;
    while(t--){
        cin >> n >> m >> wplane;
        adj.clear();
        adj.resize(n);
        taken.clear();
        taken.resize(n, 0);
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u,w});
        }
        int min_cost = 0;
        int total_planes = 0;
        for(int i = 0; i < n; i++){
            if(!taken[i]){
                process(i);
                total_planes++;
                min_cost += wplane;
                while(!pq.empty()){
                    pair<int, int> f = pq.top();
                    pq.pop();
                    int v = -f.second;
                    int w = -f.first;
                    if(!taken[v]){
                        if(w < wplane)min_cost += w;
                        else total_planes++, min_cost += wplane;
                        process(v);
                    }
                }
            }
        }
        cout << "Case #" << test++ <<": " << min_cost <<" " << total_planes << endl;
    }
    return 0;
}


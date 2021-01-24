#include <bits/stdc++.h>
using namespace std;
#define oo INT_MAX

vector < vector < pair < int, int> > > adj;
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t; 
    cin >> t; 
    while(t--){
        
        int n, m;
        cin >> n >> m;
        adj.clear();
        adj.resize(n);
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }
        vector<int>dist(n, oo);dist[0] = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < adj[j].size(); k++){
                    pair<int, int> v = adj[j][k];
                    dist[v.first] = min(dist[v.first], dist[j] + v.second);
                }
            }
        }
        
        bool negativeCycle = false;
        for(int i = 0; i < n && !negativeCycle; i++){
            for(int j = 0; j < adj[i].size() && !negativeCycle; j++ ){
                pair<int, int> v = adj[i][j];
                if(dist[v.first] > dist[i] + v.second){
                    negativeCycle = true;
                }
            }
        }
        if(negativeCycle)cout << "possible" << endl;
        else cout << "not possible" << endl;
    }
    return 0;
}

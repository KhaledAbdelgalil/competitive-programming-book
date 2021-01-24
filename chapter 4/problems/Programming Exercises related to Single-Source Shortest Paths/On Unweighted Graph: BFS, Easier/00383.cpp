#include <bits/stdc++.h>
using namespace std;
map < string, int > mp;
vector< vector <int> > adj ;
int n, m, p;
int bfs(int src, int des, int cost){
    std::queue< pair <int, int > >q;
    q.push({src, 0});
    vector<bool>vis(n, 0);
    vis[src] = 1;
    while(!q.empty()){
        pair<int, int> front = q.front();
        q.pop();
        if(front.first == des)return 100 * cost * front.second;
        for(int i = 0; i < adj[front.first].size(); i++){
            int v = adj[front.first][i];
            if(vis[v] == 0){
                vis[v] = 1;
                q.push({v, front.second + 1});
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
    cout << "SHIPPING ROUTES OUTPUT" << endl;
    for(int i = 1; i <= t; i++){
        cout << endl;
        cout << "DATA SET  " << i << endl;
        cout << endl;
       
        cin >> n >> m >> p;
        adj.clear();
        adj.resize(n);
        mp.clear();
        for(int i = 0; i < n; i++){
            string u;
            cin >> u;
            mp[u] = i;
        }
        
        for(int i = 0; i < m; i++){
            string u, v;
            cin >> u >> v;
            adj[mp[u]].push_back(mp[v]);
            adj[mp[v]].push_back(mp[u]);
        }
        for(int i = 0; i < p; i++){
            int cost;
            string u, v;
            cin >> cost >> u >> v;
            int totalCost = bfs(mp[u], mp[v], cost);
            if(totalCost == -1)cout <<"NO SHIPMENT POSSIBLE" << endl;
            else cout << "$" << totalCost << endl;
        }
        
    }
    
    
    cout << endl << "END OF OUTPUT" << endl;
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define notColoring 300
vector < vector <int> > adj;
vector< int > colors;
bool dfs(int u){
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(colors[v] == colors[u])return 0;
        else if(colors[v] == notColoring){
            colors[v] = 1 - colors[u];
            dfs(v);
        }
    }
    return 1;
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n;
    while(cin >> n && n){
        adj.clear();
        adj.resize(n);
        colors.clear();
        colors.resize(n, notColoring);
        int u, v;
        while(cin >> u >> v){
            if(u == 0 && v == 0)break;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
                
        bool ans = true;
        for(int i = 0; i < n && ans; i++){
            if(colors[i] ==  notColoring){
                colors[i] = 0;
                ans &= dfs(i);
            }
        }
        if(ans)cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    
    return 0;
}


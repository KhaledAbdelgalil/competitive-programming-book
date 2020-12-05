#include <bits/stdc++.h>
using namespace std;
#define notColoring 300
int n, m;
vector< vector < int > > adj_list;
int coloring[205];// 0/1 coloring
bool check_bipartite(int src){
    queue<int>q;
    coloring[src] = 0;
    q.push(src);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int i = 0; i < adj_list[f].size(); i++){
            int v = adj_list[f][i];
            if(coloring[v] == notColoring){
                coloring[v] = 1 - coloring[f];
                q.push(v);
            }else if(coloring[v] == coloring[f])// not bipartite
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    while(cin >> n && n){
        cin >> m;
        adj_list.clear();
        adj_list.resize(n);
        
        for(int i = 0; i < n; i++){
            coloring[ i ] = notColoring; 
        }
        
        while( m-- ){
            int u, v;
            cin >> u >> v;
            adj_list[ u ].push_back( v );
            adj_list[ v ].push_back( u );
        }
        bool bipartite = check_bipartite(0);
        if(bipartite) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
    
    return 0;
}


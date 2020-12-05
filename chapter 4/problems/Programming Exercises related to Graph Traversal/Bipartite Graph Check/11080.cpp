#include <bits/stdc++.h>
using namespace std;
#define notColoring 300
int n, m;
std::vector< vector<int> >adj_list;
int coloring[205];
bool ok_bipartite;
int check_bipartite(int src){
    vector<int>count_colors(2, 0);
    coloring[src] = 0;
    std::queue<int>q;
    q.push(src);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        count_colors[coloring[f]]++;
        for(int i = 0; i < adj_list[f].size(); i++){
            int v = adj_list[f][i];
            if(coloring[v] == notColoring){
                coloring[v] = 1 - coloring[f];
                q.push(v);
            }else if(coloring[v] == coloring[f])//not bipartite 
            {
                ok_bipartite = false;
                return 0;
            }
        }
    }
    return max(1, min(count_colors[0], count_colors[1]));//minimum number of guards is 1 for each single connected component
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        adj_list.clear();
        adj_list.resize(n);
        for(int i = 0; i < n; i++)coloring[i] = notColoring;
        while(m--){
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        
        //check connected components and bipartite property.
        int bipartite = 0;
        ok_bipartite = true;
        for(int i = 0; i < n && ok_bipartite; i++){
            if(coloring[i] == notColoring){
                bipartite += check_bipartite(i);
            }
        }
        if(ok_bipartite)cout << bipartite << endl;
        else cout << -1 << endl;
    }
    return 0;
}


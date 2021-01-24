#include <bits/stdc++.h>
using namespace std;
int n , m ,q;
vector < vector < pair<int, int> > > adj;
int decibel[105][105];//have decibel between u, v
class DSU {            
private:
  vector <int> p, rank;                       
public:
 
  DSU(int N) {
    rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) {  
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x;}
    else                   { p[x] = y;
                             if (rank[x] == rank[y]) rank[y]++; } } }
};
int dfs(int src, int target){
    if(src == target)return 0;
    queue< pair <int, int > > q;
    int maxx_ = -1;
    q.push({src, 0});
    vector<bool>vis(n, 0);
    vis[src] = 1;
    
    while(!q.empty()){
        pair<int, int> f = q.front();
        q.pop();
        if(f.first == target)maxx_ = max(maxx_, f.second);
        for(int  i = 0; i < adj[f.first].size(); i++){
            pair<int,int> v = adj[f.first][i];
            if(vis[v.first] == 0){
                vis[v.first] = 1;
                q.push( {v.first, max(f.second, v.second) } );
            }
        }
    }
    
    
    return maxx_;
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    vector < pair < int, pair<int, int > > > edgeList;
    int test = 1;
    while(cin >> n >> m >> q){
        if(n == 0 && m == 0 && q == 0)break;
        if(test != 1)cout << endl;
        edgeList.clear();
        edgeList.resize(m);
        adj.clear();
        adj.resize(n);
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            edgeList[i] = { w, { u, v } }; 
        }
        sort(edgeList.begin(), edgeList.end());
        //MST
        DSU sets(n);
        for(int i = 0; i < m; i++){
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            int w = edgeList[i].first;
            if(!sets.isSameSet(u, v)){
                sets.unionSet(u, v);
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                decibel[i][j] = dfs(i, j);
                decibel[j][i] = decibel[i][j];
            }
        }
        cout << "Case #" << test++ << endl;
        for(int i = 0; i < q; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(decibel[u][v] != -1)cout << decibel[u][v] << endl;
            else cout << "no path" << endl;
        }
        
    }
    return 0;
}


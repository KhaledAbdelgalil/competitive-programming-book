#include <bits/stdc++.h>
using namespace std;
double x[1000], y[1000];
bool edgeTaken[1000][1000];
double calculate(int i, int j){
    return sqrt( (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) );
}
class DSU {            
private:
  vector <int> p, rank, setSize;                       
  int numSets;
public:
  DSU(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    bool first = true;
    vector < pair < double, pair < int, int > > > edgeList;
    while(t--){
        if( !first )cout << endl;
        first = false;
        int n;
        cin >> n;
        edgeList.clear();
        for(int i = 0; i < n; i++)cin >> x[i] >> y[i];
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                double edgeWeight = calculate(i, j);
                edgeList.push_back({ edgeWeight, {i,j} });
            }
        }
        memset(edgeTaken, false, sizeof edgeTaken);
        int m;
        cin >> m;
        
        DSU sets(n);
        
        while(m--){
            int u, v;
            cin >> u >> v;
            u--, v--;
            edgeTaken[u][v] = 1;
            edgeTaken[v][u] = 1;
            sets.unionSet(u, v);
        }
        
        vector< pair < int, int > > ans;
        sort(edgeList.begin(), edgeList.end());
        for(int i = 0; i < edgeList.size(); i++){
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            if(edgeTaken[u][v] || edgeTaken[v][u])continue;
            if(!sets.isSameSet(u, v)){
                ans.push_back({u, v});
                sets.unionSet(u, v);
                edgeTaken[u][v] = true;
                edgeTaken[v][u] = true;
            }
        }
        if(ans.size() == 0){
            cout << "No new highways need" << endl;
        }else {
            sort(ans.begin(), ans.end());
            for(int i = 0; i < ans.size(); i++)
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
        }
    }
    return 0;
}


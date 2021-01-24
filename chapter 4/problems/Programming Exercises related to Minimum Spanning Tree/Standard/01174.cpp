#include <bits/stdc++.h>
using namespace std;
map < string , int > mp;
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
    int n, m;
    vector < pair < int, pair <int, int> > > edgeList;
    bool first = true;
    while(t--){
        mp.clear();
        edgeList.clear();
        if(!first)cout << endl;
        first = false;
        cin >> n >> m;
        int index = 0;
        while(m--){
            string u, v;
            int w;
            cin >> u >> v >> w;
            int uu, vv;
            if(mp.find(u) != mp.end()){
                uu = mp[u];
            }else {
                uu = mp[u] = index++;
            }
            
            if(mp.find(v) != mp.end()){
                vv = mp[v];
            }else {
                vv = mp[v] = index++;
            }
            edgeList.push_back({w, { uu, vv } });
        }
        sort(edgeList.begin(), edgeList.end());
        DSU sets(n);
        int totalWeight = 0;
        for(int i = 0; i < edgeList.size(); i++){
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            int w = edgeList[i].first;
            if( !sets.isSameSet(u, v) ){
                sets.unionSet(u, v);
                totalWeight += w;
            }
        }
        cout << totalWeight << endl;
    }
    
    return 0;
}


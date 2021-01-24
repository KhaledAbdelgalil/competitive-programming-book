#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
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
    
    int n;
    vector< pair < int, pair<int,int> >>edgeList;
    bool first = true;
    while(cin >> n){
        if(!first) cout << endl;
        first = false;
        edgeList.clear();
        int old_weight = 0;
        int u, v, w;
        int newWeight = 0;
        for(int i = 0; i < n - 1; i++){
            cin >> u >> v >> w;
            old_weight += w;
        }
        int m;
        cin >> m;
        while(m--){
            cin >> u >> v >> w;
            u--, v--;
            edgeList.push_back({w,{u,v}});
        }
        cin >> m;
        
        while(m--){
            cin >> u >> v >> w;
            u--, v--;
            edgeList.push_back({w,{u,v}});
        }
        UnionFind DSU(n);
        sort(edgeList.begin(), edgeList.end());
        for(int i = 0; i < edgeList.size(); i++){
            w = edgeList[i].first;
            u = edgeList[i].second.first;
            v = edgeList[i].second.second;
            if( !DSU.isSameSet(u,v) ){
                DSU.unionSet(u, v);
                newWeight += w;
            }
        }
        cout << old_weight << endl << newWeight << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    vector < pair < int, pair<int, int > > > edgeList;
    int t;
    cin >> t;
    int test = 1;
    while(t--){
        int n, m;
        cin >> n >> m;
        edgeList.clear();
        
        
        int secondCost;
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            edgeList.push_back({ w, { u, v } });
            secondCost += w;
        }
        sort(edgeList.begin(), edgeList.end());
    
        vector < int > takenEdges;
        DSU sets(n);
        for(int i = 0; i < m; i++){
            int u, v, w;
            u = edgeList[i].second.first;
            v = edgeList[i].second.second;
            w = edgeList[i].first;
            if(!sets.isSameSet(u, v)){
                sets.unionSet(u, v);
                takenEdges.push_back(i);
            }
        }
        cout << "Case #" << test++ <<" : ";
        // we have at least one way
        if(takenEdges.size() == n - 1){
            
            secondCost += 20;
            int maxx = secondCost;
           
              for(int j = 0; j < takenEdges.size(); j++){
                DSU sets2(n);
                int cost = 0;
                int edges = 0;
                for(int i = 0; i < m; i++){
                        if(takenEdges[j] == i)continue;
                        int u, v, w;
                        u = edgeList[i].second.first;
                        v = edgeList[i].second.second;
                        w = edgeList[i].first;
                        if(!sets2.isSameSet(u, v)){
                            sets2.unionSet(u, v);
                            cost += w;
                            edges++;
                        }
                        //make sure you have correct spanning tree;
                        if(edges == n -1 )secondCost = min(secondCost, cost);
                }
             }
        
            
            if(secondCost == maxx)
                cout << "No second way" << endl;
            else cout << secondCost << endl;
            
        }else {
            cout << "No way" << endl;
        }
        
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
double x[105], y[105];
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
        edgeList.clear();
        if(!first)cout << endl;
        first = false;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)cin >> x[i] >> y[i];
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                double edgeWeight = calculate(i, j);
                edgeList.push_back({ edgeWeight, {i,j} });
            }
        }
        DSU sets(n);
        sort(edgeList.begin(), edgeList.end());
        double totalWeight = 0.0;
        for(int i = 0; i < edgeList.size(); i++){
            double w = edgeList[i].first;
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            if(!sets.isSameSet(u, v)){
                sets.unionSet(u, v);
                totalWeight += w;
            }
        }
        cout << setprecision(2) << std::fixed << totalWeight << '\n';
    }
    return 0;
}


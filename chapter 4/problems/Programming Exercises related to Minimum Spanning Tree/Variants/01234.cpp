#include <bits/stdc++.h>
using namespace std;
class DSU{
private:
    std::vector<int>p,rank;
public:
    DSU(int n){
        p.assign(n+1,0),rank.assign(n+1,0);
        for(int i=0;i<n+1;i++)p[i]=i;
    }
    int findSet(int i){
        return (i==p[i])?i:(p[i]=findSet(p[i]));
    }
    int isSameSet(int i,int j){
        return findSet(i)==findSet(j);
    }
    void unionSet(int i,int j){
        int x=findSet(i);
        int y=findSet(j);
        if(rank[x]>rank[y]){
            p[y]=x;
        }
        else{
            p[x]=y;
            if(rank[x]==rank[y])rank[y]++;
        }
    }
};
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
    int n, m;
    vector < pair < int, pair< int, int > > > edgeList;
    int t;
    cin >> t;
    while(cin >> n >> m){
        edgeList.clear();
        
        if(n == 0)break;
        int total_weight = 0;
        while(m--){
            int u, v, w;
            cin >>  u >> v >> w;
            total_weight += w;
            edgeList.push_back( { w, { u, v } } );
        }
        int max_weight = 0;
        DSU sets(n);
        sort(edgeList.rbegin(), edgeList.rend());
        for(int i = 0; i < edgeList.size(); i++){
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            if(!sets.isSameSet(u, v)){
                sets.unionSet(u, v);
                max_weight += edgeList[i].first;
            }
        }
        cout << total_weight - max_weight << endl;
    }

    return 0;
}

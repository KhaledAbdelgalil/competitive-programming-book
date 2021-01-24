#include <bits/stdc++.h>
using namespace std;
vector<double>x,y;
double calculate(int i, int j){
    return sqrt( (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) );
}
class DSU{
private:
    std::vector<int>p,rank;
    int sets;
public:
    DSU(int n){
        sets=n;
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
            if(x!=y)sets--;
            p[y]=x;
        }
        else{
            
            if(x!=y)sets--;
            p[x]=y;
            if(rank[x]==rank[y])rank[y]++;
        }
    }
    
    int Size(){
        return sets;
    }
  
};

int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    vector < pair < double, pair < int, int > > > edgeList;
    while(t--){
        x.clear();
        y.clear();
        edgeList.clear();
        int n;
        cin >> n;
        int xx, yy;
        while(cin >> xx && xx != -1){
            cin >> yy;
            x.push_back(xx);
            y.push_back(yy);
        }
        for(int i = 0; i < x.size() ; i++){
            for(int j = i + 1; j < y.size(); j++){
                double edgeWeight = calculate(i, j);
                edgeList.push_back( { edgeWeight, { i, j } } );
            }
        }
        DSU sets(x.size());
        sort(edgeList.begin(), edgeList.end());
        double maxDist = 0;
        for(int i = 0; i < edgeList.size(); i++){
            if(sets.Size() == n){
            break;        
            }
            double w = edgeList[i].first;
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            if(!sets.isSameSet(u, v)){
                sets.unionSet(u, v);
                maxDist = max(w, maxDist);
            }
        }
        cout << (int)ceil(maxDist) << endl;
    }
    return 0;
}


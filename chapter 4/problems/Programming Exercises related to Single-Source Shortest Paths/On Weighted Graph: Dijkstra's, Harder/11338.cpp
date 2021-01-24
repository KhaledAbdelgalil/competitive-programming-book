#include <bits/stdc++.h>
using namespace std;
#define oo DBL_MAX
struct point {
  double x,y;
   point(double x_, double y_):x(x_), y(y_){}
};

vector < struct point > safePoints;
vector < vector< pair< int, double> > > adj;
vector < double > distances;
double dist(int i, int j){
    return sqrt( (safePoints[i].x -safePoints[j].x) * (safePoints[i].x -safePoints[j].x) 
            + (safePoints[i].y -safePoints[j].y) * (safePoints[i].y -safePoints[j].y) );
}
void build_graph(){
    for(int i = 0; i < safePoints.size(); i++){
        for(int j = i + 1; j < safePoints.size(); j++){
            double distance = dist(i, j);
            if( distance <= 1.5){// to move from a safe place to another safe place the upper limit of distance is 1.5
                adj[i].push_back({j, distance});
                adj[j].push_back({i, distance});
            }
        }
    }
}
bool found_path(int src, int target, double constraint){
    distances[src] = 0;
    priority_queue < pair < double, int >, vector < pair < double, int > >, greater < pair < double, int > > > pq;
    pq.push({distances[src], src});
    while(!pq.empty()){
        pair < double, int > top = pq.top();
        pq.pop();
        int u = top.second;
        double d = top.first;
        if(u == target)
            break;
        if(d > distances[target])//you have already found a better path, ignore that path
            continue;
        for(int i = 0; i < adj[u].size(); i++){
            pair< int, double> v = adj[u][i];
            if(d + v.second < distances[v.first]){
                distances[v.first] = d + v.second;
                pq.push({distances[v.first], v.first});
            }
        }
    }
    return distances[target] <= constraint;//there is a constraint on total walking in the field
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n, m;
    while(cin >> n >> m){
        safePoints.clear();
        safePoints.push_back( point(0.0, 0.0) );
        int f;
        cin >> f;
        while(f--){
            double x, y;
            cin >> x >> y;
            safePoints.push_back( point(x, y) );
        }
        safePoints.push_back( point(n, m) );
        double constraint;
        cin >> constraint;
        adj.clear();
        adj.resize(safePoints.size());
        distances.clear();
        distances.resize(safePoints.size(), oo);
        build_graph();
        bool ans = found_path(0, safePoints.size() - 1, constraint);
        if(ans)cout << "I am lucky!" << endl;
        else  cout << "Boom!" << endl;
    }
    
    return 0;
}


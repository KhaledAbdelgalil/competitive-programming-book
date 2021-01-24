#include <bits/stdc++.h>
using namespace std;
#define oo INT_MAX
int T[6];
vector<int>start_elevator_vec;
vector < vector < pair< pair<int,int> , int > > > adj;
vector<int> dist;
int dijkstra(int src, int target, int start_elevator){
    dist[src] = 0;
    priority_queue < pair<int, pair<int, int > > , vector < pair<int, pair<int,int> > > , greater < pair<int, pair<int,int> > > > pq;
    pq.push({dist[src], {src, start_elevator} });
    while(!pq.empty()){
        pair<int, pair<int, int > > top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second.first;
        int elevator = top.second.second;
        if(u == target)return dist[u];
        if(d > dist[u])//you already found a better way
            continue;
        for(int i = 0; i < adj[u].size(); i++){
            pair< pair<int,int> , int > v = adj[u][i];
            int newW = d + v.first.second;
            if(v.second != elevator)// you need to wait 60 seconds
                newW += 60;
            if(newW < dist[v.first.first]){
                dist[v.first.first] = newW;
                pq.push({ newW, {v.first.first, v.second}});
            }
        }
    }
    return oo;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n, k;
    while(cin >> n >> k){
        adj.clear();
        adj.resize(101);
        dist.clear();
        dist.resize(101, oo);
        start_elevator_vec.clear();
        for(int i = 0; i < n ; i++){
            cin >> T[i];
        }
        cin.ignore();
        for(int i = 0; i < n; i++){
            string s;
            vector <int> v;
            getline(cin, s);
            stringstream ss(s);
            int x;
            while(ss >> x){
                v.push_back(x);
                if(x == 0)start_elevator_vec.push_back(i);
                
            }
            for(int j = 0; j < v.size(); j++){
                for(int f = j + 1; f < v.size(); f++){
                    int node1 = v[j];
                    int node2 = v[f];
                    int w = T[i] * abs(v[f] - v[j]);
                    adj[node1].push_back({ {node2, w}, i });
                    adj[node2].push_back({ {node1, w}, i });
                }
            }
        }
        
        int ans = oo;
        for(int i = 0; i < start_elevator_vec.size(); i++){
            ans = min(dijkstra(0, k, start_elevator_vec[i]), ans);// try using this elevator you may reach faster
            if(ans == oo)break;//if you cannot reach break as adj[0] will contain all vertices(so if you cannot reach from first elevator , you will not reach from any elevators)
        }
        if(ans == oo)cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
    
    return 0;
}


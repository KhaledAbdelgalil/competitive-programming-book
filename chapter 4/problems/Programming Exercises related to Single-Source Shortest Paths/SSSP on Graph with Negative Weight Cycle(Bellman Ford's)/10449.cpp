#include <bits/stdc++.h>
using namespace std;
#define oo LLONG_MAX
long long dist[205];
long long busyness[205];
vector<  pair < int, pair<int,int> > >  edjList;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    long long n;
    long long test = 1;
    while(cin>>n){
        for(int i = 1; i <= n; i++){
            cin >> busyness[i];
            dist[i] = oo;
        }
        long long m;
        cin >> m;
        edjList.clear();

        
        while(m--){
            long long u,v;
            cin >> u >> v;
            edjList.push_back({ (busyness[v] - busyness[u]) * (busyness[v] - busyness[u]) * (busyness[v] - busyness[u]), {u, v}});
        }
        dist[1] = 0;
        for(int i = 0; i < 3 * n; i++){//O(VE) bellman ford
            for(int j = 0; j < edjList.size(); j++){
                int w = edjList[j].first;
                int u = edjList[j].second.first;
                int v = edjList[j].second.second;
                if(dist[u] != oo && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        
        for(int j = 0; j < edjList.size(); j++){
                int w = edjList[j].first;
                int u = edjList[j].second.first;
                int v = edjList[j].second.second;
                if(dist[v] != oo && dist[u] + w < dist[v])
                    dist[v] = -1;//output ? as you still can make smaller (negative cycle)
            }
        
        
        cout << "Set #" << test++ << endl;
        long long q;
        cin >> q;
        while(q--){
            long long v;
            cin >> v;
            if(dist[v] >= 3 && dist[v] != oo)cout << dist[v] << endl;
            else cout << "?" << endl;
        }
    }

    return 0;
}

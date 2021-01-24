#include <bits/stdc++.h>
using namespace std;
int n, m;
int s, e, d;
int mem[105][205];
vector < vector <int> > adj;
int solve(int city, int days){
    if(days == 0){
        if(city == e)return 1;
        else return 0;
    }
    if(mem[city][days] != -1)return mem[city][days];
    
    for(int i = 0; i < adj[city].size(); i++){
        if(solve(adj[city][i], days -1) == 1)return mem[city][days] = 1;//I can finish trip and return to e
    }
    return mem[city][days] = 0;
}
int main()
{
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        memset(mem, -1, sizeof mem);
        adj.clear();
        adj.resize( n + 1);
        while(m--){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin >> s >> e >> d;
        if(solve(s, d)){
            cout << "Yes, Teobaldo can travel." << endl;
        }else cout << "No, Teobaldo can not travel." << endl;
    }
     
    return 0;
}

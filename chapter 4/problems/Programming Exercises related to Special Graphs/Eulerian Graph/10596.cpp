#include <bits/stdc++.h>
using namespace std;
bool connected[205][205];
int n, m;
void dfs(int src, vector<bool>&vis, vector<int>&degree){
    for(int i = 0; i < n; i++){
        if(degree[i] && connected[src][i] && vis[i] == 0){
            vis[i] = 1;
            dfs(i, vis, degree);
        }
    }
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    while(cin >> n >> m){
        memset(connected, 0, sizeof connected);
        bool can = 1;
        vector<int>degree(n, 0);
        for(int i = 0 ; i < m ; i++){
            int u, v;
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
            connected[u][v] = connected[v][u] = 1;
        }
        
        //just check euler tour property
        for(int i = 0; i < n; i++){
            if((degree[i] % 2 == 1) ){can = 0;break;}
        }
        //eulerian cycle must be in same connected component
        vector<bool>vis(n, 0);
        for(int i = 0; i < n; i++){
            if(degree[i] && vis[i] == 0){
                vis[i] = 1;
                dfs(i, vis, degree);
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(degree[i] && vis[i] == 0){can = 0;break;}
        }
        if(can && m)cout << "Possible" << endl;
        else cout << "Not Possible" << endl;
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
map < string , int > mapNames;
map < int, string > mapNodesNumber;
int adjMat[105][105];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        cout << "Case " << tt << ": ";
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adjMat[i][j] = 1e9;
                if(i == j)adjMat[i][j] = 0;
            }
        }
        while(m--){
            int u, v;
            cin >> u >> v;
            adjMat[u][v] = adjMat[v][u] = 1;
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }
        int src, des;
        cin >> src >> des;
        int maxx = 0;
        for(int i = 0; i < n; i++){
            if(adjMat[src][i] != 1e9 && adjMat[i][des] != 1e9 )
            maxx = max(adjMat[src][i] + adjMat[i][des], maxx);//send one troop to every building from base and see the latest one come to the destination, this one determines the time
        }
        
        cout << maxx << endl;
    }
    
    return 0;
}

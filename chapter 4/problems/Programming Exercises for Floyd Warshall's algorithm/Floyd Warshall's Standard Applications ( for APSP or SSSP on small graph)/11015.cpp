#include <bits/stdc++.h>
using namespace std;
map < string , int > mapNames;
map < int, string > mapNodesNumber;
int adjMat[25][25];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n, m;
    int test = 1;
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        mapNames.clear();
        mapNodesNumber.clear();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adjMat[i][j] = 1e9;
                if(i == j)adjMat[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            mapNodesNumber[i] = s;
            mapNames[s] = i;
        }
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adjMat[u][v] = w;
            adjMat[v][u] = w;
        }
        
        //get APSP
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }
        vector <int> cost(n, 0);
        int min_cost = 1e9;
        int index_min = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cost[i] += adjMat[i][j];
            }
            if(index_min == -1){
                min_cost = cost[i];
                index_min = i;
            }else if(min_cost > cost[i]) {
                min_cost = cost[i];
                index_min = i;
            }
        }
        cout << "Case #" << test++ <<" : " << mapNodesNumber[index_min] << endl;
    }
    return 0;
}

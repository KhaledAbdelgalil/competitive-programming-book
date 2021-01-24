#include <bits/stdc++.h>
using namespace std;
int BOSS[105][105], ME[105][105];
int connection_closed[105];
int n, m, BH, OF, YH, M;
void floydwarshall(int adjMat[105][105]){
    for(int k = 1; k <= n; k++){
        if(connection_closed[k])continue;//you cannot go through k
        for(int i = 1; i <= n; i++){
            if(connection_closed[i])continue;
            for(int j = 1; j <= n; j++){
                if(connection_closed[j])continue;
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
            }
        }
    }
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    while(cin >> n >> m >> BH >> OF >> YH >> M){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)BOSS[i][j] = ME[i][j] = 0;
                else BOSS[i][j] = ME[i][j] = 1e9;
            }
        }
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            BOSS[u][v] = ME[u][v] = BOSS[v][u] = ME[v][u] = w;
        }
        memset(connection_closed, false, sizeof connection_closed);
        floydwarshall(BOSS);//get shortest paths
        for(int i = 1; i <= n; i++){
            if(BOSS[BH][OF] == BOSS[BH][i] + BOSS[i][OF])// if your boss can go through i, so this connection is closed for you
                connection_closed[i] = true;
        }
        if(connection_closed[YH] || connection_closed[M])//if connection that contains your house or market are closed, you are in a danger , please stay at your home.
        {
            cout << "MISSION IMPOSSIBLE." << endl;
            continue;
        }
        floydwarshall(ME);//get shortest paths for you after closing unsafe connections
        if(ME[YH][M] != 1e9)//safe
        {
            cout << ME[YH][M] << endl;
        }else {
              cout << "MISSION IMPOSSIBLE." << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int adjMat[25][25];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    int test = 1;
    while(1)
    {
        //if(test == 3)break;
        for(int i = 1; i <= 20; i++){
            for(int j = 1; j <= 20; j++){
                if(i == j)adjMat[i][j] = 0;
                else adjMat[i][j] = 1e9;
            }
        }
        
        for(int i = 1; i <= 19; i++){
            if(cin >> n);
            else return 0;
            while(n--){
                int v;
                cin >> v;
                adjMat[i][v] = 1;
                adjMat[v][i] =1;
            }
        }
        for(int k = 1; k <= 20; k++)
            for(int i = 1; i <= 20; i++)
                for(int j = 1; j <= 20; j++)
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
        int m;
        cin >> m;
        printf("Test Set #%d\n", test++);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            printf("%2d to %2d: %1d\n", u, v, adjMat[u][v]);
        }
        cout << endl;
    }
    return 0;
}

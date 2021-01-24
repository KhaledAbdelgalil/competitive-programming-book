#include <bits/stdc++.h>
using namespace std;
int adjMat[15][15];
int parent[15][15];
vector < int > path;
void formThePath(int i , int j){
    if(i != j){
        formThePath(i, parent[i][j]);
    }
    path.push_back(j);
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    int test = 1;
    while(cin >> n && n)
    {
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)adjMat[i][j] = 0;
                else adjMat[i][j] = 1e9;
                parent[i][j] = i;
            }
        }
        
        for(int i = 1; i <= n; i++){
            int numbers;
            cin >> numbers;
            while(numbers--){
                int v, w;
                cin >> v >> w;
                adjMat[i][v] = w;
            }
        }
        
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(adjMat[i][k] + adjMat[k][j] < adjMat[i][j]){
                     adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                     parent[i][j] = parent[k][j];
                    }
                }
            }
        }
        
        path.clear();
        int u, v;
        cin >> u >> v;
        formThePath(u, v);
        cout << "Case " << test++ << ": Path = ";
        cout << u;
        for(int i = 1; i < path.size(); i++){
            cout << " " << path[i];
        }
        cout << ";" <<" " << adjMat[u][v] << " second delay" <<endl;

    }
    return 0;
}

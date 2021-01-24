#include <bits/stdc++.h>
using namespace std;
map < string, int > mp1;
map < int, string > mp2;
int adjMat[55][55];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n, m;
    int test = 1;
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)adjMat[i][j] = 0;
                else adjMat[i][j] = 1e9;
            }
        }
        int index = 0;
        mp1.clear();
        mp2.clear();
        for(int i = 0; i < m; i++){
            string u, v;
            cin >> u >> v;
            if(mp1.find(u) ==  mp1.end())
                mp1[u] = index++;
            if(mp1.find(v) == mp1.end())
                mp1[v] = index++;
            adjMat[mp1[u]][mp1[v]] = adjMat[mp1[v]][mp1[u]] = 1;
        }
        
        for(int k = 0; k < n; k++) 
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                    
        int maxx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                maxx = max(adjMat[i][j], maxx);
        }
        cout << "Network " << test++ <<": ";
        if(maxx == 1e9)//graph is disconnected
            cout << "DISCONNECTED" << endl;
        else cout << maxx << endl;
        cout << endl;
    }
    return 0;
}

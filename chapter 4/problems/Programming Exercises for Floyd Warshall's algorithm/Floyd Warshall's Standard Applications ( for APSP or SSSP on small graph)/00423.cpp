#include <bits/stdc++.h>
using namespace std;
int adjMat[105][105];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)adjMat[i][j] = 0;
                else adjMat[i][j] = 1e9;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                string s;
                cin >> s;
                if(s[0] == 'x')continue;
                stringstream ss(s);
                ss >> adjMat[i][j];
                adjMat[j][i] = adjMat[i][j];
            }
        }
        int ans = 0;
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    adjMat[i][j] = min(adjMat[i][j] , adjMat[i][k] + adjMat[k][j]);
                   // ans = max(adjMat[i][j], ans);
                }
            }
        }
        //we start from processor zero, and we want to reach every processor , so to take the maximum time till reach last processor
        for(int j = 0; j < n; j++){
            if(adjMat[0][j] != 1e9) ans = max(ans, adjMat[0][j]);
        }
        
        cout << ans << endl;
    }
    return 0;
}

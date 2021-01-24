#include <bits/stdc++.h>
using namespace std;
map < string, int > mp1;
map < int, string > mp2;
bool adjMat1[27][27];
bool adjMat2[27][27];
bool used1[27];
bool used2[27];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        if(tt > 1)cout << endl;
        int m;
        cin >> m;
        memset(adjMat1, 0, sizeof adjMat1);
        memset(adjMat2, 0, sizeof adjMat2);
        memset(used1, 0, sizeof used1);
        memset(used2, 0, sizeof used2);
        for(int i = 0; i < m; i++){
            char u, v;
            cin >> u >> v;
            adjMat1[u - 'A'][v - 'A'] = 1;
            adjMat1[v - 'A'][u - 'A'] = 1;
            used1[u - 'A'] = used1[v - 'A'] = true;
        }
        cin >> m;
        
        
        for(int i = 0; i < m; i++){
            char u, v;
            cin >> u >> v;
            adjMat2[u - 'A'][v - 'A'] = 1;
            adjMat2[v - 'A'][u - 'A'] = 1;
            used2[u - 'A'] = used2[v - 'A'] = true;
        }
        for(int k = 0; k < 27; k++){
            for(int i = 0; i < 27; i++){
                for(int j = 0; j < 27; j++){
                    if(used1[i] && used1[j] && used1[k])
                     adjMat1[i][j] |= (adjMat1[i][k] && adjMat1[j][k]);
                     
                    if(used2[i] && used2[j] && used2[k])
                     adjMat2[i][j] |= (adjMat2[i][k] && adjMat2[j][k]);
                }
            }
        }
        bool same = 1;
        for(int i = 0; i < 27; i++){
            for(int j = 0; j < 27; j++){
                if(adjMat1[i][j] != adjMat2[i][j])same = 0;
            }
        }
        if(same)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

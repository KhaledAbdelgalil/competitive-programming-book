#include <bits/stdc++.h>
using namespace std;
int adjMat[45][45];
bool nodes[45];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) adjMat[i][j] = 0;
            else adjMat[i][j] = 1e9;
        }
    }
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        int v;
        while(ss >> v) adjMat[i][v] = 1;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    cin.ignore();
    while(q--){
        int cnt = 0;
        memset(nodes, 0, sizeof nodes);
        string s;
        getline(cin, s);
        vector<int>geodesic;
        stringstream ss(s);
        int v;
        while(ss >> v)geodesic.push_back(v), nodes[v] = 1, cnt++;
        for(int i = 0; i < geodesic.size() - 1; i++){
            for(int j = i + 1; j < geodesic.size(); j++){
                for(int k = 1; k <= n; k++){
                    if(adjMat[geodesic[i]][geodesic[j]] == adjMat[geodesic[i]][k] + adjMat[k][geodesic[j]]){
                        if(nodes[k] == 0)nodes[k] = 1, cnt++;
                    }
                }
            }
        }
        if(cnt == n)cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}

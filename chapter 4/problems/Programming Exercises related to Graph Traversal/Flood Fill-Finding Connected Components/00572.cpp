#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[105][105];
int di[]={1,1,1,0,0,-1,-1,-1};
int dj[]={1,0,-1,1,-1,1,0,-1};

void dfs(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= m)return;
    if(grid[i][j] != '@')return;
    grid[i][j] = '.'; // to avoid double counting
    for(int f = 0; f < 8; f++)dfs(i + di[f], j + dj[f]);
    return;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        int cnt_components = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '@'){
                    cnt_components++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt_components << endl;
    }
    return 0;
}


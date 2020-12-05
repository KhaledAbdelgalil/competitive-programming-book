#include <bits/stdc++.h>
using namespace std;
bool vis[ 50 ][ 50 ];
char grid[ 50 ][ 50 ];
int di[]={1,1,1,0,0,-1,-1,-1};
int dj[]={1,0,-1,1,-1,1,0,-1};
int n;
void dfs(int i, int j){
    vis[i][j] = true;
    for(int f = 0; f < 8; f++){
        int newI = i + di[f];
        int newJ = j + dj[f];
        if(newJ >= 0 && newJ < n && newI >= 0 && newI < n && vis[newI][newJ] == false && grid[newI][newJ] == '1')
            dfs(newI, newJ);
    }
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int test = 1;
    while(cin >> n){
        memset(vis, false, sizeof vis);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
                if(grid[i][j] == '0')vis[i][j] == true;
            }
        int cnt_components = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
               
                if(grid[i][j] == '1' && vis[i][j] == false)cnt_components++,dfs(i, j);
            }
        cout << "Image number " << test++ << " contains " << cnt_components << " war eagles." << endl;

    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int di[]={1,1,1,0,0,-1,-1,-1};
int dj[]={1,0,-1,1,-1,1,0,-1};
int r, w;
int floodfill(int i, int j){
    if(i >= r || j >= w || i < 0 || j < 0 || vis[i][j] || grid[i][j] == '.')return 0;
    vis[i][j] = true;
    int cnt = 1;
    for(int f = 0; f < 8; f++)
        cnt += floodfill(i + di[f], j + dj[f]);
        
    return cnt;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    
    
    while(cin >> r >> w){
        if(r == 0 && w == 0)break;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < w; j++)
            cin >> grid[ i ][ j ];
        }
        memset(vis, false, sizeof vis);
        int cnt = 0;
        int cnt_stars = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0 ; j < w; j++){
                if(vis[i][j] == false && grid[i][j] == '*'){
                    cnt = floodfill(i, j);
                    if(cnt == 1)cnt_stars++;
                }
            }
        }
        cout << cnt_stars << endl;
    }
    return 0;
}


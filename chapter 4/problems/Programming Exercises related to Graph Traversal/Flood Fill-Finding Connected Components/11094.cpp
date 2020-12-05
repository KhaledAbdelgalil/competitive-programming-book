#include <bits/stdc++.h>
using namespace std;
int x,y;
char grid[25][25];
bool vis[25][25];
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

int floodfill(int i, int j, char n){
    if(j == -1) j = y -1;
    if(j == y) j = 0;
    if(i >= x  || x < 0  || vis[i][j] || grid[i][j] != n)return 0;
    int cnt = 1;
    vis[i][j] = true;
    for(int f = 0; f < 4; f++){
        cnt += floodfill(i + di[f], j + dj[f], n);
    }
    return cnt;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int problem = 1;
    while(cin >> x >> y){
     for(int i = 0; i < x; i++){
         for(int j = 0; j < y; j++){
             cin >> grid[ i ][ j ];
         }
     }        
     memset(vis, false, sizeof vis);
     int l,w;
     cin >> l >> w;
     char required = grid[ l ][ w ];
     floodfill(l, w, grid[ l ][ w ]);
     int cnt = 0;
     for(int i = 0; i < x; i++){
         for(int j = 0; j < y; j++){
             if(grid[i][j] == required && !vis[i][j])
                cnt = max(cnt, floodfill(i, j, required));
         }
     }
     cout << cnt << endl;
    }
    return 0;
}


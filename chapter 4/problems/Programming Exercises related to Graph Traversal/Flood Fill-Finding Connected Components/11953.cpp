#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int n;
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
bool ship_floodfill(int i, int j){
    if(i >= n || j >= n || i < 0 || j < 0 || vis[i][j] || grid[i][j] == '.')return 0;
    bool found_part_ship = false;
    if(grid[i][j] == 'x')found_part_ship = true;
    vis[i][j] = true;
    for(int f = 0; f < 4; f++){
        found_part_ship |= ship_floodfill(i + di[f], j + dj[f]);
    }
    return found_part_ship;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
    
    int t;
    cin >> t;
    int test = 1;
    while(t--){
        
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];
        memset(vis, false, sizeof vis);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j =0; j < n; j++){
                if(grid[i][j] == 'x' && !vis[i][j]){
                    if(ship_floodfill(i, j))cnt++;
                }
            }
        }
        cout << "Case " << test++ << ": "<< cnt << endl;
    }
   
    return 0;
}

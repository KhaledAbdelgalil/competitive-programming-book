#include <bits/stdc++.h>
using namespace std;
struct point{
    int x;
    int y;
    int d;
    point(int x_, int y_, int d_):x(x_), y(y_), d(d_){};
};
int n, m;
char grid[105][105];
int xend, yend;
queue < struct point > king, horses;
bool canWalk[1005][1005];
int xDir[] = {0, 0, 1, -1, 1, -1, 1, -1};
int yDir[] = {1, -1, 0, 0, 1, -1, -1, 1};
int horsesX[] = {-2, -1, 1, 2, -1, -2, 1, 2};
int horsesY[] = {1, 2, 2, 1, -2, -1, -2, -1};
bool inGrid(int x, int y){
    if(x >= n)return false;
    if(y >= m)return false;
    if(x < 0)return false;
    if(y < 0)return false;
    return true;        
}
int bfs_escape(){
   
        
    while(!horses.empty()){
        struct point front = horses.front();
        horses.pop();
        int x = front.x;
        int y = front.y;
        int d = front.d;
        for(int i = 0; i < 8; i++){
            int newX = x + horsesX[i];
            int newY = y + horsesY[i];
            if(inGrid(newX, newY) && canWalk[newX][newY]){
                canWalk[newX][newY] = false;
            }
        }
    }
        
    while(!king.empty()){
        struct point front = king.front();
        king.pop();
        int x = front.x;
        int y = front.y;
        int d = front.d;
        for(int i = 0; i < 8; i++){
            int newX = x + xDir[i];
            int newY = y + yDir[i];
            if( grid[newX][newY] == 'B')return d + 1;
            if(inGrid(newX, newY) && canWalk[newX][newY]){
                canWalk[newX][newY] = false;
                king.push(point(newX, newY, d + 1));
            }
        }
    }
            
    
    return -1;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin >> t;
    while(t--){
        while(!king.empty())king.pop();
        while(!horses.empty())horses.pop();
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
                canWalk[i][j] = false;
                if(grid[i][j] == '.')
                    canWalk[i][j] = true;
                else if(grid[i][j] == 'A')
                    king.push(point(i, j, 0));
                else if(grid[i][j] == 'B')
                    xend = i, yend = j;
                else if(grid[i][j] == 'Z'){
                    horses.push(point(i, j, 0));
                }
                    
            }
        }
        int ans = bfs_escape();
        if(ans == -1)cout << "King Peter, you can't go now!" << endl;
        else cout << "Minimal possible length of a trip is " << ans << endl;
    }

    return 0;
}


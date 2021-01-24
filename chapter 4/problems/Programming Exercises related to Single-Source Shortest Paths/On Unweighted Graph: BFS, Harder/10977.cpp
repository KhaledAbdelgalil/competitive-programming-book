#include <bits/stdc++.h>
using namespace std;
int n, m;
bool canWalk[210][210];
struct point{
    int x;
    int y;
    int d;
    point(int x_, int y_, int d_):x(x_), y(y_), d(d_){};
};
int xDir[] = {0, -1, 1, 0};
int yDir[] = {-1, 0, 0, 1};

bool inGrid(int x, int y){
    if(x >= n + 1)return false;
    if(y >= m + 1)return false;
    if(x < 1)return false;
    if(y < 1)return false;
    return true;        
}
int bfs_escape(){
   
   
    if (!canWalk[1][1])
        return -1;
    
    if (n == 1 && m == 1)
        return 0;
        
    std::queue<struct point>q;
    q.push(point(1, 1, 0));
    canWalk[1][1] = false;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();
        for(int i = 0; i < 4; i++){
            int newX = x + xDir[i];
            int newY = y + yDir[i];
            if(canWalk[newX][newY]){
                if(newX == n && newY == m)return d + 1;
                canWalk[newX][newY] = false;
                q.push(point(newX, newY, d + 1));
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
    
    while(cin >> n >> m , n){
        for(int i = 1; i <= n; i++){
            canWalk[i][0] = canWalk[i][ m + 1] = false;
            for(int j = 1; j <= m; j++)canWalk[i][j] = true;
        }
        for(int i = 0; i <= m; i++)canWalk[0][i] = canWalk[n + 1][i] = false;
        int f;
        cin >> f;
        while(f--){
            int u, v;
            cin >> u >> v;
            canWalk[u][v] = false;
        }
        cin >> f;
         
        while (f--)
        {
            int r, c, l;
            cin >> r >> c >> l;
            
            int farthest = l * l;
            
            for (int rC = -l; rC <= l; ++rC)
            {
                for (int cC = -l; cC <= l; ++cC)
                {
                    if (cC * cC + rC * rC > farthest)
                        continue;
                    
                    int rNew = r + rC, cNew = c + cC;
                    if (rNew > 0 && cNew > 0 && rNew <= n && cNew <= m)
                        canWalk[rNew][cNew] = false;
                }
            }
        }
        
        //cout << " here " << endl;
        int ans = bfs_escape();
        if(ans == -1){
            cout << "Impossible." << endl;
        }else cout << ans << endl;
    }
    return 0;
}


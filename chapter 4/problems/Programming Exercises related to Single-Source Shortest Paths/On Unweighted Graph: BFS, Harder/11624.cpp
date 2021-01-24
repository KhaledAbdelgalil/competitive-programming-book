#include <bits/stdc++.h>
using namespace std;
struct point{
    int x;
    int y;
    int d;
    point(int x_, int y_, int d_):x(x_), y(y_), d(d_){};
};
int n, m;
char grid1[1005][1005];
queue < struct point > fire, joe;
bool canWalk[1005][1005];
int xDir[] = {0, 0, 1, -1};
int yDir[] = {1, -1, 0, 0};
bool inGrid(int x, int y){
    if(x >= n)return false;
    if(y >= m)return false;
    if(x < 0)return false;
    if(y < 0)return false;
    return true;        
}
int bfs_escape(){
    while(!joe.empty()){
        queue<struct point>temp;
        
        while(!fire.empty()){
            struct point front = fire.front();
            fire.pop();
            int x = front.x;
            int y = front.y;
            int d = front.d;
            for(int i = 0; i < 4; i++){
                int newX = x + xDir[i];
                int newY = y + yDir[i];
                if(inGrid(newX, newY) && canWalk[newX][newY]){
                    canWalk[newX][newY] = false;
                    temp.push(point(newX, newY, d + 1));
                }
            }
        }
        //now all new fires are in temp , let's swap;
        fire.swap(temp);//temp now is empty
        while(!joe.empty()){
            struct point front = joe.front();
            joe.pop();
            int x = front.x;
            int y = front.y;
            int d = front.d;
            for(int i = 0; i < 4; i++){
                int newX = x + xDir[i];
                int newY = y + yDir[i];
                if(!inGrid(newX, newY))//joe esacped
                    return d + 1;
                if(inGrid(newX, newY) && canWalk[newX][newY]){
                    canWalk[newX][newY] = false;
                    temp.push(point(newX, newY, d + 1));
                }
            }
        }
        //new positions of joe are in temp;
        joe.swap(temp);
            
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
        while(!joe.empty())joe.pop();
        while(!fire.empty())fire.pop();
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid1[i][j];
                canWalk[i][j] = false;
                if(grid1[i][j] == '.')
                    canWalk[i][j] = true;
                else if(grid1[i][j] == 'F')
                    fire.push(point(i, j, 0));
                else if(grid1[i][j] == 'J')
                    joe.push(point(i, j, 0));
            }
        }
        int ans = bfs_escape();
        if(ans == -1)cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }

    return 0;
}


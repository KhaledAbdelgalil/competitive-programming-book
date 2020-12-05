#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
int n,m,l;
string s;
int main(){
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    while(cin >> n >> m >> l){
        if(n == 0 && m == 0 && l == 0)break;
        int x,y;
        char orientation;
        for(int i = 0; i < n; i++ ){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
                if(grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'L' || grid[i][j] == 'O'){
                x = i, y = j, orientation = grid[i][j];    
                }
            }
        }
        cin >> s;
        int cntSticker = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == 'F'){
                int newX, newY;
                if(orientation == 'N'){
                    newX = x - 1;
                    newY = y;
                }else if(orientation == 'S'){
                    newX = x + 1;
                    newY = y;
                }else if(orientation == 'O'){
                    newX = x;
                    newY = y - 1;
                }else if(orientation == 'L'){
                    newX = x;
                    newY = y + 1;
                }
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] != '#'){
                    x = newX;
                    y = newY;
                    if(grid[x][y] == '*') cntSticker++, grid[x][y] = '.';//you collect sticker so put grid[x][y] = '.' to avoid overcount
                }
            }else if(s[i] == 'D'){
                if(orientation == 'N')orientation = 'L';
                else if(orientation == 'L')orientation = 'S';
                else if(orientation == 'S')orientation = 'O';
                else if(orientation == 'O')orientation = 'N';
            }else if(s[i] == 'E'){
                if(orientation == 'N')orientation = 'O';
                else if(orientation == 'O')orientation = 'S';
                else if(orientation == 'S')orientation = 'L';
                else if(orientation == 'L')orientation = 'N';
            }
        }
        cout << cntSticker << endl;
    }
   
   
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int grid[105][105];
bool vis[105][105];
int n;
int di[] = {1,0,0,-1};
int dj[] = {0,1,-1,0};
int floodfill(int i, int j, int x){
    if(i >= n + 1 || j >= n + 1 || i < 1 || j < 1 || vis[i][j] || grid[i][j] != x)return 0;
    vis[i][j] = true;
    int cnt = 1;
    for(int f = 0; f < 8; f++)
        cnt += floodfill(i + di[f], j + dj[f], x);
        
    return cnt;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    
    
    while(cin >> n && n){
        cin.ignore();
       for(int i = 1; i <= n; i++){
           for(int j = 1; j <= n; j++)
                grid[i][j] = n;
       }
       
       for(int i = 1; i < n; i++){
           string s;
           int x,y;
           getline(cin, s);
           if(s == "")continue;
           stringstream is(s);
           while(is >> x >> y){
               grid[x][y] = i;
           }
       }
        memset(vis, false, sizeof vis);
        bool ok = true;
        for(int i =1; i <= n && ok; i++){
            for(int j = 1; j <= n && ok; j++){
                if(vis[i][j] == false){
                    int cnt = floodfill(i, j, grid[i][j]);
                    if(cnt != n)ok =false;
                }
            }
        }
        if(ok)cout << "good" << endl;
        else cout << "wrong" << endl;
    }
    return 0;
}

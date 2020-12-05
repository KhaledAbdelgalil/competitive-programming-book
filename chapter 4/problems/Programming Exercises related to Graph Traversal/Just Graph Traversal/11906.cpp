#include <bits/stdc++.h>
using namespace std;
int t,r,c,n,m,w;
bool can_vis[105][105];
bool vis[105][105];
int cnt_even, cnt_odd;
void dfs (int i, int j){
    if(vis[ i ][ j ])return;
    vis[ i ][ j ] = true;
    if(n == m){
        
        int cnt = 0;
        int newI,newJ;
        newI = i - n;
        newJ = j - m;
        if(newI >= 0 && newJ >= 0 && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        newI = i - n;
        newJ = j + m;
        if(newI >= 0 && newJ < c && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        newI = i + n;
        newJ = j - m;
        if(newI < r && newJ >= 0 && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        
        newI = i + n;
        newJ = j + m;
        if(newI < r && newJ < c && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        
        if(cnt % 2 == 0 )cnt_even++;
        else  cnt_odd++;
        
    }else if(n == 0){
        int newI = i - m;
        int newJ = j;
        int cnt = 0;
        if(newI >= 0 && can_vis[newI][newJ]){
            cnt++;
            dfs(newI,newJ);
        }
        newI = i + m;
        newJ = j;
        if(newI < r && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        newI = i;
        newJ = j - m;
        if(newJ >= 0 && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        newI = i;
        newJ = j + m;
        
        if(newJ < c && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        
        if(cnt % 2 == 0 )cnt_even++;
        else  cnt_odd++;
        
    }else if(m == 0){
        
        int newI = i - n;
        int newJ = j;
        int cnt = 0;
        if(newI >= 0 && can_vis[newI][newJ]){
            cnt++;
            dfs(newI,newJ);
        }
        newI = i + n;
        newJ = j;
        if(newI < r && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        newI = i;
        newJ = j - n;
        if(newJ >= 0 && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        newI = i;
        newJ = j + n;
        
        if(newJ < c && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        
        if(cnt % 2 == 0)cnt_even++;
        else  cnt_odd++;
    }else {
        int cnt = 0;
        int newI,newJ;
        newI = i - n;
        newJ = j - m;
        if(newI >= 0 && newJ >= 0 && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        newI = i - n;
        newJ = j + m;
        if(newI >= 0 && newJ < c && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        newI = i + n;
        newJ = j - m;
        if(newI < r && newJ >= 0 && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        
        newI = i + n;
        newJ = j + m;
        if(newI < r && newJ < c && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        
        
        
        
        
        newI = i - m;
        newJ = j - n;
        if(newI >= 0 && newJ >= 0 && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        newI = i - m;
        newJ = j + n;
        if(newI >= 0 && newJ < c && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        newI = i + m;
        newJ = j - n;
        if(newI < r && newJ >= 0 && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        
        newI = i + m;
        newJ = j + n;
        if(newI < r && newJ < c && can_vis[newI][newJ]){
            cnt++;
            dfs(newI, newJ);
        }
        if(cnt % 2 == 0)cnt_even++;
        else  cnt_odd++;
    }
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    cin >> t;
    int test = 1;
    while(t--){
        cin >> r >> c >> n >> m;
        for(int i = 0; i <= r; i++){
            for(int j = 0; j <= c; j++)
                can_vis[i][j] = true;
        }
        memset(vis, false, sizeof vis);
        cin >> w;
        cnt_odd = cnt_even = 0;
        for(int i = 0; i < w; i++){
            int x, y;
            cin >> x >> y;
            can_vis[x][y] = false;
        }
        
        dfs(0,0);
        cout << "Case " << test++ << ": " << cnt_even << " " << cnt_odd << endl;
    }
    return 0;
}

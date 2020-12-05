#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
int  n, m;
int di[]={1,0,0,-1};
int dj[]={0,1,-1,0};
bool vis[105][105];
int dfs(int rst,int cst){
    if(rst >= n || rst < 0 || cst < 0 || cst >= m || grid[rst][cst] != '0' || vis[rst][cst])return 0;
    vis[rst][cst] = true;
    int cnt = 1;
    for(int i = 0; i < 4; i++){
        cnt = cnt + dfs(rst + di[i], cst + dj[i]);
    }    
    return cnt;
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin >> t;
    bool first = true;
    while(t--){
        if(!first)cout << endl;
        first = false;
        string s;
        int rst, cst;
        cin >> rst >> cst;
        rst--, cst--;
        cin.ignore();
        grid.clear();
        memset(vis, false, sizeof vis);
        while(getline(cin, s) && s != ""){
            grid.push_back(s);
        }
        n = grid.size();
        m = grid[0].size();
        cout << dfs(rst, cst) << endl;
    }
   
    return 0;
}


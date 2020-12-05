#include <bits/stdc++.h>
using namespace std;
string s[30];
bool vis[30][30];
int di[]={1,1,1,0,0,-1,-1,-1};
int dj[]={1,0,-1,1,-1,1,0,-1};
int n;
int floodfill(int i, int j){
    if(i >= n || j >= n || i < 0 || j < 0 || vis[i][j] || s[i][j] == '0')return 0;
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
    
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    bool first = true;
    while(t--){
        if(!first)cout << endl;
        first = false;
        n = 0;
        while(getline(cin, s[n]) && s[n] != ""){
            n++;
        }
        memset(vis, false, sizeof vis);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < s[0].size(); j++){
                if(vis[i][j] == false && s[i][j] == '1'){
                    cnt = max(cnt, floodfill(i, j));
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}


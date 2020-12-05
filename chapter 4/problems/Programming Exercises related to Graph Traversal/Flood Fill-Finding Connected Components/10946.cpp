#include <bits/stdc++.h>
using namespace std;
int x,y;
char grid[55][55];
bool vis[55][55];
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
map < char, vector < int > > mp;
bool cmp(const pair<int, char> &a, const pair<int, char> &b){
    if(a.first > b.first)return true;
    else if(a.first == b.first && a.second < b.second)return true;
    return false;
}
int floodfill(int i, int j, char n){
    if(i >= x || j >= y || x < 0 || y < 0 || vis[i][j] || grid[i][j] != n)return 0;
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
        mp.clear();
        if( x == 0 && y == 0 )break;
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                cin >> grid[i][j];
            }
        }
        memset(vis, false, sizeof vis);
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                if(vis[i][j] == false && grid[i][j] != '.'){
                    int cnt = floodfill(i, j , grid[i][j]);
                    mp[ grid[i][j] ].push_back( cnt ); 
                }
            }
        }
        vector< pair<int, char> > ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            for(int i = 0; i < (it -> second).size(); i++)
            ans.push_back( { (it -> second)[i], it -> first} );
        }
        sort(ans.begin(), ans.end(), cmp);
        cout << "Problem "<< problem++ << ":" << endl;
        
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i].second << " " << ans[i].first << endl;
        }
        
    }
    return 0;
}


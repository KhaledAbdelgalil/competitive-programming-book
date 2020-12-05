#include <bits/stdc++.h>
using namespace std;
bool vis[2000][2000];
char grid[2000][2000];
int h,w;
int t;
map <char, int>mp;
int di[] = {1,0,0,-1};
int dj[] = {0,1,-1,0};
void floodfill(int i, int j, char x){
    if(vis[i][j] || grid[i][j] != x)return;
    vis[i][j] = true;
    for(int f = 0; f < 4; f++)floodfill(i + di[ f ], j + dj[ f ], x);
}
bool cmp(const pair<int, char> & a, const pair <int, char> &b){
    if(a.first > b.first)return true;
    else if(a.first == b.first && a.second < b.second)return true;
    return false;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    cin >> t;
    int test = 1;
    while( t-- ){
        mp.clear();
        cin >> h >> w;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                cin >> grid[ i ][ j ];
        
        memset(vis, false, sizeof vis);
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(vis[i][j] == false){
                    floodfill(i, j, grid[i][j]);
                    mp[grid[i][j]]++;
                }
            }
        }
        std::vector< pair<int, char> >ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back({it -> second, it -> first});
        }
        sort(ans.begin(), ans.end(), cmp);
        
        cout << "World #" << test++ << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i].second << ": " << ans[i].first << endl;
        }
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
vector < vector <int> > adj;
map <int, int> mp;//day --> boomSize
int n;
void bfs(int src){
    std::queue< pair <int,int> >q;
    q.push({src, 0});
    vector < bool > vis(n, 0);
    vis[src] = 1;
    while( !q.empty() ){
        pair<int, int> front = q.front();
        q.pop();
        for(int i = 0; i < adj[front.first].size(); i++){
            int v = adj[front.first][i];
            if(vis[v] == 0){
                vis[v] = 1;
                pair <int, int > t = {v, front.second + 1};
                q.push(t);
                mp[front.second + 1]++;
            }
        }
    }
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    while(cin >> n){
        adj.clear();
        adj.resize(n);
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            adj[i].resize(m);
            for(int j = 0; j < m; j++)
                cin >> adj[i][j];
        }
        int p;
        cin >> p;
        while( p-- ){
            int src;
            cin >> src;
            mp.clear();
            bfs(src);
            int day = 0;
            int maxx = 0;
            for(int i = 1; i <= n; i++){
                if(mp.find(i) != mp.end()){
                    if(mp[i] > maxx){
                        maxx = mp[i];
                        day = i;
                    }
                }
            }
            if(maxx == 0){
                cout << 0 << endl;
            }else cout << maxx << " " << day << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m;
int dist[1005][1005];
int xDir[] = {0, 0, 1, -1};
int yDir[] = {1, -1, 0, 0};
int grid[1005][1005];
int dijkstra(){
    dist[0][0] = grid[0][0];
    priority_queue < pair<int, pair<int,int> >, vector < pair<int, pair<int,int> > >, greater < pair<int, pair<int,int> > > > pq;
    pq.push({grid[0][0], {0,0} });
    while(!pq.empty()){
        pair<int, pair<int,int> > p = pq.top();
        pq.pop();
        int x = p.second.first;
        int y = p.second.second;
        int d = p.first;
        if(d > dist[x][y]) //you have found another shortest path to u
            continue;
        for(int j = 0; j < 4; j++){
            int newX = x + xDir[j];
            int newY = y + yDir[j];
            if(newY < 0 || newX < 0 || newX >= n || newY >= m)continue;
            
            if(dist[x][y] + grid[newX][newY] < dist[newX][newY]){
                //this is another better path for v.first
                dist[newX][newY] = dist[x][y] + grid[newX][newY];
                pq.push({dist[newX][newY], {newX, newY}});
            }
        }
    }
    return dist[ n - 1 ][ m - 1 ];
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin >> t;
    while(t--){
    
     cin >> n >> m;
     for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++){
            cin >>  grid[i][j];
            dist[i][j] = 1000 * 1000 * 9;//the maximum 
         }
     }
     
     int ans = dijkstra();
     cout << ans << endl;
    }
    return 0;
}


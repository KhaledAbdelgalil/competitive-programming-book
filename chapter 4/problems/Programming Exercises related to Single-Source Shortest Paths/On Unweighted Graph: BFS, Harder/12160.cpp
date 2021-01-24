#include <bits/stdc++.h>
using namespace std;
vector<int>keys;
map <int, vector<int> > graph;
int bfs(int src, int des){
    map<int, bool>vis;
    vis[src] = 1;
    queue < pair <int, int> >q;
    q.push({src, 0});
    while(!q.empty()){
      pair<int, int > front = q.front();
      q.pop();
      if(des == front.first)return front.second;
      for(int i = 0; i < graph[front.first].size(); i++){
          int v = graph[front.first][i];
          if(vis.find(v) == vis.end()){
              vis[v] = 1;
              q.push({v, front.second + 1});
          }
      }
    }
    return -1;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int src , des, k;
    int test = 1;
    while(cin >> src >> des >> k){
        if(src == 0 && des == 0 && k == 0)break;
        keys.clear();
        keys.resize(k);
        graph.clear();
        for(int i = 0; i < k; i++){
            cin >> keys[i];
            //adding edges
            for(int j = 0; j <= 9999; j++){
                graph[j].push_back((keys[i] + j)% 10000);
            }
        }
        
        int ans = bfs(src, des);
        cout <<"Case "<< test++ <<": ";
        if(ans == -1){
            cout << "Permanently Locked" << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}


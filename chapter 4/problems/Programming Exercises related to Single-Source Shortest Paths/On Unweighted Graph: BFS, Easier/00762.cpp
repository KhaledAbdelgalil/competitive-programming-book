#include <bits/stdc++.h>
using namespace std;
map<string, vector < string> > graph;
map < string, string> parents;
void print_path(string u, string v){
    if(u == v)return;
    print_path(parents[u], u);
    cout << u << " " << v << endl;
    
}
bool bfs(string u, string v){
    map < string, bool> vis;
    vis[u] == 1;
    queue<string>q;
    q.push(u);
    parents[u] = u;
    
    while( !q.empty() ){
        string front = q.front();
        q.pop();
        if(front == v)return true;
        for(int i = 0; i < graph[front].size(); i++){
            string v = graph[front][i];
            if(vis.find(v) == vis.end()){
                vis[v] = 1;
                parents[v] = front;
                q.push(v);
            }
        }
    }
    return false;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    bool first = true;
    while(cin >> n){
        if( !first )cout << endl;
        first = false;
        parents.clear();
        graph.clear();
        while(n--){
            string u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        string u, v;
        cin >> u >> v;
        if( bfs(u, v) )
            print_path(parents[v], v);
        else cout << "No route\n";
    }
    return 0;
}


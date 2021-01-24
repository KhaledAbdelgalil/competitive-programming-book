#include <bits/stdc++.h>
using namespace std;
vector < string > buckets[17];
map < string , vector<string> > adj;
map < string, string > route;

int isDoublet(string x, string y, int len) {
    static int i, cnt;
    for(i = 0, cnt = 0; i < len; i++) {
        cnt += x[i] != y[i];
        if(cnt > 1)
            return 0;
    }
    return cnt == 1;
}
bool bfs(string u, string v){
    map < string, bool > vis;
    std::queue<string>q;
    q.push(u);
    vis[u] = 1;
    route[u] = u;
    while(!q.empty()){
        string t = q.front();
        q.pop();
        if(t == v)return 1;
        for(int i = 0; i < adj[t].size(); i++){
            string f = adj[t][i];
            if(vis.find(f) == vis.end()){
                route[f] = t;
                vis[f] = 1;
                q.push(f);
            }
        }
    }
    return 0;
}
void print_path(string v){
    if(route[v] == v){
        cout << v << endl;
        return;
    }
    print_path(route[v]);
    cout << v << endl;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    string s;
    while(getline(cin, s) && s != "" && s[0] != '\0'){
       buckets[s.size()].push_back(s);
       //cout << s << endl;
    }
    //exit(0);
    //build graph
    for(int i = 0; i < 17; i++){
        int m = buckets[i].size();//get words of same length
        for(int j = 0; j < m; j++){
            for(int k = j + 1; k < m; k++){
                if( isDoublet(buckets[i][j], buckets[i][k], buckets[i][k].size()) ){
                    adj[buckets[i][j]].push_back(buckets[i][k]);
                    adj[buckets[i][k]].push_back(buckets[i][j]);
                }
            }
        }
    }
    
    //bfs
    bool first = 1;
    while(getline(cin, s) && s != ""){
       // cout << s << endl;
        if(!first)cout << endl;
        first = 0;
        string u, v;
        stringstream ss(s);
        ss >> u >> v;
        bool ans = bfs(u, v);
        if(ans){
            print_path(v);
        }else cout << "No solution." << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
map < string, int > mp1;
map < int, string > mp2;
vector< vector <int> > adj ;
bool differInOneLetter(string s, string f){
    if(s.size() != f.size())return 0;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != f[i])cnt++;
    }
    return cnt == 1;
}
int bfs(int src, int des){
    std::queue< pair <int, int > >q;
    q.push({src, 0});
    vector<bool>vis(mp1.size(), 0);
    vis[src] = 1;
    while(!q.empty()){
        pair<int, int> front = q.front();
        q.pop();
        if(front.first == des)return  front.second;
        for(int i = 0; i < adj[front.first].size(); i++){
            int v = adj[front.first][i];
            if(vis[v] == 0){
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
    
    int t;
    cin >> t;
    while(t--){
        string s;
        int index = 0;
        mp1.clear();
        mp2.clear();
        while(cin >> s && s != "*"){
            mp1[s] = index;
            mp2[index] = s;
            index++;
        }
        adj.clear();
        adj.resize(mp1.size());
        for(int i = 0; i < mp1.size(); i++){
            for(int j = i + 1; j < mp1.size(); j++){
                if(differInOneLetter(mp2[i], mp2[j]))
                    {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    }
            }
        }
        cin.ignore();
        while(getline(cin, s) && s != "" && s != "\r"){
            if(s.size() == 0)break;
            stringstream ss(s);
            string u, v;
            ss >> u >> v;
            //cout << u << v;
            int ans = bfs(mp1[u], mp1[v]);
            if(ans != -1)cout << u << " " << v << " " << ans << endl;
        }
        if(t)cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
vector< vector < pair <int, int > > >adj;
int degree[26];
int dist[26];
int min_pathBetween(int src, int t){
    for(int i = 0; i < 26; i++)dist[i] = oo;
    priority_queue< pair <int, int >, vector < pair<int,int> >, greater < pair<int,int> > > pq;
    dist[src] = 0;
    pq.push({dist[src], src});
    while(!pq.empty()){
        pair <int, int > top = pq.top();
        pq.pop();
        int u = top.second;
        int d = top.first;
        if(d > dist[u])continue;
        if(u == t)return dist[u];
        for(int i = 0; i < adj[u].size(); i++){
            pair<int, int> v = adj[u][i];
            if(dist[v.first] > dist[u] + v.second){
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    return dist[t];
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
    string s;
    while(cin >> s && s != "deadend" && s != ""){
        adj.clear();
        adj.resize(26);
        memset(degree, 0, sizeof degree);
        int totalWeight = 0;
        do{
            degree[s[0] - 'a']++;
            degree[s[s.size() - 1] - 'a']++;
            adj[s[0] - 'a'].push_back({s[s.size() - 1] - 'a', s.size()});
            adj[s[s.size() - 1] - 'a'].push_back({s[0] - 'a', s.size()});
            totalWeight += s.size();
        }while(cin >> s && s != "deadend");
        vector<int>oddDegreesNodes;
        for(int i = 0; i < 26; i++){
            if(degree[i] % 2 == 1)oddDegreesNodes.push_back(i);
        }
        if(oddDegreesNodes.size() == 0){//so you need only to make euler path(totalWeight)
            cout << totalWeight << endl;
        }else if(oddDegreesNodes.size() == 1){
            int minWeight = totalWeight;
            for(int i = 0; i < adj[oddDegreesNodes[0]].size(); i++){
                pair<int, int> v = adj[oddDegreesNodes[0]][i];
                minWeight = min(v.second, minWeight);
            }
            totalWeight += minWeight;
            cout << totalWeight << endl;
        }else if(oddDegreesNodes.size() == 2){
            //euler tour + min_pathBetween 2 nodes
            /*cout << totalWeight << endl;
            cout << char(oddDegreesNodes[0] + 'a') << " " << char(oddDegreesNodes[1] + 'a') << endl;
            */
            totalWeight += min_pathBetween(oddDegreesNodes[0], oddDegreesNodes[1]);
            cout << totalWeight << endl;
        }
        
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int Rgraph[38][38];
int parent[38];
bool vis[38];
bool bfs(int s, int t){
    queue<int> q;
    parent[s] = -1;
    vis[s] = 1;
    memset(vis, 0, sizeof vis);
    q.push(s);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i = 0; i < 38; i++){
            if(Rgraph[top][i] > 0 && vis[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
                parent[i] = top;
            }
        }
    }
    return vis[t] == 1;//there is a path between s,t
}
int fordFulkerson(int s, int t){
    int maxFlow = 0;
    while(bfs( s, t)){//while there is still residual path(augmented) between s, t
        int min_flow_in_path = 1e9;
        int v, u;
        for(v = t; v != s; v = parent[v]){
            u = parent[v];
            min_flow_in_path = min(min_flow_in_path, Rgraph[u][v]);
        }
        for (v=t; v != s; v=parent[v]) 
        { 
            u = parent[v]; 
            Rgraph[u][v] -= min_flow_in_path; 
            Rgraph[v][u] += min_flow_in_path; 
        } 
        maxFlow += min_flow_in_path;
  
    }
    return maxFlow;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    string s;
    while(getline(cin , s)){
        int allApps = 0;
        memset(Rgraph, 0, sizeof Rgraph);
        for(int i = 27; i <= 36; i++){
            Rgraph[i][37] = 1;//between computer and target is 1(you can only use one computer)
        }
        int application = (int)(s[0] - 'A') + 1;
        int neededComputers = s[1] - '0';
        Rgraph[0][application] = neededComputers;//you should run neededComputers of this application
        s = s.substr(3);
        allApps += neededComputers;
        for(int i = 0; i < s.size(); i++){
            int computerVertex = (s[i] - '0') + 27;
            Rgraph[application][computerVertex] = 1;//the application need to be runned on one of the computers
        }
        while(getline(cin, s) && s != ""){
            application = (int)(s[0] - 'A') + 1;
            neededComputers = s[1] - '0';
            Rgraph[0][application] = neededComputers;//you should run neededComputers of this application
            s = s.substr(3);
            allApps += neededComputers;
            for(int i = 0; i < s.size(); i++){
                int computerVertex = (s[i] - '0') + 27;
                Rgraph[application][computerVertex] = 1;//the application need to be runned on one of the computers
            }
        }
        //till now you formed the model of network flow problem(residual graph)
        //get maxFlow from source(0) till target(37)
        int maxFlow = fordFulkerson(0, 37);
        //cout << maxFlow <<endl;
        if(maxFlow == allApps){
            for(int i = 27; i <= 36; i++)//this the computers let's see where it allocated
            {
                bool alloc = false;
                for(int j = 1; j <= 26 && !alloc; j++)//application
                {
                    if(Rgraph[i][j]){
                        cout << char(j - 1 + 'A');
                        alloc = true;
                    }
                }
                if(!alloc)cout <<"_" ;
            }
            cout << endl;
        }
        else cout << "!" << endl;
    }
    return 0;
}

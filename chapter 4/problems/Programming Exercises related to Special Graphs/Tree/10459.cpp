#include <bits/stdc++.h>
using namespace std;
vector< vector < int > > adj;
vector < int > dist;
vector < int > prevs;
int n;
int bfs(int src){
    prevs.clear();
    prevs.resize(n + 1);
    dist.clear();
    dist.resize(n + 1, -1);
    dist[src] = 0;
    prevs[src] = -1;
    queue<int>q;
    q.push(src);
    int index = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(index == -1){
            index = u;
        }else if(dist[u] > dist[index]){
            index = u;
        }
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
                prevs[v] = u;
            }
        }
    }
    return index;
}
int main()
{  
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    while(cin >> n){
        adj.clear();
        adj.resize(n + 1);
        for(int i  = 1; i <= n; i++){
            int f;
            cin >> f;
            while(f--){
                int v;
                cin >> v;
                adj[i].push_back(v);
            }
        }
        /*
            to solve problem correctly, get diameter of tree, the nodes in center on the half way
            (actually will be one or two nodes in every tree)of diameter are the best to choose,
            the nodes that are far from center are the worst to choose.
        */
        int u, v;
        u = bfs(1);//get farhtest point from 1
        v = bfs(u);//get farthest point from u, now dist[v] is diameter of tree
        //now you have dist[v] = diameter, let us get centers(best nodes)
        vector<int> best;
        int diameter = dist[v];
        if(diameter % 2)//diameter is odd
        {
            //go back on your path to find center
            for(int i = v; i != -1; i = prevs[i]){
                if(dist[i] == (diameter + 1) / 2){
                    best.push_back(i);
                }else if(dist[i] == diameter /2){
                    best.push_back(i);
                }
            }
        }else{//diameter is even
        
            //go back on your path to find center
            for(int i = v; i != -1; i = prevs[i]){
                if(dist[i] == diameter  / 2){
                    best.push_back(i);
                }
            }
        }
        vector<int>worst;
        //now you have the best nodes , just got farthest from them, these nodes will be worst.
        for(int i = 0; i < best.size(); i++){
            int farthest = bfs(best[i]);
            for(int i = 1; i <= n; i++){
                if(dist[i] == dist[farthest] )//so this is a worst node
                    worst.push_back(i);
            }
        }
        sort(worst.begin(), worst.end());
        sort(best.begin(), best.end());
        cout << "Best Roots  :";
        for(int i = 0; i < best.size(); i++){
            cout << " " << best[i];
        }
        cout << endl;
        
        cout << "Worst Roots :";
        for(int i = 0; i < worst.size(); i++){
            cout << " " << worst[i];
        }
        cout << endl;
        //best nodes must be 1 or 2, think about it.
       //assert(best.size() == 1 || best.size() == 2); 
    }
    return 0;
}


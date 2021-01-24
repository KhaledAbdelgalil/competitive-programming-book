#include <bits/stdc++.h>
using namespace std;
vector < vector<int> > adj;
map < int, int > mp;
int main()
{  
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int test = 1;
    int u, v;
    while(cin >> u >> v){
        if(u == 0 && v == 0){
            cout << "Case " << test++ << " is a tree." << endl;
            continue;
        }
        if(u <= -1 && v <= -1)break;
        int sizee = 1;
        adj.clear();
        adj.resize(105);
        mp.clear();
        int x =mp[u];
        if(!x){
            x = sizee++;
            mp[u] = x;
        }
        int y = mp[v];
        if(!y){
            y = sizee++;
            mp[v] = y;
        }
        u = x, v =y;
        adj[u].push_back(v);
        vector<int>indegree(105, 0);
        vector<bool>usedInt(105, 0);
        indegree[v]++;
        usedInt[u] = usedInt[v] = 1;
        int maxxNodeNumber = max(u, v);
        while(cin >> u >> v){
            if(u <= 0 && v <= 0)break;
            x =mp[u];
            if(!x){
                x = sizee++;
                mp[u] = x;
            }
            y = mp[v];
            if(!y){
                y = sizee++;
                mp[v] = y;
            }
            u = x, v =y;
            adj[u].push_back(v);
            indegree[v]++;
            usedInt[u] = usedInt[v] = 1;
            maxxNodeNumber = max(u, v);
        }
        //let's bring the root of the tree
        int root = -1;
        for(int  i = 1; i <= maxxNodeNumber; i++){
            if(usedInt[i] && indegree[i] == 0 && root == -1){
                //this is the first root you find
                root = i;
            }else if(usedInt[i] && indegree[i] == 0){
                //second root to find!!!!!! not a tree
                root = -1;
                break;
            }
        }
        if(root == -1)//it's not a tree(this means that you don't find a root or find more than one root, so not a tree)
        {
            cout << "Case " << test++ << " is not a tree." << endl;
        }else //let's check the unique path between root and every node
        {
            vector<bool>vis(105, 0);
            queue <int> q;
            q.push(root);
            bool treeOrNot = 1;
           // cout << root << endl;
            vis[root] = 1;
            while(!q.empty() && treeOrNot){
                int top = q.front();
                q.pop();
                for(int i = 0; i < adj[top].size(); i++){
                    int v = adj[top][i];
                    if(vis[v] == 0){
                        vis[v] = 1;
                        q.push(v);
                    }else if(vis[v] == 1){
                        //not unique path!!!! not a tree
                        treeOrNot = 0;
                        break;
                    }
                }
            }
            //let's see if all nodes are visited i.e graph is connected(this is the last check we will make)
            for(int i = 1; i <= maxxNodeNumber && treeOrNot; i++){
                if(usedInt[i] && vis[i] == 0)treeOrNot = 0;
            }
            if(treeOrNot) cout << "Case " << test++ << " is a tree." << endl;
            else cout << "Case " << test++ << " is not a tree." << endl;
        }
    }
    return 0;
}


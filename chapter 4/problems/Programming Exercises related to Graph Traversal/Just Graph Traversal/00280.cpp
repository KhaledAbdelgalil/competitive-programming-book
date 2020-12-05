#include <bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > vvi;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    vvi adj_list;
    int n;
    while(cin>>n && n){
        adj_list.clear();
        adj_list.resize(n + 5);
        int u;
        while(cin >> u && u){
            int v;
            while(cin >> v && v){
                adj_list[ u ].push_back( v );
            }
        }
        int ques;
        cin >> ques;
        while(ques--){
            int u;
            cin>>u;
            vector<bool>vis(n + 5,0);
            queue<int>q;
            q.push(u);
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(int i = 0; i < adj_list[front].size(); i++){
                    if(vis[adj_list[front][i]] == false){
                        vis[adj_list[front][i]] = true;
                        q.push(adj_list[front][i]);
                    }
                }
            }
            vector<int>ans;
            for(int i = 1;i <= n; i++){
                if(vis[i] == false)ans.push_back(i);
            }
            cout<<ans.size();
            for(int i = 0; i < ans.size(); i++)cout<<" "<<ans[i];
            cout<<endl;
        }
    }
    
    
    return 0;
}


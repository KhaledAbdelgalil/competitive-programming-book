#include <bits/stdc++.h>
using namespace std;
int nodes_value[105];
vector<int>DAG[105];
int t;
int n,m;
int end_journey;
int dfs(int src){
    int ans = 0;
    int next_node = -1;
    int value_added_next = -1;
    for(int i = 0; i < DAG[src].size(); i++){
        if(nodes_value[DAG[src][i]] > value_added_next ){
            next_node = DAG[src][i];
            value_added_next = nodes_value[next_node];
        }
    }
    if(next_node != -1 && value_added_next != -1){
        ans += value_added_next;
        ans += dfs(next_node);
    }else{
        //it's end of your journey
        end_journey = src;
    }
    return ans;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    cin >> t;
    int test = 1;
    while(t--){
        
        end_journey = 0;
        cin >> n >> m;
        
        for(int i = 0; i < n; i++)
            cin >> nodes_value[i],DAG[i].clear();
        
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            DAG[ u ].push_back( v ); 
        }
        
        int ans = dfs(0);
        cout << "Case " << test++ << ": " << ans << " " << end_journey << endl;
    }

    return 0;
}


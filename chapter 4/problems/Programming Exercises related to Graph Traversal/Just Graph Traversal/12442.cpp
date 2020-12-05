#include <bits/stdc++.h>
using namespace std;
int messageForwaded_from_this_one[50010];
bool vis[50010];
int graph_from_to[50010];

int dfs(int index){
    int ans = 0;
    vis[index] = true;
    
    if(graph_from_to[index] != -1 && vis[graph_from_to[index]] == false){
        ans = 1 + dfs(graph_from_to[index]);
    }
    messageForwaded_from_this_one[index] = max(messageForwaded_from_this_one[index], ans);
    vis[index] = false;
    return ans;
}

int main(){
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    int n;
    cin>>t;
    int test = 1;
    while(t--){
        cin>>n;
        memset(vis, false, sizeof vis);
        memset(messageForwaded_from_this_one, -1, sizeof messageForwaded_from_this_one);
        memset(graph_from_to, -1, sizeof graph_from_to);
        
        for(int i = 1; i <= n; i++){
            int from,to;
            cin>>from>>to;
            graph_from_to[from] = to;
        }
        int maxCount = 0;
        int index = -1;
        for(int i = 1; i <= n; i++){
            if(messageForwaded_from_this_one[i] == -1)dfs(i);
            if(messageForwaded_from_this_one[i] > maxCount ){
                maxCount = messageForwaded_from_this_one[i];
                index = i;
            }
        }
        cout << "Case " << test++ << ": " << index << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
string prev, next;
vector< vector<int> >adj_list(30);
vector< int > ans;
bool vis[30];
bool found_in_input[30];
void topoSort(int index){
    vis[index] = true;
    for(int i = 0 ; i < adj_list[index].size(); i++){
        int v = adj_list[index][i];
        if(vis[v])continue;
        topoSort(v);
    }
    ans.push_back(index);
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    string prev, next;
    cin >> prev;
    cin >> next;
    bool ok = 0;
    if(next != "#")ok = 1;
    do{
        if(next == "#")break;
        for(int i = 0; i < min(prev.size(), next.size()); i++){
            char u = prev[i], v = next[i];
            if(u == v)continue;
            adj_list[u - 'A'].push_back(v - 'A');
            found_in_input[u - 'A'] = true;
            found_in_input[v - 'A'] = true;
            break;
        }
        prev = next;
    }while(cin >> next);
  
    memset(vis, false, sizeof vis);
    if(!ok)cout << prev << endl;
    else{
        for(int i = 0; i <= 25; i++){
            if(found_in_input[i] && !vis[i]){
                topoSort(i);
            }
        }
        for(int i = ans.size() - 1; i >= 0; i--)cout << char(ans[i] + 'A');
        cout << endl;
    }
   
    return 0;
}

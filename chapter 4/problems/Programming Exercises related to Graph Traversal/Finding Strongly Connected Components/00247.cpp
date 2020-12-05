#include <bits/stdc++.h>
using namespace std;
map< string, int > mp;
map < int, string > mp2;
vector< vector<int> >adj_list;
vector<int> dfsNum, dfsLow, dfsStackSCC;
vector<bool> dfsFoundInStack;
int timeVisited;
void tarjanSCC(int u){
    dfsNum[u] = dfsLow[u] = timeVisited++;
    dfsStackSCC.push_back(u);
    dfsFoundInStack[u] = true;
    
    for(int i = 0; i < adj_list[u].size(); i++){
        int v = adj_list[u][i];
        if(dfsNum[v] == 0)
            tarjanSCC(v);
        if(dfsFoundInStack[v])
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
    }
    
    //if u == root
    if(dfsLow[u] == dfsNum[u]){
        int top1 = dfsStackSCC.back();
        dfsStackSCC.pop_back();
        dfsFoundInStack[top1] = false;
        cout << mp2[top1];    
        
        while(!dfsStackSCC.empty() && u != top1){
            int top = dfsStackSCC.back();
            dfsStackSCC.pop_back();
            dfsFoundInStack[top] = false;
            cout << ", " << mp2[top];
            if(u == top)break;
        }
        cout << endl;
    }
    
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    int n, m;
    bool first = true;
    int test = 1;
    while(cin >> n >> m){
        if( n == 0 && m == 0)break;
        if(!first)cout << endl;
        first = false;
        mp.clear();
        mp2.clear();
        adj_list.clear();
        adj_list.resize(n);
        dfsNum.clear();
        dfsNum.resize(n, 0);
        dfsLow.clear();
        dfsLow.resize(n, 0);
        dfsFoundInStack.clear();
        dfsFoundInStack.resize(n, 0);
        dfsStackSCC.clear();
        timeVisited = 1;
        int index = 0;
        while(m--){
            string u, v;
            int u_, v_;
            cin >> u >> v;
            if( mp.find(u) != mp.end() )u_ = mp[u];
            else u_ = mp[u] = index++, mp2[u_] = u;
            
            if( mp.find(v) != mp.end() )v_ = mp[v];
            else v_ = mp[v] = index++, mp2[v_] = v;
            
            adj_list[u_].push_back(v_);
        }
        cout << "Calling circles for data set " << test++ << ":" << endl;
        for(int i = 0; i < n; i++){
            if(dfsNum[i] == 0)
                tarjanSCC(i);
        }
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
map < string, int > mp;
vector< vector < int > > adj_list;
vector < int > dfsNum, dfsLow, dfsStackSCC;
vector < bool > dfsInStack;
int cntSCC;
int timeVisited;

void tarjanSCC(int u){
    dfsLow[ u ] = dfsNum[ u ] = timeVisited++;
    dfsInStack[u] = true;
    dfsStackSCC.push_back( u );
    
    for(int i = 0; i < adj_list[u].size(); i++){
        int v = adj_list[u][i];
        
        if(dfsNum[ v ] == 0)
            tarjanSCC(v);
        if(dfsInStack[ v ])//if v belong to current SCC 
            dfsLow[ u ] = min(dfsLow[ u ], dfsLow[ v ]);        
    }
    
    //if found a root
    if(dfsLow[ u ] == dfsNum[ u ]){
        cntSCC++;
        while( !dfsStackSCC.empty() ){
            int top = dfsStackSCC.back();
            dfsStackSCC.pop_back();
            dfsInStack[ top ] = false;
            if(top == u)break;
        }
    }
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int n, m;
    while(cin >> n >> m){
        if( n == 0 && m == 0){
            break;
        }
        cin.ignore();
        
        //clear previous dataset
        mp.clear();
        adj_list.clear();
        adj_list.resize(n);
        dfsInStack.clear();
        dfsInStack.resize(n, 0);
        dfsNum.clear();
        dfsNum.resize(n, 0);
        dfsStackSCC.clear();
        dfsLow.clear();
        dfsLow.resize(n, 0);
        cntSCC = 0;
        timeVisited = 1;
        
        for(int i = 0; i < n; i++){
            string s;
            getline(cin, s);
            mp[ s ] = i;
        }
        
        for(int i = 0; i < m; i++){
            string u, v;
            getline(cin, u);
            getline(cin, v);
            adj_list[ mp[ u ] ].push_back( mp[ v ] );
        }
        for(int i = 0; i < n; i++){
            if(dfsNum[i] == 0)
                tarjanSCC(i);
        }
        cout << cntSCC << endl;
    }
    return 0;
}


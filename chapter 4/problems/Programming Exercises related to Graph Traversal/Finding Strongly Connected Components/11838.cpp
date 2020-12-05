#include <bits/stdc++.h>
using namespace std;
vector < vector < int > > adj_list;
vector < int > dfsLow, dfsNum, dfsStackSCC;
vector < bool > dfsFoundInStack;
int cntSCC,timeVisited;

void tarjanSCC(int u){
    dfsLow[ u ] = dfsNum[ u ] = timeVisited++;
    dfsFoundInStack[ u ] = true;
    dfsStackSCC.push_back( u );
    
    for(int i = 0; i < adj_list[ u ].size(); i++){
        int v = adj_list[ u ][ i ];
        if(dfsNum[ v ] == 0)
            tarjanSCC(v);
        if(dfsFoundInStack[ v ])// belong to this SCC
            dfsLow[ u ] = min( dfsLow[ u ], dfsLow[ v ]);
    }
    
    //root
    if(dfsLow[ u ] == dfsNum[ u ]){
        cntSCC++;
        while( !dfsStackSCC.empty() ){
            int top = dfsStackSCC.back();
            dfsStackSCC.pop_back();
            dfsFoundInStack[ top ] = false;
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
       if( n == 0 && m == 0)break;
       adj_list.clear();
       dfsLow.clear();
       dfsNum.clear();
       dfsStackSCC.clear();
       dfsFoundInStack.clear();
       dfsFoundInStack.resize(n, 0);
       dfsNum.resize(n, 0);
       dfsLow.resize(n, 0);
       adj_list.resize(n);
       cntSCC = 0;
       timeVisited = 1;
       while( m-- ){
           int u, v, p;
           cin >> u >> v >> p;
           u--, v--;
           if( p == 1)adj_list[ u ].push_back( v );
           else if(p == 2)adj_list[ u ].push_back( v ),adj_list[ v ].push_back( u );
       }
       
       for(int i = 0; i < n; i++){
           if(dfsNum[ i ] == 0)
                tarjanSCC(i);
       }
       cout << (cntSCC == 1) << endl;
    }
    return 0;
}


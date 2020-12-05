#include <bits/stdc++.h>
using namespace std;
#define UNVISITED 0
#define NIL 0
vector < vector<int> > network;
vector < int > dfsNum, dfsLow, dfsParent;
vector < bool > criticalVertices;
int timeVisited = 1;
int dfsRoot;
int rootChildren;
void dfs(int src){
    
    dfsLow[src] = dfsNum[src] = timeVisited++;
    for(int i = 0; i < network[src].size(); i++){
        int v = network[src][i];
        if(dfsNum[v] ==  UNVISITED){
            dfsParent[v] = src;
            if(src == dfsRoot)rootChildren++;
            dfs(v);
            if(src != dfsRoot && dfsLow[v] >= dfsNum[src])
                criticalVertices[src] = true;
            dfsLow[src] = min(dfsLow[src], dfsLow[v]);
        }else if(v != dfsParent[src]){
            dfsLow[src] = min(dfsLow[src], dfsNum[v]);
        }
    }
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
   
    int n;
    while (cin >> n, n != 0)
    {
        cin.ignore();

        network.clear();
        network.resize(n + 1);
        dfsNum.clear();
        dfsNum.resize(n + 1, UNVISITED);
        dfsLow.clear();
        dfsLow.resize(n + 1, UNVISITED);
        dfsParent.clear();
        dfsParent.resize(n + 1, UNVISITED);
        criticalVertices.clear();
        criticalVertices.resize(n + 1, UNVISITED);
        timeVisited = 1;
        
        string s;
        while (getline(cin, s), s != "0")
        {
            stringstream ss(s);
            int u, v;
            ss >> u;
            while (ss >> v)
            {
                network[u].push_back(v);
                network[v].push_back(u);
            }
        }
        
        dfsRoot = 1;
        rootChildren = 0;
        timeVisited = 1;
        dfs(dfsRoot);
        if(rootChildren > 1)
            criticalVertices[1] = true;
        cout << count(criticalVertices.begin(), criticalVertices.end(), true) << endl;
    }
    return 0;
}


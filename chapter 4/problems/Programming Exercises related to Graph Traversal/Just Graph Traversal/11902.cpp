#include <bits/stdc++.h>
using namespace std;
bool adj_mat[105][105];//adjacent matrix to represent the graph
bool dominates[105][105];//if dominates[A][B] == true, this means that A dominates B
int t,n;

/* The idea of the problem is:
   1) for node = 0, if you can reach node i then dominates[0][i] is true , otherwise is false(this to test which nodes are dominated by node 0)
   2) now let's test for other nodes, say we want to test if A dominates B or not , it's so easy:
   test if you can find a path from 0 to B without using A => this is the condition dontVis != i in dfs function
   and test if you can find a path from 0 to B with A => we sent to dfs function dontVis = -1
   so by this 2 conditions we ensure that the paths are all passing by B

*/
bool dfs(int src ,int des, vector<bool> &vis, int dontVis){
    if(src == des)return true;
    vis[ src ] = true;
    bool ans = false;
    for(int i = 0; i < n ; i++ ){
        if(adj_mat[src][i] == true && vis[ i ] == false && dontVis != i && !ans )ans |= dfs(i, des, vis, dontVis);
    }
    return ans;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int test = 1;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> adj_mat[ i ][ j ];
            }
        }
        memset(dominates,0,sizeof dominates);
        for(int i = 0; i < n; i++){
            vector<bool>vis(n,0);
            if(dfs(0, i, vis, -1))dominates[0][i] = true;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < n; j++){
                std::vector<bool>vis1(n + 5,0),vis2(n + 5, 0);
                if(! dfs(0, j, vis1, i) && dfs(0, j , vis2 , -1) )dominates[i][j] = true;
                else dominates[i][j] = false;
            }
        }
   
   
   
      //printing the result
      cout<<"Case "<<test++<<":"<<endl;
      
      string s = "+";
      for(int i = 1;i < n ;i++)s = s + "--";
      s  = s + "-+";
      cout << s << endl;
      
      for(int i = 0; i < n; i ++){
          for(int j = 0;j < n; j++ ){
              if(dominates[i][j])cout<<"|Y";
              else cout<<"|N";
          }
          cout<<"|"<<endl;
          cout << s << endl;
      }
      
    }
    
    return 0;
}


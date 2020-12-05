#include <bits/stdc++.h>
using namespace std;
char mat[15][15];
bool vis[15][15];
int r, w, cstart;
//the idea is to dfs until you are out of grid or reach a node reached before, 
// then you have 2 cases : 1) out of grid -> ok
//                         2) loop : make another dfs but start this dfs from node inside loop and get count of nodes,
//                                  and subtract from original dfs count.
void dfs(int rs, int cs, int &node_in_loopi, int &node_in_loopj, int &cnt){
    
    //if we are out of the grid just return 
    if(rs <= 0 || cs <= 0 || rs > r || cs > w)return;
    //this a loop store any node in the loop to run another dfs
    if(vis[rs][cs] == true){
        node_in_loopi = rs;
        node_in_loopj = cs;
        return;
    }
    //this a node inside graph
    vis[rs][cs] = true;
    cnt++;
    if(mat[rs][cs] == 'N')//move upward
        dfs(rs - 1, cs, node_in_loopi, node_in_loopj, cnt);
    else if(mat[rs][cs] == 'S')//move downwards
        dfs(rs + 1, cs, node_in_loopi, node_in_loopj, cnt);
    else if(mat[rs][cs] == 'E')//move right
        dfs(rs, cs + 1, node_in_loopi, node_in_loopj, cnt);
    else dfs(rs, cs - 1, node_in_loopi, node_in_loopj, cnt);//left
    
}

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    while(cin >> r >> w >>cstart){
        if(r == 0 && w == 0 && cstart == 0)break;
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= w; j++) cin >> mat[i][j]; 
        }
        
        int cnt1 = 0;
        int node_in_loopi = -1,node_in_loopj = -1;
        memset(vis, false, sizeof vis);
        dfs(1, cstart, node_in_loopi, node_in_loopj, cnt1);
        if(node_in_loopi == -1)//there is no loop
        {
            cout<<cnt1<<" step(s) to exit"<<endl;
        }else{
            //there is a loop count this loop and subtract from original count
            memset(vis, false, sizeof vis);
            int cnt2 = 0;
            int dummy1,dummy2;
            dfs(node_in_loopi, node_in_loopj, dummy1, dummy2, cnt2);
            cout<<cnt1 - cnt2<<" step(s) before a loop of "<<cnt2<<" step(s)"<<endl;
        }
    }
    return 0;
}

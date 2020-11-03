#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool adj_mat[3005][3005];
int main()
{
    /*std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!*/
    int t;
    scanf("%d",&t);
    while(t--){
        memset(adj_mat,0,sizeof adj_mat);
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            adj_mat[x][y]=1;
            adj_mat[y][x]=1;
        }
        ll cnt=0;
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                if(adj_mat[i][j]==0)continue;
                for(int k=j+1;k<=n;k++){
                    if(adj_mat[k][i]==0)continue;
                    if(adj_mat[j][k]==0)continue;
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

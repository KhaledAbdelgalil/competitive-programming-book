#include <bits/stdc++.h>
using namespace std;
int running_rows[105];
int mat[105][105];
map< pair<int,int>,bool>mp_not_free;
#define neg_INF -1e6
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    while(t--){
        mp_not_free.clear();
        int n;
        cin>>n;
        int p;
        cin>>p;
        while(p--){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            for(int i=x1-1;i<=x2-1;i++)for(int j=y1-1;j<=y2-1;j++)
                mp_not_free[{i,j}]=1;
        }
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)
        if(mp_not_free.find({i,j})!=mp_not_free.end())mat[i][j]=neg_INF;
        else mat[i][j]=1;
        int ans=neg_INF;
        for(int i=0;i<n;i++){
            memset(running_rows,0,sizeof running_rows);
            for(int j=i;j<n;j++){
                
                for(int r=0;r<n;r++)running_rows[r]+=mat[r][j];
                
                int sum=0;
                for(int r=0;r<n;r++){
                    sum+=running_rows[r];
                    ans=max(sum,ans);
                    if(sum<0)sum=0;
                }
                
            }
        }
        cout<<max(ans,0)<<endl;
    }
    return 0;
}


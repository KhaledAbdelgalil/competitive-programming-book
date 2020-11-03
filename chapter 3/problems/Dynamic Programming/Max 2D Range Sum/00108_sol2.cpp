#include <bits/stdc++.h>
using namespace std;
int mat[105][105];
int running_rows[105];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n;
    while(cin>>n){
        //mat[i][j] contains sum from (0,0)->(i,j)
        for(int i=0;i<n;i++)for(int j=0;j<n;j++){
            cin>>mat[i][j];
            if(i>0)mat[i][j]+=mat[i-1][j];
            if(j>0)mat[i][j]+=mat[i][j-1];
            if(i>0&&j>0)mat[i][j]-=mat[i-1][j-1];
        }
        int ans=-127*100*100;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=i;k<n;k++){
                    for(int l=j;l<n;l++){
                        int sum=mat[k][l];
                        if(i>0)sum-=mat[i-1][l];
                        if(j>0)sum-=mat[k][j-1];
                        if(i>0&&j>0)sum+=mat[i-1][j-1];
                        ans=max(ans,sum);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


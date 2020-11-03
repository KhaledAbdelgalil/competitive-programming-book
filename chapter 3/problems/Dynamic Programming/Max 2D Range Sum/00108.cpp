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
        int ans=-127*100*100;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>mat[i][j];
        
        for(int i=0;i<n;i++){//scan cols starting from first col
            memset(running_rows,0,sizeof running_rows);
            for(int j=i;j<n;j++)//scan cols
            {
                for(int r=0;r<n;r++)running_rows[r]+=mat[r][j];
                
                int sum=0;
                for(int r=0;r<n;r++){
                    sum+=running_rows[r];
                    ans=max(sum,ans);
                    if(sum<0)sum=0;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int running_rows[30];
int mat[30][30];

#define neg_INF -1e6
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0')mat[0][i]=neg_INF;
            else mat[0][i]=1;
        }
        for(int i=1;i<n;i++){
            cin>>s;
            for(int j=0;j<n;j++){
            if(s[j]=='0')mat[i][j]=neg_INF;
            else mat[i][j]=1;
            }   
        }
        int ans=neg_INF;
        for(int i=0;i<n;i++){
            memset(running_rows,0,sizeof running_rows);
            for(int j=i;j<n;j++){
                
                for(int r=0;r<n;r++)running_rows[r]+=mat[r][j];
                int sum=0;
                for(int r=0;r<n;r++){
                    sum+=running_rows[r];
                    ans=max(ans,sum);
                    if(sum<0)sum=0;//start from zero it's better than diving in negative numbers
                }
                
            }
        }
        if(ans==neg_INF)cout<<0<<endl;
        else cout<<ans<<endl;
        if(t)cout<<endl;
    }
    
    return 0;
}


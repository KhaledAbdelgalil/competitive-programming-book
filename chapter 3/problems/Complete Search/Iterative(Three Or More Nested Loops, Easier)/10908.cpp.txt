#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    char mat[105][105];
    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)cin>>mat[i][j];
        
        cout<<n<<" "<<m<<" "<<q<<endl;
        while(q--){
            int r,c;
            cin>>r>>c;
            int ans=1;
            int side=3;
            char s=mat[r][c];
            while(1){
                
            
                bool flag_good=1;
                int amount_added=(side-1)/2;
                if(r-amount_added<0)break;
                if(r+amount_added>=n)break;
                if(c-amount_added<0)break;
                if(c+amount_added>=m)break;
                for(int i=r-amount_added;i<=r+amount_added;i++){
                    for(int j=c-amount_added;j<=c+amount_added;j++){
                        if(mat[i][j]!=s){
                            flag_good=0;
                            break;
                        }
                    }
                    if(flag_good==0)break;
                }
                if(flag_good)ans=side;//no more good answer we can obtain
                else break;
                side+=2;
            }
        cout<<ans<<endl;
        }
        
        
        //if(t)cout<<endl;
    }
    return 0;
}

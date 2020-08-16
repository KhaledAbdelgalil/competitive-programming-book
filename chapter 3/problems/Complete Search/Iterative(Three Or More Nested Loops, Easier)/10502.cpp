#include <bits/stdc++.h>
using namespace std;
char mat[105][105];
int main(){
   
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
  
    int m,n;
    while(cin>>n&&n){
        cin>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>mat[i][j];
                
        int ans=0;
        for(int topLeftx=0;topLeftx<n;topLeftx++){
            for(int topLefty=0;topLefty<m;topLefty++){
                if(mat[topLeftx][topLefty]=='0')continue;
                for(int downrightx=topLeftx;downrightx<n;downrightx++)
                    for(int downrighty=topLefty;downrighty<m;downrighty++){
                        if(mat[downrightx][downrighty]=='0')continue;
                        
                        bool flag=1;
                        for(int i=topLeftx;i<=downrightx;i++){
                            for(int j=topLefty;j<=downrighty;j++){
                                if(mat[i][j]=='0'){
                                    flag=0;
                                    break;
                                }
                            } 
                            if(flag==0)break;
                        }
                        if(flag)ans++;
                    }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

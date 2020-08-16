#include <bits/stdc++.h>
using namespace std;

int mat[105][105];
int main(){
   
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>mat[i][j];
                
        std::vector<pair<int, pair<int,int> > >ans;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(i==j)continue;
                    else if(i==k)continue;
                    else if(j==k)continue;
                    if(mat[j][k]&&mat[i][j]&&mat[k][i]&&i<j&&j<k)ans.push_back({i,{j,k}});
                    else if(mat[i][j]&&mat[j][k]&&mat[k][i]&&i>j&&j>k)ans.push_back({i,{j,k}});
                }
            }
        }
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
        }
        cout<<"total:"<<ans.size()<<endl<<endl;
    }
   
    return 0;
}


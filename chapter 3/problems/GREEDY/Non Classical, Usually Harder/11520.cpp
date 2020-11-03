#include <bits/stdc++.h>
using namespace std;
char grid[15][15];
int test=1;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)cin>>grid[i][j];
            
            
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='.'){
                    
                    for(char x='A';x<='Z';x++){
                        if(i-1>=0){
                            if(grid[i-1][j]==x)continue;
                        }
                        if(i+1<n){
                            if(grid[i+1][j]==x)continue;
                        }
                        if(j-1>=0){
                            if(grid[i][j-1]==x)continue;
                        }
                        
                        if(j+1<n){
                            if(grid[i][j+1]==x)continue;
                        }
                        //you can put x now
                        grid[i][j]=x;
                        break;
                    }
                }
            }
        }
        cout<<"Case "<<test++<<":"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cout<<grid[i][j];
            cout<<endl;
        }
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    int n;
    while(cin>>n&&n){
    vector< vector<char> >original_board(n,vector<char>(n)) ;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>original_board[i][j];
    map<int,pair<int,int> >mp;
    int index=0;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)mp[index++]={i,j};
    
    int maxx=0;
    for(int i=0;i<(1<<n*n);i++){
        int curr=0;
        bool flag=1;
        vector < vector<char> > new_board=original_board;
        for(int j=0;j<n*n;j++){
            if(i&(1<<j)){
                int r=mp[j].first;
                int c=mp[j].second;
                if(new_board[r][c]=='.'){
                     bool col_row_flag=1;
                    //check col
                    for(int k=r+1;k<n;k++){
                        if(new_board[k][c]=='X')break;
                        else if(new_board[k][c]=='O'){col_row_flag=0;break;}
                    }
                    for(int k=r-1;k>=0;k--){
                        if(new_board[k][c]=='X')break;
                        else if(new_board[k][c]=='O'){col_row_flag=0;break;}
                    }
                    
                    if(col_row_flag==0){flag=0;break;}
                    //check row
                    for(int k=c+1;k<n;k++){
                        if(new_board[r][k]=='X')break;
                        else if(new_board[r][k]=='O'){col_row_flag=0;break;}
                    }
                    for(int k=c-1;k>=0;k--){
                        if(new_board[r][k]=='X')break;
                        else if(new_board[r][k]=='O'){col_row_flag=0;break;}
                    }
                    if(col_row_flag==0){flag=0;break;}
                    new_board[r][c]='O';
                    curr++;
                }
                else {flag=0;break;}
                
            }
        }
        if(flag)maxx=max(curr,maxx);
    }
    cout<<maxx<<endl;
    }
    return 0;
}


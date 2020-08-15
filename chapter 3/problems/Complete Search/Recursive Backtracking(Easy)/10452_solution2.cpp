#include <bits/stdc++.h>
using namespace std;
int t;
int n,m;
char mat[10][10];
string moves[3]={"forth","left","right"};
string needed_path="IEHOVA#";
int movesc[3]={0,-1,1};
int movesr[3]={-1,0,0};
string output[7];

void sol(int pos,int i,int j){
    if(mat[i][j]=='#'){
        cout<<output[0];
        for(int s=1;s<7;s++)cout<<" "<<output[s];
        cout<<endl;
        return;
    }
    for(int mv=0;mv<3;mv++){
        int nexti=movesr[mv]+i;
        int nextj=movesc[mv]+j;
        if(nexti>=0&&nexti<n&&nextj>=0&&nextj<m&&mat[nexti][nextj]==needed_path[pos]){
            output[pos]=moves[mv];
            sol(pos+1,nexti,nextj);
            return;
        }
    }
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    cin>>t;
    while(t--){
        
        cin>>n>>m;
        
        int str,stc;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
                if(mat[i][j]=='@')str=i,stc=j;
            }        
        }
       sol(0,str,stc);
    }
    return 0;
}


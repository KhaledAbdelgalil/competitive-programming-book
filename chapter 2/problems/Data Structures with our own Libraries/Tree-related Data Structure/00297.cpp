
#include <bits/stdc++.h>

using namespace std;
int cnt=0;
bool mat[32][32];
char q;
void build(int x,int y,int w){
    cin>>q;
    if(q=='p'){
        //build 4 children
        build(x,y,w/2);
        build(x+w/2,y,w/2);
        build(x,y+w/2,w/2);
        build(x+w/2,y+w/2,w/2);
    }
    else if(q=='f'){
        //check for range it's black
        for(int i=x;i<x+w;i++){
            for(int j=y;j<y+w;j++){
                if(mat[i][j]==0){
                    mat[i][j]=1,cnt++;
                }
            }
        }
    }
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n;
    cin>>n;
    while(n--){
        cnt=0;
        memset(mat,0,sizeof(mat));
        build(0,0,32);
        build(0,0,32);
        cout<<"There are "<<cnt<<" black pixels."<<endl;
    }
    return 0;
}


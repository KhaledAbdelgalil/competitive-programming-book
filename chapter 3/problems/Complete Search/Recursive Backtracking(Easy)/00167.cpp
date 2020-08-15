#include <bits/stdc++.h>
using namespace std;
int mat[8][8];
int ans=0;
int d1[16];
int d2[16];
int c[8];
void solution(int index,int sum){
    if(index==8)ans=max(ans,sum);
    else{
        for(int i=0;i<8;i++){
            int dd1=index-i;
            if(dd1<0)dd1=i-index+8;
            int dd2=index+i;
            if(d1[dd1]==0&&dd2[d2]==0&&c[i]==0){
                d1[dd1]=d2[dd2]=c[i]=1;
                solution(index+1,mat[index][i]+sum);
                d1[dd1]=d2[dd2]=c[i]=0;
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
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                cin>>mat[i][j];
        memset(c,0,sizeof c);
        memset(d1,0,sizeof d1);
        memset(d2,0,sizeof d2);
        solution(0,0);
       cout<<setw(5)<<setiosflags(ios::right)<<ans<<endl;
        ans=0;
    }
    return 0;
}


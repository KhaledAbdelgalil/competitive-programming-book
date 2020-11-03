#include <bits/stdc++.h>
using namespace std;
#define mod 1000000
int mem[105][105];


int main(){
    
     
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!

    memset(mem,0,sizeof mem);
    //base case
    for(int i=0;i<105;i++)mem[i][1]=1;//if you have n=i and k=1 there is just one way to make i to take number = i
    
    for(int k=2;k<105;k++)//starting building other dps
    {
        for(int j=0;j<105;j++){
            for(int x=0;x<105-j;x++){
                mem[j+x][k]=(mem[j+x][k]+mem[j][k-1]%mod)%mod;
            }
        }
    }
    
    
    int n,k;
    while(cin>>n>>k){
        if(n==0&&k==0)break;
        cout<<mem[n][k]<<endl;
    }
    return 0;
}


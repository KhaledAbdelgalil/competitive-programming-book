
#include <bits/stdc++.h>

using namespace std;
int n;
int total;
int pegs[55];
void solve(int peg_no,int ball_no){
    if(peg_no==n)return;
    if(pegs[peg_no]==0){
        pegs[peg_no]=ball_no;
        total++;
        return solve(peg_no,ball_no+1);
    }
    for(int i=0;i<=peg_no;i++){
        int root=sqrt(pegs[i]+ball_no);
        if(root*root==pegs[i]+ball_no){
            pegs[i]=ball_no;
            total++;
            return solve(peg_no,ball_no+1);
        }
    }
    //cannot add more start another empty peg
    return solve(peg_no+1,ball_no);
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int t;
    cin>>t;
    while(t--){
       cin>>n;
       total=0;
       memset(pegs,0,sizeof pegs);
       solve(0,1);
       cout<<total<<endl;
    }
    return 0;
}


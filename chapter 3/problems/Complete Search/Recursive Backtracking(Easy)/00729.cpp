#include <bits/stdc++.h>
using namespace std;
int t;
int n,m;

void sol(int pos,int ones,string s=""){
   if(pos==n){
       if(ones==m)
       cout<<s<<endl;
       return;
   }
   
       if(ones<m){
           
           sol(pos+1,ones,s+'0');
           sol(pos+1,ones+1,s+'1');
           
       }else{
           sol(pos+1,ones,s+'0');
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
        
        sol(0,0);
        if(t)cout<<endl;
    }
    return 0;
}


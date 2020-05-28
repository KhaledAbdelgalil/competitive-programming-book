#include <bits/stdc++.h>
#include <string>

using namespace std;


int main(){
    
    
  std::ifstream in ("input");
  std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
  std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  int n;
  int t=0;
  while(cin>>n)
  {
     
     if(n%6==0)cout<<"Y"<<endl;
     else cout<<"N"<<endl;
      
  }
  return 0;
}


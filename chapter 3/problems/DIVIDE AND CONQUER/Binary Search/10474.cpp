#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n,q;
    int tests=1;
    while(cin>>n>>q){
      if(n==0&&q==0)break;
      vector<int>v(n);
      for(int i=0;i<n;i++)cin>>v[i];
      sort(v.begin(),v.end());
      vector<int>::iterator it;
      cout<<"CASE# "<<tests++<<":"<<endl;
      for(int i=0;i<q;i++){
          int val;
          cin>>val;
          it=lower_bound(v.begin(),v.end(),val);
          if(it==v.end()||*(it)!=val){
              cout<<val<<" not found"<<endl;
          }
          else cout<<val<<" found at "<<it-v.begin()+1<<endl;
      }
    }
    return 0;
}


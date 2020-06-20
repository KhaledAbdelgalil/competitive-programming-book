#include<bits/stdc++.h>
using namespace std;

class DSU{
  
  private:
  std::vector<int>rank,p,SetMoney;
  public:
  DSU(int n,vector<int>moneys){
    rank.assign(n,0);
    p.assign(n,0);
    SetMoney.assign(n,0);
    for(int i=0;i<n;i++)p[i]=i,SetMoney[i]=moneys[i];
  }
  bool IsSameSet(int i,int j){
      return findSet(i)==findSet(j);
  }
  
  int findSet(int i){
      return (i==p[i])?i:p[i]=findSet(p[i]);
  }
  
  void unionSet(int i,int j)
  {
      int x=findSet(i);
      int y=findSet(j);
      if(rank[x]>rank[y]){
          p[y]=x;
          if(x!=y)SetMoney[x]+=SetMoney[y];
      }else{
          p[x]=y;
          if(x!=y)SetMoney[y]+=SetMoney[x];
          if(rank[x]==rank[y])rank[y]++;
      }
  }
  int money_in_set(int i){
      int x=findSet(i);
      return SetMoney[x];
  }
    
};
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());
    
   int t;
   cin>>t;
   while(t--){
       int n,m;
       cin>>n>>m;
       vector<int>moneys(n);
       for(int i=0;i<n;i++)cin>>moneys[i];
       DSU friends(n,moneys);
       for(int i=0;i<m;i++)
       {
           int x,y;
           cin>>x>>y;
           friends.unionSet(x,y);
       }
       bool flag=1;
       for(int i=0;i<n;i++)if(friends.money_in_set(i)){
           flag=0;
           break;
       }
       if(flag)cout<<"POSSIBLE"<<endl;
       else cout<<"IMPOSSIBLE"<<endl;
   }
    
    
    return 0;
}

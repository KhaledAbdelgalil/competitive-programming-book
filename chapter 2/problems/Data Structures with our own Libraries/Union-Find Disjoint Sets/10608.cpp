#include<bits/stdc++.h>
using namespace std;

class DSU{
    
private:
    int sets,max_elements_in_allSets;
    std::vector<int>p,rank,sets_size;
public:
    DSU(int n){
        sets=n;
        max_elements_in_allSets=1;
        p.assign(n+1,0),rank.assign(n+1,0);
        sets_size.assign(n+1,1);
        for(int i=0;i<n+1;i++)p[i]=i;
    }
    
    int findSet(int i){
        return (i==p[i])?i:(p[i]=findSet(p[i]));
    }
    
    int isSameSet(int i,int j){
        return findSet(i)==findSet(j);
    }
    
    void unionSet(int i,int j){
        int x=findSet(i);
        int y=findSet(j);
        if(rank[x]>rank[y]){
            if(x!=y)sets_size[x]+=sets_size[y],sets--,max_elements_in_allSets=max(max_elements_in_allSets,sets_size[x]);
            p[y]=x;
        }
        else{
            
            if(x!=y)sets_size[y]+=sets_size[x],sets--,max_elements_in_allSets=max(max_elements_in_allSets,sets_size[y]);
            p[x]=y;
            if(rank[x]==rank[y])rank[y]++;
        }
    }
    
    int Size(){
        return sets;//I don't want the zero
    }
    int Size_in_set(int parent)
    {
        return sets_size[parent];
    }
    int max_elements()
    {
        return max_elements_in_allSets;
    }
};
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
   int t;
   cin>>t;
   while(t--)
   {
      int n,m;
      cin>>n>>m;
      DSU friends_groups(n);
      while(m--)
      {
          int x,y;
          cin>>x>>y;
          friends_groups.unionSet(x,y);
      }
      cout<<friends_groups.max_elements()<<endl;
   }
    
    return 0;
}

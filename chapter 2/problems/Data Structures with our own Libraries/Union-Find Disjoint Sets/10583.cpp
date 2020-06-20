#include<bits/stdc++.h>
using namespace std;

class DSU{
    
private:
    int sets;
    std::vector<int>p,rank;
public:
    DSU(int n){
        sets=n;
        p.assign(n+1,0),rank.assign(n+1,0);
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
            p[y]=x;
           if(x!=y) sets--;
        }
        else{
            p[x]=y;
            if(x!=y)sets--;
            if(rank[x]==rank[y])rank[y]++;
        }
    }
    
    int Size(){
        return sets;//I don't want the zero
    }
    
};
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
    int n,m;
    int test=1;
    while(cin>>n>>m)
    {
       if(n==0&&m==0)break;
       DSU religions(n);
       while(m--)
       {
           int i,j;
           cin>>i>>j;
           religions.unionSet(i,j);
       }
       cout<<"Case "<<test++<<": "<<religions.Size()<<endl;
    }
    
    return 0;
}

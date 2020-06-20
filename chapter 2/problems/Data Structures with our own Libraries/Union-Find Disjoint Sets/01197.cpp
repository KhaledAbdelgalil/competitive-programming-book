#include <bits/stdc++.h>
using namespace std;

class DSU{
private:vector<int>p,rank,setSize;
public:
    DSU (int n){
        rank.assign(n,0);
        p.assign(n,0);
        for(int i=0;i<n;i++)p[i]=i;
        setSize.assign(n,1);
    }
    
    int findSet(int i){
        return (p[i]==i)?i:(p[i]=findSet(p[i]));
    }
    
    bool isSameSet(int i,int j)
    {
        return findSet(i)==findSet(j);
    }
    
    void unionSet(int i,int j)
    {
        if(!isSameSet(i,j))
        {
            int x=findSet(i);
            int y=findSet(j);
            if(rank[x]>rank[y])p[y]=x,setSize[x]+=setSize[y];
            else
            {
                p[x]=y;
                setSize[y]+=setSize[x];
                if(rank[x]==rank[y])rank[y]++;
            }
        }
    }
    int sizeOfSet(int i){
        return setSize[findSet(i)];
    }

};
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n,m;
    while(cin>>n>>m&&!(n==0&&m==0) )
    {
        DSU groups(n);
        for(int i=0;i<m;i++)
        {
            int k;
            cin>>k;
            vector<int>v(k);
            for(int i=0;i<k;i++)cin>>v[i];
            
            for(int i=0;i<k-1;i++)
            {
                groups.unionSet(v[i],v[i+1]);
            }
        }
        cout<<groups.sizeOfSet(0)<<endl;
    }
    
    return 0;
}


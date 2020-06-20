#include<bits/stdc++.h>
using namespace std;
class DSU{
 private: 
    std::vector<int>rank,p,setSize;
 public:
    DSU(int n){
        rank.assign(n,0);
        p.assign(n,0);
        setSize.assign(n,1);
        for(int i=0;i<n;i++)p[i]=i;
    }
    
    int isSameSet(int i,int j){
        return findSet(i)==findSet(j);
    }
    
    int findSet(int i){
        return (p[i]==i)?i:p[i]=findSet(p[i]);
    }
    void unionSet(int i,int j){
        int x=findSet(i);
        int y=findSet(j);
        if(rank[x]>rank[y]){
            p[y]=x;
            if(x!=y)setSize[x]+=setSize[y];
        }
        else{
            p[x]=y;
            if(x!=y)setSize[y]+=setSize[x];
        }
    }
    
    int size_of_set(int i){
        return setSize[findSet(i)];
    }
};
int main(){
    
   /* std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!*/
    int t;
     cin>>t;
    while(t--){
        int f;
        cin>>f; 
        DSU friends(2*f+1000);
        int idx=0;
        map<string,int>mp_friends;
        while(f--){
            string s,ss;
            cin>>s>>ss;
            if(mp_friends.find(s)==mp_friends.end())mp_friends[s]=idx++;
            if(mp_friends.find(ss)==mp_friends.end())mp_friends[ss]=idx++;
            friends.unionSet(mp_friends[s],mp_friends[ss]);
            cout<<friends.size_of_set(mp_friends[s])<<endl;
        }
        
    }
    
    
    
    return 0;
}

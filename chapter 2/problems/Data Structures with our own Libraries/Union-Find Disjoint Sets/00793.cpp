#include <bits/stdc++.h>
using namespace std;

class DSU{
private:vector<int>p,rank;
public:
    DSU (int n){
        rank.assign(n,0);
        p.assign(n,0);
        for(int i=0;i<n;i++)p[i]=i;
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
            if(rank[x]>rank[y])p[y]=x;
            else
            {
                p[x]=y;
                if(rank[x]==rank[y])rank[y]++;
            }
        }
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
        int n;
        cin>>n;
        DSU network(n);
        cin.ignore();
        string s;
        int cnt_correct=0,cnt_wrong=0;
        while(getline(cin,s)&&s.size())
        {
            char q;
            int i,j;
            stringstream ss(s);
            ss>>q>>i>>j;
            if(q=='c'){
                
                network.unionSet(i-1,j-1);
            }
            else{
                if(network.isSameSet(i-1,j-1))cnt_correct++;
                else cnt_wrong++;
            }
            
        }
        cout<<cnt_correct<<","<<cnt_wrong<<endl;
        if(t)cout<<endl;
    }
    
    return 0;
}


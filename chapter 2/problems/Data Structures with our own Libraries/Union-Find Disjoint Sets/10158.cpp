
#include <bits/stdc++.h>

using namespace std;
#define MaxN 20010
int N;
class DSU{
private:vector<int>p,rank;
public:
    DSU (int n){
        rank.assign(MaxN,0);
        p.assign(MaxN,0);
        for(int i=0;i<MaxN;i++)p[i]=i;
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


int ID_OF_ENEMY(int i){
    return i+N;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    while(cin>>N)
    {
    
        int op,x,y;
        DSU friends(N);
        while(cin>>op>>x>>y){
            
            if(op==0&&x==0&&y==0)break;
            
            if(op==1){
                if( friends.findSet(x) == friends.findSet( ID_OF_ENEMY(y) ) )//if there are enemies they cannot be friends
                cout<<-1<<endl;
                else if(friends.findSet(y)==friends.findSet(ID_OF_ENEMY(x)))
                cout<<-1<<endl;
                else{
                    friends.unionSet(x,y);
                    friends.unionSet(ID_OF_ENEMY(x),ID_OF_ENEMY(y));
                }
            }
            else if(op==2){
                if(friends.findSet(x)==friends.findSet(y))//if friends ->cannot be enemies
                cout<<-1<<endl;
                else if(friends.findSet(ID_OF_ENEMY(x))==friends.findSet(ID_OF_ENEMY(y)))//if their enemies are friends so they are friends->cannot be friends
                cout<<-1<<endl;
                else{
                    friends.unionSet(x,ID_OF_ENEMY(y));
                    friends.unionSet(y,ID_OF_ENEMY(x));
                }
            }
            else if(op==3){
                if(friends.findSet(x)==friends.findSet(y))cout<<1<<endl;
                else if(friends.findSet(ID_OF_ENEMY(x))==friends.findSet(ID_OF_ENEMY(y)))cout<<1<<endl;
                else cout<<0<<endl;
            }
            else{
                if(friends.findSet(x)==friends.findSet(ID_OF_ENEMY(y)))cout<<1<<endl;
                else if(friends.findSet(y)==friends.findSet(ID_OF_ENEMY(x)))cout<<1<<endl;
                else cout<<0<<endl;
            }
        }
   }
    return 0;
}


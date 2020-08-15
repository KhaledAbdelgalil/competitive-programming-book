#include <bits/stdc++.h>
using namespace std;
//2D segment problem
class SegmentTree{
    private:
        int n;
        std::vector<int>treeNodesmax,treeNodesmin,values;
        int left(int p){
            return 2*p;
        }
        int right(int p){
            return 2*p+1;
        }
        
        void build(int p,int L,int R){
            if(L==R){
                treeNodesmax[p]=values[L];
                treeNodesmin[p]=values[L];
                return;
            }
            
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2+1,R);
            treeNodesmax[p]=max(treeNodesmax[left(p)],treeNodesmax[right(p)]);
            treeNodesmin[p]=min(treeNodesmin[left(p)],treeNodesmin[right(p)]);
        }
        int getValuemax(int p,int L,int R,int i,int j){
            if(L>j)return 0;
            if(R<i)return 0;
            if(R<=j&&L>=i)return treeNodesmax[p];
            int r1=getValuemax(left(p),L,(L+R)/2,i,j);
            int r2=getValuemax(right(p),(L+R)/2+1,R,i,j);
            return max(r1,r2);
            
        }
        
        int getValuemin(int p,int L,int R,int i,int j){
            if(L>j)return 1e9;
            if(R<i)return 1e9;
            if(R<=j&&L>=i)return treeNodesmin[p];
            int r1=getValuemin(left(p),L,(L+R)/2,i,j);
            int r2=getValuemin(right(p),(L+R)/2+1,R,i,j);
            return min(r1,r2);
            
        }
        void update(int p,int L,int R,int i,int v){
            if(L==R){
                treeNodesmax[p]=treeNodesmin[p]=v;
                return;
            }
            if(i<=(L+R)/2){
                update(left(p),L,(L+R)/2,i,v);
            }else{
                update(right(p),(L+R)/2+1,R,i,v);
            }
            treeNodesmax[p]=max(treeNodesmax[left(p)],treeNodesmax[right(p)]);
            treeNodesmin[p]=min(treeNodesmin[left(p)],treeNodesmin[right(p)]);
        }
    public:
        SegmentTree(){};
        void init(const vector<int>&values_){
            n=values_.size(),values=values_;
            treeNodesmax.assign(n*4,0);
            treeNodesmin.assign(n*4,0);
            build(1,0,n-1);
        }
        void update(int i,int v){
            update(1,0,n-1,i,v);
        }
        int getValue(int i,int j,string which){
        if(which=="max")
        return  getValuemax(1,0,n-1,i,j);
        else return getValuemin(1,0,n-1,i,j);
        }
       
};
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n,q;
    while(cin>>n){
        
        vector<int>v(n);
        SegmentTree trees[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin>>v[j];
            trees[i].init(v);
        }
        cin>>q;
        while(q--){
            char qe;
            cin>>qe;
            if(qe=='q'){
                int x1,y1,x2,y2;
                int mx=0,mn=1e9;
                cin>>x1>>y1>>x2>>y2;
                for(int i=x1-1;i<=x2-1;i++){
                    mx=max(mx,trees[i].getValue(y1-1,y2-1,"max"));
                    mn=min(mn,trees[i].getValue(y1-1,y2-1,"min"));
                }
                cout<<mx<<" "<<mn<<endl;
            }
            else{
                int x,y,v;
                cin>>x>>y>>v;
                trees[x-1].update(y-1,v);
            }
        }
    }
    return 0;
}


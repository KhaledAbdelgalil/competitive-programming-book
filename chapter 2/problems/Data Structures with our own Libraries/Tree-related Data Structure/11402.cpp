#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    private:
        int n;
        vector<int>treeNodes,lazy;
        vector<bool>found_bucc;
        int left(int p){
            return 2*p;
        }
        int right(int p){
            return 2*p+1;
        }
        void build(int p,int L,int R){
            if(L==R){
                if(found_bucc[L])
                    treeNodes[p]=1;
                return;
            }
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2+1,R);
            treeNodes[p]=treeNodes[left(p)]+treeNodes[right(p)];
        }   
        void check(int p,int L,int R){
            if(lazy[p]){
                if(lazy[p]==1){
                    treeNodes[p]=R-L+1;
                    if(L!=R)lazy[left(p)]=lazy[right(p)]=1;
                }
                else if(lazy[p]==2){
                    treeNodes[p]=0;
                    if(L!=R)lazy[left(p)]=lazy[right(p)]=2;
                }
                else if(lazy[p]==3) {
                    treeNodes[p]=R-L+1-treeNodes[p];
                    if(L!=R){
                        if(lazy[left(p)]==1)lazy[left(p)]=2;
                        else if(lazy[left(p)]==2)lazy[left(p)]=1;
                        else if(lazy[left(p)]==3)lazy[left(p)]=0;
                        else lazy[left(p)]=3;
                        
                        if(lazy[right(p)]==1)lazy[right(p)]=2;
                        else if(lazy[right(p)]==2)lazy[right(p)]=1;
                        else if(lazy[right(p)]==3)lazy[right(p)]=0;
                        else lazy[right(p)]=3;
                    }
                }
                lazy[p]=0;
            }
        }
        void update(int p,int L,int R,int i,int j,int v){
            check(p,L,R);
            if(R<i)return;
            if(L>j)return;
            if(R<=j&&L>=i){
                if(v==1){
                    treeNodes[p]=R-L+1;
                    if(L!=R)lazy[left(p)]=lazy[right(p)]=1;
                }
                else if(v==2){
                    treeNodes[p]=0;
                    if(L!=R)lazy[left(p)]=lazy[right(p)]=2;
                }
                else {
                    treeNodes[p]=R-L+1-treeNodes[p];
                    if(L!=R){
                        
                        if(lazy[left(p)]==1)lazy[left(p)]=2;
                        else if(lazy[left(p)]==2)lazy[left(p)]=1;
                        else if(lazy[left(p)]==3)lazy[left(p)]=0;
                        else lazy[left(p)]=3;
                        
                        if(lazy[right(p)]==1)lazy[right(p)]=2;
                        else if(lazy[right(p)]==2)lazy[right(p)]=1;
                        else if(lazy[right(p)]==3)lazy[right(p)]=0;
                        else lazy[right(p)]=3;
                    }
                }
                return;
            }
            update(left(p),L,(L+R)/2,i,j,v);
            update(right(p),(L+R)/2+1,R,i,j,v);
            treeNodes[p]=treeNodes[left(p)]+treeNodes[right(p)];
        }
        int getValue(int p,int L,int R,int i,int j){
            check(p,L,R);
            if(L>j)return 0;
            if(R<i)return 0;
            if(L>=i&&R<=j)return treeNodes[p];
            int r1=getValue(left(p),L,(L+R)/2,i,j);
            int r2=getValue(right(p),(L+R)/2+1,R,i,j);
            return r1+r2;
        }
        public:
        SegmentTree(const vector<bool>&v){
            found_bucc=v;
            n=v.size();
            treeNodes.assign(4*n,0);
            lazy.assign(4*n,0);
            build(1,0,n-1);
        }
       void update(int i,int j,int v){
           update(1,0,n-1,i,j,v);
       }
       int getValue(int i,int j){
           return getValue(1,0,n-1,i,j);
       }
};
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<":"<<endl;
        int m;
        cin>>m;
        string s="";
        while(m--){
            int f;string ss;
            cin>>f>>ss;
            while(f--)s+=ss;
        }
        vector<bool>v(s.size(),0);
        for(int l=0;l<s.size();l++)if(s[l]=='1')v[l]=1;
        SegmentTree tree(v);
        int q;
        cin>>q;
        int Q=1;
        while(q--){
            char question;
            int x1,x2;
            cin>>question>>x1>>x2;
            if(question=='F'){
                tree.update(x1,x2,1);
            }
            else if(question=='E'){
                tree.update(x1,x2,2);
            }
            else if(question=='I'){
                tree.update(x1,x2,3);
            }
            else{
                cout<<"Q"<<Q++<<": "<<tree.getValue(x1,x2)<<endl;
            }
        }
    }
    return 0;
}


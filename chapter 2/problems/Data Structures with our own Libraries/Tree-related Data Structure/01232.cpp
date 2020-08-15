#include <bits/stdc++.h>

using namespace std;


class segmentTree{
    private:
    int n;
    std::vector<int>treeNodeMaxH,treeNodeMinH;
    vector<int>lazy;
    int left(int p){return 2*p;}
    int right(int p){return 2*p+1;}
    void check(int p,int L,int R){
        if(lazy[p]){
            treeNodeMinH[p]=lazy[p];
            treeNodeMaxH[p]=lazy[p];
            if(L!=R){
                lazy[left(p)]=lazy[p];
                lazy[right(p)]=lazy[p];
            }
            lazy[p]=0;
        }
    }
    int update(int p,int L,int R,int i,int j,int h)//bring overlap and update range
    {
        check(p,L,R);
      
        if(j<L)return 0;
        if(i>R)return 0;
        if(L>=i&&R<=j){
            if(h>=treeNodeMaxH[p])//all points in interval are of same height
            {
            
                    treeNodeMinH[p]=h;
                    treeNodeMaxH[p]=h;
                    lazy[p]=h;
                
                   return R-L+1;
               
              
            }
            else if(h>=treeNodeMinH[p]){//bigger than min height so go deeper you have interval that will be smaller than you so take that answer
                int r1=update(left(p),L,(L+R)/2,i,j,h);
                 int r2=update(right(p),(L+R)/2+1,R,i,j,h);
        
                treeNodeMinH[p]=min(treeNodeMinH[left(p)],treeNodeMinH[right(p)]);
                treeNodeMaxH[p]=max(treeNodeMaxH[left(p)],treeNodeMaxH[right(p)]);
                 return r1+r2;
            }
            return 0;//not bigger than min height or max height so return 0
        }
        int r1=update(left(p),L,(L+R)/2,i,j,h);
        int r2=update(right(p),(L+R)/2+1,R,i,j,h);
        
        treeNodeMinH[p]=min(treeNodeMinH[left(p)],treeNodeMinH[right(p)]);
        treeNodeMaxH[p]=max(treeNodeMaxH[left(p)],treeNodeMaxH[right(p)]);
        return r1+r2;
    }
    public:
    segmentTree(int n_){
        n=n_;
        treeNodeMinH.assign(4*n,0);
        treeNodeMaxH.assign(4*n,0);
        lazy.assign(4*n,0);
    }
    int update(int i,int j,int h){
        return update(1,0,n-1,i,j,h);
    }
};
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        segmentTree tree(100001);
        int res=0;
        while(n--){
            int i,j,h;
            cin>>i>>j>>h;
            res+=tree.update(i,j-1,h);
            
        }
        cout<<res<<endl;
        //cin>>n;
    }

    return 0;
}


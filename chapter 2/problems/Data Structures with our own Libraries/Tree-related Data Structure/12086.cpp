#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    private:
    vector<int>values,treeNodes;
    int n;
    int left(int p){return p*2;}
    int right(int p){return 2*p+1;}
    void build(int p,int L,int R){
        if(L==R){
            treeNodes[p]=values[L];
        } 
        else{
        build(left(p),L,(L+R)/2);
        build(right(p),(L+R)/2+1,R);
        int p1_v=treeNodes[left(p)];
        int p2_v=treeNodes[right(p)];
        treeNodes[p]=p1_v+p2_v;
        }
    }
    int get_value(int p,int L,int R,int i,int j){
        int pp=p,LL=L,RR=R,ii=i,jj=j;
        if(i>R || j < L)return 0;
        if(L>=i&&R<=j)return treeNodes[p];//value in interval L-R
        int p1_v=get_value(left(p),L,(L+R)/2,i,j);
        int p2_v=get_value(right(p),(L+R)/2+1,R,i,j);
        return p1_v+p2_v;
    }
    void update(int p,int L,int R,int i,int v){
        if(L==R){
            treeNodes[p]=v;
            return;
        }
        if(i<=(L+R)/2){
            int old_value=treeNodes[left(p)];
            update(left(p),L,(L+R)/2,i,v);
            treeNodes[p]=treeNodes[p]-old_value+treeNodes[left(p)];//treeNodes[left(p)] is the updated value
        }
        else{
            int old_value=treeNodes[right(p)];
            update(right(p),(L+R)/2+1,R,i,v);
            treeNodes[p]=treeNodes[p]-old_value+treeNodes[right(p)];//treeNodes[left(p)] is the updated value
        }
    }
    public:
    SegmentTree(const vector<int>&A){
        values=A,n=A.size();
        treeNodes.assign(4*n,0);
        build(1,0,n-1);
        
    }
    int get_value(int i,int j){
        return get_value(1,0,n-1,i,j);
    }
    void update(int i,int v){
        update(1,0,n-1,i,v);
    }
};
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n;
    int test=1;
    while(cin>>n&&n){
        if(test!=1)cout<<endl;
        std::vector<int>values(n);
        for(int i=0;i<n;i++)cin>>values[i];
        
        SegmentTree tree(values);
        string s;
      
        cout<<"Case "<<test++<<":"<<endl;
        cin.ignore();
        while(getline(cin,s)&&s!="END"){
            stringstream ss(s);
            char op;
            int x,y;
            ss>>op>>x>>y;
            
            if(op=='M'){
                x--;
                y--;
                cout<<tree.get_value(x,y)<<endl;
            }
            else{
                x--;
                tree.update(x,y);
            }
        }
    }
    return 0;
}


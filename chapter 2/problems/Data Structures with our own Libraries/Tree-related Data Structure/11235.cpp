#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
 private:
    std::vector<int>element_values,tree_node;
    int n;
    int left(int p){return 2*p;}
    int right(int p){return 2*p+1;}
    void build(int p,int L,int R){
        if(L==R){
            tree_node[p]=L;
        }
        else{
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2+1,R);
            int p1=tree_node[left(p)];
            int p2=tree_node[right(p)];
            tree_node[p]=element_values[p1]>element_values[p2]?p1:p2;
        }
    }
    int rqm(int p,int L,int R,int i,int j){
        if(i>R || j<L)return -1;//out of range
        if(L>=i&&R<=j)return tree_node[p];
        
        int p1=rqm(left(p),L,(L+R)/2,i,j);
        int p2=rqm(right(p),(L+R)/2+1,R,i,j);
        
        if(p1==-1)return p2;
        if(p2==-1)return p1;
        return element_values[p1]>element_values[p2]?p1:p2;
    }
 public:
    SegmentTree(const vector<int> &v){
        element_values=v;n=v.size();
        tree_node.assign(4*n,0);
        build(1,0,n-1);
    }
    int rqm(int i,int j){
        return rqm(1,0,n-1,i,j);
    }
};
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n,q;
    while(cin>>n&&n){
        cin>>q;
        vector<int> A(n),freq(n);
        map<int,int>mp_f;
        for(int i=0;i<n;i++)cin>>A[i],mp_f[A[i]]++;
        for(int i=0;i<n;i++)freq[i]=mp_f[A[i]];
        
        SegmentTree t(freq);
        while(q--){
            int i,j;
            cin>>i>>j;
            i--,j--;
            
            //all range is the same number
            if(A[i]==A[j]){
                cout<<j-i+1<<endl;
                continue;
            }
            /*
            we need to handle the case:
            index:  1 2 3 4 5 6 
            value: 1 1 1 1 2 3 
            freq:  4 4 4 4 1 1 
            query from 4 to 6 answer is 1 not 4 so we make these 2 while loops
            */
            int left=0,right=0;
            while(i>0&&i<=j&&A[i]==A[i-1])left++,i++;
            while(j<n-1&&j>=i&&A[j]==A[j+1])right++,j--;
            
            cout<<max({left,right,freq[t.rqm(i,j)]})<<endl;
        }
    }

    return 0;
}


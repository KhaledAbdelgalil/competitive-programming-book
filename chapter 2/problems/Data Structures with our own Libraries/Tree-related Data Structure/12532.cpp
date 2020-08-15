#include <bits/stdc++.h>
using namespace std;

class segementTree{
 private:
    int n;
    std::vector<int>values;
    vector<char>treesNodes;//+-0
    int left(int p){return 2*p+1;}
    int right(int p){return 2*p;}
    void build(int p,int L,int R){
        if(L==R){
            treesNodes[p]=(values[L]==0)?'0':(values[L]>0)?'+':'-';
        }
        else{
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2+1,R);
            //handle all 6 cases
            if(treesNodes[left(p)]=='0')treesNodes[p]='0';
            else if(treesNodes[right(p)]=='0')treesNodes[p]='0';
            else if(treesNodes[left(p)]=='+'&&treesNodes[right(p)]=='-')treesNodes[p]='-';
            else if(treesNodes[left(p)]=='-'&&treesNodes[right(p)]=='+')treesNodes[p]='-';
            else treesNodes[p]='+';
        }
    }
    char getValueOfNode(int p,int L,int R,int i,int j){
        if(L>=i&&R<=j)return treesNodes[p];
        if(R<i)return '_';//out of range
        if(L>j)return '_';//out of range
        
        char l=getValueOfNode(left(p),L,(L+R)/2,i,j);
        char r=getValueOfNode(right(p),(L+R)/2+1,R,i,j);
        if(l=='_')return r;
        if(r=='_')return l;
        if(r=='0')return '0';
        if(l=='0')return '0';
        if(r!=l)return '-';
        else return '+';
    }
    void updateNode(int p,int L,int R,int i,char v){
        if(L==R){
         treesNodes[p]=v;
         return;  
        }
        if(i<=(L+R)/2){
            updateNode(left(p),L,(L+R)/2,i,v);
            
        }
        else{
            updateNode(right(p),(L+R)/2+1,R,i,v);
        }
        char l=treesNodes[left(p)];
        char r=treesNodes[right(p)];
        
        if(r=='0')treesNodes[p]='0';
        else if(l=='0')treesNodes[p]='0';
        else if(r!=l)treesNodes[p]='-';
        else treesNodes[p]='+';
    }
    public:
    segementTree(const vector<int>&values_){
        values=values_;n=values_.size();
        treesNodes.resize(n*4);
        build(1,0,n-1);
    }
    void updateNode(int i,int v){
        updateNode(1,0,n-1,i,v);
    }
    char getValueOfNode(int i,int j){
        return getValueOfNode(1,0,n-1,i,j);
    }
};

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n,k;
    while(cin>>n>>k){
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        segementTree tree(v);
        string s="";
        while(k--){
            char q;
            int i,j;
            cin>>q>>i>>j;
            i--,j--;
            if(q=='P'){
                s.push_back(tree.getValueOfNode(i,j));
            }
            else {
                j++;
                if(j>0)
                tree.updateNode(i,'+');
                else if(j<0)tree.updateNode(i,'-');
                else tree.updateNode(i,'0');
            }
        }
        cout<<s<<endl;
    }
    
    return 0;
}


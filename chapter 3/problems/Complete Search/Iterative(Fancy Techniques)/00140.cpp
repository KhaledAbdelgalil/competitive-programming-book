#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    
    string s;
    while(getline(cin,s)&& s!="#"){
        stringstream ss(s);
        char node;
        bool adj_mat[26][26]={0};
        bool vis[26]={0};
        vector<char>nodes;
        while(ss>>node){
    
            int node_num=node-'A';
            if(vis[node_num]==0)nodes.push_back(node);
            vis[node_num]=1;
            char temp;
            ss>>temp;
             while(ss>>temp&&temp!=';'){
                 adj_mat[node_num][temp-'A']=1;
                 adj_mat[temp-'A'][node_num]=1;
                 if(vis[temp-'A']==0)nodes.push_back(temp);
                 vis[temp-'A']=1;
             }
            
        
            
        }
        //cout<<"end"<<endl; 
        vector<char>ans;
        int minn=1e6;
        sort(nodes.begin(),nodes.end());
        do{
            int maxx=1;
            for(int i=0;i<nodes.size();i++){
                for(int j=i+1;j<nodes.size();j++){
                    if(adj_mat[nodes[i]-'A'][nodes[j]-'A']==1){
                        maxx=max(maxx,j-i);
                    }
                }
            }
            if(maxx<minn){
                minn=maxx;
                ans=nodes;
            }
        }while(next_permutation(nodes.begin(),nodes.end()));
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<"-> "<<minn<<endl;
    }
    return 0;
}


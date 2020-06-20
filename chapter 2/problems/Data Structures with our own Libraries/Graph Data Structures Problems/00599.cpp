#include <bits/stdc++.h>
using namespace std;
bitset<26>vis;
void dfs(int node,vector< vector<int> > &adj_list)
{
    vis[node]=1;
    for(int i=0;i<adj_list[node].size();i++)
    {
        if(vis[adj_list[node][i]]==0)
        {
            dfs(adj_list[node][i],adj_list);
        }
    }
}
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   vector< vector<int> > adj_list;
   int t;
   cin>>t;
   while(t--){
       string s;
       adj_list.resize(26);
       while(cin>>s&&s[0]!='*')
       {
           int first_node=s[1]-'A';
           int second_node=s[3]-'A';
           adj_list[first_node].push_back(second_node);
           adj_list[second_node].push_back(first_node);
       }
       vis=0;
       cin>>s;
       int cnt_acrons=0,cnt_trees=0;
       for(int i=0;i<s.size();i+=2)
       {
           int node=s[i]-'A';
           if(vis[node]==0)
           {
               if(adj_list[node].size()==0)cnt_acrons++,vis[node]=1;
               else dfs(node,adj_list),cnt_trees++;;
               
           }
       }
       cout<<"There are "<<cnt_trees<<" tree(s) and "<<cnt_acrons<<" acorn(s)."<<endl;
       adj_list.clear();
   }
   return 0;
}

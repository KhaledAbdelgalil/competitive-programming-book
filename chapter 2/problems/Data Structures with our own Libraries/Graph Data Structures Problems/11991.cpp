#include <bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   //look at this problem as it's multigraph?
   /*
   In each graph:
   we have a special vertex which is v connected to other vertices which are its occurence indices
   so each adjacency list contain a graph for example 
   1 2 2 3 3 
   adjacency list of 1 is : 1
   adjacency list of 2 is : 2 3
   adjacency list of 3 is : 4 5 
   so if now we ask you where third occurence of 3 :answer will be 0 as 3 > size of adjacency list of 3
   where is 2nd occurence of 2 : you can answer it which is 3
   */
   int n,q;
   while(cin>>n>>q)
   {
       vector< vector<int> >adj_list(1000001);
       for(int i=1;i<=n;i++)
       {
           int special_node;
           cin>>special_node;
           adj_list[special_node].push_back(i);
       }
       while(q--)
       {
           int k,v;
           cin>>k>>v;
           if(k>adj_list[v].size())cout<<0<<endl;
           else cout<<adj_list[v][k-1]<<endl;
       }
   }
   return 0;
}

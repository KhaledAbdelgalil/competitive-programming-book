#include <bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   int n,m;
   while(cin>>n>>m)
   {
       map<pair<int,int> ,int>mp;//pair of nodes /weight between them
       
       for(int i=1;i<=n;i++)
       {
           int cols;
           cin>>cols;
           std::vector<int>v(cols);
           for(int i=0;i<cols;i++)cin>>v[i];
           
           for(int j=0;j<cols;j++)
           {
               int value;
               cin>>value;
               mp[{i,v[j]}]=value;//row-col=value
           }
       }
       cout<<m<<" "<<n<<endl;
       for(int j=1;j<=m;j++)//make column as row
       {
           vector<int>v;
           for(int i=1;i<=n;i++)//make row as col
           {
               if(mp.find({i,j})!=mp.end())v.push_back(i);
           }
           if(v.size())
           {
               cout<<v.size();
               for(int i=0;i<v.size();i++)cout<<" "<<v[i];
               cout<<endl;
               //then cout values;
               cout<<mp[{v[0],j}];
               for(int i=1;i<v.size();i++)cout<<" "<<mp[{v[i],j}];
               cout<<endl;
           }
           else cout<<0<<endl<<endl;
       }
      
   }
   
   return 0;
}

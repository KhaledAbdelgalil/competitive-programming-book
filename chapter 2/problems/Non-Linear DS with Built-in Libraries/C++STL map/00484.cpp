#include <bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   int n;
   map<int,int>mp;
   std::vector<int>v;
   while(cin>>n)
   {
       if(mp[n]==0)v.push_back(n);
       mp[n]++;
   }
   for(int i=0;i<v.size();i++)
   cout<<v[i]<<" "<<mp[v[i]]<<endl;
   
    
   return 0;
}


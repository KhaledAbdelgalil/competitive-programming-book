#include <bits/stdc++.h>
using namespace std;


int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
   string temp;
   while(cin>>temp)
   {
      list<char>out;
      list<char>::iterator it=out.begin();
      for(int i=0;i<temp.size();i++)
      {
          if(temp[i]=='[')it=out.begin();
          else if(temp[i]==']')it=out.end();
          else out.insert(it,temp[i]);
      }
      
      for(it=out.begin();it!=out.end();it++)
      cout<<*it;
      cout<<endl;
   }
   return 0;
}


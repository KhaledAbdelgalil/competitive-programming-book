#include <bits/stdc++.h>
using namespace std;
bool cond(char s)
{
    if(s=='X')return true;
    return false;
}
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
  
  int n;
  string s;
  while(cin>>n&&n)
  {
      cin.ignore();
      std::vector<int>v(n);
      int maxx=-1;
      for(int i=0;i<n;i++)
      {
        getline(cin,s);
        int cntX=count_if(s.begin(),s.end(),cond);
        if(cntX>maxx)maxx=cntX;
        v[i]=cntX;
      }
      int out=0;
      for(int i=0;i<v.size();i++)
      out=out+(maxx-v[i]);
      
      cout<<out<<endl;
  }
   
   return 0;
}


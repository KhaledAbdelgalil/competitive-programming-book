#include <bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
   string e,f;
   map<string,string>dic;
   while(getline(cin,e)&&e!="")
   {
        int idx=e.find(' ');
        f=e.substr(idx+1);
        e=e.substr(0,idx);
       dic[f]=e;
   }
   //cin.ignore();
   while(cin>>f)
   {
       e=dic[f];
       if(e!="")
       cout<<e<<endl;
       else cout<<"eh"<<endl;
   }
   return 0;
}


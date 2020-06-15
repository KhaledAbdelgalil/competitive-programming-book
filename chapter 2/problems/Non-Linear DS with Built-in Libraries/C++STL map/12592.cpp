#include <bits/stdc++.h>
using namespace std;


int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   map<string,string>mp;
   int n;
   cin>>n;
   cin.ignore();
   while(n--)
   {
       string t1,t2;
       getline(cin,t1);
       getline(cin,t2);
       //cout<<t1<<endl<<t2<<endl;
       mp[t1]=t2;
   }
   cin>>n;
   cin.ignore();
   while(n--)
   {
       string t;
       getline(cin,t);
       cout<<mp[t];
       cout<<endl;
   }
   return 0;
}


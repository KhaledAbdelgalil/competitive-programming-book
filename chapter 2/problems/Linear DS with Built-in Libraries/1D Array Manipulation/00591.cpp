#include <bits/stdc++.h>
using namespace std;


int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
   int n;
   int f=0;
   while(cin>>n&&n)
   {
       f++;
       std::vector<int>v(n);
       int out=0;
       for(int i=0;i<n;i++)
       cin>>v[i],out+=v[i];
       
       out=(int)out/(int)n;
       
       int steps=0;
       for(int i=0;i<v.size();i++)
       if(v[i]>out)steps+=v[i]-out;
       
       cout<<"Set #"<<f<<endl;
       cout<<"The minimum number of moves is "<<steps<<"."<<endl;
       cout<<endl;
       
   }
   
   return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
   string n;
   while(cin>>n&&n!="#")
   {
       
       string f=n;
       next_permutation(n.begin(),n.end());
       sort(f.begin(),f.end());
       if(f==n)cout<<"No Successor"<<endl;
       else cout<<n<<endl;
   }
   
   return 0;
}


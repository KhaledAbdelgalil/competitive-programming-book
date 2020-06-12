#include <bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
   int t;
   cin>>t;
   
   while(t--)
   {
       int n;
       std::vector<int>v;
       while(cin>>n&&n)v.push_back(n);
       sort(v.rbegin(),v.rend());
       
       int i=0;
       //5,000,000
       int sum=0;
       for(;i<v.size();i++)
       {
          
        sum+=(2*pow(double(v[i]),double(i+1)));
        if(sum>5000000)break;
       }
       if(i==v.size())cout<<sum<<endl;
       else cout<<"Too expensive"<<endl;
       
   }
   
   return 0;
}


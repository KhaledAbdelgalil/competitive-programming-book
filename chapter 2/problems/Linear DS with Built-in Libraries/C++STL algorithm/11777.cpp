#include <bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
   int t;
   cin>>t;
   
   for(int i=1;i<=t;i++)
   {
       int sum=0;
       int temp;
       
       for(int i=0;i<4;i++)
       cin>>temp,sum+=temp;
       
       std::vector<int>v(3) ;
       for(int i=0;i<3;i++)
       cin>>v[i];
       sort(v.begin(),v.end());
       double avg=(v[1]+v[2])/2;
       
       cout<<"Case "<<i<<": ";
       if(avg+(double)sum>=90.0)cout<<"A"<<endl;
       else if(avg+(double)sum>=80)cout<<"B"<<endl;
       else if(avg+(double)sum>=70)cout<<"C"<<endl;
       else if(avg+(double)sum>=60)cout<<"D"<<endl;
       else cout<<"F"<<endl;
   }
   return 0;
}


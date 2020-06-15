#include <bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   map<string,int>mp;
   int n,m;
   cin>>n>>m;
   while(n--)
   {
       string t1,t2;
       cin>>t1>>t2;
       int res=0;
       string str=t2.substr(0,t2.size()-2);
       if(str.size()==1)
       {
           res=int(str[0]-'0');
       }
       else res=int(str[0]-'0')*10+int(str[1]-'0');
       mp[t1]=(res*100)+(t2[t2.size()-1]-'0')*10;
       //cout<<t1<<" "<<mp[t1]<<endl;
   }
   for(int i=0;i<m;i++)
   {
       string t;
       int res=0;
       cin>>t;
       res=mp[t];
       while(cin>>t&&t!="<"&&t!="<="&&t!=">="&&t!=">"&&t!="=")
       {
           cin>>t;
           res+=mp[t];
       }
       int res2;
       cin>>res2;
       res2*=100;
       if(res<res2&&t=="<")cout<<"Guess #"<<i+1<<" was correct."<<endl;
       else if(res<=res2&&t=="<=")cout<<"Guess #"<<i+1<<" was correct."<<endl;
       else if(res>=res2&&t==">=")cout<<"Guess #"<<i+1<<" was correct."<<endl;
       else if(res>res2&&t==">")cout<<"Guess #"<<i+1<<" was correct."<<endl;
       else if(res==res2&&t=="=")cout<<"Guess #"<<i+1<<" was correct."<<endl;
       else cout<<"Guess #"<<i+1<<" was incorrect."<<endl;
       
   }
   return 0;
}


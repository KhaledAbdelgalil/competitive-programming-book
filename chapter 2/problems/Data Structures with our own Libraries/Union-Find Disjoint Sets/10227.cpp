#include<bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
   int t,p,n;
   cin>>t;
   while(t--)
   {
       cin>>p>>n;
       cin.ignore();
       std::vector< set<int> >peoples(p+5);
       string s;
       while(getline(cin,s)&&s.size())
       {
           stringstream ss(s);
           int x,y;
           ss>>x>>y;
           peoples[x].insert(y);
       }
      vector<bool>vis(p+1,0);
      int diff_opinions=0;
      for(int i=1;i<=p;i++)
      {
          if(vis[i]==0){
              vis[i]=1;
              diff_opinions++;
              //see other peoples that have same opinion and visit them
              for(int j=i+1;j<=p;j++)
              {
                  if(peoples[i]==peoples[j])vis[j]=1;
              }
          }
      }
      std::cout << diff_opinions << std::endl;
      if(t)cout<<endl;
   }
}

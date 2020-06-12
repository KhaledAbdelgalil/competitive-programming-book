#include <bits/stdc++.h>
using namespace std;
map<string,vector<int> >mp_name_cs;
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
   int n,r;
   cin>>n>>r;
  
   for(int i=0;i<n;i++)
   {
      string name;
      int B,CD,D;
      cin>>name>>B>>CD>>D;
      
      vector<int>Cs(D+1);
      Cs[D]=CD;
      
      vector<int>Ls(D+1),Us(D+1);
      
      for(int i=1;i<=D;i++)
      cin>>Ls[i]>>Us[i];
      
      int C0=B-CD*Ls[D];
      
      for(int i=D-1;i>=1;i--)
      {
          Cs[i]=Cs[i+1]*(Us[i+1]-Ls[i+1]+1);
          C0-=Cs[i]*Ls[i];    
      }
      
      Cs[0]=C0;
      
      /*
      for(int i=0;i<Cs.size();i++)
      cout<<Cs[i]<<" ";
      
      cout<<endl;
      */
      mp_name_cs[name]=Cs;
   }
  
   for(int i=0;i<r;i++)
    {
      string name;
      cin>>name;
      vector<int>Cs(mp_name_cs[name].begin(),mp_name_cs[name].end());
      int out=Cs[0];
      
      int x;
      cout<<name<<"[";
      for(int i=1;i<Cs.size();i++)
      {
          cin>>x;
          cout<<x;
          if(i!=Cs.size()-1)cout<<", ";
          else cout<<"] = ";
          out+=Cs[i]*x;
      }
      cout<<out<<endl;
      
    }
    return 0;
}


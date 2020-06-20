#include <bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   int t;
   cin>>t;
   //rows are vertices cols are edges so in each edge we must found 2 ones only
  //edge is connected to 2 vertices only
   while(t--)
   {
       int n,m;
       cin>>n>>m;
      vector< vector <int> >mat(n,vector<int>(m));
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
      bool incidence=1;
      map<pair<int,int>,int>mp;
      for(int j=0;j<m;j++)
        {
            int cnt_ones=0;
            vector<int>vertices;
            for(int i=0;i<n;i++)
            {
               if(mat[i][j])vertices.push_back(i),cnt_ones++;
            }
            
            if(cnt_ones!=2)incidence=0;
            else
            {   
                mp[{vertices[0],vertices[1]}]++;
                //to avoid that there is 2 edges between 1 and 2 
                if(mp[{vertices[0],vertices[1]}]!=1)incidence=0;
            }
            if(incidence==0)break;
        }
      if(incidence)cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
   }
   
   return 0;
}

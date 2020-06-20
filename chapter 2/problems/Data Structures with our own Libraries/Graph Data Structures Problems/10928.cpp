#include <bits/stdc++.h>
using namespace std;
 typedef pair<int ,int > ii;
 typedef std::vector<ii>vii ;
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   vector<int>neighbours_count_in_this_place;
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       cin.ignore();
       neighbours_count_in_this_place.clear();
       neighbours_count_in_this_place.resize(n);
       int minn=1e6;
       for(int i=0;i<n;i++)
       {
           string s;
           getline(cin,s);
           stringstream ss(s);
           int node;
           int cnt=0;
           while(ss>>node)
           {
               cnt++;
           }
           neighbours_count_in_this_place[i]=cnt;
           minn=min(cnt,minn);
       }
       vector<int>ans;
       for(int i=0;i<n;i++)
       {
         if(neighbours_count_in_this_place[i]==minn)ans.push_back(i+1);
       }
       cout<<ans[0];
       for(int i=1;i<ans.size();i++)cout<<" "<<ans[i];
       cout<<endl;
       
   }
   
   return 0;
}

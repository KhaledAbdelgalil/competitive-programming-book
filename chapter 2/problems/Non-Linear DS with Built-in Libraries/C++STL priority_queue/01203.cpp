#include<bits/stdc++.h>
using namespace std;



int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
 
   priority_queue< pair< int,int> >queries;//pair is time and id but with negative to return minimum
   map<int,int>mp;//map Q_num to know period
   
   string s;
   while(cin>>s&&s!="#")
   {
       int Q_num,period;
       cin>>Q_num>>period;
       Q_num*=-1;
       period*=-1;
       queries.push({period,Q_num});
       mp[Q_num]=period;
   }
   int next_time=0;
   int n;
   cin>>n;
   while(n--)
   {
       int Q_num,period;
       pair<int,int>p=queries.top();
       queries.pop();
       Q_num=p.second;
       next_time=p.first;
       period=mp[Q_num];
       next_time=next_time+period;
       queries.push({next_time,Q_num});
       Q_num*=-1;
       cout<<Q_num<<endl;
   }
   return 0;
}


#include <bits/stdc++.h>

using namespace std;
int n;
double w,l;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
 
   while(cin>>n>>l>>w){
       vector< pair<double,double> >v;
       for(int i=0;i<n;i++){
           double x,r;
           cin>>x>>r;
           if(r*r>=w*w/4){
               double dx=sqrt(r*r-w*w/4);
               v.push_back({x-dx,x+dx});//interval covered by this valid sprinkle 
           }
       }
       
       if(v.size())//we may find a solution
       {
          //we want to cover [0-------L] interval
          sort(v.begin(),v.end());
          //let answer be all sprinkles
          vector < pair<double,double> >ans(v.size());
          int curr_sprinkle=0;
          int countt=0;
          double wanted_x=0;
          while(wanted_x<l&&curr_sprinkle<v.size()){
              ans[countt].second=0;
              for(;v[curr_sprinkle].first<=wanted_x&&curr_sprinkle<v.size();curr_sprinkle++){
                  if(v[curr_sprinkle].second>ans[countt].second)ans[countt]=v[curr_sprinkle];
              }
              if(ans[countt].second==wanted_x)break;//we will not find better solution
              
              wanted_x=ans[countt].second;
              countt++;
          }
          if(wanted_x>=l)cout<<countt<<endl;
          else cout<<-1<<endl;
       }
       else cout<<-1<<endl;
       
   }
    return 0;
}


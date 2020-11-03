#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
   int t;
   cin>>t;
   while(t--){
       
       int n;
       cin>>n;
       std::vector<int>v(n);
       long long totalTime=0;
       for(int i=0;i<n;i++)cin>>v[i];
       stringstream ss;
       //consider four people in each round 2 fastest people and 2 slowest people
       //ABXY    so we have 2 scanerios:
       /*
       1-AB went then A return then XY go then B return so XY now on other side
       2-AX went then A return then AY go then A return so XY now on other side
    
       in 1-totaltime B+A+X+B
       in 2-totaltime X+A+Y+A
       so if A+2B<2A+y choose 1
       i.e if v[0]+2*v[1]<2*v[0]+v[n-2]
       note both leads to same output on 2 sides of bridge
       
       */
       while(n>=4){
           
           if(v[0]+2*v[1]<2*v[0]+v[n-2]){
               totalTime+=v[n-1]+v[0]+2*v[1];
               //output on stream ss
               ss<<v[0]<<" "<<v[1]<<endl<<v[0]<<endl<<v[n-1]<<" "<<v[n-2]<<endl<<v[1]<<endl;
           }
           else {
               ss<<v[0]<<" "<<v[n-1]<<endl<<v[0]<<endl<<v[0]<<" "<<v[n-2]<<endl<<v[0]<<endl;
               totalTime+=v[n-1]+2*v[0]+v[n-2];
           }
           n-=2;//2 people reached other side of bridge
       }
       //ABC
       if(n==3){
           totalTime+=v[0]+v[1]+v[2];
           ss<<v[0]<<" "<<v[1]<<endl<<v[0]<<endl<<v[0]<<" "<<v[2]<<endl;
       }else if(n==2){
           totalTime+=v[1];
           ss<<v[0]<<" "<<v[1]<<endl;
           
       }else if(n==1){
           totalTime+=v[0];
           ss<<v[0]<<endl;
       }
       cout<<totalTime<<endl;
       cout<<ss.str();
       if(t)cout<<endl;
   }

    return 0;
}


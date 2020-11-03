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
       unsigned long long N=0;
       int ones,zeros;
       cin>>ones>>zeros;
       int best_101=min(ones/2,zeros);
       //the best is to concentate 101 every 2 ones put zeros between them
       if(best_101!=0){
           ones-=2*best_101;
           zeros-=best_101;
           //if still ones and zeros put 000.....01 at beginning
           if(zeros&&ones)ones--,N+=1;
           
           while(best_101--){
              N=N<<3;//shift 3 positions and put 101
               N+=5;
           }
       }
       while(ones--){
           N=N<<1;
           N++;
       }
       cout<<N<<endl;
   }
    return 0;
}


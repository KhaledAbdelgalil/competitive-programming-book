#include <bits/stdc++.h>
using namespace std;



int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int vi,vo;
    while(cin>>vi>>vo){
        if(vi==0&&vo==0)break;
        
        int mx=0;
        double lmx=0;
        for(int i=1;i<=vi;i++){
          double v=(double)vi/i;
          //if(i*v!=vi)continue;
          if(v<=vo)break;
          else{
              char longest[101],l[101];
              double length=sqrt(v-vo)*0.3*i;
              sprintf(l,"%.10lf",length);
              sprintf(longest,"%.10lf",lmx);
              if(strcmp(l,longest)==0)mx=0;
              else if(length>lmx)lmx=length,mx=i;
              
          }
        }
        
        cout<<mx<<endl;
    }
   
    
    return 0;
}


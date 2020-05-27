#include <bits/stdc++.h>
#include <string>

using namespace std;


int main(){
    
    
  std::ifstream in ("input");
  std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
  std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  int n;
  int t=0;
  while(cin>>n&&n)
  {
     
      t++;
      cout<<"Output for data set "<<t<<", "<<n<<" bytes:"<<endl;
      int bytes;
      int totalbytes=0;
      int bytesevert5=0;
      int secs=0;
      do
      {
          cin>>bytes;
          
          secs++;
          n-=bytes;
          totalbytes+=bytes;
          bytesevert5+=bytes;
          
          
          if(secs%5==0&&secs!=0)
          {
              if(bytesevert5)
              {
                
                int time1=(int)ceil(  n  *5.0 / bytesevert5 );
                
                 printf("   Time remaining: %d seconds\n", time1);
              }
              else   printf("   Time remaining: stalled\n");
              bytesevert5=0;
          }
          
          
      }while(n>0);
  
      printf("Total time: %d seconds\n\n", secs);
      
  }
  return 0;
}


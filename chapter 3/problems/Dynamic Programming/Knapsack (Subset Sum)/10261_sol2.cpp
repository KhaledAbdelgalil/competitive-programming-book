#include <bits/stdc++.h>
using namespace std;

bool dp[2][10005];//states of port  ------- trick of memory 
int pre[205][10005];
int currLen[205];
bool answer[205];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
   int tests;
   cin>>tests;
   for(int test=0;test<tests;test++){
       
       int L;
       cin>>L;
       L*=100;//L in cm
     
     
       memset(dp,0,sizeof dp);
       memset(pre,-1,sizeof pre);
       dp[0][0]=true;//I can reach state length=0 at port
       bool done=false;//we are done no more cars can be loaded
      
       int x;//x represent current length of car in front of queue
       int sumlen=0;//sumlen represent lengths of all cars till now
       int i=0;
       int n=0;//n represent answer(no. of cars taken)
       int t=0,pt;
       int lastLen=0;//I want lastLen I reached for port side to back track the answer
       while(cin>>x&&x){
           if(done)continue;
           sumlen+=x;
           currLen[++i]=x;
           pt=t,t^=1;//swap the dp
           memset(dp[t],0,sizeof dp[t]);
           bool canload=0;
           for(int len=0;len<=L;len++){
              if(dp[pt][len]==false)//if cannot reach len from previous state skip this len 
               continue;
               //so now port has len cars so try put this car to port
               if(len+x<=L&&sumlen-(len+x))//safe port and safe starboard
               {
                   //I can load this car to port
                   canload=1;
                   dp[t][len+x]=1;//I can reach a port of cars length len+x
                   pre[i][len+x]=0;//this car is put at port(0)
                   lastLen=len+x;//so lastLen of cars at port is len+x
               }
               if(sumlen-len<=L){
                   //if I put car at starboard so port now still have len
                   canload=1;
                   dp[t][len]=1;//I can still reach this port current state so let's have it in next dp iteration
                   lastLen=len;//As said still have len in port side
                   pre[i][len]=1;//this car is put at starboard;
               }
               
           }
           
           if(!canload)done=1;//we cannot load this car at front of cars so we cannot load more we are done
           else n=i;
       }
       
       cout<<n<<endl;
       for(int j=n;j>=1;j--)//let's backtrack the answer
       {
           if(pre[j][lastLen]==0)//if last car is put at port
           {
               //go to the previous car to that car
               lastLen-=currLen[j];
               answer[j]=0;
           }
           else if(pre[j][lastLen]==1)//if last car is put at starboard
           {
               answer[j]=1;//we don't need to subtract as it's not on port side
           }
       }
       for(int i=1;i<=n;i++){
           if(answer[i])cout<<"starboard"<<endl;
           else cout<<"port"<<endl;
       }
       if(test!=tests-1)cout<<endl;
   }

    return 0;
}


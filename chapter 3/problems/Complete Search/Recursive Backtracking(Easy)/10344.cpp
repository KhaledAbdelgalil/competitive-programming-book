#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
bool flag;
int nums[5];
void solve(int i,int sum){
    if(i==5){
        if(sum==23)
        flag=1;
    }
    else{
        solve(i+1,sum+nums[i]);
        solve(i+1,sum-nums[i]);
        solve(i+1,sum*nums[i]);
    }
    
    
}

int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    while(cin>>a>>b>>c>>d>>e){
      if(a==0&&b==0&&c==0&&d==0&&e==0)break;  
       flag=0;
       nums[0]=a,nums[1]=b,nums[2]=c,nums[3]=d,nums[4]=e;
       sort(nums,nums+5);
       do{
         solve(1,nums[0]);
         if(flag)break;
       }while(next_permutation(nums,nums+5));
      
       if(flag)cout<<"Possible"<<endl;
       else cout<<"Impossible"<<endl;
    }
    return 0;
}


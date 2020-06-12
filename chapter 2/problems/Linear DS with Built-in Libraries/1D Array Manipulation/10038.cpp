#include <bits/stdc++.h>
using namespace std;


int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
   int n;
   while(cin>>n)
   {
       vector<bool>v(n,false);
       vector<int>nums(n);
       
       for(int i=0;i<n;i++)
        cin>>nums[i];
        
       if(n==1)
        {
            cout<<"Jolly"<<endl;
            continue;
        }
        int i;
        for(i=0;i<n-1;i++)
        {
            int diff=abs(nums[i]-nums[i+1]);
            if(diff<=n-1&&v[diff]==false)v[diff]=true;
            else break; 
        }
        if(i==n-1)cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
   }
   
   return 0;
}


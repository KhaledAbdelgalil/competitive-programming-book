#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    int t;
    cin>>t;
    bool first=1;
    while(t--){
       if(!first)cout<<endl;
       else first=0;
       int sum;
       cin>>sum;
       int n=1;
       while(((n+1)*(n+2)/2)-1<=sum){//start 2 3 4 5 as 1 will not be useful
           //let's find largest n 
           n++;
       }
       n--;
       vector<unsigned long long>ans(n);
       //let's form n distinct numbers that  sums=sum
        int left_from_sum=sum-(((n+1)*(n+2)/2)-1);
        for(int i=0;i<n;i++){
            ans[i]=i+2+left_from_sum/n;
               if(i>=n-(left_from_sum%n))ans[i]++;
        }
           
           
       cout<<ans[0];
       for(int i=1;i<ans.size();i++)cout<<" "<<ans[i];
       cout<<endl;
    }
    return 0;
}


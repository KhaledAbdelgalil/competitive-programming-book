#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    int n,d,r;
    while(cin>>n>>d>>r){
       if(n==0&&d==0&&r==0)break;
       vector<int>vm(n),ve(n);
       for(int i=0;i<n;i++)cin>>vm[i];
       for(int i=0;i<n;i++)cin>>ve[i];
       sort(vm.begin(),vm.end());
       sort(ve.rbegin(),ve.rend());
       long long ans=0;
       for(int i=0;i<n;i++){
           if(ve[i]+vm[i]>d){
               ans=ans+(long long)(ve[i]+vm[i]-d)*(long long)(r);
           }
       }
       cout<<ans<<endl;
    }
    return 0;
}


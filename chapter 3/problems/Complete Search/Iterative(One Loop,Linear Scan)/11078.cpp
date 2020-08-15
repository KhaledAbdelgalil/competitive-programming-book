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
        for(int i=0;i<n;i++)cin>>v[i];
        int mx=-150000*2;
        
        
        int best=-150000*2;
        for(int i=0;i<n-1;i++){
            best=max(best,v[i]);
            mx=max(best-v[i+1],mx);
        }
        cout<<mx<<endl;
    }
   
    
    return 0;
}


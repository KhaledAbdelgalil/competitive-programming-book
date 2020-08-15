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
        int r;
        cin>>r;
        std::vector<int>relatives(r);
        int mn=30000,mx=0;
        for(int i=0;i<r;i++){
            cin>>relatives[i];
            mn=min(mn,relatives[i]);
            mx=max(mx,relatives[i]);
        }
        int sum=0,mn_sum=30000*500;
        for(int h=mn;h<=mx;h++){
            sum=0;
            for(int i=0;i<r;i++)sum+=abs(h-relatives[i]);
            mn_sum=min(mn_sum,sum);
        }
        cout<<mn_sum<<endl;
    }

    return 0;
}


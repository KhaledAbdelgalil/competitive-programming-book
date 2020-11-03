#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    while(cin>>n&&n){
        ll ans=0;
        // I will start say with 5 so I need to sell 5 i will sell it to the nearst neighbour as it's minimum distance
        // if neighbour need -5 so sum=0 so we finish if he/she need -4 so he/she have 1 so sell to next neighbour and so on
        ll sum=0;
        while(n--){
            ll x;
            cin>>x;
            sum+=x;
            if(sum>0)ans+=sum;
            else ans-=sum;//handle negative
        }
        cout<<ans<<endl;
    }
    return 0;
}


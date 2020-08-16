#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool valid(ll n){
    ll f=n;
    int sz=log10(n)+1;
    set<ll>sz2;
    while(f){
        sz2.insert(f%10);
        f/=10;
    }
    if(sz==sz2.size())return 1;
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll s2=1;s2*n<=9876543210;s2++){
            ll s1=s2*n;
            if(valid(s1)&&valid(s2)){
                cout<<s1<<" / "<<s2<<" = "<<n<<endl;
            }
        }
        if(t)cout<<endl;
    }

    return 0;
}


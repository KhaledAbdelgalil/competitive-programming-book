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

        vector< pair<ll,ll> >pos,neg;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            if(x>0)pos.push_back({i,x});
            else neg.push_back({i,-1*x});
        }
        
        ll out=0;
        for(int i=0;i<pos.size();i++){
            for(int j=0;j<neg.size()&&pos[i].second;j++){
                if(neg[j].second){
                    if(pos[i].second>neg[j].second){
                        pos[i].second-=neg[j].second;
                        out+=neg[j].second*abs(pos[i].first-neg[j].first);
                        neg[j].second=0;
                    }
                    else{
                        out+=pos[i].second*abs(pos[i].first-neg[j].first);
                        neg[j].second-=pos[i].second;
                        pos[i].second=0;
                    }
                }
            }
        }
        cout<<out<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

//try to deal with long long not double
//so range a=0->20*100 so sum will be multiplied by 100 and product by 10^8
typedef long long ll;
int main(){
    
    for(ll a=1;a+a+a+a<=2000;a++){
        for(ll b=a;a+b+b+b<=2000;b++){
            for(ll c=b;a+b+c+c<=2000;c++){
                ll s=a+b+c;//(s+d)*1e6=p*d
                ll p=a*b*c;
                if(p<=1e6)continue;
                ll d=(s*1e6)/(p-1e6);
                if(s+d>2000||d<c)continue;
                //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                if(fabs( (a+b+c+d)/100.0-(a*b*c*d)/100000000.0)<1e-9 ){
                    printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", a / 100.0,
							b / 100.0, c / 100.0, d / 100.0);
                }
            }
        }
    }
    return 0;
}


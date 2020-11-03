#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool flag_found=0;
        for(int a=0;3*a*a<=n;a++){
            for(int b=a;a*a+2*b*b<=n;b++){
                int c=n-a*a-b*b;
                if(c<b*b)break;
                c=sqrt(c);
                if(n==a*a+b*b+c*c){
                    flag_found=1;
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    break;
                }
                
            }
            if(flag_found)break;
        }
        if(flag_found==0)cout<<-1<<endl;
    }
    return 0;
}


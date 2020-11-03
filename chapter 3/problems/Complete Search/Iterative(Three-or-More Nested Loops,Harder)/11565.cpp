#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        bool found=0;
         //three different numbers so x=min that formed from three equations when a=b=c=10000
        for(int x=-100;x<=100;x++){
            for(int y=x+1;y<=100;y++){
                int z=a-x-y;
                if(z<=y)break;
                if(x+y+z==a&&x*y*z==b&&x*x+y*y+z*z==c){
                    found=1;
                    cout<<x<<" "<<y<<" "<<z<<endl;
                    break;
                }
            }
            if(found)break;
        }
        if(!found)cout<<"No solution."<<endl;
    }
    return 0;
}


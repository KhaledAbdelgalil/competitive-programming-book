
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int t,n,p;
    cin>>t;
    while(t--){
        cin>>n>>p;
        vector<int>v(p);
        for(int i=0;i<p;i++)cin>>v[i];
        bool can=0;
        for(int i=0;i<(1<<p);i++){
            int sum=0;
            for(int j=0;j<p;j++){
                if(i&(1<<j))sum+=v[j];
            }
            if(sum==n){
                can=1;
                break;
            }
        }
        if(can)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    
    return 0;
}


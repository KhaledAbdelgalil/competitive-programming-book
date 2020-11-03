
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    //train can be increased from both sides so we want LIS in and LDS and then answer is LIS+LDS-1 as myself is added twice
    //but we want to build dp from last index as if we have sequence 1 2 3 0 we want at 1 LIS to be 3 and LDS=2 so answer is 3+2-1=4
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==0){cout<<0<<endl;continue;}
        std::vector<int>v(n),LIS,LDS;
        LIS.assign(n,1);
        LDS.assign(n,1);
        for(int i=0;i<n;i++)cin>>v[i];
        int maxx=1;
        for(int j=n-2;j>=0;j--){
            for(int i=j+1;i<n;i++){
                if(v[j]>v[i])LDS[j]=max(LDS[j],LDS[i]+1);
                else if(v[j]<v[i])LIS[j]=max(LIS[j],LIS[i]+1);
            }
            maxx=max(LDS[j]+LIS[j]-1,maxx);
        }
        
        cout<<maxx<<endl;
        
        
    }
    
    return 0;
}


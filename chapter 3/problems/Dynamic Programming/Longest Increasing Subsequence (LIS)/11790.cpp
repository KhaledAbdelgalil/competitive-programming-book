
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
    int t;
    cin>>t;
    
    int test=1;
    while(t--){
        int n;
        cin>>n;
        std::vector<int>heights(n),widths(n);
        for(int i=0;i<n;i++)cin>>heights[i];
        for(int i=0;i<n;i++)cin>>widths[i];
        vector<int>LIS(n),LDS(n);
        for(int i=0;i<n;i++)LIS[i]=LDS[i]=widths[i];
        int maxx_inc=widths[0],maxx_dec=widths[0];
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(heights[j]>heights[i])//increasing
                LIS[j]=max(LIS[j],widths[j]+LIS[i]);
                else if(heights[j]<heights[i])
                LDS[j]=max(LDS[j],LDS[i]+widths[j]);
            }
            maxx_inc=max(maxx_inc,LIS[j]),maxx_dec=max(maxx_dec,LDS[j]);
        }
        if(maxx_inc>=maxx_dec){
            cout<<"Case "<<test++<<". Increasing ("<<maxx_inc<<"). Decreasing ("<<maxx_dec<<")."<<endl;
        }
        else cout<<"Case "<<test++<<". Decreasing ("<<maxx_dec<<"). Increasing ("<<maxx_inc<<")."<<endl;

    }
    return 0;
}


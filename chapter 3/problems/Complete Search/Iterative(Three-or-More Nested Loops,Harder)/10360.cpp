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
        int killed_if_we_put_spray_here[1025][1025]={0};
        int d,n;
        cin>>d>>n;
        for(int i=0;i<n;i++){
            int x,y,p;
            cin>>x>>y>>p;
            for(int i=max(x-d,0);i<=min(1024,x+d);i++){
                for(int j=max(y-d,0);j<=min(1024,y+d);j++){
                    killed_if_we_put_spray_here[i][j]+=p;
                }
            }
        }
        int maxx_pop=0;
        int locx,locy;
        for(int i=0;i<=1024;i++){
            for(int j=0;j<=1024;j++){
                if(killed_if_we_put_spray_here[i][j]>maxx_pop)maxx_pop=killed_if_we_put_spray_here[i][j],locx=i,locy=j;
            }
        }
        cout<<locx<<" "<<locy<<" "<<maxx_pop<<endl;
    }
    return 0;
}


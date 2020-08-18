
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n;
    int t=1;
    while(cin>>n){
        long long maxx=0;
        long long p=1;
        std::vector<long long>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        for(int i=0;i<n;i++){
           long long p1=1;
            for(int j=0;j<=i;j++){
                p1*=v[j];
                long long p2=1;
                for(int k=j;k<=i;k++){
                    p2*=v[k];
                }
                maxx=max(maxx,max(p1,p2));
            }
        }
        cout<<"Case #"<<t++<<": The maximum product is "<<maxx<<"."<<endl<<endl;
    }
    return 0;
}


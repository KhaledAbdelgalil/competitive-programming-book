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
    int n;
    cin>>n;
    int ans=1e9;
    //constant volume =n
    for(int i=1;i*i*i<=n;i++){
        for(int j=i;i*j*j<=n;j++){
            if(n%(i*j)!=0)continue;
            int k=n/(i*j);
            //now we have cube of dimension i*j*k
            int area=2*(i*j+j*k+i*k);
            if(area<ans)ans=area;
        }
    }
    cout<<ans<<endl;
    }
    
    return 0;
}


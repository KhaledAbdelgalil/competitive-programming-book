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
        int C;
        cin>>C;
        std::vector<long long>coeff(C+1);
        for(int i=0;i<C+1;i++)cin>>coeff[i];
        
        long long n=1;
        long long d,k;
        cin>>d>>k;
        long long start=d*n;
        while(k>start){
            n++;
            start+=d*n;
        }
        //subsitute in equation
        long long ans=0;
        //cout<<n<<endl;
        for(int i=0;i<C+1;i++){
            ans+=coeff[i]*pow(n,i);
        }
        cout<<ans<<endl;
    }
    
   
    
    return 0;
}


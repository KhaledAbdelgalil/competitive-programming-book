#include <bits/stdc++.h>
using namespace std;

int main()
{
     std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int p,q,r,s,t,u;
    while(cin>>p>>q>>r>>s>>t>>u){
        
        //if maximum number of equation is less than zero (at x=0 ) or minimum number of equation is more than zero(at x=1 )
        //then we cannot find solution
        if(p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t+u>1e-9|| p+r+u<0){
            cout<<"No solution"<<endl;
            continue;
        }
        
        double low=0.0000;
        double high=1.0000;
        //make 50 iterations is very enough as if binary search is used log2((1-0)/e) which is 30 iterations
        double mid;
        for(int i=0;i<50;i++){
            mid=(low+high)/2;
            double equation=p*exp(-1*mid)+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*mid*mid+u;
            if(equation>0)//i.e we are near zero as at x=zero it's maximum answer so we need to decrease f i.e increase mid
            low=mid;
            else high=mid;
        }
        printf("%.4f\n",mid);
    }

    return 0;
}


#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        double p;
        double out=0;
        for(int i=0;i<12;i++)
        cin>>p,out+=p;
       // cout<<out/12.0<<endl;
        out/=12.00;
        if(out>1000)
        {
            cout<<i<<" $1,";
            double o=out-1000;
            
            
            printf("%.2f",o);
        }
        else
        {
            cout<<i<<" $";
            printf("%.2f",out);
        }
        cout<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;



int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    
    while(cin>>n&&n){
    
    int sum=0,maxx=-1;
    while(n--){
        int x;
        cin>>x;
        sum+=x;
        if(sum>maxx)maxx=sum;
        else if(sum<0) sum=0;
    }
        if(maxx>0)cout<<"The maximum winning streak is "<<maxx<<"."<<endl;
        else cout<<"Losing streak."<<endl;
    }

    return 0;
}


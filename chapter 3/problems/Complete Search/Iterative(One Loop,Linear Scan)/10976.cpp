#include <bits/stdc++.h>
using namespace std;



int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int k;
    
    while(cin>>k){
        int x,y;
        std::vector<int>xx,yy;
        for(y=k+1;y<=2*k;y++){
            x=(y*k)/(y-k);
            if(x*y==k*x+k*y){
                xx.push_back(x);
                yy.push_back(y);
            }
        }
        cout<<xx.size()<<endl;
        for(int i=0;i<xx.size();i++){
            cout<<1<<"/"<<k<<" = "<<1<<"/"<<xx[i]<<" + "<<1<<"/"<<yy[i]<<endl;
        }
    }
   
    
    return 0;
}


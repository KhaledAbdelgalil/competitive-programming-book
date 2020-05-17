#include <bits/stdc++.h>
#include<fstream>
using namespace std;
int main()
{
    /*std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    int t;
    cin>>t;
    while(t--)
    {
        char r;
        int x,y;
        cin>>r>>x>>y;
        if(r=='r')cout<<min(x,y)<<endl;
        else if(r=='Q')cout<<min(x,y)<<endl;
        else if(r=='k')
        {
            int out=y*(x/2);
            if(x%2!=0)if(y%2==0)out+=(y/2);
                    else out+=(y/2)+1;
            cout<<out<<endl;
        }
        else {
            x+=1;
            x/=2;
            y+=1;
            y/=2;
            cout<<x*y<<endl;
            
        }
    }
    
    
    return 0;
}


#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main()
{
    /*std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    int n,m;
    while(cin>>n>>m&&(n||m))
    {
        if(n<3&&m<3)
        {
            cout<<n*m<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
        }
        else if(n==1 || m==1 )cout<<n*m<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
        else if(n==2 || m==2 )
        {
            int out;
            int blocks=(n*m)/4;
            if(blocks%2==0)out=blocks*2;
            else out=(blocks/2 +1)*4;
            if((n*m)%4!=0)
            {
                if((blocks)%2==0)out+=2;
            }
            
            cout<<out<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
        }
        else
        {
            int out=m*(n/2);
            if(n%2!=0)
            {
                out+=(m%2==0)?m/2:m/2+1;
            }
            cout<<out<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
    
        }
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
   
    int n;
    while(cin>>n&&n)
    {
        bitset<32>a(0);
        bitset<32>b(0);
        bool isA=1;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i))
            {
                if(isA)a[i]=1,b[i]=0,isA=0;
                else b[i]=1,a[i]=0,isA=1;
            }
            else a[i]=0,b[i]=0;
        }
        cout<<a.to_ulong()<<" "<<b.to_ulong()<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
   
    int n;
    while(cin>>n)
    {
        bitset<32>num;
        num=n;
        int out=0;
        int p=31;
        //cout<<num.to_ulong();
        out+=pow(2.0,double(p))*num[7]*-1;//this is sign
        p--;
        for(int i=6;i>=0;i--)
        out+=pow(2.0,double(p--))*num[i];
        
        for(int i=15;i>=8;i--)
        out+=pow(2.0,double(p--))*num[i];
        
        for(int i=23;i>=16;i--)
        out+=pow(2.0,double(p--))*num[i];
        
        for(int i=31;i>=24;i--)
        out+=pow(2.0,double(p--))*num[i];
        
        //cout<<out<<endl;
        cout<<n<<" converts to "<<out<<endl;
    }
    return 0;
}


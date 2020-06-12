#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
   
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int r=k/2;
        int out=r^k;
        cout<<out<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int tableAns[MAX+5];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    tableAns[0]=1;
    for(int i=1;i<=MAX;i++){
        double d=i;
        tableAns[i]=(tableAns[(int)(d-sqrt(d))]%MAX+tableAns[(int)(log(d))]%MAX+tableAns[(int)(d*sin(d)*sin(d))]%MAX)%MAX;
        
    }
    
    int n;
    while(cin>>n&&n!=-1){
      cout<<tableAns[n]<<endl;
    }
    return 0;
}


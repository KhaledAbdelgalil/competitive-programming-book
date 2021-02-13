#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    double n, p;
    while(cin >> n >> p){
       printf("%.lf\n", pow(p, 1.0/n));
    }
  
}



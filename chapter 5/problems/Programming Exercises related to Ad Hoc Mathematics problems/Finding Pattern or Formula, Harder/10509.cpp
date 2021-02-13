#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    double n;
    while(cin >> n && n){
        double a = floor( pow(n, 1/3.0) + 1e-6 );
        double dx = (n - a * a * a) / a / a / 3.0 ;
        printf("%.4f\n", a + dx);
    }
    return 0;
}


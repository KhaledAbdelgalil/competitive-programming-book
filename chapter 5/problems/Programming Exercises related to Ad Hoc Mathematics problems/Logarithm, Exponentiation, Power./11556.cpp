#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    long long n, b;
    while(cin >> n >> b){
        long long ans = pow(2, b + 1) - 1;
        if(ans >= n) cout << "yes" << endl;
        else cout << "no" << endl;
    }
   
    return 0;
}


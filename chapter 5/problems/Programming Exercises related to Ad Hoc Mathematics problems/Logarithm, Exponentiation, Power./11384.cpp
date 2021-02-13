#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    long long n;
    while(cin >> n){
        cout << ceil(log2(n + 1e-6)) << endl;//bring next power so use 1e-6
    }
    return 0;
}


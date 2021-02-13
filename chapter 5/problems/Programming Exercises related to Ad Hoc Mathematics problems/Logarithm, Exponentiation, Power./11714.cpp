#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    long long n;
    while(cin >> n){
        cout << n-1 + (int)log2(n - 1) << endl;//n-1 to get 1st , log2(n) to get second
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    long long n;
    while(cin >> n && n >= 0){
        //every cut add pi * r^2 i.e 25%
        if(n >= 2)cout << n * 25 << "%" << endl;
        else cout << 0 << "%" << endl;
    }
    return 0;
}


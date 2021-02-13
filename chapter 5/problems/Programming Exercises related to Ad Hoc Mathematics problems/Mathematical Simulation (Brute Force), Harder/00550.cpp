#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int base, a, b;
    while(cin >> base >> a >> b){
        int num = a * b;
        int res = 1;
        while(num != a){
            num = (num % base) * b + num / base;
            res++;
        }
        cout << res << endl;
    }
    return 0;
}

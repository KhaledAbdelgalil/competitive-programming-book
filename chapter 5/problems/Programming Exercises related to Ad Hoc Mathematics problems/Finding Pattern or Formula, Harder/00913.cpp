#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    unsigned long long n;
    while(cin >> n){
        unsigned long long oddNumbersTillNow = ( (n + 1) / 2 ) * ( (n + 1) / 2 );
        //series of odd numbers 1 + 3 + 5 + 7 + .... to count their sum use n ^ 2 where n is position of odd number
        unsigned long long ans = oddNumbersTillNow * oddNumbersTillNow - (oddNumbersTillNow - 3) * (oddNumbersTillNow -3 );
        cout << ans << endl;
    }
    return 0;
}


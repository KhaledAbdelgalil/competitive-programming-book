#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    //if you have n = 10 sum is 10 + 5 + 3 + 2 + 2 + 1 + 1 + 1 + 1 + 1
    //which is (10 + 5 + 3) * 2 - 3 * 3
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long ans = 0;
        long long r = sqrt(n);
        for(long long i = 1; i <= r; i++) ans = ans + (n / i);
        ans = ans * 2 - r * r;
        cout << ans << endl;
    }
    return 0;
}

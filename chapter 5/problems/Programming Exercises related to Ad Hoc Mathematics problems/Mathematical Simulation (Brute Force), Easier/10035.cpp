#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!

    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0)break;
        int ans = 0;
        bool have_carry_now = 0;
        while(n || m){
            int digit1 = n % 10;
            int digit2 = m % 10;
            int current_digit = digit1 + digit2 + have_carry_now;
            if(current_digit >= 10){
                have_carry_now = 1;
                ans++;
            }else have_carry_now = 0;
            n = n / 10;
            m = m / 10;
        }
        if(ans == 0) cout << "No carry operation." << endl;
        else if(ans == 1)cout << "1 carry operation." << endl;
        else 
        cout << ans << " carry operations." << endl;
    }
    return 0;
}

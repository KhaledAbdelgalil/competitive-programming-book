#include <bits/stdc++.h>
using namespace std;

long long power_mod(long long x, long long y, long long p)
{
        // Initialize result
        long long res = 1;     
       
        // Update x if it is more  
        // than or equal to p
        x = x % p; 

       if (x == 0) return 0; // In case x is divisible by p;   

        while (y > 0)
        {
            // If y is odd, multiply x
            // with result
            if((y & 1)==1)
                res = (res * x) % p;
    
            // y must be even now
            // y = y / 2
            y = y >> 1; 
            x = (x * x) % p; 
        }
        return res;
}


int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    long long  n, k, mod;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        cin >> n >> k >> mod;
        //answer is (n ^ (k - 1)) * k * sum % mod
        long long ans  = 0;
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            ans =  (ans + x) % mod;
        }
        ans = (((ans * k) % mod) * (power_mod(n, k - 1, mod))) % mod;
        cout << ans << endl;
    } 
    return 0;
}


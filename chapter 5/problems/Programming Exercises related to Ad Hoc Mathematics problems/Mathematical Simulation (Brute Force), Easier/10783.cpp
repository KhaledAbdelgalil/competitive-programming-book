#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin >> t;
   for(int tt = 1; tt <= t; tt++){
       cout << "Case " << tt << ": ";
       int ans = 0;
       int a, b;
       cin >> a >> b;
       for(int i = a; i <= b; i++){
           if(i % 2)ans += i;
       }
       cout << ans << endl;
    }
    return 0;
}

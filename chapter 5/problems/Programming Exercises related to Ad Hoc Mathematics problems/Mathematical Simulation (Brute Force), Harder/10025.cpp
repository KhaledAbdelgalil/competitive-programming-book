#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    bool first = true;
    while(t--){
      if(!first) cout << endl;
      first = false;
      long long k;
      long long n = 1;
      cin >> k;
      k = abs(k);
      for(;;n++){
          //ok if sum is greater than or equal k we are done, but the difference between sum and k should be even?
          //because you will remove half of that difference, to remove the whole difference, here is an example
          //if you want 12, you have 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 that will make you break ,
          // 28 - 12 = 16, if you remove 1 , 7 by making them negative you actually removed 16 not 8 from the whole sum.
          if(n *(n+1) / 2 >= k && (n * (n + 1) / 2 - k ) % 2 == 0)
          break;
      }
      cout << n << endl;
    }
    return 0;
}

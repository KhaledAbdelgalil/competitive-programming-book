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
       cout << "Case #" << tt << ": ";//120 = 12 * 10 = 6 * 20 
       int cnt = 0;
       int a = -1, b = -1, c = -1, d = -1;
       int n;
       cin >> n;
       for(int i = 2; i < n; i++){
           if((n % i == 0)){
               if(a == -1 && b == -1){
                   a = i;
                   b = n / i;
               }else if(i != a && i != b){
                   c = i;
                   d = n / i;
                   break;
               }
           }
       }
       cout << n << " = " << a << " * " << b << " = " << c << " * " << d << endl;
    }
    return 0;
}

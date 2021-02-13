#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    while(t--){
     int n;
     cin >> n;
     double a, b;
     cin >> a >> b;
     double ans = b + n * a;
     for(int i = 0; i < n; i++){
         double c;
         cin >> c;
         ans = ans - 2 * (n - i) * c;
     }
     printf("%.2lf\n", ans/(double)(n + 1));
     if(t)cout << endl;
    }
    return 0;
}

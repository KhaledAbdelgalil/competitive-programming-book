#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int a, b, c, d, l;
    while(cin >> a >> b >> c >> d >> l){
        if(a == 0 && b == 0 && c == 0 && d == 0 && l == 0)break;
        int ans = 0;
        for(int i = 0; i <= l; i++){
            int fn = a * i * i + b * i + c;
            if(fn % d == 0)ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

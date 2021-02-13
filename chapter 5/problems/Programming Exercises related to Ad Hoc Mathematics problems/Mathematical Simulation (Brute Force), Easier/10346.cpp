#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!

    int n, k;
    while(cin >> n >> k){
        if(k > n){
            cout << n << endl;
        }else if(k == n){
            cout << n + 1 << endl;
        }else {
            int ans = 0;
            int butts = 0;
            while(n){//while we can make more cigaretes
                ans += n;
                //you have now n butts
                butts += n;
                n = 0;//you used all cigaretes
                n = butts / k;//you can make n cigaretes from butts
                butts = (butts % k);//these are remaining butts
            }
            cout << ans << endl;
        }
    }
    return 0;
}

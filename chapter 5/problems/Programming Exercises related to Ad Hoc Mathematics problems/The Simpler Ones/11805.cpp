#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n, k, p;
    int test = 1;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k >> p;
        k--;//let numbers of players to start from 0 to n - 1
        k = (k + p) % n;//this is the wanted player , add to it 1 to get player from 1 - > n instead from 0 -> n - 1
        cout << "Case " << test++ << ": " << k + 1 << endl;
    }
    return 0;
}

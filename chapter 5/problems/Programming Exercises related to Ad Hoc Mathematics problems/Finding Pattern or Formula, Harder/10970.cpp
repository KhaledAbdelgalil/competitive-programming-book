#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int  n, m;
    while(cin >> n >> m ){
        //you need to touch every line 
        cout << n * m - 1 << endl;
    }
    return 0;
}


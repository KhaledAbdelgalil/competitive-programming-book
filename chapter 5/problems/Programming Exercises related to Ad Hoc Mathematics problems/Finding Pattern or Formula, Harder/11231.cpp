#include <bits/stdc++.h>
using namespace std;
//Solution: We simply count the number of white squares which has row number and column number both greater than 7 (counting from 1).
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    long long n, m, c;
    while(cin >> n >> m >> c && (n || m || c)){
        if(c == 0)//black
            cout << (n - 7) * (m - 7) / 2<< endl;
        else cout << ((n - 7) * (m - 7) + 1) / 2 << endl;
    }
    return 0;
}


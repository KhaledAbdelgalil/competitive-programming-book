#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    int test = 1;
    while(cin >> n && n > 0){
        cout << "Case " << test++ << ": ";
        cout << ceil(log2(n)) << endl;
    }
   
    return 0;
}


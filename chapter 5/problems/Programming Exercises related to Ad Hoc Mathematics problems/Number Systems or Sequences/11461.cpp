#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int a, b;
    while(cin >> a >> b){
        if(a == 0)break;
        //number of squares < a is sqrt(a-1), number of squares <= b is sqrt(b-1)
        cout << (int)((int)sqrt(b) - (int)sqrt(a - 1)) << endl;
    }
    return 0;
}

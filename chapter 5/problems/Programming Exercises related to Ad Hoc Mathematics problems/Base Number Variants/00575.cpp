#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    string s;
    while(getline(cin, s) && s[0] != '0'){
        long long  ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans = ans + ( (s[i] - '0') * ( pow(2, s.size()-i) - 1) );
        }
        cout << ans << endl;
    }
    return 0;
}

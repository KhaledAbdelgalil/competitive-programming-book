#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    string s;
    while(cin >> s){
        if(s.size() == 1 && s[0] == '0')break;
        int u = s[0] - '0';
        if(s.size() % 2 == 0)u = u * 10 + (s[1] - '0');
        cout << (int)sqrt(u);
        int len = (s.size() - 1) / 2;
        while(len--)cout << 0;
        cout << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        string s1 = s.substr(0, 3);
        string s2 = s.substr(4);
        int n1 = (s1[0] - 'A') * 26 * 26 + (s1[1] - 'A') * 26 + (s1[2] - 'A');
        stringstream ss(s2);
        int n2;
        ss >> n2;
        //cout << n1 <<" " << n2 << endl;
        if(abs(n1 - n2) <= 100)cout << "nice" << endl;
        else cout << "not nice" << endl;
    }
    return 0;
}

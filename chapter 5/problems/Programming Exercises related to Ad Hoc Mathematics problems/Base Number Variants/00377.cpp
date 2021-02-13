#include <bits/stdc++.h>
using namespace std;
//look at problem , you will see that it's a BASE 4 problem
int convertBase4Dec(string s){
    map<char, int>letters;
    letters['V'] = 0;
    letters['U'] = 1;
    letters['C'] = 2;
    letters['D'] = 3;
    int ret = 0;
    for(int i = 0; i < s.size(); i++){
        ret += pow(4, s.size() - i - 1) * letters[s[i]];
    }
    return ret;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    cin >> n;
    cout << "COWCULATIONS OUTPUT" << endl;
    while(n--){
        string a, b, r;
        int n1, n2, res;
        cin >> a >> b;
        n1 = convertBase4Dec(a);
        n2 = convertBase4Dec(b);
        char op;
        for(int i = 0; i < 3; i++){
            cin >> op;
            if(op == 'A')n2 = n1 + n2;
            else if(op == 'L')n2 *= 4;
            else if(op == 'R')n2 /= 4;
        }
        cin >> r;
        res = convertBase4Dec(r);
        if(n2 == res)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}

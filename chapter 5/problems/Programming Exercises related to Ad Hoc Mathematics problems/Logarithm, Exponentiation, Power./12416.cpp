#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    string s;
    while(getline(cin, s)){
        int cnt = 0;
        int max_spaces = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                cnt++;
            }else max_spaces = max(cnt, max_spaces), cnt = 0;
        }
        cout << ceil(log2(max_spaces)) << endl;
    }
   
    return 0;
}


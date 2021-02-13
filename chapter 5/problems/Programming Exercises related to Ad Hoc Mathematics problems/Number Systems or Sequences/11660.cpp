#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    string s;
    int i, j;
    while(cin >> s >> i >> j){
        if(s[0] == '0' && i == 0 && j == 0)break;
        string f = "";
        for(int k = 1; k < i; k++){
            int char_pos = 0;
            string f = "";
            
            while(char_pos < s.size() && char_pos <= j){//we don't want to make more than j chars, as sequence is increasing everytime, i.e will be more than j
                int n = 1;
                char now = s[char_pos];
                char_pos++;
                while(s[char_pos] == now)n++, char_pos++;
                
                f = f + char(n + '0') + now;
                
            }
           // cout << f << endl;
            s = f;
        }
        cout << s[j - 1] << endl;
    }
    return 0;
}

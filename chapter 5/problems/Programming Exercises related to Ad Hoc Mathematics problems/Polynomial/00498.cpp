#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        vector<int>coeff;
        int x;
        while(ss >> x)coeff.push_back(x);
        getline(cin, s);
        stringstream ss2(s);
        bool first = 1;
        while(ss2 >> x){
            if(!first)cout << " ";
            first = 0;
            int ans = 0;
            for(int i = 0; i < coeff.size(); i++){
                ans = ans + pow(x, coeff.size() - i - 1) * coeff[i];
            }
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}


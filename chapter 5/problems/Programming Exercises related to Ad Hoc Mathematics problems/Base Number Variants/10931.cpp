#include <bits/stdc++.h>
using namespace std;
int Binary[33];
void solve(int n){
    int i = 0;
    int bits = 0;
    while(n > 0){
        Binary[i] = n % 2;
        n /= 2;
        bits += Binary[i];
        i++;
    }
    cout << "The parity of ";
    for(int j = i - 1; j >= 0; j--){
        cout << Binary[j];    
    }
    cout << " is " << bits << " (mod 2)." << endl;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    while(cin >> n && n){
        solve(n);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    int test = 1;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector < int > players(n);
        for(int i = 0; i < n; i++)cin >> players[i];
        sort(players.begin(), players.end());
        cout << "Case " << test++ << ": " << players[players.size() / 2] << endl;//answer is median
    }
    return 0;
}

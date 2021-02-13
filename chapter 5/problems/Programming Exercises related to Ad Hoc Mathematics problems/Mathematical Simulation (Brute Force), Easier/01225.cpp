#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!

    //preproccesing.
    int dp[10005][10];
    memset(dp, 0, sizeof dp);
    //solution of base-case n = 1
    dp[1][1] = 1;
    for(int i = 2; i <= 10000; i++){
        for(int j = 0; j <= 9; j++)
            dp[i][j] = dp[i - 1][j];//put numbers till n - 1;
        int k = i;
        while(k){
            int digit = k % 10;
            k = k / 10;
            dp[i][digit] = dp[i][digit] + 1;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n][0];
        for(int i = 1; i <= 9; i++){
            cout << " " << dp[n][i];
        }
        cout << endl;
    }
    return 0;
}

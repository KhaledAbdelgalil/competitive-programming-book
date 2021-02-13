#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    //if we have 3 persons we need 3 * 3 + 1 coconuts to have solution,
    //so if we have 10 coconuts , we brute focre solution till i = sqrt(coconuts)
    //cout << sqrt(10);
    //exit(0);
    int n;
    while(cin >> n && n >= 0){
        int ans = -1;
        for(int i = sqrt(n) + 1 ; i > 0 && ans == -1; i--){
            int coconuts = n;
            int j;
            for(j = 0; j < i; j++){
                if(coconuts % i == 1){//I can give that to the monkey
                    coconuts = (coconuts / i) * (i - 1);//the remainder after this person hid his share
                }else{
                    break;//cannot stasify the critera
                }
            }
            if(j == i && coconuts % i == 0)//the remainder , persons can divide it in the morning equally
                ans = i;
        }
        if(ans > 0){
            cout << n << " coconuts, " << ans << " people and 1 monkey" << endl;
        }else{
            cout << n << " coconuts, no solution" << endl;
        }
    }
    return 0;
}

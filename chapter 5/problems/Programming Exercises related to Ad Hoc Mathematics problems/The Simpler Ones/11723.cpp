#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int R, N;
    int test = 1;
    while(cin >> R >> N){
        if(R == 0 && N == 0)break;
        cout << "Case " << test++ << ": ";
        if(N >= R){
            cout << 0 << endl;
        }else{
            int ans = -1;
            for(int i = 1; i <= 26; i++){
                if(i * N + N >= R){
                    ans = i;
                    break;
                }
            }
            if(ans != -1) cout << ans << endl;
            else cout << "impossible" << endl;
        }
    }
    return 0;
}

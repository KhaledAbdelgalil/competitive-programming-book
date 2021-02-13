#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!

    //you can improve the performance by using dynamic programming to precalculate, and segment tree instead of linear search.
    int n , m;
    while(cin >> n >> m){
        cout << n << " " << m << " ";
        int ans = 1;
        for(int i = min(n, m), e = max(n, m); i <= e; i++)//you can improve that linear search by using segement tree data-structure
        {
            int j = i;
            int c = 1;    
            while(j > 1){
                if(j % 2)j = 3 * j + 1;
                else j = j / 2;
                c++;
            }
            ans = max(ans, c);
        }
        cout << ans << endl;
    }
    
    return 0;
}

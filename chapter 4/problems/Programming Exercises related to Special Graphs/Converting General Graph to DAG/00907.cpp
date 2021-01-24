#include <bits/stdc++.h>
using namespace std;
int walking[605];
int mem[605][305];
int n, k;
int solve(int pos, int nights_left){
    if(pos == n)return 0;//you have reached
    if(nights_left == 0)//you have reached your maximum number of nights complete to destination walking
    {
        int dist = 0;
        for(int i = pos; i < n; i++){
            dist += walking[i];
        }
        return dist;
    }
    
    int &best = mem[pos][nights_left];
    if(best == -1){
        best = 2e9;
        int dist = walking[pos];
        for(int next = pos + 1; next <= n && best > dist; dist += walking[next], ++next){
            best = min(best, max(dist//here I decide to continue walking
            , solve(next, nights_left - 1)// decide to stay
            ));
        }
    }
    return best;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    while(cin >> n >> k){
        memset(mem, -1, sizeof mem);
        n++;
        for(int i = 0; i < n; i++)cin >> walking[i];
        cout  << solve(0, k)<<endl;
    }
    return 0;
}

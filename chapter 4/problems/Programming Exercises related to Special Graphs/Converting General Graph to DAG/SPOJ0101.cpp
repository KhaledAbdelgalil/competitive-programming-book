#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int gridToll[55][55];
int gridTime[55][55];
pair<int,int> mem[55][1005];
int n, t;
pair<int,int> solve(int curr, int timeLeft){
    if(timeLeft < 0)return {INF, INF};//we don't want this state
    if(curr == n - 1)//you reached your market ,no more money or time
        return {0, 0};
    if(mem[curr][timeLeft].first != -1 && mem[curr][timeLeft].second != -1)return mem[curr][timeLeft];
    
    pair <int, int> ans  = make_pair(INF, INF);
    for(int i = 0; i < n; i++){
        if(curr != i){
            pair < int, int > nextCity = solve(i, timeLeft - gridTime[curr][i]);
            if(nextCity.first + gridToll[curr][i] < ans.first){
                ans.first = nextCity.first + gridToll[curr][i];
                ans.second = nextCity.second + gridTime[curr][i];
            }
        }
    }
    return mem[curr][timeLeft] = ans;
}
int main()
{
    /*std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    */
    while(cin >> n >> t){
        if(n == 0 && t == 0)break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
            cin >> gridTime[i][j];
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
            cin >> gridToll[i][j];
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= t; j++)
            mem[i][j].first = -1, mem[i][j].second = -1;
        }
        pair <int, int > ans = solve(0, t);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}

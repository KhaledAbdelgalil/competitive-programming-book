#include <bits/stdc++.h>
using namespace std;
int mem[27][31];
int choose0[27];
int choose1[27];
bool special[27];
bool used[27];
int n, m;
int solve(int pos, int moves){
    if(moves == 0){
        if(special[pos])return 1;//this is a way to win.
        else return 0;//this is not a way to win.
    }
    if(mem[pos][moves] != -1)return mem[pos][moves];
    int &ans = mem[pos][moves];
    ans =  solve(choose0[pos], moves - 1) + solve(choose1[pos], moves - 1);
    return ans;
}
int main()
{
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    while(cin >> n){
        memset(used, 0 ,sizeof used);
        memset(mem, -1, sizeof mem);
        for(int i = 0; i < n; i++){
            char u, ch0, ch1, spec;
            cin >> u >> ch0 >> ch1 >> spec;
            used[u - 'A'] = true;
            choose0[u - 'A'] = (int)(ch0 - 'A');
            choose1[u - 'A'] = (int)(ch1 - 'A');
            if(spec == 'x')special[u - 'A'] = 1;
            else special[u - 'A'] = 0;
        }
        cin >> m;
        if(used[0])//there is A in graph
        cout << solve(0, m) << endl;
        else cout << 0 << endl;
    }
    return 0;
}

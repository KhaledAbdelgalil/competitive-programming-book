//962
#include <bits/stdc++.h>
using namespace std;
set<int> precalculate;
map <int, int>mp;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    for(int i = 1; i <= 1001; i++){
        for(int j = i; j <= 1001; j++)
        {
            int val = i * i * i + j * j * j;
            mp[val]++;
            if(mp[val] > 1)precalculate.insert(val);
        }
    }
    
    int n, rg;
    while(cin >> n >> rg){
        vector<int> ans;
        for(auto it = precalculate.begin(); it != precalculate.end(); it++){
            if(*it >= n & *it <= n + rg)ans.push_back(*it);
            else if(*it > n + rg)break;
        }
        if(ans.size() == 0)cout << "None" << endl;
        else{
            for(int i = 0; i < ans.size(); i++)cout << ans[i] << endl;
        }
    }
    return 0;
}

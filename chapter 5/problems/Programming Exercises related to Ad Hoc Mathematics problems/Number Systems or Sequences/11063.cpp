#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int test = 1;
    int n;
  
    while(cin >> n){
        bool valid = true;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] <= 0)valid = false;
            else if(i !=0 && a[i] <= a[i - 1])valid = false;
        }
        if(valid){
            map<int, bool>mp;
            for(int j = 0; j < n && valid; j++){
                for(int i = 0; i <= j && valid; i++){
                    if(mp.find(a[i] + a[j]) == mp.end())mp[a[i] + a[j]] = true;
                    else valid = false;
                }
            }
        }
        
        if(valid)cout << "Case #" << test++ << ": It is a B2-Sequence." << endl;
        else cout << "Case #" << test++ << ": It is not a B2-Sequence." << endl;
        cout << endl;
    }
    return 0;
}

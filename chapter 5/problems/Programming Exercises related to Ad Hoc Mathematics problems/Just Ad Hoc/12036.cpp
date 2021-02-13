#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    //use pigeon hole principle:
    //if a value has repetition more than number of cols , it will appear more than one time in a column
    
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int n;
        cin >> n;
        int values[105] = {0};
        bool stable = true;
        int x;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> x;
                values[x]++;
                if(values[x] > n)stable = false;
            }
        }
        cout << "Case " << tt << ": ";
        if(stable)cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}

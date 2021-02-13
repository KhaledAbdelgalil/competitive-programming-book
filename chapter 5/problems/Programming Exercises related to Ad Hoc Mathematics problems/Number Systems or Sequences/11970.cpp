#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    //perfect squares, chache them
    int perfectCache[35000];
    for(int i = 0; i < 35000; i++){
        perfectCache[i] = i * i;
    }
    
    int n;
    int t;
    cin >> t;
    //in order that X/sqrt(n- X) be integer , X should be integer and sqrt(n-x) should be integer
    //so n-x should be perfect square, so let sqrt(n - x) = i so n-x = i * i and x = n - i * i
    // also x % sqrt(n-x)i.e x % i is zero
   
    for(int tt = 1; tt <= t; tt++){
        cin >> n;
        cout << "Case " << tt << ":";
        vector < int > ans;
        for(int i = 1; perfectCache[i] < n; i++){
            //perfectCache[i] is i * i
            int x = n - perfectCache[i];
            if(x % i ==0){
                ans.push_back(x);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}

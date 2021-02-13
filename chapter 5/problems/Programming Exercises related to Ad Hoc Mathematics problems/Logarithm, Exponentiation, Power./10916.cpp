#include <bits/stdc++.h>
using namespace std;
//if you have 16 bits , the maximum number will be 2 ^ 16 , let this number to be x
//log(x) = 16 * log(2);
//factorial of n is n * (n -1) * (n-2) ... *1
//LOG(x * y) = LOG(x) + LOG(y)
//that's all you need to solve this problem
int years_to_bits[2161];
int ans[2161];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int f = 4;
    for(int i = 1960; i <= 2160; i += 10)
    {
        years_to_bits[i] = f;
        f *= 2;
    }
    /*
    double xLog = 16 * log(2);
    double ans = log(1);
    int i = 1;
    while(ans <= xLog){
        i++;
        ans += log(i);
    }
    cout << i - 1;
    */
    for(int i = 1960; i <= 2160; i += 10){
        
        double xLog = years_to_bits[i] * log(2);
        double s = log(1);
        int n = 1;
        while(s <= xLog){
            n++;
            s += log(n);
        }
        for(int j = i; j <= i + 9; j++)
        ans[j] = n - 1;
    }
    int y;
    while(cin >> y && y){
        cout << ans[y] << endl;
    }
    return 0;
}


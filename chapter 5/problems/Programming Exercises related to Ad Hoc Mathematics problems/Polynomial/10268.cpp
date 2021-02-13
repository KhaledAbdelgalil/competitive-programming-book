#include <bits/stdc++.h>
using namespace std;
long long Pow(long long x, long long y) {
    if(y == 0)
        return 1;
    if(y&1)
        return x*Pow(x*x, y/2);
    else
        return Pow(x*x, y/2);
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    string s;
    string num;
    long long x, y;
    while(getline(cin, num)){
        stringstream ss2(num);
        ss2 >> y;
        getline(cin, s);
        stringstream ss(s);
        vector<long long>coeff;
        while(ss >> x)coeff.push_back(x);
        long long ans = 0;
        for(long long i = 0; i < coeff.size(); i++){
           if(coeff.size() - i - 1 != 0)
               ans = ans + (coeff.size() - i - 1) * Pow(y, coeff.size() - i - 2) * coeff[i];//use custom power in case of long long/int
        }
        cout << ans << endl;
    }
    return 0;
}


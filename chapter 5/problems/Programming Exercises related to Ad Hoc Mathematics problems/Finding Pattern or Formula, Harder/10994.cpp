#include <bits/stdc++.h>
using namespace std;
map<long long, long long > mem;
long long summation(long long n){
    return (n * (n + 1) )/ 2;
}
long long sumF(long long n){
    if(n == 0)return 0;
    else if(mem.find(n) != mem.end())return mem[n];
    else if(n < 10)return mem[n] = summation(n);
    else return mem[n] = sumF( n / 10) + (n / 10 * 45) + summation(n % 10);
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    long long lower, upper;
    while(cin >>  lower >> upper){
        if(lower < 0 && upper < 0)break;
        cout << sumF(upper) - sumF(lower - 1) << endl;
    }
    return 0;
}


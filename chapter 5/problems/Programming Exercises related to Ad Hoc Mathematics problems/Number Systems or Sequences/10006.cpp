//10006
#include <bits/stdc++.h>
using namespace std;
/*
A Carmicheal Number has the Following Property :
i)  It must not be a Prime Number .// we need sieve()
ii) It should be pass the Fermat's Test .
hat means For the given N you need to implement the equetion : (a^n) mod n = a .// we need power_mod()
*/
bool isNotPrime[65000];
void sieve(){
    for(int i = 2; i < 65000; i++){
        if(isNotPrime[i] == 0){
            for(int j = 2; i * j < 65000; j++){
                isNotPrime[i * j] = 1;
            }
        }
    }
}
long long bigMod(long long x, long long y, long long mod){
    long long ans = 1;
    while(y) {
		if(y&1) {
			ans *= x;
			ans %= mod;
		}
		x = x*x, x %= mod;
		y >>= 1;
	}
	return ans;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    memset(isNotPrime, 0, sizeof isNotPrime);
    isNotPrime[1] = isNotPrime[0] = 1;
    sieve();//to get prime numbers
    long long n;
    while(cin >> n && n){
        if(isNotPrime[n] == 0){//it's prime so it's normal
            cout << n << " is normal." << endl;
        }else{//it's not prime, let's apply Fermat's test, if passed it's Carmichael number.
          
          bool Carmichael = true;
          for(long long i = 2; i <= n - 1; i++){
              if(bigMod(i, n, n) != i){
                  Carmichael = false;
                  break;
              }
          }
          if(Carmichael)cout << "The number " << n << " is a Carmichael number." << endl;
          else  cout << n << " is normal." << endl;
        }
    }
    return 0;
}

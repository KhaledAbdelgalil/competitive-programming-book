#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!

    int n;
    cout << "PERFECTION OUTPUT" << endl;
    
    while(cin >> n && n){
        int sum = 0;
        for(int i = 1; i < n; i++){
            if(sum > n)break;//abundant
            else if(n % i == 0){//divisor
                sum += i;
            }
        }
        cout << setw(5) << n << "  ";
        if(sum > n){
            cout << "ABUNDANT" << endl;
        }else if(sum == n){
             cout << "PERFECT" << endl;
        }else if(sum < n){
            cout << "DEFICIENT" << endl;
        }
    }
    
    
    
    
    cout << "END OF OUTPUT" << endl;
    
    return 0;
}

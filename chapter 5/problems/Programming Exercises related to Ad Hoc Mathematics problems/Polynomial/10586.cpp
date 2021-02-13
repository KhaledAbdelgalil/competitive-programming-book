#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n, k;
    while(cin >> n >> k){
        if(n == -1 && k == -1)break;
        vector <int> a(n + 1,0);
        for(int i = 0; i <= n; i++)
            cin >> a[i];
        if( k == 0 ){
               cout << 0 << endl;//remindar is 0
        }else{
            while(n >= k){
                if(a[n] == 0){
                    n--;
                    continue;//this term is not found
                }
              
                 a[n - k] -= a[n];
                a[n] = 0;
               
               
            }
            cout << a[0];
            for(int i = 1; i <= n; i++) cout << " " << a[i];
            cout << endl;
        }
        
    }
    return 0;
}


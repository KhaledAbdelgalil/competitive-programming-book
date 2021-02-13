#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        std::vector<int>v(n);
        int total = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            total += v[i];
        }
        int numbers = 0;
        for(int i = 0; i < n; i++){
            if(v[i] * n > total)numbers++;
        }
        double perc = (double(numbers) * 100.0)/ double(n) ;
        //cout << setprecision(5) << perc << endl;
        printf("%.3f%\n", perc);
    }
    return 0;
}

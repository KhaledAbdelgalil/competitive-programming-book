#include <bits/stdc++.h>
using namespace std;
/*int f91(int n){
    if(n >= 101)return n -10;
    else return f91( f91(n + 11) );
}*/
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    /*for(int i = 0; i <= 100; i++){
        if(f91(100) != 91)cout << "not 91" << endl;
    }*/
    int n;
    while(cin >> n && n){
        cout << "f91(" << n <<") = ";
        if(n >= 101)cout << n - 10 << endl;
        else cout << 91 << endl;
    }
    return 0;
}

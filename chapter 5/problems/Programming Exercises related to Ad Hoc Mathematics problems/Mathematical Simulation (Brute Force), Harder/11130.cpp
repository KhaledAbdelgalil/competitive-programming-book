#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    double a, b, v, A, s;
    while(cin >> a >> b >> v >> A >> s){
        if(a == 0 && b == 0 && v == 0 && A == 0 && s == 0)break;
        double vx = v * cos(A * pi / 180);
        double vy = v * sin(A * pi / 180);
        double ax = -vx / s;
        double ay = -vy / s;
        double dx = vx * s + 0.5 * ax * s * s;
        double dy = vy * s + 0.5 * ay * s * s;
        double totalX = dx + a / 2;
        double totalY = dy + b / 2;
        int countVertical = totalX / a;
        int countHorizontal = totalY / b;
        cout << countVertical << " " << countHorizontal << endl;
    }
    return 0;
}

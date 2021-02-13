//974
#include <bits/stdc++.h>
using namespace std;
bool Kaprekar[40005];
void preprocessing(){
    Kaprekar[9] = Kaprekar[45] = Kaprekar[55] = true;
   for(int i = 91; i <= 40000; i++){
       int square = i * i;
       string sq;
       sq = to_string(square);
       for(int j = 0; j < sq.size(); j++){
           //split
           string num1 = sq.substr(0, j);
           string num2 = sq.substr(j);
           stringstream ss1(num1);
           stringstream ss2(num2);
           int n1, n2;
           ss1 >> n1;
           ss2 >> n2;
           if(n1 && n2 && n1 + n2 == i){
               Kaprekar[i] = true;
               break;
           }
       }
   }
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    memset(Kaprekar, 0, sizeof Kaprekar);
    preprocessing();   
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        cout << "case #" << tt << endl;
        bool flag = 0;
        int l, h;
        cin >> l >> h;
        for(int i = l; i <= h; i++){
            if(Kaprekar[i]){
                flag = 1;
                cout << i << endl;
            }
        }
        if(flag == 0)cout << "no kaprekar numbers" << endl;
        if(tt < t)cout << endl;
    }
    return 0;
}



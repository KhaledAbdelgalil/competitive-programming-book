#include <bits/stdc++.h>
using namespace std;
string maze[65];
int r,w;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin >> t;
    
    while(t--){
        cin >> r >> w;
        cin.ignore();
        for(int i = 0; i < r; i++){
             getline(cin,maze[i]);
        }
        char orientation = 'N';
        int initr,initc;
        cin >>initr >> initc;
        initc--;
        initr--;
        cin.ignore();
        string s;
         bool flagQ = 0;
        while(getline(cin,s) && s != ""){
            int i;
            for(i = 0; i < s.size(); i++){
                if(s[i] == 'F'){
                  int newR,newC;
                  if(orientation == 'N')newR = initr - 1,newC = initc;
                  else if(orientation == 'E')newR = initr,newC = initc + 1;
                  else if (orientation == 'S')newR = initr + 1, newC = initc;
                  else if(orientation == 'W')newR = initr, newC = initc - 1;
                  if(newR >= 0 && newR < r && newC >= 0 && newC < w && maze[newR][newC] != '*')//ok, you can move
                    initr = newR, initc = newC;
                }else if(s[i] == 'Q'){
                    flagQ = 1;
                    break;
                }else if(s[i] == 'R'){
                    if(orientation == 'N')orientation = 'E';
                    else if(orientation == 'E')orientation = 'S';
                    else if(orientation == 'S')orientation = 'W';
                    else if(orientation == 'W')orientation = 'N';
                }else if(s[i] == 'L'){
                    if(orientation == 'N')orientation = 'W';
                    else if(orientation == 'W')orientation = 'S';
                    else if(orientation == 'S')orientation = 'E';
                    else if(orientation == 'E')orientation = 'N';
                }
            }
            if(flagQ){
                cout << initr + 1 <<" "<< initc + 1<<" "<<orientation<<endl;
                break;
            }
        }
        if(t)cout<<endl;
    }
    return 0;
}

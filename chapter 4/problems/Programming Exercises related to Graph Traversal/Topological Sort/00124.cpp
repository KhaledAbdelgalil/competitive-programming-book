#include <bits/stdc++.h>
using namespace std;
bool dep[30][30];//dep[i][j] i.e i appears before j , or in other words j depends on i 
bool vis[30];
bool found_in_input[30];
int cnt_inputs = 0;
void backtrack(string s){
    if(s.size() != cnt_inputs){
        for(int i = 0; i <= 25; i++){
            if(vis[i] == false && found_in_input[i] == true){
                bool ok = true;
                for(int j = 0; j <= 25 && ok; j++){
                    if(vis[j] == false && found_in_input[j] == true){
                        if(dep[j][i])//j mush appear before i so visit it before(we cannot visit i now)
                            ok = false;
                    }
                }
                if(ok){
                    vis[i] = true;
                    backtrack(s + char(i + 'a'));
                    vis[i] = false;
                }
            }
        }
    }else{
        cout << s << endl;
    }
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    string s;
    bool first = true;
    while(getline(cin, s)){
        if(!first)puts("");
        first = false;
        memset(found_in_input, false, sizeof found_in_input);
        memset(vis, false, sizeof vis);
        memset(dep, false, sizeof dep);
        cnt_inputs = 0;
        stringstream is1(s);
        char x, y;
        while(is1 >> x){
            cnt_inputs++;
            found_in_input[x - 'a'] = true;
        }
        getline(cin, s);
        stringstream is2(s);
        while(is2 >> x >> y){
            dep[x - 'a'][y - 'a'] = true;
        }
        backtrack("");
    }
    return 0;
}

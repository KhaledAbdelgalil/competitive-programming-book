#include <bits/stdc++.h>
using namespace std;
char previous[30];
map <char,int> ans;
//the idea is to count the degree of node
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int test = 1;
    int t;
    cin>>t;
    string s;
    
    while(t--){
        ans.clear();
        cin>>s;
        int p = -1;
        for(int i = 0; i < s.size(); i++ ){
           if( p == -1){
               char e1 = s[ i ],e2 = s[ i + 1];
               ans[e1]++;
               ans[e2]++;
               previous[++p] = e1;
               previous[++p] = e2;
               i++;
           }else{
               //you are closing this sprinkle
               if(previous[p] == s[i]){
                   p--;
               }else{
                   ans[previous[p]]++;
                   ans[s[i]]++;
                   previous[++p] = s[i];
               }
           }
        }
        cout<<"Case "<<test++<<endl;
        for(auto it = ans.begin(); it != ans.end(); it++){
            cout << it -> first << " = "<< it -> second << endl;
        }
    }
    return 0;
}


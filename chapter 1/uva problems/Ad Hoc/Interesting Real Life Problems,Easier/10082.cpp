#include <bits/stdc++.h>
#include <string>

using namespace std;
string keyboard="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    string s;
    while(getline(cin,s))
    {
        //cout<<s<<endl;
        for(int i=0;i<s.size();i++)
        {
            int n=keyboard.find(s[i]);
            if(n==-1)
            cout<<s[i];
            else cout<<keyboard[n-1];
        }
        cout<<endl;
    }
    
}

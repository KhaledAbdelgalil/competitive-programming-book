#include <bits/stdc++.h>
#include<fstream>
using namespace std;

int main()
{
    /*std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        do{
            cout<<s<<endl;
        }while(next_permutation(s.begin(),s.end()));
        cout<<endl;
    }

    return 0;
}


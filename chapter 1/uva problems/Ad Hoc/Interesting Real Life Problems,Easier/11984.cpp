#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    /*std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        double c,deltaf;
        cin>>c>>deltaf;
        cout<<"Case "<<i<<": ";
        printf("%.2f", c+(deltaf*5.0/9.0));
        cout<<endl;
    }
}

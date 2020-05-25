#include <bits/stdc++.h>
using namespace std;


bool cmp(const char& a,const char& b)
{
    if(tolower(a)<tolower(b))return true;
    if(tolower(a)==tolower(b)&&a<b)return true;
    return false;
}

int main()
{
    /*
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    int t;
    cin>>t;
    
    while(t--)
    {
        string temp;
        cin>>temp;
        sort(temp.begin(),temp.end(),cmp);
        do{
            cout<<temp<<endl;
        }while(next_permutation(temp.begin(),temp.end(),cmp));
    }
    
    return 0;
}


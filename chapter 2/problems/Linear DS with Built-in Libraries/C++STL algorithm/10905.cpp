#include <bits/stdc++.h>
using namespace std;


bool cmp(const string &a,const string &b)
{
    if(a+b>=b+a)return true;
    return false;
}
int main()
{
    
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    int n;
    while(cin>>n&&n)
    {
        std::vector<string>v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        
        sort(v.begin(),v.end(),cmp);
        
        for(int i=0;i<v.size();i++)cout<<v[i];
        
        cout<<endl;
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 

    int n;
    while(cin>>n&&n){
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x)v.push_back(x);
        }
        if(v.size()){
            cout<<v[0];
            for(int i=1;i<v.size();i++)cout<<" "<<v[i];
            cout<<endl;
        }
        else cout<<0<<endl;
    }
    
    return 0;
}


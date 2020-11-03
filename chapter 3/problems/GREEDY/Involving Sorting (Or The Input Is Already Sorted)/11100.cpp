#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int n;
    while(cin>>n&&n){
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        int curr=1;
        int maxx=0;
        for(int i=0;i<n;i++){
            if(v[i]==v[i+1]){
                curr++;
                continue;
            }
            maxx=max(maxx,curr);
            curr=1;
        }
        maxx=max(maxx,curr);
        cout<<maxx<<endl;
        for(int i=0;i<maxx;i++){
            cout<<v[i];
            for(int j=i+maxx;j<n;j+=maxx)cout<<" "<<v[j];
            cout<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}


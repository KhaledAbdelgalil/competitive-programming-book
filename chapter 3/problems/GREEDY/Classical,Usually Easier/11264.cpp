#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int coins=1;
        vector<long long>v(n);
        vector<bool>taken(n);
        for(int i=0;i<n;i++)cin>>v[i];
        long long sum=v[0];
        for(int i=1;i<n-1;i++){
            if(sum+v[i]<v[i+1]){
                sum+=v[i];
                coins++;
            }
        }
        cout<<coins+1<<endl;
    }
    return 0;
}


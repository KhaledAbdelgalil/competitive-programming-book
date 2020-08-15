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
        std::vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int sum=0;
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<i;j++)if(v[i]>=v[j])sum++;
        }
        cout<<sum<<endl;
    }

    return 0;
}


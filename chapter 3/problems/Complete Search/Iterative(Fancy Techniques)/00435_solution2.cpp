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
        vector<int>v(n);
        int half=0;
        for(int i=0;i<n;i++)cin>>v[i],half+=v[i];
        half/=2;
        vector<int>pow_index(n,0);
        //create all combinations
        for(int i=0;i<(1<<n);i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j))sum+=v[j];
            }
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    if(sum>half&&sum-v[j]<=half)pow_index[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<"party "<<i+1<<" has power index "<<pow_index[i]<<endl;
        }
        cout<<endl;
        
    }
    return 0;
}


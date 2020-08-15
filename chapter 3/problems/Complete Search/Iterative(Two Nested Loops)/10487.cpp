#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int test=1;
    int n;
    while(cin>>n&&n)
    {
        cout<<"Case "<<test++<<":"<<endl;
        std::vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        int q;
        cin>>q;
        while(q--){
            int f;
            cin>>f;
            int sum_close=v[0]+v[1];
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(abs(v[i]+v[j]-f)<abs(sum_close-f))sum_close=v[i]+v[j];
                }
            }
            
            
            
            cout<<"Closest sum to "<<f<<" is "<<sum_close<<"."<<endl;
        }
    }
   
    return 0;
}


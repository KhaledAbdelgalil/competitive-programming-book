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
        int r;
        cin>>r;
        std::vector<int>relatives(r);
        for(int i=0;i<r;i++){
            cin>>relatives[i];
        }
        sort(relatives.begin(),relatives.end());
        //best solution is median
        int median=relatives[r/2];
        if(r%2==0)median=(median+relatives[r/2-1])/2;
        int ans=0;
        for(int i=0;i<r;i++)ans+=abs(median-relatives[i]);
        cout<<ans<<endl;
    }

    return 0;
}


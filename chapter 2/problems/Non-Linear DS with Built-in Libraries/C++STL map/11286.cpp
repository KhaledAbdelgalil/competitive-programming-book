#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
    int n;
    map< vector<int> ,int> mp;
    while(cin>>n&&n)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int>v(5);
            cin>>v[0]>>v[1]>>v[2]>>v[3]>>v[4];
            sort(v.begin(),v.end());
            ans=max(ans,++mp[v]);
        }
        if(mp.size()==n)
        cout<<n<<endl;
        else 
        {
            map< vector<int> , int > ::iterator it;
           
            
            //handling if there are say 3 students take same combination and another 3 students take 
            //another combination so ans is 6 not 3
            int groups=0;
            for(it=mp.begin();it!=mp.end();it++)if(it->second==ans)groups++;
            cout<<ans*groups<<endl;
        }
        mp.clear();
    }
    
}

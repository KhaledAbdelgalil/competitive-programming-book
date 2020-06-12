#include <bits/stdc++.h>
using namespace std;


int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,r;
        cin>>n>>r;
        std::vector<bool>coins(n+1,false);
        
        for(int i=0;i<r;i++)
        {
            int p;
            char w;
            cin>>p;
            vector<int>weighted_coins(p*2);
            for(int i=0;i<2*p;i++)
            cin>>weighted_coins[i];
            cin>>w;
            if(w=='=')
            {
                for(int i=0;i<2*p;i++)
                coins[weighted_coins[i]]=true;
            }
            else {
                for(int i=1;i<=n;i++)
                if(find(weighted_coins.begin(),weighted_coins.end(),i)==weighted_coins.end())
                coins[i]=true;
            }
        }
        
        int false_coin,cnt_false=0;
        for(int i=1;i<=n;i++)
        if(coins[i]==false)false_coin=i,cnt_false++;
        
        if(cnt_false==1)cout<<false_coin<<endl;
        else cout<<0<<endl;
        if(t)cout<<endl;
    }
   
   return 0;
}


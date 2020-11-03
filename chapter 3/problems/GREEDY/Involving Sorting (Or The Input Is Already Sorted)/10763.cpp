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
        mp.clear();
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            //x leave y enter
            mp[x]++;
            mp[y]--;
        }
        bool can=1;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end()&&can;it++){
            if(it->second)//if value is positive/negative i.e student didn't find one for him
            can=0;
        }
        if(can)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    

    return 0;
}


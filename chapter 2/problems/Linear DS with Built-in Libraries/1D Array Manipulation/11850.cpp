#include <bits/stdc++.h>
using namespace std;


int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
   int n;
   while(cin>>n&&n)
   {
        std::vector<int>v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        
        sort(v.begin(),v.end());
        
        bool can=1;
        int pos=0;
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>1422)break;
            else if(v[i]-pos>200){can=0;break;}
            pos=v[i];
        }
        if(1422-pos>100)can=0;
        if(can)cout<<"POSSIBLE"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
   }
   
   return 0;
}


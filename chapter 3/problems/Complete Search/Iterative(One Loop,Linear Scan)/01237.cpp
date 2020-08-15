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
        std::vector< pair <string,pair<int,int> > > v(n);
        string ans="";
        
        for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second.first>>v[i].second.second;
        int q;
        cin>>q;
        while(q--){
            int p;
            cin>>p;
            for(int i=0;i<n;i++){
                if(p>=v[i].second.first&&p<=v[i].second.second){
                    if(ans=="")ans=v[i].first;
                    else {
                        ans="UNDETERMINED";
                        break;
                    }
                }
            }
            if(ans=="")cout<<"UNDETERMINED"<<endl;
            else cout<<ans<<endl;
            ans="";
        }
        
        if(t)cout<<endl;
    }
   
    
    return 0;
}


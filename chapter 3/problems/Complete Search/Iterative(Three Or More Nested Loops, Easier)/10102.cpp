#include <bits/stdc++.h>
using namespace std;

int main(){
   
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
  
    int n;
    while(cin>>n){
        std::vector<pair<int,int> >threes,ones;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            char s;
            cin>>s;
            if(s=='1')ones.push_back({i,j});
            else if(s=='3')threes.push_back({i,j});
        }
        
        int ans=-1;
        for(int i=0;i<ones.size();i++){
            int minn=abs(threes[0].first-ones[i].first)+abs(threes[0].second-ones[i].second);
            
            for(int j=0;j<threes.size();j++){
                if(abs(threes[j].first-ones[i].first)+abs(threes[j].second-ones[i].second)<minn)minn=abs(threes[j].first-ones[i].first)+abs(threes[j].second-ones[i].second);
            }
            ans=max(ans,minn);
        }
        cout<<ans<<endl;
    }
    return 0;
}


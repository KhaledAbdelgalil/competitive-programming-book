#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int main(){
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    while(cin>>n){
        std::vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        int m;
        cin>>m;
        int diff=m;
        int ans1,ans2;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            vector<int>::iterator it=lower_bound(v.begin(),v.end(),m-v[i]);
            if(it!=v.end()&&(v[i]+*it)==m&&abs((*it) - v[i])<diff)ans1=v[i],ans2=*it,diff=abs((*it)-v[i]);
        }
        cout<<"Peter should buy books whose prices are "<<min(ans1,ans2)<<" and "<<max(ans1,ans2)<<"."<<endl<<endl;
    }
    return 0;
}


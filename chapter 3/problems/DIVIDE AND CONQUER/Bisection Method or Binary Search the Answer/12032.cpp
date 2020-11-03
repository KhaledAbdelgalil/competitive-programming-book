#include <bits/stdc++.h>
using namespace std;
std::vector<int>v;
bool can(int max_k){
    if(v[0]>max_k)return 0;
    if(v[0]==max_k)max_k--;
    for(int i=0;i<v.size()-1;i++){
        if(v[i+1]-v[i]>max_k)return 0;
        if(v[i+1]-v[i]==max_k)max_k--;
    }
    return 1;
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        int n;
        cin>>n;
        v.resize(n);
        int low=0;
        for(int j=0;j<n;j++){
            cin>>v[j];
            if(j!=0)low=max(low,v[j]-v[j-1]);
            else low=max(low,v[j]);
        }
        int mid;
        int high=low*n;
        for(int i=0;i<50;i++){
            mid=(low+high)/2;
            if(can(mid)){
                high=mid;
            }else {
                low=mid;
            }
        }
        if(can(mid))
        cout<<mid<<endl;
        else cout<<mid+1<<endl;
    }
    return 0;
}


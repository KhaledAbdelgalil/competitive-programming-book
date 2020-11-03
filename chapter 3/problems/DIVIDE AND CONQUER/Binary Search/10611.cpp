#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    map<char,vector<int>>mp_indices;

   
    int n,q;
    while(cin>>n){
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        cin>>q;
        while(q--){
            int val;
            cin>>val;
            vector<int>::iterator it=upper_bound(v.begin(),v.end(),val-1);
            if(it==v.begin())cout<<"X ";
            else cout<<*(it-1)<<" ";
            it=lower_bound(v.begin(),v.end(),val+1);
            if(it==v.end())cout<<"X";
            else cout<<*it;
            cout<<endl;
        }
    }
    return 0;
}


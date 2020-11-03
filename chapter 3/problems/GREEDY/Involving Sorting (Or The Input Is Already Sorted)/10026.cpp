#include <bits/stdc++.h>

using namespace std;
bool cmp(const pair< int, pair<int,int> > &A,const pair< int, pair<int,int> >& B){
    if(A.second.second*B.second.first>B.second.second*A.second.first)return true;
    else if(A.second.second*B.second.first==B.second.second*A.second.first)return A.first<B.first;
    return false;
}
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
        std::vector< pair< int, pair<int,int> > >v(n);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            v[i]={i,{x,y}};//id time fine
        }
        sort(v.begin(),v.end(),cmp);
        cout<<v[0].first+1;
        for(int i=1;i<n;i++)cout<<" "<<v[i].first+1;
        cout<<endl;
        if(t)cout<<endl;
    }
    return 0;
}


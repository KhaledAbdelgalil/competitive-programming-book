#include <bits/stdc++.h>
using namespace std;
#define MAX pow(2.0,42)
vector<long long>v;
int main(){
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!

    for(long long i=1;i*3<=MAX;i*=2)
        for(long long j=1;i*j<=MAX;j*=3){
            v.push_back(i*j);
        }
    /*for(long long i=1;i<=MAX;i*=2)v.push_back(i);
    for(long long j=1;j<=MAX;j*=3)v.push_back(j);*/
    sort(v.begin(),v.end());
    /*for(int i=0;i<v.size();i++)cout<<v[i]<<endl;
    return 0;*/
    long long n;
    while(cin>>n&&n){
       vector<long long>::iterator it=lower_bound(v.begin(),v.end(),n);
       cout<<*it<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>v;

int mem[22][2002];
int solve(int id,int remW)
{
    if(remW<0)return 0;
    if(id==n){
        if(remW)return 0;
        return 1;
    }
    int &ans=mem[id][remW];
    if(ans!=-1)return ans;
    
    if(remW<v[id])ans=solve(id+1,remW);
    else ans=solve(id+1,remW)||solve(id+1,remW-v[id]);
    return ans;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        v.clear();
        string s;
        getline(cin,s);
        stringstream ss(s);
        int f;
        int sum=0;
        while(ss>>f){
            v.push_back(f);
            sum+=f;
        }
        memset(mem,-1,sizeof mem);
        n=v.size();
        bool ans=0;
        if(sum%2==0)//we may find a solution
        ans=solve(0,sum/2);
        
        (ans)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }

    return 0;
}


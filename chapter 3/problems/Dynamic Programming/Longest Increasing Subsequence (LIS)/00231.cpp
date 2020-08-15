#include <bits/stdc++.h>
using namespace std;

std::vector<int>v;
map< pair<int,int> ,int>dp;
int solution(int i,int p){
    if(i==v.size())return 0;
    if(dp.find({i,p})!=dp.end())return dp[{i,p}];
    int sol1=solution(i+1,p);
    int sol2=0;
    if(p==-1)//first element to take
        sol2=solution(i+1,v[i])+1;
    else if(v[i]<=p)
    sol2=solution(i+1,v[i])+1;
    return dp[{i,p}]=max(sol1,sol2);
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    int test=1;
    while(cin>>n){
        if(n==-1){
            if(test!=1)cout<<endl;
            cout<<"Test #"<<test++<<":"<<endl;
            cout<<"  maximum possible interceptions: "<<solution(0,-1)<<endl;//-1 represent first element
            v.clear();
            dp.clear();
            cin>>n;
            if(n==-1)break;
        }
        v.push_back(n);
    }

    return 0;
}


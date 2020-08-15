#include <bits/stdc++.h>
using namespace std;

vector<int>v ;
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    int test=1;
    while(cin>>n){
        if(n==-1)break;
        v.push_back(n);
        while(cin>>n&&n!=-1)v.push_back(n);
        
        int dp[1000]={};
        dp[0]=0;//assume not take at beginning
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++)
                if(v[j]<v[i]&&dp[j]<dp[i]+1)dp[j]=dp[i]+1;
        }
        int maxx=0;
        for(int i=0;i<v.size();i++)maxx=max(dp[i],maxx);
        if(test!=1)cout<<endl;
        cout<<"Test #"<<test++<<":"<<endl;
        cout<<"  maximum possible interceptions: "<<1+maxx<<endl;//1 for me and maxx for missles can be formed before me
        v.clear();
        
    }

    return 0;
}


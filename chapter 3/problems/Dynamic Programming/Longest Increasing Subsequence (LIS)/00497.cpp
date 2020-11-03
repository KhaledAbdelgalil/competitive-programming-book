#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin>>t;
    cin.ignore();
    cin.ignore();
    while(t--){
        int n;    
        vector<int>v;
        string s;
        while(getline(cin,s)&&s!=""){
            stringstream ss(s);
            ss>>n;
            v.push_back(n);
        }
        //cin.ignore();
        //cin.ignore();
        vector<int>dp;
        dp.assign(v.size(),1);//base case is myself 1 
        
        int maxx=1;
        for(int j=1;j<v.size();j++){
            for(int i=0;i<j;i++){
                if(v[j]>v[i])dp[j]=max(dp[j],dp[i]+1);//I can add myself to sequence that contain i
            }
            maxx=max(dp[j],maxx);
        }
        //cout<<maxx<<endl;
        int start_index=v.size()-1;
        while(start_index>=0&&dp[start_index]!=maxx)start_index--;
        vector<int>ans(maxx);
        int curr=maxx-1;
        ans[curr--]=v[start_index];
        start_index--;
        for(int i=start_index;i>=0;i--){
            if(dp[i]==curr+1&&v[i]<ans[curr+1])ans[curr--]=v[i];
        }
        cout<<"Max hits: "<<maxx<<endl;
        for(int i=0;i<maxx;i++)cout<<ans[i]<<endl;
        if(t)cout<<endl;
        
    }
    return 0;
}


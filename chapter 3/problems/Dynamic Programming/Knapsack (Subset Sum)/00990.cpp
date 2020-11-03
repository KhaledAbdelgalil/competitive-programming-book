#include <bits/stdc++.h>
using namespace std;
int weights[35],values[35];
int dp[35][1005];//row0 represents considering first item only,row1 considering first+second items
bool taken[35];//represents items we take
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t,w;
    bool first=1;
    while(cin>>t>>w){
        //t => represents weight you have and you can take from it 
        if(!first)//don't print the first time you enter
           cout<<endl;//print newline between two testcases
        first=0;
        
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>weights[i]>>values[i];
            weights[i]=3*w*weights[i];//adjust the actual weight
        }
        
        memset(dp,0,sizeof dp);
        memset(taken,0,sizeof taken);
                
        //let's build the base case in dp(having only item1)
        for(int j=0;j<=t;j++){
            if(weights[0]<=j)dp[0][j]=values[0];//it's better to take if we have weight more than item1 weight 
        }
        //build the other dps
        for(int i=1;i<n;i++){
            for(int j=0;j<=t;j++){
                if(j>=weights[i])//we can take this treasure
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i]]+values[i]);
                else dp[i][j]=dp[i-1][j];//we cannot take this treasure 
            }
        }
        int takes=0;
        int i=n-1;//let's start from end and backtrack to get answer
        int we=t;
        //while we are looping in items or if dp[i][we]=0 it means that previous items are not taken
        while(i>=0&&dp[i][we]!=0){
            if(i==0){
                if(dp[i][we]==values[i]){
                    takes++;
                    taken[i]=1;
                }
                else taken[i]=0;
            }
            else if(weights[i]<=we&&dp[i][we]==dp[i-1][we-weights[i]]+values[i])//we take it 
                taken[i]=1,takes++,we=we-weights[i];
            else if(dp[i][we]==dp[i-1][we])//so we don't take it
                taken[i]=0;
            i--;
        }
        //printing answer
        cout<<dp[n-1][t]<<endl;
        cout<<takes<<endl;
        for(int i=0;i<n;i++){
            if(taken[i])cout<<weights[i]/(3*w)<<" "<<values[i]<<endl;
        }
        
    }

    return 0;
}


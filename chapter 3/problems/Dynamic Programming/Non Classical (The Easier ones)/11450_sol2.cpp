#include <bits/stdc++.h>
using namespace std;
int prices[25][25];
int models[25];
int m,g;
bool reachable[2][205];//need 2 rows to process problems.
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin>>t;
    while(t--){
        
        cin>>m>>g;
        for(int i=0;i<g;i++){
            cin>>models[i];
            for(int j=0;j<models[i];j++)cin>>prices[i][j];
        }
        memset(reachable,0,sizeof reachable);
        int curr=0;
        int prev=1;
        //base case 
        for(int i=0;i<models[0];i++){
            if(m-prices[0][i]>=0)//we can reach g+1 with money
                reachable[0][m-prices[0][i]]=true;
        }
        
        curr=1;
        prev=0;
        for(int i=1;i<g;i++){
            memset(reachable[curr],0,sizeof reachable[curr]);//remove processing of before previous we don't need it
            //see if remains money from g-1
            for(int money=0;money<=m;money++){
                if(reachable[prev][money]){
                    //process current g
                    for(int j=0;j<models[i];j++){
                        if(money-prices[i][j]>=0)
                        reachable[curr][money-prices[i][j]]=true;
                    }
                }
            }
            swap(curr,prev);
        }
        int money=0;
        for(money=0;money<=m;money++)if(reachable[prev][money])break;
        if(money==m+1)cout<<"no solution"<<endl;
        else cout<<m-money<<endl;
    }
    return 0;
}


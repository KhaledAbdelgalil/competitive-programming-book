#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n,m;
    while(cin>>n>>m){
        if(n==1&&m==1)break;
        vector<int>num={0,1,1};
        vector<int>den={1,1,0};
        int a=num[1];
        int b=den[1];
        string ans="";
        while(n*b!=m*a){
            //move right
            if(n*b>m*a){
                int newLeftnum=num[1];
                int newLeftden=den[1];
                int newMidnum=num[1]+num[2];
                int newMidden=den[1]+den[2];
                num[0]=newLeftnum;
                den[0]=newLeftden;
                num[1]=newMidnum;
                den[1]=newMidden;
                ans=ans+'R';
            }
            else if(n*b<m*a){
                int newRightnum=num[1];
                int newRightden=den[1];
                int newMidnum=num[1]+num[0];
                int newMidden=den[1]+den[0];
                num[2]=newRightnum;
                den[2]=newRightden;
                num[1]=newMidnum;
                den[1]=newMidden;
                ans=ans+'L';
            }
            a=num[1];
            b=den[1];
        }
        cout<<ans<<endl;
    }
    return 0;
}


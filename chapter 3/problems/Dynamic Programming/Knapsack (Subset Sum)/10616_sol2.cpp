#include <bits/stdc++.h>
using namespace std;
int N,Q,D,M;
long long  arr[205];
long long mem[44][205][205];//D sum id taken
long long solution(int id,int taken,long long  sum=0){
    if(taken<0)return 0;
    if(id>N)return 0;
    if(id==N){
        return (taken==0)&&(sum%D==0);
    }
    //to start sum from zero as it's signed
    long long &ans=mem[sum+20][id][taken];
    if(ans!=-1)return ans;
    
    long long ans1=solution(id+1,taken,sum);
    long long s=(sum+arr[id]%D)%D;
    long long ans2=solution(id+1,taken-1,s);
    ans=ans1+ans2;
    return ans;
    
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    int test=1;
    while(cin>>N>>Q){
        if(N==0&&Q==0)break;
        cout<<"SET "<<test++<<":"<<endl;
        for(int i=0;i<N;i++)cin>>arr[i];
        int query=1;
        while(Q--){
            memset(mem,-1,sizeof mem);//every D has a different mem
            cin>>D>>M;
            cout<<"QUERY "<<query++<<": ";
            cout<<solution(0,M)<<endl;
        }
    }
    
    
    
    return 0;
}


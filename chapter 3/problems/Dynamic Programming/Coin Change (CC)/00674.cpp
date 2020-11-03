#include <bits/stdc++.h>
using namespace std;
long long mem[6][8005];//the coin_index total_rem_money
long long coins[5]={1,5,10,25,50};

long long count_ways(int index,int rem){
    if(index>=5)return 0;//no ways more
    if(rem<0)return 0;//negative money no way to make it
    if(rem==0)return 1;//ok this a way 
    if(mem[index][rem]!=-1)return mem[index][rem];
    
    return mem[index][rem]=count_ways(index+1,rem)//take from next coins
                            +count_ways(index,rem-coins[index]);//take from this coin
}
int main(){
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n;
    memset(mem,-1,sizeof mem);
    while(cin>>n){
        cout<<count_ways(0,n)<<endl;
    }

    return 0;
}


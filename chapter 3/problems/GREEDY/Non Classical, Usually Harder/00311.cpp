#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    int arr[7];
    while(cin>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5]>>arr[6]&&(arr[1]||arr[2]||arr[3]||arr[4]||arr[5]||arr[6])){
        int ans=0;
        ans+=arr[6];
        ans+=arr[5];
        arr[1]-=arr[5]*11;//remaining of 5*5 use it for 1*1
        ans+=arr[4];
        //take remaining of 4*4 for 2*2 for now
        arr[2]-=5*arr[4];
        
        //handle 3*3
        ans+=(arr[3]+3)/4;
        if(arr[3]%4==1){
            arr[2]-=5;
            arr[1]-=7;
        }
        else if(arr[3]%4==2){
            arr[2]-=3;
            arr[1]-=6;
        }
        else if(arr[3]%4==3){
            arr[2]-=1;
            arr[1]-=5;
        }
        
        //handle 2
        if(arr[2]>0){
            ans+=(arr[2]+8)/9;//get number required for 2*2
            arr[2]-=9*((arr[2]+8)/9);//there are remaining arr[2]* 4
        }
        //handle 1
        if(arr[2]<0){//you have given 2*2 more than it need
            arr[1]+=arr[2]*4;
        }
        if(arr[1]>0){
            ans+=(arr[1]+35)/36;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}


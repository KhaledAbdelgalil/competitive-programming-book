#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    while(t--){
       int D,I;
       cin>>D>>I;
       //if I is odd it's moving left at first time 
       //if I is even it's moving right at first time
       
       int p=1;
       int n=(1<<D)-1;
       //while last ball at right bottom is less than max ball id
       while(2*p+1<=n){
        if(I%2)//odd move left
            p=2*p;
        else p=2*p+1;//move right
        I=(I+1)/2;
       }
       cout<<p<<endl;
    //why I=(I+1)/2?
    /*
    let's take examples to understand :
    if ball is 1
    at first move left as I%2=1 so p=2*p then I=2/2=1 i.e always move left which is TRUE
    if ball is 2
    at first move right as I%2=0 so p=2*p+1 then I=1 always move left after that which is True 
    if ball is 3
    at first move left then right then continue left 
    if ball is 4
    move right then right then continue left so equation is deduced by induction.
    
    */
    }
    cin>>t;
    return 0;
}


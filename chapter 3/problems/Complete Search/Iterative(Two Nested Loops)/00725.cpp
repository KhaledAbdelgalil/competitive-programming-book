#include <bits/stdc++.h>
using namespace std;
int n;
bool valid(int s1,int s2){
    int sz1=log10(s1)+1;
    int sz2=log10(s2)+1;
    if(sz1==sz2&&sz1==4)return 0;//a and f will be zero and will not be different
    set<int>digits;
    bool flag_s1=0;
    for(int i=0;i<sz1;i++){
        digits.insert(s1%10);
        if(s1%10==0)flag_s1=1;
        s1/=10;
    }
    bool flag_s2=0;
    for(int i=0;i<sz2;i++){
        digits.insert(s2%10);
        if(s2%10==0)flag_s2=1;
        s2/=10;
    }
    if(flag_s2==flag_s1&&flag_s1==1)return 0;
    if(sz2==4){
        if(flag_s1)return 0;
        else if(flag_s2)return 0;
        else digits.insert(0);
    }
    return digits.size()==10;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    //cout<<valid(12345,6789);
    int first = 1;
    while(cin>>n&&n){
        if(!first)
            puts("");
        first = 0;
        bool flag=0;
        for(int s2=1000;s2*n<=98765;s2++){
            int s1=s2*n;
            if(valid(s1,s2)){
                 printf("%05d / %05d = %d\n", s1, s2, n);
                flag=1;
            }
        }
        if(!flag){
            printf("There are no solutions for %d.\n", n);
        }
        
    }

    return 0;
}


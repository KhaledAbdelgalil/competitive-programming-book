
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    std::vector<int>v_h(20000,0);
    int l,h,r;
    int r_max=0;
    while(cin>>l>>h>>r){
        for(int i=l;i<r;i++)v_h[i]=max(h,v_h[i]);
        r_max=max(r,r_max);
    }
    int i=0;
    while(v_h[i]==0)i++;
    while(1){
        int h=v_h[i];
        cout<<i<<" "<<h;
        while(v_h[i]==h)i++;
        if(i>r_max)break;
        cout<<" ";
    }
    cout<<endl;
    return 0;
}


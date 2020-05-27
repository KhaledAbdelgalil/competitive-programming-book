#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int sum,diff;
        cin>>sum>>diff;
        if(sum<diff)cout<<"impossible"<<endl;
        else 
        {
            int m1,m2;
            m1=(sum+diff)/2;
            m2=m1-diff;
            if(m1!=(double(sum)+double(diff))/2.0)cout<<"impossible"<<endl;
            else
            cout<<m1<<" "<<m2<<endl;
        }
    }
    
}

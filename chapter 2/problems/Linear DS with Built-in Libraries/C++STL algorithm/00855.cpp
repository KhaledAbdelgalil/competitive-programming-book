#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
   
    int t;
    cin>>t;
    while(t--)
    {
        int s,a,f;
        cin>>s>>a>>f;
        std::vector<int>cornersx(f),cornersy(f);
        for(int i=0;i<f;i++)
        cin>>cornersx[i]>>cornersy[i];
        
        sort(cornersx.begin(),cornersx.end());
        sort(cornersy.begin(),cornersy.end());
        
        int index=f/2;
        if(f%2==0)index--;
        
        cout<<"(Street: "<<cornersx[index]<<", Avenue: "<<cornersy[index]<<")"<<endl;
        
        
    }
   
    return 0;
}


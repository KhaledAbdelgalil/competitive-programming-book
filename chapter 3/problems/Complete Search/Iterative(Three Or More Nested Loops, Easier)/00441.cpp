#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n;
    bool first=1;
    while(cin>>n&&n){
        if(first==0)cout<<endl;
        first=0;
        std::vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        
        for(int i=0;i<n-5;i++)
            for(int j=i+1;j<n-4;j++)
                for(int k=j+1;k<n-3;k++)
                    for(int l=k+1;l<n-2;l++)
                        for(int m=l+1;m<n-1;m++)
                            for(int o=m+1;o<n;o++)
                                cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<" "<<v[l]<<" "<<v[m]<<" "<<v[o]<<endl; 
       
    }

    return 0;
}


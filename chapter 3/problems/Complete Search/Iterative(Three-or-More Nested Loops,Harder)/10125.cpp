
#include <bits/stdc++.h>

using namespace std;

int main()
{
     std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int n;
    while(cin>>n&&n){
        std::vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        sort(v.rbegin(),v.rend());
        bool flag=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int d=v[i];
            for(int j=0;j<n;j++){
                if(j==i)continue;
                int a=v[j];
                for(int k=0;k<n;k++){
                    if(k==i)continue;
                    if (k==j)continue;
                    int b=v[k];
                    for(int f=0;f<n;f++){
                        if(f==i)continue;
                        if(f==j)continue;
                        if(f==k)continue;
                        int c=v[f];
                        if(a+b+c==d){
                            ans=d;
                            flag=1;
                            break;
                        }
                    }
                    if(flag)break;
                }
                if(flag)break;
            }
            if(flag)break;
        }
        if(flag)cout<<ans<<endl;
        else cout<<"no solution"<<endl;
    }

    return 0;
}


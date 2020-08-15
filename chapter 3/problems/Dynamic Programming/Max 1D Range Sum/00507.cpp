#include <bits/stdc++.h>
using namespace std;



int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        int s;
        cin>>s;
        
        int st=-1,e=-1;
        int maxx=0;
        int tmp=1;
        int sum=0;
        for(int i=2;i<=s;i++)
        {
            int x;
            cin>>x;
            sum+=x;
            if(sum<0)sum=0,tmp=i;
            else{
                if(sum==maxx&&i-tmp>e-st){
                    st=tmp,e=i;
                    maxx=sum;
                }
                else if(sum>maxx){
                    maxx=sum,st=tmp,e=i;
                }
            }
        }
        if(st==-1&&e==-1){
            cout<<"Route "<<tt<<" has no nice parts"<<endl;
        }
        else cout<<"The nicest part of route "<<tt<<" is between stops "<<st<<" and "<<e<<endl;
    }

    return 0;
}


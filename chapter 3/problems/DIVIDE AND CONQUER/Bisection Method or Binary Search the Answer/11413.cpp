#include <bits/stdc++.h>
using namespace std;
std::vector<int>vessels;
int n,m;
bool can(int maxCapacity){
    int containers=0;
    int curr_cont=0;
    for(int i=0;i<n;i++){
        //we can take all containers of same capacity = maxCapacity,no problem
        if(vessels[i]>maxCapacity)return 0;
        if(vessels[i]+curr_cont>maxCapacity){
            curr_cont=0;
        }
        if(curr_cont==0)containers++;//start another container
        if(containers>m)return 0;
        curr_cont+=vessels[i];
    }
    return 1;
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    while(cin>>n>>m){
        vessels.resize(n);
        int high=0,low=0;
        for(int i=0;i<n;i++)cin>>vessels[i],high+=vessels[i],low=max(low,vessels[i]);
        //cout<<low<<" "<<high<<endl;
        if(m>=n){
            cout<<low<<endl;
            continue;
        }
        int mid;
        for(int i=0;i<50;i++){
            mid=(low+high)/2;
            if(can(mid))//be more greedy you can let's decrease number more and more
            {
                high=mid;
            }
            else {
                low=mid;
            }
        }
        if(can(mid))
        cout<<mid<<endl;
        else cout<<mid+1<<endl;
    }

    return 0;
}


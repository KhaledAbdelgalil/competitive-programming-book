#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> >time_to_complete_this_soldier_task; 
bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    int t1=max(a.first+a.second,a.first+b.first+b.second);
    int t2=max(b.first+b.second,b.first+a.first+a.second);
    return t1<t2;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int n,m;
    int test=1;
    while(cin>>n&&n){
        time_to_complete_this_soldier_task.resize(n);
        for(int i=0;i<n;i++)cin>>time_to_complete_this_soldier_task[i].first>>time_to_complete_this_soldier_task[i].second;
        //best sort
        sort(time_to_complete_this_soldier_task.begin(),time_to_complete_this_soldier_task.end(),cmp);
        int ans=0;
        int temp=0;
        for(int i=0;i<n;i++){
            temp+=time_to_complete_this_soldier_task[i].first;
            ans=max(temp+time_to_complete_this_soldier_task[i].second,ans);
        }
        cout<<"Case "<<test++<<": ";
        cout<<ans<<endl;
    }
    return 0;
}

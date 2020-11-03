#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> >tasks_time;
bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    int totalTime1=a.first+a.second;
    int timeTemp=a.first+b.first;
    if(totalTime1<=timeTemp)totalTime1=timeTemp+b.second;
    else totalTime1+=b.second;
    
    
    int totalTime2=b.first+b.second;
    timeTemp=b.first+a.first;
    if(totalTime2<=timeTemp)totalTime2=timeTemp+a.second;
    else totalTime2+=a.second;
    
    if(totalTime1<totalTime2)return true;
    return false;
    
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int n;
    while(cin>>n){
        tasks_time.resize(n);
        for(int i=0;i<n;i++)cin>>tasks_time[i].first;
        for(int j=0;j<n;j++)cin>>tasks_time[j].second;
        sort(tasks_time.begin(),tasks_time.end(),cmp);
        //here tasks is best sorted so let's simulate
        
        int curr_time=tasks_time[0].first+tasks_time[0].second;
        int temp1=tasks_time[0].first;
        for(int i=1;i<n;i++){
          temp1+=tasks_time[i].first;
          if(curr_time<=temp1)curr_time=temp1+tasks_time[i].second;
          else curr_time+=tasks_time[i].second;
        }
        cout<<curr_time<<endl;
    }
    
    return 0;
}


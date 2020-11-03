#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    int L,G;
    while(cin>>L>>G){
        if(L==0&&G==0)break;
        vector< pair<int,int> >stations;
        for(int i=0;i<G;i++){
            int x,r;
            cin>>x>>r;
            if(x+r<0||x-r>L)//out_of_range remove it from beginning
            continue;
            stations.push_back({x-r,x+r});//push interval covered by this station
        }
        
        int curr_station=0;
        int countt=0;
        int wanted_x=0;
        vector< pair<int,int> >ans(stations.size());
        sort(stations.begin(),stations.end());
        while(wanted_x<L&&curr_station<stations.size()){
            ans[countt].second=0;
            for(;stations[curr_station].first<=wanted_x&&curr_station<stations.size();curr_station++)
            if(stations[curr_station].second>ans[countt].second)ans[countt]=stations[curr_station];
            if(ans[countt].second==wanted_x)break;
            wanted_x=ans[countt].second;
            countt++;
        }
        if(wanted_x>=L){
            cout<<G-countt<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}


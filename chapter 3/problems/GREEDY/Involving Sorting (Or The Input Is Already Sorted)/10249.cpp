#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
   
    int m,n;
    while(cin>>m>>n){
        if(n==0&&m==0)break;
        vector< pair<int,int> >team_members(m);//number of members  id
        for(int i=0;i<m;i++)cin>>team_members[i].first,team_members[i].second=i;
        sort(team_members.rbegin(),team_members.rend());
        vector<int>tables_capacity(n);
        for(int i=0;i<n;i++)cin>>tables_capacity[i];
        
        bool flag_can=1;
        vector< vector<int> >ans(m);//each vector contain a team (i.e tables for team members)
        for(int i=0;i<m&&flag_can;i++){
            int req_different_tables=team_members[i].first;
                for(int j=0;j<n&&req_different_tables>0;j++){
                    if(tables_capacity[j]>0){
                        req_different_tables--;
                        tables_capacity[j]--;
                        ans[team_members[i].second].push_back(j+1);
                    }
                }
            if(req_different_tables>0)flag_can=0;
        }
        
        if(flag_can){
            cout<<1<<endl;
            for(int i=0;i<m;i++){
                cout<<ans[i][0];
                for(int j=1;j<ans[i].size();j++)cout<<" "<<ans[i][j];
                cout<<endl;
            }
        }
        else cout<<0<<endl;
    }

    return 0;
}


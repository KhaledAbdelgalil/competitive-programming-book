#include <bits/stdc++.h>
using namespace std;

int number;
struct team{
    int teamNo;
    int problems_penalty[10]={0};
    int problems_solved=0;
    int total_penalty=0;
};
bool team_cond(const struct team &a)
{
    if(a.teamNo==number)return true;
    return false;
}

bool cmp(const struct team &a,const struct team &b)
{
    if(a.problems_solved>b.problems_solved)return true;
    else if(a.problems_solved==b.problems_solved&&a.total_penalty<b.total_penalty)return true;
    else if(a.problems_solved==b.problems_solved&&a.total_penalty==b.total_penalty&&a.teamNo<b.teamNo)return true;
    return false;
}
int main()
{
    
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
   
    int t;
    cin>>t;
    cin.ignore();
    string s;
    getline(cin,s);
    while(t--)
    {
        getline(cin,s);
        std::vector<struct team>teams;
        do
        {
            stringstream ss(s);
            int teamno,problemno,timesubmitted;
            char state;
            ss>>teamno>>problemno>>timesubmitted>>state;
            number=teamno;
            struct team teamNow;
            auto it=find_if(teams.begin(),teams.end(),team_cond);
            if(it!=teams.end())
            {
                if(state=='C'){
                    if((*it).problems_penalty[problemno]!=-1)
                    (*it).total_penalty+=(*it).problems_penalty[problemno]+timesubmitted,(*it).problems_solved+=1;
                    (*it).problems_penalty[problemno]=-1;
                }
                else if(state=='I')
                {
                    if( (*it).problems_penalty[problemno]!=-1)//is not solved before
                    (*it).problems_penalty[problemno]+=20;
                }
            }
            else 
            {
                teamNow.teamNo=teamno;
                if(state=='C')
                {
                    teamNow.total_penalty+=timesubmitted;
                    teamNow.problems_solved=1;
                    teamNow.problems_penalty[problemno]=-1;//solved
                    teams.push_back(teamNow);
                }
                else if(state=='I') 
                {
                    teamNow.problems_penalty[problemno]+=20;
                    teams.push_back(teamNow);
                }
                else teams.push_back(teamNow);
                
            }
        }while(getline(cin,s)&&s!="");
        
        sort(teams.begin(),teams.end(),cmp);
        for(int i=0;i<teams.size();i++)
        {
            cout<<teams[i].teamNo<<" "<<teams[i].problems_solved<<" "<<teams[i].total_penalty<<endl;
        }
        if(t)cout<<endl;
    }
    return 0;
}


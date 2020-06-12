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
bool cmp2(const string &s1,const string &s2)
{
    int index1=s1.find(":");
    index1--;
    int index2=s2.find(":");
    index2--;
    string f1=s1.substr(index1,4);
    string f2=s2.substr(index1,4);
    if(f1<f2)return true;
    else if(f1==f2)
    {
        if(s1[s1.size()-1]=='N'&&s2[s2.size()-1]=='Y')return true;
    }
    return false;
}
int main()
{
    
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
   
    int t;
    string s;
    std::vector<struct team>teams ;
   cin>>t;
   cin.ignore();
   cin.ignore();
    while(t--)
    {
        teams.clear();
        int last=0;
        vector<string>strings;
        
        while(getline(cin,s)&& s[0]!='\0')
        {
            strings.push_back(s);
        }
        sort(strings.begin(),strings.end(),cmp2);
        for(int i=0;i<strings.size();i++)
        {
                s=strings[i];
                stringstream ss(s);
                int teamno,timesubmitted;
                string time_string;
                char state,problemno;
                ss>>teamno>>problemno>>time_string>>state;
                //cout<<teamno<<problemno<<time_string<<state;
                int h=(time_string[0]-'0');
                int m=(time_string[2]-'0')*10+(time_string[3]-'0');
                timesubmitted=m+h*60;
                number=teamno;
                if(last<number)last=number;
                struct team teamNow;
                auto it=find_if(teams.begin(),teams.end(),team_cond);
                if(it!=teams.end())
                {
                    if(state=='Y'){
                        if((*it).problems_penalty[problemno-'A']!=-1)
                        (*it).total_penalty+=(*it).problems_penalty[problemno-'A']+timesubmitted,(*it).problems_solved+=1;
                        (*it).problems_penalty[problemno-'A']=-1;
                    }
                    else if(state=='N')
                    {
                        if( (*it).problems_penalty[problemno-'A']!=-1)//is not solved before
                        (*it).problems_penalty[problemno-'A']+=20;
                    }
                }
                else 
                {
                    teamNow.teamNo=teamno;
                    if(state=='Y')
                    {
                        teamNow.total_penalty+=timesubmitted;
                        teamNow.problems_solved=1;
                        teamNow.problems_penalty[problemno-'A']=-1;//solved
                        teams.push_back(teamNow);
                    }
                    else if(state=='N') 
                    {
                        teamNow.problems_penalty[problemno-'A']+=20;
                        teams.push_back(teamNow);
                    }
                }
            
            
            
           
        }
        for(int i=1;i<=last;i++)
        {
            number=i;
            auto it=find_if(teams.begin(),teams.end(),team_cond);
            if(it==teams.end())
            {
                struct team f;
                f.teamNo=i;
                teams.push_back(f);
            }
                
        }
        cout<<"RANK TEAM PRO/SOLVED TIME"<<endl;
        int lastRank=1;
        sort(teams.begin(),teams.end(),cmp);
            for(int i=0;i<teams.size();i++)
            {
                if(i==0)
                {
                    printf("%4d %4d",lastRank,teams[i].teamNo);
                }            
                else if(teams[i].problems_solved==teams[i-1].problems_solved&&teams[i].total_penalty==teams[i-1].total_penalty)
                {
                    printf("%4d %4d",lastRank,teams[i].teamNo);
                }
                else
                lastRank=i+1,printf("%4d %4d",lastRank,teams[i].teamNo);
                
                if(teams[i].problems_solved) printf("    %-7d %4d\n",teams[i].problems_solved,teams[i].total_penalty);
                else cout<<endl;
            }
        
        if(t)cout<<endl;
    
    }
    return 0;
}

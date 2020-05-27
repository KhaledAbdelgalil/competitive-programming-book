#include <bits/stdc++.h>
using namespace std;

int calc(string t1,string t2)
{
    int diff;
    int time2=((t2[0]-'0')*10+(t2[1]-'0'))*60+((t2[3]-'0')*10+(t2[4]-'0'));
    int time1=((t1[0]-'0')*10+(t1[1]-'0'))*60+((t1[3]-'0')*10+(t1[4]-'0'));
    return time2-time1;
}

int time_calc_in_min(string t1)
{
    return ((t1[0]-'0')*10+(t1[1]-'0'))*60+((t1[3]-'0')*10+(t1[4]-'0'));
}
string change_to_time(int t)
{
    int hours=t/60+10;
    int mins=t%60;
    string s="12:00";
    s[0]=char(hours/10+'0');
    s[1]=char(hours%10+'0');
    s[2]=':';
    s[3]=char(mins/10+'0');
    s[4]=char(mins%10+'0');
    return s;
}
int main()
{
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    int n;
    int f=0;
    while(cin>>n)
    {
        
        f++;
        std::vector<bool>timeTable(481,true);    
        
        while(n--)
        {
            string t1,t2,name;
            cin>>t1>>t2;
            getline(cin,name);
            
            for(int i=time_calc_in_min(t1)-600;i<time_calc_in_min(t2)-600;i++)
            timeTable[i]=false;
        }
        
        
        int maxTime=-1;
        int start_in_min;
        
        for(int i=0;i<480;i++)
        {
            if(timeTable[i])
            {
                int st=i;
                int cnt=0;
                while(i<480&&timeTable[i])cnt++,i++;
                if(cnt>maxTime)maxTime=cnt,start_in_min=st;
            }
            
        }
        //cout<<maxTime<<endl<<start_in_min<<endl;
        
        string start;
        start=change_to_time(start_in_min);
        
        
        cout<<"Day #"<<f<<": the longest nap starts at "<<start<<" and will last for ";
        if(maxTime>=60)
        cout<<maxTime/60<<" hours and "<<maxTime%60<<" minutes."<<endl;
        else cout<<maxTime<<" minutes."<<endl;
        
        
    }
    
}

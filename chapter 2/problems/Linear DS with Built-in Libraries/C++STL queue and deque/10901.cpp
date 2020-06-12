#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

bool cmp(const pair<int,int>&a,const pair<int,int>&b)
{
    if(a.first<b.first)return true;
    return false;
}

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
    int t;
    cin>>t;
    while(t--)
    {
        int cars,can_load,minutes_taken;
        cin>>can_load>>minutes_taken>>cars;
        std::queue< pair<int,int> >qleft ,qright;
        for(int i=0;i<cars;i++)
        {
            int m;
            string s;
            cin>>m>>s;
            if(s=="left")qleft.push({i,m});
            else qright.push({i,m});
        }
        
        char pos='l';
        int current_time=0;
        int takens_nw=0;
        vector<pair<int,int> > outt;
        while(1)
        {
            takens_nw=0;
            if(qleft.empty()&&qright.empty())break;
            if(pos=='l')
            {
                for(int i=0;i<can_load;i++)
                {
                    if(qleft.empty())break;
                    int front=qleft.front().second;
                    if(front>current_time)break;
                    outt.push_back({qleft.front().first,current_time+minutes_taken});
                    qleft.pop();
                    takens_nw++;
                }
            }
            else
            {
                for(int i=0;i<can_load;i++)
                {
                    if(qright.empty())break;
                    int front=qright.front().second;
                    if(front>current_time)break;
                    outt.push_back({qright.front().first,current_time+minutes_taken});
                    qright.pop();
                    takens_nw++;
                }
            }
            if(takens_nw==0)
            {
                if(qleft.empty())
                {
                    current_time=max(qright.front().second,current_time);
                    if(pos=='l')current_time+=minutes_taken;
                    pos='r';
                }
                else if(qright.empty())
                {
                    current_time=max(qleft.front().second,current_time);
                    if(pos=='r')current_time+=minutes_taken;
                    pos='l';
                }
                else if(qleft.front().second<qright.front().second)
                {
                    current_time=max(qleft.front().second,current_time);
                    if(pos=='r')current_time+=minutes_taken;
                    pos='l';
                }
                else if(qleft.front().second>qright.front().second)
                {
                    current_time=max(qright.front().second,current_time);
                    if(pos=='l')current_time+=minutes_taken;
                    pos='r';
                }
                else
                {
                    current_time=max(current_time,qright.front().second);
                }
            }
            else
            {
                if(pos=='l')pos='r';
                else pos='l';
                current_time+=minutes_taken;
            }
        }
       //cout<<"REACHED"<<endl;
       sort(outt.begin(),outt.end(),cmp);
       for(int i=0;i<outt.size();i++)
       cout<<outt[i].second<<endl;
       if(t)cout<<endl;
    }
   
   return 0;
}


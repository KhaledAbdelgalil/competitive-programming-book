#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int n;
double L[10],G[10],Y[10],R[10];
bool can_pass(int speed,int i){
    double timee=60.0*60.0*L[i]/double(speed);
    timee=fmod(timee,G[i]+Y[i]+R[i]);
    return timee<=G[i]+Y[i];
}
bool is_goodSpeed(int speed){
    for(int i=0;i<n;i++){
        if(!can_pass(speed,i))return 0;
    }
    return 1;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int cases=0;
    while(cin>>n&&n!=-1){
        
        std::vector<int>ans;
        for(int i=0;i<n;i++)cin>>L[i]>>G[i]>>Y[i]>>R[i];
        
        for(int speed=30;speed<=60;speed++){
            if(is_goodSpeed(speed))           
                ans.push_back(speed);
        }
        //Case 1: 30, 32-33, 36-38, 41-45, 48-54, 59-60
        cout<<"Case "<<++cases<<": ";
        for(int i=0;i<ans.size();){
            bool range=0;
            int prev=ans[i];
            cout<<prev;
            i++;
            while(1){
                if(i==ans.size())break;
                if(ans[i]==prev+1){range=1,prev=ans[i];i++;}
                else break;
            }
            if(range)cout<<"-"<<prev;
            if(prev!=ans[ans.size()-1]){
                cout<<", ";
            }
        }
        if(ans.size()==0)cout<<"No acceptable speeds.";
        cout<<endl;
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;
std::vector< pair<int ,string > >mp_value_agency;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
   
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        mp_value_agency.clear();
        cout<<"Case "<<test<<endl;
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=0;i<k;i++){
            string s;
            cin>>s;
            int index=s.find(':');
            string name=s.substr(0,index);
            string A,B;
            s=s.substr(index);
            index=s.find(',');
            A=s.substr(1,index);
            B=s.substr(index+1);
            stringstream ss1(A),ss2(B);
            int a,b;
            ss1>>a;
            ss2>>b;
            //name a(1),b(half)
            int have=n;
            int totalCost=0;
            while(have!=m){
                int willhave=have/2;
                int cost1=b;
                int cost2=(have-willhave)*a;
                if(willhave>=m){
                    if(cost1<cost2)totalCost+=cost1;
                    else totalCost+=cost2;
                    have=willhave;
                }else{
                    totalCost=totalCost+(have-m)*a;
                    have=m;
                }
            }
            mp_value_agency.push_back({totalCost,name});
           // mp_value_agency[totalCost]=name;//map sort by key
          // cout<<name<<" "<<a<<" "<<b<<endl;
           
        }
        sort(mp_value_agency.begin(),mp_value_agency.end());
        for(int i=0;i<mp_value_agency.size();i++){
            cout<<mp_value_agency[i].second<<" "<<mp_value_agency[i].first<<endl;
        }
    }
    

    return 0;
}


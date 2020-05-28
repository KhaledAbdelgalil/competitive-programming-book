#include <bits/stdc++.h>
using namespace std;
//{“January”, “February”, “March”, “April”, “May”, “June”, “July”,
//“August”, “September”, “October”, “November” and “December”}
map<string,int>mp;

int main()
{
    {
        mp["January"]=1;
        mp["February"]=2;
        mp["March"]=3;
        mp["April"]=4;
        mp["May"]=5;
        mp["June"]=6;
        mp["July"]=7;
        mp["August"]=8;
        mp["September"]=9;
        mp["October"]=10;
        mp["November"]=11;
        mp["December"]=12;
    }
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string month1,month2;
        char temp;
        int year1,year2,day2,day1;
        cin>>month1>>day1>>temp>>year1;
        cin>>month2>>day2>>temp>>year2;
        int m1=mp[month1];
        int m2=mp[month2];
        
        //let know if year1 is with us or No
        if(m1==1)
        year1--;
        else if(m1==2&&day1<=29)year1--;
        
        //let know if year2 is with us or No
        
        if(m2>=3);
        else if(m2==2&&day2>=29);
        else year2--;
        
        int final=(year2/4-year2/100)+(year2/400);
        int initial=(year1/4-year1/100)+(year1/400);
        //cout<<final-initial<<endl;
        
        cout<<"Case "<<i+1<<": "<<final-initial<<endl;
    }
    return 0;
}


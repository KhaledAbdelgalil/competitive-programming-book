#include<bits/stdc++.h>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int pal(string s)
{
    
    if(s.size()==1)return 1;
    for(int i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-i-1])return 0;
    return 1;
}
bool dotted(const char & s)
{
    if(s==':')return true;
    return false;
}
int main()
{
    
    /*
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    string st;
    int t;
    cin>>t;
   
    for(int i=1;i<=t;i++)
    {
       cin>>st;
       
      st.erase(remove_if(st.begin(),st.end(),dotted),st.end());
      //cout<<st<<endl;
      int h,m;
      h=int(st[0]-'0')*10+int(st[1]-'0');
      m=int(st[2]-'0')*10+int(st[3]-'0');
      while(1)
      {
            m++;
            if(m==60)
            {
               m=0;
               h++;
               if(h==24)h=0;
            }
            string str="";
           
            int left=h/10;
            int right=h%10;
            if(left)str=str+char(left+'0');
            if(right)str=str+char(right+'0');
            else if(str.size())str=str+char(right+'0');
            left=m/10;
            right=m%10;
            if(left)str=str+char(left+'0');
            else if(str.size())str=str+char(left+'0');
            if(right)str=str+char(right+'0');
            else if(str.size())str=str+char(right+'0');
               
            string str2(str.begin(),str.end());
            reverse(str2.begin(),str2.end());
          
            //cout<<"MIN: "<<m<<endl;
            //cout<<"HOUR: "<<h<<endl;
           
            //cout<<str<<endl<<str2<<endl;
            if(str2==str){
               if(h<10)cout<<0;
               cout<<h<<":";
               if(m<10)cout<<0;
               cout<<m<<endl;
               break;
            }
       }
    }
    return 0;
}


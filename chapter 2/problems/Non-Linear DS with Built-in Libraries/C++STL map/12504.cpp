#include <bits/stdc++.h>
using namespace std;


int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
   
   int t;
   cin>>t;
   cin.ignore();
   while(t--)
   {
       map<string,string>dic1,dic2;
       
       string d1,d2;
       getline(cin,d1);
       getline(cin,d2);
       
       d1=d1.substr(1);
       d1=d1.substr(0,d1.size()-1);
       
       d2=d2.substr(1);
       d2=d2.substr(0,d2.size()-1);
       
       //build d1
       while(d1.size())
       {
           int pos1=d1.find(':');
           string t1=d1.substr(0,pos1);
           string t2;
           d1=d1.substr(pos1+1);
           int pos2=d1.find(',');
           //cout<<t1<<endl;
           if(pos2==string::npos)
           {
               t2=d1;
               dic1[t1]=t2;
               //cout<<t2<<endl;
               break;
           }
           
           t2=d1.substr(0,pos2);
           d1=d1.substr(pos2+1);
           dic1[t1]=t2;
          // cout<<t2<<endl;
       }
       
       //build dic2
       while(d2.size())
       {
           int pos1=d2.find(':');
           string t1=d2.substr(0,pos1);
           string t2;
           d2=d2.substr(pos1+1);
           int pos2=d2.find(',');
           //cout<<t1<<endl;
           if(pos2==string::npos)
           {
               t2=d2;
               dic2[t1]=t2;
              // cout<<t2<<endl;
               break;
           }
           t2=d2.substr(0,pos2);
           d2=d2.substr(pos2+1);
           dic2[t1]=t2;
           //cout<<t2<<endl;
       }
      // cout<<"wslna b salama"<<endl;
       vector<string>added,removed,changed;
       for(map<string,string>::iterator it=dic1.begin();it!=dic1.end();it++)
       {
           string t1=it->first;//key
           
           
           if(dic2.find(t1)==dic2.end())//removed
           removed.push_back(t1);
           else if(dic2[t1]!=dic1[t1])
           changed.push_back(t1);
           
       }
       //cout<<"wslna b salama2"<<endl;
       for(map<string,string>::iterator it=dic2.begin();it!=dic2.end();it++)
       {
           string t1=it->first;//key
           
           
           if(dic1.find(t1)==dic1.end())//added
           added.push_back(t1);
           
       }
       // cout<<"wslna b salama3"<<endl;
       if(added.size()==0&&removed.size()==0&&changed.size()==0)
       {
           cout<<"No changes"<<endl;
       }
       if(added.size())
       {
           cout<<"+"<<added[0];
           for(int i=1;i<added.size();i++)
           cout<<","<<added[i];
           cout<<endl;
       }
       
       if(removed.size())
       {
           cout<<"-"<<removed[0];
           for(int i=1;i<removed.size();i++)
           cout<<","<<removed[i];
           cout<<endl;
       }
       
       if(changed.size())
       {
           cout<<"*"<<changed[0];
           for(int i=1;i<changed.size();i++)
           cout<<","<<changed[i];
           cout<<endl;
       }
       cout<<endl;
   }
   return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    map<string,int>mp;
    int cnt_idx=1;
   
   //you can generate all strings by that way
   /*
   for(int i=0;i<26;i++)
   {
        string temp;
        temp.push_back(char(97+i));
        mp[temp]=cnt_idx++;
        
   }
   for(int i=0;i<25;i++)
   {
       for(int j=i+1;j<26;j++)
        {
            string temp;
            temp.push_back(char(97+i));
            temp.push_back(char(97+j));
            mp[temp]=cnt_idx++;
        }
   }
   
  
   for(int i=0;i<24;i++)
   {
       for(int j=i+1;j<25;j++)
        for(int k=j+1;k<26;k++)
        {
            string temp;
            temp.push_back(char(97+i));
            temp.push_back(char(97+j));
            temp.push_back(char(97+k));
            mp[temp]=cnt_idx++;
        }
   }
   
   for(int i=0;i<23;i++)
   {
       for(int j=i+1;j<24;j++)
        for(int k=j+1;k<25;k++)
         for(int m=k+1;m<26;m++)
         {
            string temp;
            temp.push_back(char(97+i));
            temp.push_back(char(97+j));
            temp.push_back(char(97+k));
            temp.push_back(char(97+m));
            mp[temp]=cnt_idx++;
         }
   }
   
   
   for(int i=0;i<22;i++)
   {
       for(int j=i+1;j<23;j++)
        for(int k=j+1;k<24;k++)
         for(int m=k+1;m<25;m++)
            for(int h=m+1;h<26;h++)
            {
                string temp;
                temp.push_back(char(97+i));
                temp.push_back(char(97+j));
                temp.push_back(char(97+k));
                temp.push_back(char(97+m));
                temp.push_back(char(97+h));
                mp[temp]=cnt_idx++;
            }
   }
   */
   
   //the better way for generation
   
   std::queue<string>Q;
   string f;
   for(char ch='a';ch<='z';ch++)f=ch,Q.push(f);
    while(true)
   {
       string temp=Q.front();
       if(temp.size()>=6)break;
       for(char ch=temp[temp.size()-1]+1;ch<='z';ch++)
       {
           string temp2=temp;
           temp2+=ch;
           Q.push(temp2);
       }
       mp[temp]=cnt_idx++;
       Q.pop();
   }
   string temp;
   while(cin>>temp)
   {
       cout<<mp[temp]<<endl;
   }
    
   return 0;
}


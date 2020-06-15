#include <bits/stdc++.h>
using namespace std;

vector<string> adjust(string s)
{
    string t;
    vector<string>v;
    for(int i=0;i<s.size();i++)
    {
        if(isalpha(s[i]))t.push_back(tolower(s[i]));
        else if(t!="")v.push_back(t),t="";
    }
    if(t!="")v.push_back(t);
    return v;
}
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   string s;
   set<string>out;
    while(getline(cin,s))
    {
        vector<string> v=adjust(s);
        for(int i=0;i<v.size();i++)
        out.insert(v[i]);
    }
    
    for(set<string>::iterator it=out.begin();it!=out.end();it++)
    {
        cout<<*it<<endl;
    }
    
   return 0;
}


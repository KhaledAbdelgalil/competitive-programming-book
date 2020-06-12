#include <bits/stdc++.h>
using namespace std;

struct student{
    string name;
    int day;
    int month;
    int year;
};

bool cmp(const struct student& a,const struct student& b)
{
    if(a.year<b.year)return true;
    if(a.year==b.year&&a.month<b.month)return true;
    if(a.year==b.year&&a.month==b.month&&a.day<b.day)return true;
    return false;
}
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   int n;
   cin>>n;
   std::vector<struct student>st(n);
   for(int i=0;i<n;i++)
   cin>>st[i].name>>st[i].day>>st[i].month>>st[i].year;
   
   sort(st.begin(),st.end(),cmp);
   
   cout<<st[n-1].name<<endl;
   cout<<st[0].name<<endl;
   
   return 0;
}


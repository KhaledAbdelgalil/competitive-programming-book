#include <bits/stdc++.h>
using namespace std;
vector<int> factorize(int number)
{
    int temp=1;
    vector<int>factors;
    for(int i=1;i<=sqrt(number);i++)
    {
        if (!(number % temp))
            {
                factors.push_back(temp);
                if(temp!=(number/temp))
                factors.push_back(number/temp);
            }
        temp++;
    }
    return factors;
}
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
   int t;
   cin>>t;
   for(int i=0;i<t;i++)
   {
       int c,r;
       cin>>c>>r;
       if(c==r)
       {
           cout<<"Case #"<<i+1<<": "<<0<<endl;
           continue;
       }
       int eaten=c-r;
       std::vector<int>factors=factorize(eaten);
       sort(factors.begin(),factors.end());
       
       cout<<"Case #"<<i+1<<":";
       
       int j=0;
       while(j<factors.size()&&factors[j]<=r)j++;
       for(;j<factors.size();j++)
       {
           cout<<" "<<factors[j];
       }
       cout<<endl;
       
   }
   
   return 0;
}


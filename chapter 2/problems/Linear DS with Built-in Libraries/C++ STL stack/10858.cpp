#include <bits/stdc++.h>
using namespace std;
typedef std::vector<vector<int> > vvi;
typedef vector<int> vi;

void factorization_solution(int start,int n,vi &factors,vvi &factorizations)
{
    for(int i=start,j=sqrt(n);i<=j;i++)
    {
        if(n%i==0)
        {
            factors.push_back(i);//take i from n 
            factorization_solution(i,n/i,factors,factorizations);//get other factors
            factors.pop_back();//don't take i 
        }
    }
    if(!factors.empty())
    {
        factorizations.push_back(factors);
        factorizations.back().push_back(n);
    }
}

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
   int n;
   while(cin>>n&&n)
   {
       vvi factorizations;
       vi v;
       factorization_solution(2,n,v,factorizations);
       cout<<factorizations.size();
       for(int i=0;i<factorizations.size();i++)
       {
           cout<<endl;
           for(int j=0;j<factorizations[i].size();j++)
           {
               if(j)cout<<" ";
               cout<<factorizations[i][j];
           }
       }
       cout<<endl;
   }
   
   return 0;
}


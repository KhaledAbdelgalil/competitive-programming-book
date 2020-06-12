#include <bits/stdc++.h>
using namespace std;
vector<int>stations,gallons;
int n;
bool can(int i)
{
    int f=n;
    int start=i;
    int have=stations[i];
    //f--;
    int go;
    while(f--)
    {
        go=(start+1)%n;
        if(have-gallons[start]<0)return false;
        have=have-gallons[start]+stations[go];
        start=go;
    }
    
    return true;
}
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
   int t;
   cin>>t;
   for(int c=0;c<t;c++)
   {
       
       cin>>n;
       stations.resize(n);
       gallons.resize(n);
       int sumgallons=0,sumstations=0;
       for(int i=0;i<n;i++)
       {
           cin>>stations[i];
           sumstations+=stations[i];
       }
       for(int i=0;i<n;i++)
       {
           cin>>gallons[i];
           sumgallons+=gallons[i];
       }
       
       if(sumgallons>sumstations)
       {
           
           cout<<"Case "<<c+1<<": ";
           cout<<"Not possible"<<endl;
           continue;
       }
       
       int i;
       for(i=0;i<n;i++)
       {
           if(can(i))
           {
               break;
           }
       }
       cout<<"Case "<<c+1<<": ";
       if(i==n){
           cout<<"Not possible"<<endl;
       }
       else cout<<"Possible from station "<<i+1<<endl;
   }
   
   return 0;
}


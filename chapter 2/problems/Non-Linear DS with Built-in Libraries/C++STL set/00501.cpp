#include <bits/stdc++.h>
using namespace std;


int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   multiset<int>box;
   int t;
   cin>>t;
   while(t--)
   {
       int m,n;
       cin>>m>>n;
       box.clear();
       std::vector<int>numbers(m),indices(n);
       for(int i=0;i<m;i++)cin>>numbers[i];
       for(int i=0;i<n;i++)cin>>indices[i];
       box.insert(numbers[0]);
       multiset<int>::iterator it=box.begin();
       int idx=0;
       for(int i=1;i<m;i++)
       {
           //just print current iterator and increment it
           while(idx<n&&indices[idx]==i)
           {
               idx++;
               cout<<*it<<endl;
               it++;
           }
           //now insert item to box
           box.insert(numbers[i]);
           
           //if iterator reaches end decrement it
           //else if iterator increases becauese added element is less<*it decrement iterator
           if(it==box.end())it--;
           else if(numbers[i]<*it)it--;
       }
       //print what still
       while(idx<n&&indices[idx]==m){
           idx++;
           cout<<*it<<endl;
           it++;
       }
       if(t)cout<<endl;
   }
   return 0;
}


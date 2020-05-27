#include <bits/stdc++.h>
#include <string>

using namespace std;


int main(){
    
    
  std::ifstream in ("input");
  std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
  std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  int n;
  while(cin>>n&&n)
  {
      cout<<"Printing order for "<<n<<" pages:"<<endl;
      
    if(n==1)
    {
        cout<<"Sheet 1, front: Blank, 1"<<endl;
          continue;
    }
      
    int up=(n-n%4),down=1;
    if(up!=n)up+=4;
    int sheets=1;
    while(up>down)
    {
         cout<<"Sheet "<<sheets<<", front: ";
         if(up%2==0)
         {
             if(up<=n)cout<<up<<", ";
             else cout<<"Blank, ";
             if(down<=n)cout<<down<<endl;
             else cout<<"Blank"<<endl;
         }
         else 
         {
             if(down<=n)cout<<down<<", ";
             else cout<<"Blank, "<<endl;
             if(up<=n)cout<<up<<endl;
             else cout<<"Blank"<<endl;
         }
        cout<<"Sheet "<<sheets<<", back : ";
        up--;
        down++;
        if(up%2==0)
        {
             if(up<=n)cout<<up<<", ";
             else cout<<"Blank, ";
             if(down<=n)cout<<down<<endl;
             else cout<<"Blank"<<endl;
        }
        else 
        {
            if(down<=n)cout<<down<<", ";
            else cout<<"Blank, "<<endl;
            if(up<=n)cout<<up<<endl;
            else cout<<"Blank"<<endl;
        }
        up--;
        down++;
        sheets++;
    }
  
      
  }
  return 0;
}


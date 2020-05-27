#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    string s;
    int t;
    cin>>t;
    cin.ignore();
    for(int i=0;i<t;i++)
    {
        int out=0;
        getline(cin,s);
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {
                int r=s[i]-'a';
                if(r<=17)
                out+=1+(r%3);
                else 
                {
                    if(r==18)out+=4;
                    else if(r<=21)
                    out+=1+((r-19)%3);
                    else out+=1+((r-22)%4);
                }
            }
            else out++;
        }
        
        cout<<"Case #"<<i+1<<": "<<out<<endl;
    }
    
}

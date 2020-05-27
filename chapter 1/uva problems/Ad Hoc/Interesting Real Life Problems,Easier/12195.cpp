#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    /*std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    string t;
    while(getline(cin,t)&&t!="*")
    {
        bool st=0;
        int cnt_tone=0;
        int out=0;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='/'&&st==0)
            {
                st=1;
                cnt_tone=0;
            
            }
            else if(t[i]=='/'&&st==1)
            {
            
                if(cnt_tone==64)out++;
                cnt_tone=0;    
            }
            
            else 
            {
                switch(t[i])
                {
                    case 'W':cnt_tone+=64;break;
                    case 'H':cnt_tone+=32;break;
                    case 'Q':cnt_tone+=16;break;
                    case 'E':cnt_tone+=8;break;
                    case 'S':cnt_tone+=4;break;
                    case 'T':cnt_tone+=2;break;
                    case 'X':cnt_tone+=1;break;
                    default: cnt_tone=88;break;
                }
            }
        }
        cout<<out<<endl;
    }
}

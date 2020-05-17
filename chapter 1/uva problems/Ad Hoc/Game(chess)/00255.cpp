//handle all cases and check for corner cases as x inbetween them so y cannot reach z
#include <bits/stdc++.h>
#include<fstream>
using namespace std;
int main()
{
    /*std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!*/
    
    int x,y,z;
    while(cin>>x>>y>>z)
    {
        if(x==y)cout<<"Illegal state"<<endl;
        else 
        {
            if((z/8==y/8 || z%8==y%8)&&z!=y)//they are  in same line horizontal or vertical
            {
                
                
                //we need to check before if x in between as this is illegal Move
                if( ( (x%8==y%8&&z%8==y%8) || (x/8==y/8&&z/8==y/8) ) &&   ( x>=min(z,y)&&x<=max(z,y) )  ) cout<<"Illegal move"<<endl;
                else if( (x+1==z&&(x+1)%8!=0)  || ( x-1 ==z && (x-1)%8!=7) || x+8==z || x-8==z)
                {
                    cout<<"Move not allowed"<<endl;
                }
                else
                {
                    if((x==0&&z==9)||(x==7&&z==14)||(x==56&&z==49)||(x==63&&z==54))
                    cout<<"Stop"<<endl;
                    else cout<<"Continue"<<endl;
                } 
            }
            else 
            {
                cout<<"Illegal move"<<endl;
               
            }
        }
    }
    
    
    return 0;
}


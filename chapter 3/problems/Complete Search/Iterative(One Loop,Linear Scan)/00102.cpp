#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    
    std::vector<int>pin1(3),pin2(3),pin3(3) ;
    while(cin>>pin1[0]>>pin1[1]>>pin1[2])//BGC
    {
        cin>>pin2[0]>>pin2[1]>>pin2[2]>>pin3[0]>>pin3[1]>>pin3[2];
        int BCG=pin2[0]+pin3[0]+pin1[2]+pin3[2]+pin1[1]+pin2[1];
        int BGC=pin2[0]+pin3[0]+pin1[1]+pin3[1]+pin1[2]+pin2[2];
        int mn=min(BCG,BGC);
        int CBG=pin2[2]+pin3[2]+pin1[0]+pin3[0]+pin1[1]+pin2[1];
        mn=min(CBG,mn);
        int CGB=pin2[2]+pin3[2]+pin1[1]+pin3[1]+pin1[0]+pin2[0];
        mn=min(CGB,mn);
        int GBC=pin2[1]+pin3[1]+pin1[0]+pin3[0]+pin1[2]+pin2[2];
        mn=min(GBC,mn);
        int GCB=pin2[1]+pin3[1]+pin1[2]+pin3[2]+pin1[0]+pin2[0];
        mn=min(GCB,mn);
        
        if(mn==BCG){
            cout<<"BCG "<<mn<<endl;
        }
        else if(mn==BGC){
            cout<<"BGC "<<mn<<endl;
        }
        else if(mn==CBG){
            cout<<"CBG "<<mn<<endl;
        }
        else if(mn==CGB){
            cout<<"CGB "<<mn<<endl;
        }
        else if(mn==GBC){
            cout<<"GBC "<<mn<<endl;
        }
        else cout<<"GCB "<<mn<<endl;
        
    }
    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
#include<deque>
using namespace std;

int main()
{
    
    /*
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    string n;
    while(cin>>n)
    {
        int s=0,h=0,c=0,d=0;
        int ones=0,kings=0,queens=0,jacks=0;
        int spades[4]={0};
        int hearts[4]={0};
        int clubs[4]={0};
        int diamonds[4]={0};
        
        if(n[0]=='A')
        {
            ones++;
            if(n[1]=='S')s++,spades[0]++;
            else if(n[1]=='H')h++,hearts[0]++;
            else if(n[1]=='C')c++,clubs[0]++;
            else d++,diamonds[0]++;
            
        }
        else if(n[0]=='K')
        {
            kings++;
            if(n[1]=='S')s++,spades[1]++;
            else if(n[1]=='H')h++,hearts[1]++;
            else if(n[1]=='C')c++,clubs[1]++;
            else d++,diamonds[1]++;
            
        }
        else if(n[0]=='Q')
        {
            queens++;
            if(n[1]=='S')s++,spades[2]++;
            else if(n[1]=='H')h++,hearts[2]++;
            else if(n[1]=='C')c++,clubs[2]++;
            else d++,diamonds[2]++;
        }
        else if(n[0]=='J')
        {
            jacks++;
            if(n[1]=='S')s++,spades[3]++;
            else if(n[1]=='H')h++,hearts[3]++;
            else if(n[1]=='C')c++,clubs[3]++;
            else d++,diamonds[3]++;
            
        }
        else
        {
            if(n[1]=='S')s++;
            else if(n[1]=='H')h++;
            else if(n[1]=='C')c++;
            else d++;
        }
        for(int i=0;i<12;i++)
        {
            
            cin>>n;
                
            if(n[0]=='A')
            {
                ones++;
                if(n[1]=='S')s++,spades[0]++;
                else if(n[1]=='H')h++,hearts[0]++;
                else if(n[1]=='C')c++,clubs[0]++;
                else d++,diamonds[0]++;
                
            }
            else if(n[0]=='K')
            {
                kings++;
                if(n[1]=='S')s++,spades[1]++;
                else if(n[1]=='H')h++,hearts[1]++;
                else if(n[1]=='C')c++,clubs[1]++;
                else d++,diamonds[1]++;
                
            }
            else if(n[0]=='Q')
            {
                queens++;
                if(n[1]=='S')s++,spades[2]++;
                else if(n[1]=='H')h++,hearts[2]++;
                else if(n[1]=='C')c++,clubs[2]++;
                else d++,diamonds[2]++;
            }
            else if(n[0]=='J')
            {
                jacks++;
                if(n[1]=='S')s++,spades[3]++;
                else if(n[1]=='H')h++,hearts[3]++;
                else if(n[1]=='C')c++,clubs[3]++;
                else d++,diamonds[3]++;
                
            }
            else
            {
                if(n[1]=='S')s++;
                else if(n[1]=='H')h++;
                else if(n[1]=='C')c++;
                else d++;
            }
                
        }
        
        int points=ones*4+kings*3+queens*2+jacks;
        //king
        {
            if(s==1&&spades[1]==1)points--;
            if(h==1&&hearts[1]==1)points--;
            if(d==1&&diamonds[1]==1)points--;
            if(c==1&&clubs[1]==1)points--;
        }
        //cout<<"here "<<points;
        //queen
        {
            if(s<=2&&spades[2]==1)points--;
            if(h<=2&&hearts[2]==1)points--;
            if(d<=2&&diamonds[2]==1)points--;
            if(c<=2&&clubs[2]==1)points--;
        }
        //cout<<"here "<<points;
        //jacks
        {
            if(s<=3&&spades[3]==1)points--;
            if(h<=3&&hearts[3]==1)points--;
            if(d<=3&&diamonds[3]==1)points--;
            if(c<=3&&clubs[3]==1)points--;
        }
        if(points>=16) 
        {
            if( ((spades[0]==1)||(s>=2&&spades[1]==1)||(spades[2]==1&&s>=3)) && ((hearts[0]==1)||(h>=2&&hearts[1]==1)||(hearts[2]==1&&h>=3)) &&((clubs[0]==1)||(c>=2&&clubs[1]==1)||(clubs[2]==1&&c>=3)) && ((diamonds[0]==1)||(d>=2&&diamonds[1]==1)||(diamonds[2]==1&&d>=3))           )
            {
                cout<<"BID NO-TRUMP"<<endl;
                continue;
            }
        }
        //cout<<"here "<<points;
        //cout<<points<<endl;
        //2cards in suit
        {
            if(h==2)points++;
            if(d==2)points++;
            if(c==2)points++;
            if(s==2)points++;
        }
        
        {
            if(h<=1)points+=2;
            if(d<=1)points+=2;
            if(c<=1)points+=2;
            if(s<=1)points+=2;
        }
        if(points>=14)
        {
            cout<<"BID ";
            int maxx=max(d,c);
            maxx=max(h,maxx);
            maxx=max(maxx,s);
            if(s==maxx)cout<<"S"<<endl;
            else if(h==maxx)cout<<"H"<<endl;
            else if(d==maxx)cout<<"D"<<endl;
            else cout<<"C"<<endl;
        }
        else {
            cout<<"PASS"<<endl;
        }
      //cout<<points<<endl;
    }
    
    return 0;
}


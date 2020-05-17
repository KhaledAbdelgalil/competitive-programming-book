#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const string& a,const string & b)
{
    if(a[0]=='C'&&b[0]!='C')return true;
    else if(a[0]=='C'&&b[0]=='C')
    {
        if(a[1]=='A')return false;
        else if (a[1]=='K'&&b[1]!='A')return false;
        else if(a[1]=='K'&&b[1]=='A') return true;
        else if(a[1]=='Q'&&b[1]!='A'&&b[1]!='K')return false;
        else if(a[1]=='Q'&&(b[1]=='A'||b[1]=='K') )return true;
        else if(a[1]=='J'&&b[1]!='A'&&b[1]!='K'&&b[1]!='Q')return false;
        else if(a[1]=='J'&&(b[1]=='A' || b[1] == 'K' || b[1] == 'Q' ) )return true;
        else if(a[1]=='T'&&b[1]!='A'&&b[1]!='K'&&b[1]!='Q' && b[1]!='J')return false;
        else if(a[1]=='T'&&(b[1]=='A' || b[1] == 'K' || b[1] == 'Q' || b[1] == 'J' ) )return true;
        else if(a[1]>b[1])return false;
        else return true;
        
    }
    
    
    if(a[0]=='D'&&b[0]!='D'&&b[0]!='C')return true;
    else if(a[0]=='D'&&b[0]=='D')
    {
        if(a[1]=='A')return false;
        else if (a[1]=='K'&&b[1]!='A')return false;
        else if(a[1]=='K'&&b[1]=='A') return true;
        else if(a[1]=='Q'&&b[1]!='A'&&b[1]!='K')return false;
        else if(a[1]=='Q'&&(b[1]=='A'||b[1]=='K') )return true;
        else if(a[1]=='J'&&b[1]!='A'&&b[1]!='K'&&b[1]!='Q')return false;
        else if(a[1]=='J'&&(b[1]=='A' || b[1] == 'K' || b[1] == 'Q' ) )return true;
        else if(a[1]=='T'&&b[1]!='A'&&b[1]!='K'&&b[1]!='Q' && b[1]!='J')return false;
        else if(a[1]=='T'&&(b[1]=='A' || b[1] == 'K' || b[1] == 'Q' || b[1] == 'J' ) )return true;
        else if(a[1]>b[1])return false;
        else return true;
        
    }
    
    
    
    if(a[0]=='S'&&b[0]!='D'&&b[0]!='C'&&b[0]!='S')return true;
    else if(a[0]=='S'&&b[0]=='S')
    {
        if(a[1]=='A')return false;
        else if (a[1]=='K'&&b[1]!='A')return false;
        else if(a[1]=='K'&&b[1]=='A') return true;
        else if(a[1]=='Q'&&b[1]!='A'&&b[1]!='K')return false;
        else if(a[1]=='Q'&&(b[1]=='A'||b[1]=='K') )return true;
        else if(a[1]=='J'&&b[1]!='A'&&b[1]!='K'&&b[1]!='Q')return false;
        else if(a[1]=='J'&&(b[1]=='A' || b[1] == 'K' || b[1] == 'Q' ) )return true;
        else if(a[1]=='T'&&b[1]!='A'&&b[1]!='K'&&b[1]!='Q' && b[1]!='J')return false;
        else if(a[1]=='T'&&(b[1]=='A' || b[1] == 'K' || b[1] == 'Q' || b[1] == 'J' ) )return true;
        else if(a[1]>b[1])return false;
        else return true;
        
    }
    
    
     if(a[0]=='H'&&b[0]=='H')
    {
        if(a[1]=='A')return false;
        else if (a[1]=='K'&&b[1]!='A')return false;
        else if(a[1]=='K'&&b[1]=='A') return true;
        else if(a[1]=='Q'&&b[1]!='A'&&b[1]!='K')return false;
        else if(a[1]=='Q'&&(b[1]=='A'||b[1]=='K') )return true;
        else if(a[1]=='J'&&b[1]!='A'&&b[1]!='K'&&b[1]!='Q')return false;
        else if(a[1]=='J'&&(b[1]=='A' || b[1] == 'K' || b[1] == 'Q' ) )return true;
        else if(a[1]=='T'&&b[1]!='A'&&b[1]!='K'&&b[1]!='Q' && b[1]!='J')return false;
        else if(a[1]=='T'&&(b[1]=='A' || b[1] == 'K' || b[1] == 'Q' || b[1] == 'J' ) )return true;
        else if(a[1]>b[1])return false;
        else return true;
        
    }
    return false;
}

int main()
{
    
    
    /*std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    string n;
    char f;
    while(cin>>f)
    {
        if(f=='#')break;
        vector< vector<string> > v(4) ;
        int start=0;
        
        if(f=='E')start=3;
        else if(f=='N')start=0;
        else if(f=='W')start=1;
        else start=2;
        
        cin>>n;
        for(int i=0;i<52;i+=2)
        {
            string x=n.substr(i, 2);
            v[start].push_back(x);
            start=(start-1+4)%4;
        }
        
        cin>>n;
        for(int i=0;i<52;i+=2)
        {
            string x=n.substr(i, 2);
            v[start].push_back(x);
            start=(start-1+4)%4;
        }
        for(int i=0;i<4;i++)
            sort(v[i].begin(),v[i].end(),cmp);
            
        //S: C3 C5 C7 CT CJ D9 DT DJ S3 SK H2 H9 HT
        
        cout<<"S:";
        for(int i=0;i<13;i++)
        cout<<" "<<v[3][i];
        cout<<endl;
        
        
        cout<<"W:";
        for(int i=0;i<13;i++)
        cout<<" "<<v[2][i];
        cout<<endl;
        
        
        cout<<"N:";
        for(int i=0;i<13;i++)
        cout<<" "<<v[1][i];
        cout<<endl;
        
        
        cout<<"E:";
        for(int i=0;i<13;i++)
        cout<<" "<<v[0][i];
        cout<<endl;
    }
    
    return 0;
}


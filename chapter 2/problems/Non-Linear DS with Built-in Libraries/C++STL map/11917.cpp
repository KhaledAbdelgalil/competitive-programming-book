#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
    map<string,int>subjects;
    int t;
    cin>>t;
    
    for(int test=1;test<=t;test++)
    {
        int n;
        cin>>n;
        while(n--)
        {
            string s;
            int h;
            cin>>s>>h;
            subjects[s]=h;
        }
        
        int d;
        string s;
        cin>>d>>s;
        if(subjects.find(s)==subjects.end())
            cout<<"Case "<<test<<": Do your own homework!"<<endl;
        else if(subjects[s]<=d)
            cout<<"Case "<<test<<": Yesss"<<endl;
        else if(subjects[s]<=d+5)
            cout<<"Case "<<test<<": Late"<<endl;
        else
            cout<<"Case "<<test<<": Do your own homework!"<<endl;
        subjects.clear();
        
    }
    

    return 0;
}


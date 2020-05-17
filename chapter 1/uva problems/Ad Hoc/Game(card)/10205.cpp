
#include <bits/stdc++.h>
#include<fstream>
using namespace std;
string cardFirst[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
string cardSecond[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
int main()
{
    /*std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!*/
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        std::vector< vector<int> >v(n);
        vector<int>out(52);
        for(int i=0;i<52;i++)
        out[i]=i;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<52;j++)
            {
                int x;
                cin>>x;
                v[i].push_back(x-1);
            }
        }
        while(n--)
        {
            int x;
            cin>>x;
            vector<int>vv(52);
            for(int i=0;i<52;i++)
            vv[i]=out[v[x-1][i]];
            
            for(int i=0;i<52;i++)
            out[i]=vv[i];
        }
        //cout<<out[0]<<endl;
        for(int i=0;i<52;i++)
        {
            cout<<cardFirst[out[i]%13]<<" of "<<cardSecond[out[i]/13]<<endl;
        }
        if(t)cout<<endl;
    }
    
    
    return 0;
}


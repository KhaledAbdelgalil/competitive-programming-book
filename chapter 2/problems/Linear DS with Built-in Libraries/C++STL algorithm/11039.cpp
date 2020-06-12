#include <bits/stdc++.h>
using namespace std;

struct build{
    int size;
    char color='b';
};

bool cmp(const struct build&a,const struct build&b)
{
    return a.size<b.size;
}
int main()
{
    
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
   
    int t;
    cin>>t;
    for(int f=0;f<t;f++)
    {
        int n;
        cin>>n;
        std::vector<struct build>floors(n);
        
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x<0)x*=-1,floors[i].color='r';
            floors[i].size=x;
        }
        sort(floors.begin(),floors.end(),cmp);
        int out=1;
        char last=floors[0].color;
        int last_size=floors[0].size;
        for(int i=0;i<n;i++)
        {
            if(last==floors[i].color)continue;
            else if(last_size>=floors[i].size)continue;
            out++;
            last=floors[i].color;
            last_size=floors[i].size;
        }
        cout<<out<<endl;
    }

    return 0;
}


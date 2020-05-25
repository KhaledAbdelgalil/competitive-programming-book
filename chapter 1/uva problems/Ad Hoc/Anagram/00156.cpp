#include <bits/stdc++.h>
using namespace std;


bool cmp(const char& a,const char& b)
{
    if(tolower(a)<tolower(b))return true;
    if(tolower(a)==tolower(b)&&a<b)return true;
    return false;
}

int main()
{
    /*
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    string temp;
    std::vector<string>v ;
    while(cin>>temp&&temp!="#")
    {
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        string temp1(v[i].begin(),v[i].end());
        
        bool put=1;
        
        for(int k=0;k<temp1.size();k++)
            temp1[k]=tolower(temp1[k]);
        sort(temp1.begin(),temp1.end());
        for(int j=0;j<v.size();j++)
        {
            if(i==j)continue;
            string temp2(v[j].begin(),v[j].end());
            for(int k=0;k<temp2.size();k++)
               temp2[k]=tolower(temp2[k]);
            sort(temp2.begin(),temp2.end());
            if(temp1==temp2){put=0;break;}
        }
        if(put)cout<<v[i]<<endl;
    }
    
    return 0;
}


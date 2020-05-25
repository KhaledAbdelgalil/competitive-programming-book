#include <bits/stdc++.h>
using namespace std;




int main()
{
    
    /*
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    int t;
    cin>>t;
    cin.ignore(100, '\n');
    cin.ignore(100, '\n');
    while(t--)
    {
        string temp;
        std::vector<string>v ;
        
        while(getline(cin,temp)&&temp.size())
        {
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            string temp1(v[i].begin(),v[i].end());
            temp1.erase(remove_if(temp1.begin(),temp1.end(),::isspace),temp1.end());
            sort(temp1.begin(),temp1.end());
            for(int j=i+1;j<v.size();j++)
            {
                string temp2(v[j].begin(),v[j].end());
                temp2.erase(remove_if(temp2.begin(),temp2.end(),::isspace),temp2.end());
                sort(temp2.begin(),temp2.end());
                if(temp1==temp2)
                cout<<v[i]<<" = "<<v[j]<<endl;
            }
        }
        if(t)cout<<endl;
    }
    
    return 0;
}


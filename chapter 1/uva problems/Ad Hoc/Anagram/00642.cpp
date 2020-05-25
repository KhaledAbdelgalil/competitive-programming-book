#include <bits/stdc++.h>
using namespace std;




int main()
{
    /*std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    std::vector<string>dict;
    string temp;
    while(getline(cin,temp))
    {
        if(temp=="XXXXXX")break;
        dict.push_back(temp);
    }
    
    sort(dict.begin(),dict.end());
    
    while(getline(cin,temp))
    {
        if(temp=="XXXXXX")break;
        
        sort(temp.begin(),temp.end());
        vector<string>out;
        for(int i=0;i<dict.size();i++)
        {
            string temp2=dict[i];
            sort(temp2.begin(),temp2.end());
            if(temp==temp2){
                out.push_back(dict[i]);
            }
        }
        if(out.size()==0) cout << "NOT A VALID WORD" << endl;
        for(int i=0;i<out.size();i++)
        cout << out[i] << endl;
        cout << "******" << endl;
    }
    
    
    
    return 0;
}


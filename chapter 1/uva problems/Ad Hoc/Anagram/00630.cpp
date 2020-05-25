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
    
    
    while(t--)
    {
        std::vector<string>dict;
        string temp;
        int n;
        cin>>n;
        while(n--)
        {
           cin>>temp;
            dict.push_back(temp);
        }
       // sort(dict.begin(),dict.end());
        
        while(cin>>temp)
        {
            if(temp=="END")break;
            string s=temp;
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
            if(out.size()==0) {
            cout<<"Anagrams for: "<<s<<endl;
            cout<<"No anagrams for: "<<s<<endl;
            }
            else
            {
                cout<<"Anagrams for: "<<s<<endl;
                    
                for(int i=0;i<out.size();i++)
                cout <<"  "<<i+1<<") "<<out[i] << endl;
                
            }
        }
        if(t) cout<<endl;
        
    }
    
    return 0;
}


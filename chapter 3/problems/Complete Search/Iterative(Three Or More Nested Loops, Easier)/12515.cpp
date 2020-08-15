#include <bits/stdc++.h>
using namespace std;
string colors="ROGBYV";
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    int n,q;
    cin>>n>>q;
    std::vector<string>vs(n);
    for(int i=0;i<n;i++)cin>>vs[i];
    while(q--){
        int min_hamming=1000;
        int index=-1;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
        if(s.size()>vs[i].size())continue;
        for(int j=0;j<vs[i].size();j++){
            if(vs[i].size()-j<s.size())break;
            string temp=vs[i].substr(j,s.size());
            int hamm=0;
            for(int k=0;k<s.size();k++)if(s[k]!=temp[k])hamm++;
            if(hamm<min_hamming){
                min_hamming=hamm;
                index=i;
            }
        }
        }
    cout<<index+1<<endl;
    }
    return 0;
}


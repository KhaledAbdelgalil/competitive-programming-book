#include <bits/stdc++.h>
using namespace std;
int main(){
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    map<char,vector<int>>mp_indices;

    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)mp_indices[s[i]].push_back(i);
    int q;
    cin>>q;
    while(q--){
        cin>>s;
        bool solved=1;
        int wanted_index=0,st_index,end_index;//at first I want index=0 or more i.e at least 0
        for(int i=0;i<s.size();i++){
            vector<int>searched=mp_indices[s[i]];
            vector<int>::iterator it=lower_bound(searched.begin(),searched.end(),wanted_index);
            if(it==searched.end()){solved=0;break;}
           
           //we want index more than found 
            wanted_index=(*it)+1;
            
            if(i==0)st_index=*it;
            else if(i==s.size()-1)end_index=*it;
        }
        if(solved)cout<<"Matched "<<st_index<<" "<<end_index<<endl;
        else cout<<"Not matched"<<endl;
    }
    return 0;
}


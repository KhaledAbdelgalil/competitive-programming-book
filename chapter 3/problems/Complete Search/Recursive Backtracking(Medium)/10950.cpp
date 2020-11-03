#include <bits/stdc++.h>
using namespace std;
map<string ,char>mp;
map<string,bool>found;
vector<string>all_ans;
string s;
void solve(int index,string temp){
    if(index==s.size()){
        if(found.find(temp)==found.end())
        all_ans.push_back(temp),found[temp]=1;
        return;
    }
    if(index>s.size())return;
    //take 1 char and try and backtrack
    if(mp.find(s.substr(index,1))!=mp.end())solve(index+1,temp+mp[s.substr(index,1)]);
    
    //take 2 char and try and backtrack
    if(index+1<s.size()&&mp.find(s.substr(index,2))!=mp.end() )solve(index+2,temp+mp[s.substr(index,2)]);
    
    //skip zeros if found
    if(s[index]=='0'){
    while(s[index]=='0')index++;
    if(index!=s.size())solve(index,temp);
    }
    
}
int main(){
    
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    int n;
    string code;
    char ch;
    int test=1;
    while(cin>>n&&n){
        all_ans.clear();
        mp.clear();
        found.clear();
        
       while(n--)cin>>ch>>code,mp[code]=ch;
       cin>>s;
       string temp="";
       //index in string     curr_output
       solve(0,temp);
       cout<<"Case #"<<test++<<endl;
       sort(all_ans.begin(),all_ans.end());
       for(int i=0;i<min((int)all_ans.size(),100);i++)cout<<all_ans[i]<<endl;
       cout<<endl;
    }
    
    return 0;
}


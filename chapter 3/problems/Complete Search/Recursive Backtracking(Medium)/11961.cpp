#include <bits/stdc++.h>
using namespace std;
string s;
string genes="ACGT";
int n,k;
vector<string>all_answers;
bool valid(string temp){
    int diff=0;
    for(int i=0;i<s.size();i++){
        if(temp[i]!=s[i]){
            diff++;
            if(diff>k)return false;
        }
    }
    return true;
}
void solve(int index,string temp){
    if(index==n){
        if(valid(temp))all_answers.push_back(temp);
        return;
    }
    for(int i=0;i<4;i++)solve(index+1,temp+genes[i]);
}
int main(){
    
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    int t;
    cin>>t;
    while(t--){
        
        cin>>n>>k;
        cin>>s;
        string f="";
        all_answers.clear();
        solve(0,f);
        cout<<all_answers.size()<<endl;
        for(int i=0;i<all_answers.size();i++)cout<<all_answers[i]<<endl;
    }
    
    return 0;
}


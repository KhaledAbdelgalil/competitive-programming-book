#include <bits/stdc++.h>
using namespace std;
string rule;
std::vector<string>dic;
void generateAll(int pos,string s=""){
    if(pos==rule.size()){
        cout<<s<<endl;
        return;
    }
    if(rule[pos]=='#'){
        for(int i=0;i<dic.size();i++){
            generateAll(pos+1,s+dic[i]);
        }
    }
    else if(rule[pos]=='0'){
        for(char i='0';i<='9';i++){
            generateAll(pos+1,s+i);
        }
    }
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    int n,m;
    while(cin>>n){
        cout<<"--"<<endl;
        dic.resize(n);
        for(int i=0;i<n;i++)cin>>dic[i];
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>rule;
            generateAll(0);
        }
        
    }
    return 0;
}


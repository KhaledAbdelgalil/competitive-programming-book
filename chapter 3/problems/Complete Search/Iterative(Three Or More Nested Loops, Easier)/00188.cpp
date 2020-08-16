#include <bits/stdc++.h>
using namespace std;


int main(){
   
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        string word;
        std::vector<int>words;
        while(ss>>word){
            int cnt=0;
            for(int i=0;i<word.size();i++){
                cnt=cnt*32+(word[i]-'a'+1);
            }
            words.push_back(cnt);
        }
        cout<<s<<endl;
        int c=0;
        while(1){
            bool flag=1;
            for(int i=0;i<words.size();i++){
                for(int j=i+1;j<words.size();j++){
                    if((c/words[i])%words.size()==(c/words[j])%words.size()){
                        flag=0;
                        c=min(((c/words[i])+1)*words[i],((c/words[j])+1)*words[j]);
                        break;
                    }
                }
                if(!flag)break;
            }
            if(flag){
                cout<<c<<endl;
                break;
            }
        }
        cout<<endl;
    }
   
    return 0;
}


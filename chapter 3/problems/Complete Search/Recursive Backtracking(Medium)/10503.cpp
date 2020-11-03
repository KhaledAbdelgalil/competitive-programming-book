#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int> >dominos;
int must_start,must_end;
bool ans=0;
void solve(int space_no,vector<bool>taken,int prev){
    if(space_no==n){
        if(prev==must_end){
            ans=1;
        }
        return;
    }
    if(ans)return;
    for(int i=0;i<m;i++){
        if(prev==dominos[i].first&&taken[i]==0){
            taken[i]=1;
            solve(space_no+1,taken,dominos[i].second);
            taken[i]=0;
        }
        else if(prev==dominos[i].second&&taken[i]==0){
            taken[i]=1;
            solve(space_no+1,taken,dominos[i].first);
            taken[i]=0;
        }
    }
}
int main(){
    
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    while(cin>>n&&n){
        cin>>m;
        int temp;
        cin>>temp>>must_start>>must_end>>temp;
        dominos.resize(m);
        for(int i=0;i<m;i++)cin>>dominos[i].first>>dominos[i].second;
        vector<bool>taken(m,0);
        ans=0;
        //which space which_taken_in_domino prev_domino
        solve(0,taken,must_start);
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
vector<string>v;
int r1,r2;
void solve_combination_of_len(int reqlen,vector<bool>taken,int currlen,int index=0){
if(currlen==reqlen){
vector<string>ans;
for(int i=0;i<v.size();i++)if(taken[i])ans.push_back(v[i]);
if(ans.size()==0)return;
cout<<ans[0];
for(int i=1;i<ans.size();i++)cout<<", "<<ans[i];
cout<<endl;
return;
}
if(index==v.size())return;
taken[index]=1;
solve_combination_of_len(reqlen,taken,currlen+1,index+1);
taken[index]=0;
solve_combination_of_len(reqlen,taken,currlen,index+1);
}

int main()
{

    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!



    int t;
    cin>>t;
    string range;
    string s;
    cin.ignore();
    cin.ignore();
    while(t--){
    getline(cin,range);
    //cout<<range<<endl;
    v.clear();
    while(getline(cin,s)&&s!="")v.push_back(s);
      r1=-1,r2=-1;
      if(range[0]=='*')r1=1,r2=v.size();
      else{
      stringstream ss(range);
      if(range.find(" ")==string::npos)ss>>r1,r2=r1;
      else ss>>r1>>r2;
      }
     // cout<<r1<<" "<<r2<<endl<<endl;
      for(int i=r1;i<=r2;i++){
       cout<<"Size "<<i<<endl;
       vector<bool>taken(v.size(),0);
       solve_combination_of_len(i,taken,0);
       cout<<endl;
      }
     if(t)cout<<endl;
    }
    return 0;
}


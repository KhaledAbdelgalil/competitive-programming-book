#include <bits/stdc++.h>
using namespace std;
int t,n;
vector<int>v;
vector< vector<int> >answers;
map<vector<int>,bool>mp_answer_found_before;
void solve(int curr,vector<bool>taken,int sum_till_nw=0){
    if(sum_till_nw>t)return;
    if(curr==n){
        if(sum_till_nw==t){
            vector<int>curr_ans;
            for(int i=0;i<n;i++)if(taken[i])curr_ans.push_back(v[i]);
            if(mp_answer_found_before.find(curr_ans)==mp_answer_found_before.end())answers.push_back(curr_ans);
            mp_answer_found_before[curr_ans]=1;
        }
        return;
    }
    taken[curr]=1;
    solve(curr+1,taken,sum_till_nw+v[curr]);
    taken[curr]=0;
    solve(curr+1,taken,sum_till_nw);
}
bool cond_remove(const vector<int>&a,const vector<int>&b){
if(a==b)return true;
return false;
}
int main()
{

    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    int test=1;
    while(cin>>t>>n&&n){
        v.resize(n);
        for(int i=0;i<n;i++)cin>>v[i];
        answers.clear();
        vector<bool>taken(n,0);
        mp_answer_found_before.clear();
        solve(0,taken);
        //remove_if(answers.begin(),answers.end(),cond_remove);
        cout<<"Sums of "<<t<<":"<<endl;
        if(answers.size()==0){
            cout<<"NONE"<<endl;
        }
        else{
            for(int i=0;i<answers.size();i++){
                cout<<answers[i][0];
                for(int j=1;j<answers[i].size();j++)cout<<"+"<<answers[i][j];
                cout<<endl;
            }
        }
    }

    return 0;
}


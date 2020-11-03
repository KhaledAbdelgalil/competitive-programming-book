
#include <bits/stdc++.h>

using namespace std;
vector<int>v;
vector<int>pow_index;
int sum;
int n;
void comb_of_length(int required_len,bool found_in_curr_comb[],int curr_index=0,int curr_len=0,int sum_till_now=0){
    if(curr_len>required_len)return;
    if(curr_len==required_len){
        if(sum_till_now<=sum)return;        
        for(int i=0;i<n;i++){
            //found in current_comb
            if(found_in_curr_comb[i]==true&&sum_till_now-v[i]<=sum){//second condition to make sure that adding index i has power index(i.e it matters it make combination majority)
                pow_index[i]++;
            }
        }
        return;
    }
    //you are about to go out of boundary
    if(curr_index==n)return;
    //take it
    found_in_curr_comb[curr_index]=true;
    comb_of_length(required_len,found_in_curr_comb,curr_index+1,curr_len+1,sum_till_now+v[curr_index]);
    //don't take it
    found_in_curr_comb[curr_index]=false;
    comb_of_length(required_len,found_in_curr_comb,curr_index+1,curr_len,sum_till_now);
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        v.resize(n);
        bool found_in_curr_comb[n];
        pow_index.assign(n,0);
        sum=0;
        for(int i=0;i<n;i++)cin>>v[i],sum+=v[i];
        
        sum=sum/2;
        for(int i=0;i<=n;i++){
            comb_of_length(i,found_in_curr_comb);
        }    
        for(int i=0;i<n;i++){
            cout<<"party "<<i+1<<" has power index "<<pow_index[i]<<endl;
        }
        cout<<endl;
    }

    return 0;
}


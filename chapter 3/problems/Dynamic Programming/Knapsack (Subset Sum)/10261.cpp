#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long>v;
map< pair<int, pair<long long,long long> > ,long long >mem;
long long solve(int id,long long left,long long right)
{
    if(id>=n)return 0;
    if(left<0||right<0)return 0;
    
    if(mem.find({id,{left,right}})!=mem.end())return mem[{id,{left,right}}];
    long long ans;
    
    //long long ans1=solve(id+1,left,right);//don't take
    long long ans2=0,ans3=0;
    if(left>=v[id])//if can take left
    ans2=1+solve(id+1,left-v[id],right);
    if(right>=v[id])
    ans3=1+solve(id+1,left,right-v[id]);
    
    ans=max({ans2,ans3});
    mem[{id,{left,right}}]=ans;
    return ans;
    
}
void print(int id,long long left,long long right){
    if(id>=n)return;
    if(left<0||right<0)return;
    long long ans=solve(id,left,right);
    long long ans2=-1,ans3=-1;
    
    if(left>=v[id])ans2=1+solve(id+1,left-v[id],right);
    if(right>=v[id])ans3=1+solve(id+1,left,right-v[id]);
    
    if(ans==ans2){
        cout<<"port"<<endl;
        print(id+1,left-v[id],right);
        return;
    }
    else if(ans==ans3){
        cout<<"starboard"<<endl;
        print(id+1,left,right-v[id]);
        return;
    }
    
    
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int t;
    cin>>t;
    while(t--){
        v.clear();
        long long len_ferry;
        cin>>len_ferry;
        long long f;
        //memset(mem,-1,sizeof mem);
        mem.clear();
        while(cin>>f&&f>0)v.push_back(f);
        n=v.size();
        long long ans=solve(0,len_ferry*100,len_ferry*100);//current id length left, length right
        cout<<ans<<endl;
        print(0,len_ferry*100,len_ferry*100);
        if(t)cout<<endl;
    }

    return 0;
}


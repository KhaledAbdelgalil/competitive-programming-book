
#include <bits/stdc++.h>

using namespace std;

int ans;
int s,d;
vector<int>months(12);
void solution(int i,int sum){
    if(i>=5){
        if(accumulate(months.begin()+i-5,months.begin()+i,0)>=0)return;
    }
    if(i==12){
        ans=max(sum,ans);
        return;
    }
    
    //prune search space as we add s first so first solution will be the best one
    if(ans==numeric_limits<int>::min()){
        months[i]=s;
        solution(i+1,sum+s);
        months[i]=-d;
        solution(i+1,sum-d);
    }
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    while(cin>>s>>d){
        ans=numeric_limits<int>::min();
        solution(0,0);
        if(ans>0)
        cout<<ans<<endl;
        else cout<<"Deficit"<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000+5

int NOD[MAX]={0};//contains no of divisors for example NOD[2]=2

int main(){
    
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    for(int factor=1;factor<MAX;factor++)
        for(int num=factor;num<MAX;num+=factor)//num(that has this factor) will not be less than factor
            NOD[num]++;
    std::vector<int>seq(MAX,0);
    seq[0]=1;
    for(int i=1;i<MAX;i++)
    seq[i]=seq[i-1]+NOD[ seq[i-1] ];
    //cout<<seq[MAX-1];
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int A,B;
        cin>>A>>B;
        cout<<"Case "<<i<<": "<<distance( lower_bound(seq.begin(),seq.end(),A),upper_bound(seq.begin(),seq.end(),B) )<<endl;
    }
    return 0;
}


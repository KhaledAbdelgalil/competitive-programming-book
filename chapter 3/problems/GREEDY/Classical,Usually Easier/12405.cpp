#include<bits/stdc++.h>
using namespace std;
int main() {
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int t;
    cin>>t;
    int test=1;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='#')continue;
            //put it after that cell to cover it and center and right think greedy
            cnt++;
            i+=2;// as i++ in for loop will increase it to cover 3 cells
        }
        cout<<"Case "<<test++<<": "<<cnt<<endl;
    }
}

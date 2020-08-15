
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int n;
    cin>>n;
    while(n--){
        pair<long long ,long long>left={0,1},mid={1,1},right={1,0};
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                right=mid;
                mid.first=mid.first+left.first;
                mid.second=mid.second+left.second;
            }
            else{
                left=mid;
                mid.first=mid.first+right.first;
                mid.second=mid.second+right.second;
            }
        }
        cout<<mid.first<<"/"<<mid.second;
        cout<<endl;
    }
    return 0;
}


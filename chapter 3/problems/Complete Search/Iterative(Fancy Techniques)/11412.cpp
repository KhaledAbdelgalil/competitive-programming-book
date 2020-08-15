#include <bits/stdc++.h>
using namespace std;
string colors="ROGBYV";
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        int n1,n2,n3,n4;
        cin>>s1>>n1>>n2>>s2>>n3>>n4;
        sort(colors.begin(),colors.end());
        bool flag=0;
        do{
            int n1_c=0,n2_c=0,n3_c=0,n4_c=0;    
            string compare=colors.substr(0,4);
            for(int i=0;i<4;i++){
                if(compare[i]==s1[i])n1_c++;
                else{
                    if(compare.find(s1[i])!=string::npos)n2_c++;
                }
                if(compare[i]==s2[i])n3_c++;
                else if(compare.find(s2[i])!=string::npos)n4_c++;
            }
            if(n1_c!=n1)continue;
            if(n2_c!=n2)continue;
            if(n3_c!=n3)continue;
            if(n4_c!=n4)continue;
            flag=1;
            break;
        }while(next_permutation(colors.begin(),colors.end()));
        if(flag)cout<<"Possible"<<endl;
        else cout<<"Cheat"<<endl;
    }
    return 0;
}


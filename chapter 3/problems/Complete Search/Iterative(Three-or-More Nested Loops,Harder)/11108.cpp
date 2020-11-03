#include <bits/stdc++.h>
using namespace std;

string comb[32] = {"00000", "00001","00010","00011","00100","00101","00110","00111","01001","01010","01011","01100","01101","01110","01111","10000","10001","10010","10011","10100","10101","10110","10111","11000","11001","11010","11011","11100","11101","111110","11111"};
string s;
int indx_pos;
//p q r s t
bool solve(int curr_comb){
    if(s[indx_pos]=='p')return comb[curr_comb][0]=='1';
    if(s[indx_pos]=='q')return comb[curr_comb][1]=='1';
    if(s[indx_pos]=='r')return comb[curr_comb][2]=='1';
    if(s[indx_pos]=='s')return comb[curr_comb][3]=='1';
    if(s[indx_pos]=='t')return comb[curr_comb][4]=='1';
    if(s[indx_pos]=='K'){
        indx_pos++;
        bool left=solve(curr_comb);
        indx_pos++;
        bool right=solve(curr_comb);
        return left&&right;
    }
    
    if(s[indx_pos]=='A'){
        indx_pos++;
        bool left=solve(curr_comb);
        indx_pos++;
        bool right=solve(curr_comb);
        return left||right;
    }
    
    if(s[indx_pos]=='N'){
        indx_pos++;
        bool left=solve(curr_comb);
        return !left;
    }
    if(s[indx_pos]=='C'){
        indx_pos++;
        bool left=solve(curr_comb);
        indx_pos++;
        bool right=solve(curr_comb);
        return !left||right;
    }
    if(s[indx_pos]=='E'){
        indx_pos++;
        bool left=solve(curr_comb);
        indx_pos++;
        bool right=solve(curr_comb);
        return left==right;
    }
    
    
    
}
int main(){
    
    
    while(cin>>s&&s!="0"){
    bool taut=true;
    for(int i=0;i<32;i++){
        indx_pos=0;
        taut=taut&&solve(i);
        if(!taut)break;
    }
    if(taut)cout<<"tautology"<<endl;
    else cout<<"not"<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
 std::vector<string>two,four,six,eight;
 vector< string > answers[4]={
    {"00","01","81"},{"0000","0001","2025","3025","9801"},
    {"000000","000001","088209","494209","998001"},
    {"00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001"}
 };

//I get answers once then save it in code and get answers in o(1)
 void pre_processing(){
     //2 digit pre-processing
    for(int i=0;i<=99;i++){
        int number=i%10+(i/10);
        if(number*number==i){
            stringstream ss;
            ss<<i;
            string s;
            ss>>s;
            for(int j=s.size();j<2;j++)s='0'+s;
            two.push_back(s);
        }
    }
    
    //4 digit pre-processing
    for(int i=0;i<=9999;i++){
        int n=i;
        int number1=n%100;
        n/=100;
        
        int number2=n;
        
        //if(i==3025)cout<<number1<<" "<<number2<<endl;
        if((number2+number1)*(number1+number2)==i){
            stringstream ss;
            ss<<i;
            string s;
            ss>>s;
            for(int j=s.size();j<4;j++)s='0'+s;
            four.push_back(s);
        }
    }
    //6 digit pre-processing
    for(int i=0;i<=999999;i++){
        int n=i;
        int number1=n%1000;
        n/=1000;
        int number2=n;
        if((number2+number1)*(number1+number2)==i){
            stringstream ss;
            ss<<i;
            string s;
            ss>>s;
            for(int j=s.size();j<6;j++)s='0'+s;
            six.push_back(s);
        }
    }
    
    //8 digit pre-processing
    for(int i=0;i<=99999999;i++){
        int n=i;
        int number1=n%10000;
        n/=10000;
        int number2=n;
        if((number2+number1)*(number1+number2)==i){
            stringstream ss;
            ss<<i;
            string s;
            ss>>s;
            for(int j=s.size();j<8;j++)s='0'+s;
            eight.push_back(s);
        }
    }
    
 }
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    
   
    //pre_processing();
    int n;
    while(cin>>n){
        //2 4 6 8
        int idx=n/2-1;
        for(int i=0;i<answers[idx].size();i++)cout<<answers[idx][i]<<endl;
    }
    return 0;
}


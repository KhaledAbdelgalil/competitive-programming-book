#include<bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
map<char,char>mp;
/*
Character Reverse Character Reverse Character Reverse
A          A         M       M         Y         Y
B                    N                 Z         5
C                    O       O         1         1
D                    P                 2         S
E          3         Q                 3         E
F                    R                 4
G                    S       2         5         Z
H          H         T       T         6
I          I         U       U         7
J          L         V       V         8         8
K                    W       W         9
L         J          X       X
*/

int pal(string s)
{
    
    if(s.size()==1)return 1;
    for(int i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-i-1])return 0;
    return 1;
}
int mirror(string in)
{
    string g(in.begin(),in.end());
    for(int i=0;i<in.size();i++)
    {
        if(mp.find(in[i])!=mp.end())in[i]=mp[in[i]];
       else return 0;
    }
    //cout<<in<<endl;
    string f(in.begin(),in.end());
    reverse(f.begin(),f.end());
    //cout<<f<<endl;
    //cout<<g<<endl;
    if(f==g)return 1;
    else return 0;
}
int main()
{
mp.insert({'A','A'});
mp['Z']='5';
mp['E']='3';
mp['1']='1';
mp['H']='H';
mp['2']='S';
mp['I']='I';
mp['3']='E';
mp['J']='L';
mp['L']='J';
mp['5']='Z';
mp['M']='M';
mp['8']='8';
mp['O']='O';
mp['S']='2';
mp['T']='T';
mp['U']='U';
mp['V']='V';
mp['W']='W';
mp['X']='X';
mp['Y']='Y';
    
   /* std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!*/
    string input;
    while(cin>>input)
    {
       int plain,mirr;
       plain=pal(input);
       mirr=mirror(input);
       if(plain&&mirr)
       cout<<input<<" -- is a mirrored palindrome."<<endl;
       else if(!plain&&mirr)
       cout<<input<<" -- is a mirrored string."<<endl;
       else if(!plain&&!mirr)
       cout<<input<<" -- is not a palindrome."<<endl;
       else cout<<input<<" -- is a regular palindrome."<<endl;
       cout<<endl;
    }
    return 0;
}


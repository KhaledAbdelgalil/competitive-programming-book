#include <bits/stdc++.h>
using namespace std;
/*
A, B, and C map to 2
D, E, and F map to 3
G, H, and I map to 4
J, K, and L map to 5
M, N, and O map to 6
P, R, and S map to 7
T, U, and V map to 8
W, X, and Y map to 9
*/
map<char,char>mp;
string modify(string s)
{
    string out;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))out.push_back(s[i]);
        else if(isalpha(s[i]))
        {
           out.push_back(mp[s[i]]);   
        }
        
        if(out.size()==3)out.push_back('-');
    }
    return out;
}

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
    {
        mp['A']=mp['B']=mp['C']='2';
        mp['D']=mp['E']=mp['F']='3';
        mp['G']=mp['H']=mp['I']='4';
        mp['J']=mp['K']=mp['L']='5';
        mp['O']=mp['N']=mp['M']='6';
        mp['S']=mp['R']=mp['P']='7';
        mp['V']=mp['U']=mp['T']='8';
        mp['W']=mp['X']=mp['Y']='9';
    }
    int t,n;
    cin>>t;
    map<string,int>telefons;
    while(t--)
    {
        telefons.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string tel;
            cin>>tel;
            tel=modify(tel);
            telefons[tel]++;
            //cout<<tel<<endl;
        }
        
        for(auto it=telefons.begin();it!=telefons.end();it++)
        {
            if(it->second > 1)
            cout<<it->first<<" "<<it->second<<endl;
        }
        if(telefons.size()==n)cout<<"No duplicates."<<endl;
        
        if(t) cout<<endl;
    }
   
   return 0;
}


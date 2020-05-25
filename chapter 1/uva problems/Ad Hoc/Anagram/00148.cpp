#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi>vii;
typedef vector<bool>vb;

string w;
vs dict;
vii freq;
vb available;
vb add_to_output;

void setAvailables()
{
    available.assign(dict.size(),1);
    stringstream ss(w);
    string t;
    while(ss>>t)
    {
        for(int i=0;i<dict.size();i++)
        if(t==dict[i])available[i]=0;
    }
    return;
}
vi getFreq(string t)
{
    vi f(26);
    
    for(int i=0;i<t.size();i++)
    if(isalpha(t[i]))
    f[t[i]-'A']++;
    
    return f;
}
void getAngram(int index,vi f)
{
    bool complete=true;
    for(int i=0;i<26;i++)
    {
        int d=f[i]-freq[index][i];
        if(d<0)return;
        if(d)complete=false;
        f[i]=d;
    }
    if(complete)
    {
        cout<<w<<" = ";
        for(int i=0;i<index;i++)
        if(add_to_output[i])cout<<dict[i]<<" ";
        cout<<dict[index]<<endl;
    }
    else 
    {
        add_to_output[index]=1;
        for(int i=index+1;i<dict.size();i++)
        if(available[i])getAngram(i,f);
        add_to_output[index]=0;
    }
    return;
}
int main()
{
  /* std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    
    while(cin>>w&&w!="#")
    dict.push_back(w);
    
    freq.resize(dict.size());
    for(int i=0;i<dict.size();i++)
    freq[i]=getFreq(dict[i]);
    
    while(getline(cin,w)&&w!="#")
    {
        setAvailables();
        add_to_output.assign(dict.size(),0);
        vi freq_w=getFreq(w);
        for(int i=0;i<dict.size();i++)
        if(available[i])getAngram(i,freq_w);
    }
    
    return 0;
}


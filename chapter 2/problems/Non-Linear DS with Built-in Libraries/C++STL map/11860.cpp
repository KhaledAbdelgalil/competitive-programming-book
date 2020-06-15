#include<bits/stdc++.h>
using namespace std;


vector<string>words;
map<string,int>word_idx_map;
int idx=0;//contain number of unique words 
int q,p;
void init()
{
    string s;
    while(getline(cin,s)&&s!="END")
    {
        string t="";
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))t.push_back(s[i]);
            else if(t!="") {
                if(word_idx_map.find(t)!=word_idx_map.end())
                {
                    words.push_back(t);
                }
                else 
                {
                    words.push_back(t);
                    word_idx_map[t]=idx++;
                }
                t="";
            }
        }
        if(t!=""){
            if(word_idx_map.find(t)!=word_idx_map.end())
                {
                    words.push_back(t);
                }
                else 
                {
                    words.push_back(t);
                    word_idx_map[t]=idx++;
                }
        }
    }
}
void solve()
{
    vector<int>frequency_of_uniqueWords(idx,0);
    int totalWords_needed_to_be_included=idx;
    for(int i=0, j=0;i<words.size();i++)
    {
        
        if(frequency_of_uniqueWords[ word_idx_map[ words[i] ] ]++ ==0)
        totalWords_needed_to_be_included--;
	//you are on word(j) that comes again in range by(i) so move away from it
        while(j<words.size()&&frequency_of_uniqueWords[word_idx_map[ words[j] ] ]>1)// a b b c a b c we want last a
        {
            frequency_of_uniqueWords[ word_idx_map[ words[j] ] ]--;
            j++;
        }
        if(totalWords_needed_to_be_included==0&&i-j<p-q)
        {
            p=i;
            q=j;
        }
    }
}
int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   int t;
   cin>>t;
   cin.ignore();
   for(int test=1;test<=t;test++)
   {
       init();
       q=0,p=words.size();
       solve();
       cout<<"Document "<<test<<": "<<q+1<<" "<<p+1<<endl;
       idx=0;       
       word_idx_map.clear();
       words.clear();
   }
    return 0;
}


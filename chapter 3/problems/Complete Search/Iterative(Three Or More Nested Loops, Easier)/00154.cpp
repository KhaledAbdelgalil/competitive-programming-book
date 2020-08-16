#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    string s;
    while(cin>>s&&s!="#"){
        
        std::vector< map < char,char > >vecs;
        do{
            map<char,char>mp_x;
            mp_x[s[0]]=s[2];
            mp_x[s[4]]=s[6];
            mp_x[s[8]]=s[10];
            mp_x[s[12]]=s[14];
            mp_x[s[16]]=s[18];
            vecs.push_back(mp_x);
        }while(cin>>s&&s[0]!='e');
        
        int minn=5*vecs.size()+5;
        int index=-1;
        for(int i=0;i<vecs.size();i++){
            int needed_alloc=0;
            for(int j=0;j<vecs.size();j++){
                if(vecs[i]['r']!=vecs[j]['r'])needed_alloc++;
                if(vecs[i]['o']!=vecs[j]['o'])needed_alloc++;
                if(vecs[i]['y']!=vecs[j]['y'])needed_alloc++;
                if(vecs[i]['g']!=vecs[j]['g'])needed_alloc++;
                if(vecs[i]['b']!=vecs[j]['b'])needed_alloc++;
            }
            if(needed_alloc<minn){
                minn=needed_alloc;
                index=i;
            }
        }
        cout<<index+1<<endl;
    }
    return 0;
}


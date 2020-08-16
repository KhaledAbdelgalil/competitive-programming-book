#include <bits/stdc++.h>
using namespace std;

int main(){
   
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
  
  
    int n;
    set<int>scores;
    for(int i=0;i<=20;i++){
        scores.insert(i);
        scores.insert(i*2);
        scores.insert(i*3);
    }
    scores.insert(50);
    std::vector<int>vscores(scores.begin(),scores.end());
    
    while(cin>>n&&n>0){
        
        int cnt_perm=0;
        int cnt_comb=0;
        bool taken[61][61][61]={0};
        for(int i=0;i<vscores.size();i++)
            for(int j=0;j<vscores.size();j++)
                for(int k=0;k<vscores.size();k++)
                {
                    if(vscores[i]+vscores[j]+vscores[k]!=n)continue;
                    
                    cnt_perm++;
                    
                    if(taken[vscores[i]][vscores[j]][vscores[k]]==0){
                        cnt_comb++;
                        taken[vscores[i]][vscores[j]][vscores[k]]=1;
                        taken[vscores[i]][vscores[k]][vscores[j]]=1;
                        taken[vscores[j]][vscores[i]][vscores[k]]=1;
                        taken[vscores[j]][vscores[k]][vscores[i]]=1;
                        taken[vscores[k]][vscores[i]][vscores[j]]=1;
                        taken[vscores[k]][vscores[j]][vscores[i]]=1;
                    }
                }
       if (cnt_comb == 0 && cnt_perm == 0) {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
        } else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << cnt_comb << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << cnt_perm << "." << endl;
        }
        cout << "**********************************************************************" << endl;
 
    }
    cout << "END OF OUTPUT" << endl;
   
    return 0;
}


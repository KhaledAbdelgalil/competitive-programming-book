#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int f,r;
    while(cin>>f>>r){
        std::vector<double>rears(r),fronts(f);
        for(int i=0;i<f;i++)cin>>fronts[i];
        for(int j=0;j<r;j++)cin>>rears[j];
        vector<double>ans;
        for(int i=0;i<r;i++)
            for(int j=0;j<f;j++){
              ans.push_back(rears[i]/fronts[j]);
        }
        
        sort(ans.begin(),ans.end());
        double maxx=0;
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i+1]/ans[i]>maxx)maxx=ans[i+1]/ans[i];
        }
        cout << setprecision(2) << fixed << maxx << endl;
    }

    return 0;
}


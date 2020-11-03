#include <bits/stdc++.h>
using namespace std;
vector<int>spicmen;
//vector< pair<int,int> >chambers;
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int C,S;
    int test=1;
    while(cin>>C>>S){
        //chambers.resize(C);
        spicmen.assign(2*C,0);
        double totalWeight=0;
        double imbalance=0;
        for(int i=0;i<S;i++)cin>>spicmen[i],totalWeight+=spicmen[i];
        double averageWeight=totalWeight/C;
        sort(spicmen.begin(),spicmen.end());
       /* for(int i=0;i<C;i++){
            chambers[i].first=spicmen[i];
            chambers[i].second=spicmen[spicmen.size()-i-1];
            imbalance+=abs(chambers[i].first+chambers[i].second-averageWeight);
        }*/
        cout<<"Set #"<<test++<<endl;
        /*for(int i=0;i<C;i++){
            cout<<" "<<i<<":";
            if(chambers[i].first)cout<<" "<<chambers[i].first;
            if(chambers[i].second)cout<<" "<<chambers[i].second;
            cout<<endl;
        }*/
         for(int i=0;i<C;i++){
            cout<<" "<<i<<":";
            if(spicmen[i])cout<<" "<<spicmen[i];
            if(spicmen[2*C-i-1])cout<<" "<<spicmen[2*C-i-1];
            cout<<endl;
            imbalance+=abs(spicmen[i]+spicmen[2*C-i-1]-averageWeight);
        }
        cout<<"IMBALANCE = ";
        printf("%.5f\n",imbalance);
        cout<<endl;
    }
    return 0;
}


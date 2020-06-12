#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    int n;
    while(cin>>n&&n)
    {
        vector<int>cols(n);
        vector<int>rows(n);
        
        for(int i=0;i<rows.size();i++)
         for(int j=0;j<cols.size();j++)
        {
            int x;
            cin>>x;
            if(x==1)rows[i]++,cols[j]++;
        }
        
        vector<int>cols_corr;
        vector<int>rows_corr;
        for(int i=0;i<n;i++)
        {
            if(rows[i]%2!=0)rows_corr.push_back(i+1);
            if(cols[i]%2!=0)cols_corr.push_back(i+1);
        }
        
        if(rows_corr.size()==0&&cols_corr.size()==0)cout<<"OK"<<endl;
        else if (rows_corr.size()==1&&cols_corr.size()==1)cout<<"Change bit ("<<rows_corr[0]<<","<<cols_corr[0]<<")"<<endl;
        else cout<<"Corrupt"<<endl;
    }

    return 0;
}


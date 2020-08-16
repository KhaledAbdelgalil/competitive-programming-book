/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    int T,R,H;
    int mat_T_R[25][25];
    int mat_R_H[25][25];
    int mat_H_T[25][25];
    int prices_T[25];
    int prices_R[25];
    int prices_H[25];
    while(cin>>T>>R>>H){
        for(int i=0;i<T;i++){
            cin>>prices_T[i];
            for(int j=0;j<R;j++)cin>>mat_T_R[i][j];
        }
        for(int i=0;i<R;i++){
            cin>>prices_R[i];
            for(int j=0;j<H;j++)cin>>mat_R_H[i][j];
        }
        for(int i=0;i<H;i++){
            cin>>prices_H[i];
            for(int j=0;j<T;j++)cin>>mat_H_T[i][j];
        }
        int minn=INT_MAX;
        int t=-1,h=-1,r=-1;
        for(int i=0;i<T;i++)
            for(int j=0;j<R;j++)
                for(int k=0;k<H;k++){
                    if(mat_T_R[i][j]==0&&mat_R_H[j][k]==0&&mat_H_T[k][i]==0){
                        if(prices_T[i]+prices_R[j]+prices_H[k]<minn)t=i,r=j,h=k,minn=prices_T[i]+prices_R[j]+prices_H[k];
                    }
                }
        if(minn==INT_MAX)cout<<"Don't get married!"<<endl;
        else cout<<t<<" "<<r<<" "<<h<<":"<<minn<<endl;
    }

    return 0;
}


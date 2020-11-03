#include <bits/stdc++.h>
using namespace std;
bool valid(vector<int>row){
    for(int i=0;i<8;i++){
        for(int j=i+1;j<8;j++){
            if(abs(i-j)==abs(row[i]-row[j]))//same diagonal
            return false;
        }
    }
    return true;
}
int main()
{
 int t;
 cin>>t;
 while(t--){
     int a,b;
     cin>>a>>b;
     a--,b--;
     cout<<"SOLN       COLUMN"<<endl;
     cout<<" #      1 2 3 4 5 6 7 8\n\n";
     int id=1;
     vector<int>row_indices={0,1,2,3,4,5,6,7};
     do{
         if(row_indices[b]==a)//check that in this column and row there is a queen
         {
            if(valid(row_indices)){
                printf("%2d      ",id++);
                cout<<row_indices[0]+1;
                for(int i=1;i<row_indices.size();i++)
                cout<<" "<<row_indices[i]+1;
                cout<<endl;
            }
         }

     }while(next_permutation(row_indices.begin(),row_indices.end()));
    if(t)cout<<endl;
 }

   return 0;
}


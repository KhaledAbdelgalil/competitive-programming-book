#include <bits/stdc++.h>
using namespace std;
int a,b;
vector<int>rows;
int id;
bool can_place(int r,int c){
for(int i=0;i<c;i++){
	if(rows[i]==r||abs(c-i)==abs(r-rows[i]))return false;
}
return true;
}
void solve(int c){
if(c==8&&rows[b]==a){
    printf("%2d      ",id++);
    cout<<rows[0]+1;
    for(int i=1;i<8;i++)
    cout<<" "<<rows[i]+1;
    cout<<endl;
}
else{
//rows
for(int i=0;i<8;i++){
    if(can_place(i,c)){rows[c]=i;solve(c+1);}
}
}
}
int main()
{
 int t;
 cin>>t;
 while(t--){
     cin>>a>>b;
     a--,b--;
     id=1;
     cout<<"SOLN       COLUMN"<<endl;
     cout<<" #      1 2 3 4 5 6 7 8\n\n";
     rows.assign(8,0);
     solve(0);
     if(t)cout<<endl;
 }

   return 0;
}


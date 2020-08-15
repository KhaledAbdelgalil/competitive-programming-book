#include <bits/stdc++.h>
using namespace std;
int t;
int n,m;
char mat[10][10];
string search(int i,int j,char se){
    if(i-1>=0){
        if(mat[i-1][j]==se)return "forth";
    }
    if(j+1<m){
        if(mat[i][j+1]==se)return "right";
    }
    return "left";
}
int main()
{
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    cin>>t;
    while(t--){
        
        cin>>n>>m;
        
        int str,stc,endr,endc;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
                if(mat[i][j]=='@')str=i,stc=j;
                else if(mat[i][j]=='#')endr=i,endc=j;
            }        
        }
        string s=search(str,stc,'I');
        cout<<s<<" ";
        if(s=="forth"){
            str=str-1;
        }
        else if(s=="right")stc++;
        else stc--;
        s=search(str,stc,'E');
        
        cout<<s<<" ";
        if(s=="forth"){
            str=str-1;
        }
        else if(s=="right")stc++;
        else stc--;
        s=search(str,stc,'H');
        
        cout<<s<<" ";
        if(s=="forth"){
            str=str-1;
        }
        else if(s=="right")stc++;
        else stc--;
        s=search(str,stc,'O');
        
        
        cout<<s<<" ";
        if(s=="forth"){
            str=str-1;
        }
        else if(s=="right")stc++;
        else stc--;
        s=search(str,stc,'V');
        
        
        cout<<s<<" ";
        if(s=="forth"){
            str=str-1;
        }
        else if(s=="right")stc++;
        else stc--;
        s=search(str,stc,'A');
        
        
        cout<<s<<" ";
        if(s=="forth"){
            str=str-1;
        }
        else if(s=="right")stc++;
        else stc--;
        s=search(str,stc,'#');
        cout<<s<<endl;
    }
    return 0;
}


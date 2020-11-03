#include <bits/stdc++.h>
using namespace std;
std::vector<vector<int> >balls;
bool flags[100000000]={0};

int main(){
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    
    vector<int>v(3,0);
    balls.push_back(v);
    
    int start_ball=1;
    int t;
    cin>>t;
    while(t--){
        int D,I;
        cin>>D>>I;
        if(I<start_ball){
            v=balls[I];
            int last_ball_in_depth=pow(2.0,D)-1;
            int i;
            for( i=0;i<v.size();i++){
                if(last_ball_in_depth<v[i])break;
            }
            cout<<v[i-1]<<endl;
        }
        else{
            for(;start_ball<=I;start_ball++)
            {
                int st=1;
                int last=pow(2.0,20)-1;
                v.clear();
                while(st<=last){
                    v.push_back(st);
                    if(flags[st]==0 ) //move left
                    {
                        flags[st]=1;
                        st=st*2;
                    }
                    else{//move right
                        flags[st]=0;
                        st=st*2+1;
                    }
                }
                balls.push_back(v);
            }
            
            v=balls[I];
            int last_ball_in_depth=pow(2.0,D)-1;
            int i;
            for( i=0;i<v.size();i++){
                if(last_ball_in_depth<v[i])break;
            }
            cout<<v[i-1]<<endl;
        }
    }
    cin>>t;
    return 0;
}


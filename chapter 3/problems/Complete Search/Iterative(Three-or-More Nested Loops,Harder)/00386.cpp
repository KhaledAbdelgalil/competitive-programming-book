
#include <bits/stdc++.h>

using namespace std;

int main()
{
   
    map< pair<long long ,pair<long long ,long long> >,bool>mp;
    long long a,b,c,d;
    for(a=6;a<=200;a++){
        long long req=a*a*a;
        for(b=2;b<=a;b++){
            long long ansb=b*b*b;
            if(ansb>req)break;
            for(c=2;c<=a;c++){
                long long ansc=c*c*c;
                if(ansb+ansc>req)break;
                for(d=2;d<=a;d++){
                    long long ansd=d*d*d;
                    if(ansb+ansc+ansd>req)break;
                    else if(ansb+ansc+ansd==req){
                        std::vector<long long>v({b,c,d});
                        sort(v.begin(),v.end());
                        if(mp.find({ v[0],{v[1],v[2]} })==mp.end()){
                        cout<<"Cube = "<<a<<", Triple = ("<<v[0]<<","<<v[1]<<","<<v[2]<<")"<<endl;
                        mp[{v[0],{v[1],v[2]}}]=1;
                        }
                        break;
                    }
                    
                }
                
            }
        }
        
    }
    return 0;
}


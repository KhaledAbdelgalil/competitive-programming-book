
/*         
             (x,y)





       A------x-----B
       
    (X-A)^2+y^2=d^2 and (B-X)^2+y^2=d^2
    so range of radar installition A/B=x+ or - sqrt(d2-y2);
*/
#include <bits/stdc++.h>

using namespace std;
int n,d;
pair<double,double>islands_range_coverage[1005];
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
    
    int test=1;
    while(cin>>n>>d){
        if(n==0&&d==0)break;
        bool flag=1;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            if(y>d)flag=0;
            else{
                islands_range_coverage[i].first=x-sqrt(d*d-y*y);
                islands_range_coverage[i].second=x+sqrt(d*d-y*y);
            }
        }
        if(flag==0){
            cout<<"Case "<<test++<<": "<<-1<<endl;
        }
        else{
            double r=-1e9;
            int i=0;
            int cnt=0;
            sort(islands_range_coverage,islands_range_coverage+n);//sort and then walk on x-axis
            while(i<n){
                while(i<n&&islands_range_coverage[i].first<=r){
                    if(islands_range_coverage[i].second<r)r=islands_range_coverage[i].second;//to have i island in range radar
                    i++;
                }
                r=islands_range_coverage[i].second;
                cnt++;
            }
            cout<<"Case "<<test++<<": "<<cnt-1<<endl;//cnt-1 as last i<n is counted but we finished
        }
    }

    return 0;
}


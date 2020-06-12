#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
   
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        std::vector<string>out(n);
        for(int i=0;i<n;i++)
        cin>>out[i];
        int op;
        cin>>op;
        while(op--)
        {
            string o;
            cin>>o;
            if(o=="row"){
                int a,b;
                cin>>a>>b;
                swap(out[a-1],out[b-1]);
            }
            else if(o=="col")
            {
                int a,b;
                cin>>a>>b;
                for(int i=0;i<n;i++)
                {
                   /* char temp=out[i][a-1];
                    out[i][a-1]=out[i][b-1];
                    out[i][b-1]=temp;*/
                    swap(out[i][a-1],out[i][b-1]);
                }
            }
            else if(o=="inc")
            {
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                    out[i][j]=(char)(((int)(out[i][j]-'0'+1)%10)+'0');
            }
            else if(o=="dec")
            {
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                    out[i][j]=(char)(((int)(out[i][j]-'0'-1+10)%10)+'0');
            }
            else if(o=="transpose")
            {
                vector<string>transposed(out.begin(),out.end());
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                    transposed[i][j]=out[j][i];
                    
                out.assign(transposed.begin(),transposed.end());
            }
        }
        cout<<"Case #"<<i+1<<endl;
        for(int i=0;i<n;i++)
        cout<<out[i]<<endl;
        cout<<endl;
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;
vector<int>weights;


int n;
int getPotency(int corner)
{
    int ret=0;
    for(int i=0;i<n;i++)
    {
	//difference between corner and neighbour is 2^0 2^1 ......2^(n-1)
        int idx_neighbour=pow(2.0,double(i));
        //if contains say 2 subtract 2 else add draw cube and add points on drawing and you will see that
        if(corner&(1<<i))
            ret+=weights[corner-idx_neighbour];
        else ret+=weights[corner+idx_neighbour];
    }
    return ret;
}
int main()
{
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    while(cin>>n)
    {
     
        weights.resize((int)pow(2.0,double(n)));
        for(int i=0;i<weights.size();i++)
        cin>>weights[i];
        int maxPotency=0;
        for(int i=0;i<weights.size();i++)
        {
            int potency_corner=getPotency(i);
            for(int j=0;j<n;j++)
            {
                int idx_neighbour=pow(2.0,double(j));
                if(i&(1<<j))
                {
                  int ret=getPotency(i-idx_neighbour);
                  maxPotency=max(ret+potency_corner,maxPotency);
                }
                else 
                {
                  int ret=getPotency(i+idx_neighbour);
                  maxPotency=max(ret+potency_corner,maxPotency);                 
                }
            }
        }
        cout<<maxPotency<<endl;
    }
    return 0;
}


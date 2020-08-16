#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
    while(cin>>n,n){
        char tmp;
        cin>>tmp;
        std::vector<int>nums(n),nums_indices(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            nums_indices[nums[i]]=i;
        }
        bool isAnti=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int third_num=2*nums[j]-nums[i];//get number that completes progression
                if(third_num>=0&&third_num<n){
                    int index_third_num=nums_indices[third_num];
                    if(index_third_num>j){
                        isAnti=0;
                        break;
                    }
                }
                if(!isAnti)break;
            }
            if(!isAnti)break;
        }
        
        if(isAnti)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }

    return 0;
}


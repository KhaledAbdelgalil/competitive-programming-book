
#include <iostream>

using namespace std;

int main()
{
    int n;
    bool first=1;
    while(cin>>n&&n){
        
        bool flag=0;
        if(!first)puts("");
        first=0;
        for(int fghij=1234;fghij*n<=98765;fghij++){
            int abcde=fghij*n;
            int temp,used=fghij<10000;//if fghij is 0xxxx we have to flag it
            temp=abcde;
            while(temp){
                used|=(1<<(temp%10));
                temp/=10;
            }
            temp=fghij;
            while(temp){
                used|=(1<<(temp%10));
                temp/=10;
            }
            //check all digits are used
            if(used==(1<<10)-1)flag=1,printf("%0.5d / %0.5d = %d\n",abcde,fghij,n);
        }
        if(flag==0)cout<<"There are no solutions for "<<n<<"."<<endl;
        
    }
    return 0;
}


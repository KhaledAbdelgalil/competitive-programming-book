#include <bits/stdc++.h>
using namespace std;

int digits_sum(int n){
    int sum = 0;
    char s[12];
    sprintf(s, "%d", n);
    for(int i = 0; s[i]; i++)
        sum += s[i]-'0';
    return sum;
}

int primeFactors_sum(int n)  
{  
    // sum the number of 2s that divide n  
    bool flag = 0;
    int sum = 0;
    
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 2; i <= sqrt(n); i++)  
    {  
        int times = 0;
        // While i divides n, sum i and divide n  
        
        while (n % i == 0)  
        {  
            times++; 
            n = n/i;
            flag = 1;
        }  
        sum += digits_sum(i) * times;
    }  
  
    // This condition is to handle the case when n  
    if (n != 1)  
        sum += digits_sum(n);
    if(flag == 1)// not a prime number
        return sum;
    else return -1;
}  


int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = n + 1;; i++){
            int sum1 = primeFactors_sum(i);
            int sum2 = digits_sum(i);
            if(sum1 == sum2){
                cout << i << endl;
                break;
            }
        }
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
map < unsigned long long , bool > found;
vector < unsigned long long > ans;
string suffix(int n){
    int f = n % 100;
    if(f > 10 && f < 20)return "th";
    if(f % 10 == 1)return "st";
    if(f % 10 == 2)return "nd";
    if(f % 10 == 3)return "rd";
    return "th";
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    //pre-calculate the sequence
    
    unsigned long long num = 1;
    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long >>numbers;
    numbers.push(num);
    for(int i = 0; ans.size() <= 5842; i++){
        num = numbers.top();
        numbers.pop();
        while(!numbers.empty() && numbers.top() == num)//remove same elements
            numbers.pop();
        if(found[num] == false)
        ans.push_back(num), found[num] = true;//this is the smallest humble number now
        numbers.push(num * 2);
        numbers.push(num * 3);
        numbers.push(num * 5);
        numbers.push(num * 7);
    }
    //sort(ans.begin(), ans.end());
    int n;
    while(cin >> n && n)cout << "The " << n << suffix(n) << " humble number is " << ans[n - 1] << "." << endl;
    return 0;
}



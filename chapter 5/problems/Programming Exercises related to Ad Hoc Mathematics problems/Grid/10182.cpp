#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int x[MAX];
int y[MAX];
int counter = 2;
void update(int &i, int &j){
    x[counter] = i;
    y[counter] = j;
    counter++;
}
void down(int &i, int &j){
    j++;
    update(i, j);
}
void downleft(int &i, int &j){
    i--;
    j++;
    update(i, j);
}
void upleft(int &i, int &j){
    i--;
    update(i, j);
}
void up(int &i, int &j){
    j--;
    update(i, j);
}
void upright(int &i, int &j){
    i++;
    j--;
    update(i, j);
}
void downright(int &i, int &j){
    i++;
    update(i, j);
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int loop = 1;
    x[1] = 0;
    y[1] = 0;
    int current_x = 0;
    int current_y = 0;
    while(1){
        //by looking at cells you find that you move down then upleft,......
        //then in second loop move down then downleft , then upleft then upleft and so on
        if(counter >= 100000)break;//this is the maximum in our problem
        down(current_x, current_y);
        for(int i = 1; i < loop; i++)downleft(current_x, current_y);
        for(int i = 0; i < loop; i++)upleft(current_x, current_y);
        for(int i = 0; i < loop; i++)up(current_x, current_y);
        for(int i = 0; i < loop; i++)upright(current_x, current_y);
        for(int i = 0; i < loop; i++)downright(current_x, current_y);
        for(int i = 0; i < loop; i++)down(current_x, current_y);
        loop++;
    }
    while(cin >> counter){
        cout << x[counter] << " " << y[counter] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
The idea is first to find closet stations to every station(pre-processing step) but considering first x coordinate then y
this is done by sorting .
then dfs from first station,if number of distinct stations you can get to it is N => so all stations are reachable.

*/

#define MAX 1005
struct point{
    int x,y;
    bool operator <(const struct point & other){
        if(x != other.x)return x < other.x;
        return y < other.y;
    }
};

point points[MAX];
int ClosestIndices[MAX][2];
int n;
bool vis[MAX];
int square(int x){
    return x * x;
}
void FindClosetForAll(){
    for(int i = 0; i < n; i++){
        int &first = ClosestIndices[i][0],&second = ClosestIndices[i][1];
        first = -1,second = -1;
        int firstDis,secDis;
        for(int j = 0; j < n; j++){
            if(i != j){
                if(first == -1 || square(points[i].x - points[j].x) + square(points[i].y - points[j].y) < firstDis ){
                    second = first;
                    secDis = firstDis;
                    first = j;
                    firstDis = square(points[i].x - points[j].x) + square(points[i].y - points[j].y);
                }else if(second == -1 || square(points[i].x - points[j].x) + square(points[i].y - points[j].y) < secDis){
                    secDis = square(points[i].x - points[j].x) + square(points[i].y - points[j].y);
                    second = j;
                }
            }
        }
    }
}
int dfs(int i){
    if(i == -1 || vis[i] == true)return 0;//you already send to it(i.e not a new station)
    vis[i] = true;
    return 1 + dfs(ClosestIndices[i][0]) + dfs(ClosestIndices[i][1]);
}
int main(){
    
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    while(cin >> n && n){
        for(int i = 0; i < n; i++)cin >> points[i].x >> points[i].y;
        int xSource = points[0].x, ySource = points[0].y;
        sort(points, points + n);
        FindClosetForAll();
        bool valid = false;
        memset(vis, false, sizeof vis);
        for(int i = 0 ; i < n; i++){
            if(points[i].x == xSource && points[i].y == ySource){
                int numberStationsReached = dfs(i);
                if(numberStationsReached == n){
                    valid = true;
                }
                break;
            }
        }
        if(valid)
            cout << "All stations are reachable." << endl;
        else 
            cout<< "There are stations that are unreachable." << endl;
    }
    return 0;
}


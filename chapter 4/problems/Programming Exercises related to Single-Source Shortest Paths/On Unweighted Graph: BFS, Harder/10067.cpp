#include <bits/stdc++.h>
using namespace std;
int xStart, yStart, zStart, wStart, xEnd, yEnd, zEnd, wEnd;
vector<int>xForbidden, yForbidden, zForbiden, wForbidden;
void clear(int n){
    xForbidden.clear();
    xForbidden.resize(n);
    yForbidden.clear();
    yForbidden.resize(n);
    zForbiden.clear();
    zForbiden.resize(n);
    wForbidden.clear();
    wForbidden.resize(n);
}
int bfs(){
    map< pair< pair<int, int> , pair<int, int> > , int > mp_distance;//x, y ,z ,w 
    mp_distance[{ {xStart, yStart}, {zStart, wStart} }] = 0;
    queue< pair< pair<int, int> , pair<int, int> > >q;
    q.push({{xStart, yStart}, {zStart, wStart}});
    for(int i = 0; i < xForbidden.size(); i++){
        mp_distance[{{xForbidden[i], yForbidden[i]}, {zForbiden[i], wForbidden[i]}}] = -1;//forbidden to visit them on your way
    }
    while(!q.empty()){
        pair< pair<int, int> , pair<int, int> > front = q.front();
        q.pop();
        int x = front.first.first;
        int y = front.first.second;
        int z = front.second.first;
        int w = front.second.second;
        int d = mp_distance[{{x, y}, {z, w}}];
        
        if(x == xEnd && y == yEnd && z == zEnd && w == wEnd)return d;
        
        //change x only 
        int newX = x + 1;
        if(newX == 10) newX = 0;
        if(mp_distance.find({{newX, y}, {z, w}}) == mp_distance.end()){
            mp_distance[{{newX, y} , {z, w}}] = d + 1;
            q.push({{newX, y}, {z, w}});
        }
        newX = x - 1;
        if(newX == -1)newX = 9;
        if(mp_distance.find({{newX, y}, {z, w}}) == mp_distance.end()){
            mp_distance[{{newX, y} , {z, w}}] = d + 1;
            q.push({{newX, y}, {z, w}});
        }
        //change y only 
        int newY = y + 1;
        if(newY == 10) newY = 0;
        if(mp_distance.find({{x, newY}, {z, w}}) == mp_distance.end()){
            mp_distance[{{x, newY} , {z, w}}] = d + 1;
            q.push({{x, newY}, {z, w}});
        }
        newY = y - 1;
        if(newY == -1)newY = 9;
        if(mp_distance.find({{x, newY}, {z, w}}) == mp_distance.end()){
            mp_distance[{{x, newY} , {z, w}}] = d + 1;
            q.push({{x, newY}, {z, w}});
        }
        // change z only 
        
        int newZ = z + 1;
        if(newZ == 10) newZ = 0;
        if(mp_distance.find({{x, y}, {newZ, w}}) == mp_distance.end()){
            mp_distance[{{x, y} , {newZ, w}}] = d + 1;
            q.push({{x, y}, {newZ, w}});
        }
        newZ = z - 1;
        if(newZ == -1)newZ = 9;
        if(mp_distance.find({{x, y}, {newZ, w}}) == mp_distance.end()){
            mp_distance[{{x, y} , {newZ, w}}] = d + 1;
            q.push({{x, y}, {newZ, w}});
        }
        // change w only
        
        int newW = w + 1;
        if(newW == 10) newW = 0;
        if(mp_distance.find({{x, y}, {z, newW}}) == mp_distance.end()){
            mp_distance[{{x, y} , {z, newW}}] = d + 1;
            q.push({{x, y}, {z, newW}});
        }
        newW = w - 1;
        if(newW == -1)newW = 9;
        if(mp_distance.find({{x, y}, {z, newW}}) == mp_distance.end()){
            mp_distance[{{x, y} , {z, newW}}] = d + 1;
            q.push({{x, y}, {z, newW}});
        }
    }
    return -1;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    while(t--){
        cin >> xStart >> yStart >> zStart >> wStart >> xEnd >> yEnd >> zEnd >> wEnd;
        int n;
        cin >> n;
        clear(n);
        for(int i = 0; i < n; i++){
            cin >> xForbidden[i] >> yForbidden[i] >> zForbiden[i] >> wForbidden[i];
        }
        cout << bfs() << endl;
    }

    return 0;
}


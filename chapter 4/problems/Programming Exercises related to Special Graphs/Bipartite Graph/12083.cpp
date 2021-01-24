#include <bits/stdc++.h>
using namespace std;
//In any network flow problem, please draw relations and the graph on a paper to be able to solve it correctly
int graphR[505][505];
int n;
bool vis[505];
int parent[505];
class person
{
private:
    int height;
    string music;
    char sex;
    string sport;
public:
    person(int height_, char sex_, string music_, string sport_):height(height_),
    sex(sex_), music(music_), sport(sport_){};
    char getSex(){
        return sex;
    }
    string getMusic(){
        return music;
    }
    string getSport(){
        return sport;
    }
    int getHeight(){
        return height;
    }
};
vector < person > pupils;
bool bfs(int s, int t){
    memset(vis, 0, sizeof vis);
    vis[s] = 1;
    parent[s] = -1;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i = 0; i <= n + 1; i++){
            if(graphR[top][i] > 0 && vis[i] == 0){
                vis[i] = 1;
                parent[i] = top;
                q.push(i);
            }
        }
    }
    return vis[t] == 1;
}
int fordFulkerson(int s, int t){
    int maxFlow = 0;
    while(bfs(s, t)){
        int u, v;
        int min_flow_on_path = 1e9;
        for(v = t; v != s; v = parent[v]){
            u = parent[v];
            min_flow_on_path = min(graphR[u][v], min_flow_on_path);
        }
        for(v = t; v != s; v = parent[v]){
            u = parent[v];
            graphR[u][v] -= min_flow_on_path;
            graphR[v][u] += min_flow_on_path;
        }
        maxFlow += min_flow_on_path;
    }
    return maxFlow;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    while(t--)// n: number of pupils
    {
        pupils.clear();
        memset(graphR, 0, sizeof graphR);
        cin >> n;
        for(int i = 1; i <= n; i++){
            int h;
            string music, sport;
            char sex;
            cin >> h >> sex >> music >> sport;
            person p(h, sex, music, sport);
            pupils.push_back(p);
            if(sex == 'M'){//put Males on left and add them to source
                graphR[0][i] = 1;
            }else {//put Females on right and add them to target
                graphR[i][n + 1] = 1;
            }
        }
        
        //the problem is max flow on a bipartite graph to calculate MCBM, then calculate MIS = V - MCBM
        //building residual graph(total number of graphVertices = n + 2)
        //put M on left, F on right, add edge of couples.
        //get Max FLow, then answer = V - maxFlow
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                //there might be couple
                if(pupils[i].getSex() == 'M' && pupils[j].getSex() == 'F' && abs(pupils[i].getHeight() - pupils[j].getHeight()) <= 40
                    && pupils[i].getMusic() == pupils[j].getMusic() && pupils[i].getSport() != pupils[j].getSport()){
                    graphR[i + 1][j + 1] = 1;
                }
            }
        }
        //till here, you have built the residual graph
        int maxFlow = fordFulkerson(0, n + 1);
        cout << n - maxFlow << endl;
    }
    return 0;
}

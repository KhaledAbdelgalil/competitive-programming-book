#include <bits/stdc++.h>
using namespace std;
int adjMat[125][125];
map < int, int >NodeMapped;
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    string s;
    int test = 1;
    while(getline(cin, s)){
        if(s[0] == '0' && s[2] == '0')break;
        stringstream ss(s);
        for(int i = 0; i < 125; i++){
            for(int j = 0; j < 125; j++){
                if(i == j)adjMat[i][j] = 0;
                else adjMat[i][j] = 1e9;
            }
        }
        NodeMapped.clear();
        int index = 1;
        int u, v;
        while(ss >> u >> v){
            if(u == 0 && v == 0)break;
            if(NodeMapped.find(u) == NodeMapped.end()){
                NodeMapped[u] = index++;
            }
            if(NodeMapped.find(v) == NodeMapped.end()){
                NodeMapped[v] = index++;
            }
            adjMat[NodeMapped[u]][NodeMapped[v]] = 1;
        }
        for(int k = 1; k <= NodeMapped.size(); k++){
            for(int i = 1; i <= NodeMapped.size(); i++){
                for(int j = 1; j <= NodeMapped.size(); j++){
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }
        double sum = 0, routes = 0;
        for(int i = 1; i <= NodeMapped.size(); i++){
            for(int j = 1; j <= NodeMapped.size(); j++){
                if(i != j) routes++;
                sum += adjMat[i][j];
            }
        }
        //cout << sum << endl;
        printf("Case %d: average length between pages = %.3lf clicks\n",
				test++, sum / routes);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
map < string, int > mp1;
map < int, string > mp2;
map < string, vector<string> > ans;

//if it contains 1 , this means that it's connected directly
int adjMatConnectedDirectly[1005][1005];


int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    while(t--){
        int n, m;
        mp1.clear();
        mp2.clear();
        ans.clear();
        memset(adjMatConnectedDirectly, 0, sizeof adjMatConnectedDirectly);
        cin >> n;
        for(int i = 0 ; i < n; i++){
            string s;
            cin >> s;
            mp1[s] = i;
            mp2[i] = s;
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            string u, v;
            int f;
            cin >> u >> f;
            while(f--){
                cin >> v;
                adjMatConnectedDirectly[ mp1[u] ][ mp1[v] ]  = 1;
            }
        }
        //let's get connected Indirectly
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(adjMatConnectedDirectly[i][k] != 0 && adjMatConnectedDirectly[k][j] != 0)//you have edge from i - > k and from k -> j
                    adjMatConnectedDirectly[i][j] = max(adjMatConnectedDirectly[i][j], adjMatConnectedDirectly[i][k] + adjMatConnectedDirectly[k][j]);//let us bring maximum length of path, if more than 1 , this will mean that we have indirect edge
                }
            }
        }
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(adjMatConnectedDirectly[i][j] == 1){//if length of path is 1 , this means that it's connected only directly(that's we only want to output)
                    ans[mp2[i]].push_back(mp2[j]);
                }
            }
            sort(ans[mp2[i]].begin(), ans[mp2[i]].end());
        }
        for(auto it = ans.begin(); it != ans.end(); it++){
            if((it -> second).size() == 0)continue;//have no prerequisites
            cout << it->first << " " << (it->second).size() << " "  << (it->second)[0];
            for(int i = 1; i < (it->second).size(); i++){
                cout << " " << (it -> second)[i];
            }
            cout << endl;
        }
    }
    return 0;
}

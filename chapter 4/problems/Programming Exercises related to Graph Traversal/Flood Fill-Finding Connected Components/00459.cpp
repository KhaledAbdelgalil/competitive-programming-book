#include <bits/stdc++.h>
using namespace std;
bool vis[30];
vector<char>neighbours[30];
void dfs(int i){
    vis[i] = true;
    for(int j = 0; j < neighbours[i].size(); j++){
        if(vis[neighbours[i][j] - 'A'] == false){
            dfs(neighbours[i][j] - 'A');
        }
    }
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    bool fisrt = true;
    while(t--){
        for(int i = 0;i < 30; i++)neighbours[i].clear();
        char max_node;
        cin >> max_node;
        cin.ignore();
        string s;
        memset(vis, false, sizeof vis);
        while(getline(cin, s) && s != ""){
            neighbours[ s[0]-'A' ].push_back( s[1] );
            neighbours[ s[1] - 'A'].push_back( s[0] );
        }
        int cnt_components = 0;
        for(char node = 'A'; node <= max_node; node++){
            if(vis[node - 'A'] == false){
                dfs(node - 'A');
                cnt_components++;
            }
        }
        if(!fisrt)cout << endl;
        fisrt = false;
        cout << cnt_components << endl;
    }
    return 0;
}


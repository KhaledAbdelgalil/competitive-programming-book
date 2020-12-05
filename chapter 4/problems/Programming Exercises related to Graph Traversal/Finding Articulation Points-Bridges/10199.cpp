#include <bits/stdc++.h>
using namespace std;
#define UNVISTED 0
map < string, int >mp;
map < int, string> mp2;
std::vector < vector < int >> adj_list;
vector < int >dfsNum, dfsLow, dfsParent;
vector < bool > cameras;
int timeVisited;
int rootChildren;
int dfsRoot;
void dfs(int u){
    dfsNum[u] = dfsLow[u] = timeVisited++;
    for(int i = 0; i < adj_list[u].size(); i++){
        int v = adj_list[u][i];
        if(dfsNum[v] == UNVISTED){
            dfsParent[v] = u;
            if(u == dfsRoot)
                rootChildren++;
            dfs(v);
            if(u != dfsRoot && dfsLow[v] >= dfsNum[u])
                cameras[u] = true;
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }else if(dfsParent[u] != v){
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
        }
    }
}
main ()
{

  std::ifstream in ("input");
  std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
  std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt! 
  int test = 1;
  int n;
  bool first = true;
  while (cin >> n && n)
  {
      if(!first)cout << endl;
      first = false;
      adj_list.clear ();
      adj_list.resize (n);
      mp.clear();
      mp2.clear();
      dfsNum.clear ();
      dfsParent.clear ();
      dfsLow.clear ();
      cameras.clear ();
      dfsNum.assign (n, UNVISTED);
      dfsParent.assign (n, UNVISTED);
      dfsLow.assign (n, UNVISTED);
      cameras.assign (n, UNVISTED);

      for (int i = 0; i < n; i++)
	  {
	    string s;
	    cin >> s;
	    mp[s] = i;
	    mp2[i] = s;
	  }
      int m;
      cin >> m;
    
      while (m--)
	  {
	   string u, v;
	   cin >> u >> v;
	   adj_list[mp[u]].push_back (mp[v]);
	   adj_list[mp[v]].push_back (mp[u]);
	  }
      timeVisited = 1;	
	  for(int i = 0; i < n; i++){
	      if(dfsNum[i] == UNVISTED){
	         rootChildren = 0;
	         dfsRoot = i;
	         dfs(i);
	         if(rootChildren > 1)cameras[i] = true;
	      }
	  }
	  vector<string>ans;
	  cout << "City map #" << test++ << ": " << count(cameras.begin(), cameras.end(), true) <<" camera(s) found" << endl;
	  for(int i = 0; i < n; i++){
	      if(cameras[i]){
	        ans.push_back(mp2[ i ]);
	      }
	  }
	  sort(ans.begin(), ans.end());
	  for(int i = 0; i < ans.size(); i++)cout << ans[i] << endl;
   }

  return 0;
}


#include <bits/stdc++.h>
using namespace std;
double x[105], y[105];
double adjMat[105][105];
double calculate(int i, int j){
    double xDist = (x[i] - x[j]) * (x[i] - x[j]);
    double yDist = (y[i] - y[j]) * (y[i] - y[j]);
    return xDist + yDist;
}
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        cout << "Case #" << tt << ":" << endl;
        int n; 
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        
        //build_graph
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adjMat[i][j] = calculate(i, j);
                if(adjMat[i][j] > 10 * 10){
                    adjMat[i][j] = 1e9;
                }
                else adjMat[i][j] = sqrt(adjMat[i][j]);
            }
        }
        double maxx = 0;
        //get APSP
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }
        
        //get maximum among them
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                maxx = max(adjMat[i][j], maxx);
            }
        }
        if(maxx != 1e9)
            printf("%.4f\n\n", maxx);
        else cout << "Send Kurdy" << endl << endl;
    }
    
    
    
    
    //printf("Case %d: average length between pages = %.3lf clicks\n",
	//		test++, sum / routes);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;


int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   multiset<int>box;
   int t;
   cin>>t;
   while(t--)
   {
       int Ba,SG,SB;
       cin>>Ba>>SG>>SB;
       multiset<int,greater<int> >SoldiersG,SoldiersB;
       std::vector<int>roundBattleG,roundBattleB;
       for(int i=0;i<SG;i++)
       {
           int x;
           cin>>x;
           SoldiersG.insert(x);
       }
       for(int i=0;i<SB;i++)
       {
           int x;
           cin>>x;
           SoldiersB.insert(x);
       }
       while(SoldiersB.size()&&SoldiersG.size())
       {
           //clear roundBattle
           roundBattleB.clear();
           roundBattleG.clear();
           for(int i=0;i<Ba;i++)
           {
               int G,B;
                if(SoldiersG.size())
                    G=*(SoldiersG.begin());
                else break;
                if(SoldiersB.size())
                    B=*(SoldiersB.begin());
                else break;
                SoldiersB.erase(SoldiersB.begin());
                SoldiersG.erase(SoldiersG.begin());
                roundBattleB.push_back(B);
                roundBattleG.push_back(G);
           }
           for(int i=0;i<min(roundBattleG.size(),roundBattleB.size());i++)
           {
                int G=roundBattleG[i];
                int B=roundBattleB[i];
                if(G>B)SoldiersG.insert(G-B);
                else if(B>G)SoldiersB.insert(B-G);
           }
       }
       if(SoldiersB.size()){
           cout<<"blue wins"<<endl;
           for(multiset<int>::iterator it=SoldiersB.begin();it!=SoldiersB.end();it++)
           cout<<*it<<endl;
       }
       else if(SoldiersG.size()){
           cout<<"green wins"<<endl;
           for(multiset<int>::iterator it=SoldiersG.begin();it!=SoldiersG.end();it++)
           cout<<*it<<endl;
       }
       else{
           cout<<"green and blue died"<<endl;
       }
       if(t)cout<<endl;
   }
   return 0;
}


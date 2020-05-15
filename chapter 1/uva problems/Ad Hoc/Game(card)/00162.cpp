#include <iostream>
#include <fstream>
#include <string>
#include<deque>
using namespace std;

int main()
{
    
    /*
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    */
    std::deque<int>play,player1,player2;
    string n;
    /*
    make sure to check correctly for winning player as if they ends normally player1 have zero cards and player2 have zero cards
    you must be sure whose turn is so the other player is the winner
    
    */
    while(cin>>n)
    {
        if(n[0]=='#')break;
        play.clear();
        player1.clear();
        player2.clear();
        if(n[1]=='A')player1.push_back(4);
        else if(n[1]=='K')player1.push_back(3);
        else if(n[1]=='Q')player1.push_back(2);
        else if(n[1]=='J')player1.push_back(1);
        else player1.push_back(0);
        cin>>n;
        if(n[1]=='A')player2.push_back(4);
        else if(n[1]=='K')player2.push_back(3);
        else if(n[1]=='Q')player2.push_back(2);
        else if(n[1]=='J')player2.push_back(1);
        else player2.push_back(0);
        for(int i=0;i<25;i++)
        {
            cin>>n;
           if(n[1]=='A')player1.push_back(4);
        else if(n[1]=='K')player1.push_back(3);
        else if(n[1]=='Q')player1.push_back(2);
        else if(n[1]=='J')player1.push_back(1);
        else player1.push_back(0);
        cin>>n;
        if(n[1]=='A')player2.push_back(4);
        else if(n[1]=='K')player2.push_back(3);
        else if(n[1]=='Q')player2.push_back(2);
        else if(n[1]=='J')player2.push_back(1);
        else player2.push_back(0);
        }
        int top=0;
       bool finished=0;
       bool break_cannot_play=0;
      // cout<<player1.size()<<endl<<player2.size();
      int win=0;
       while(!break_cannot_play)
       {
           if(top==0){
               if(player1.empty()){win=2;break;}
               play.push_back(player1.back());
               player1.pop_back();
               top=play.back();
           }
           else
           {
               int top_now=top;
               for(int i=0;i<top_now;i++)
               {
              if(player1.empty()){win=2;break_cannot_play=1;break;}
                play.push_back(player1.back());
               player1.pop_back();
               top=play.back();
               if(top)break;
               }
               if (break_cannot_play)break;
               else if(top);
               else
               {
                   while(!play.empty())player2.push_front(play.front()),play.pop_front();
               }
           }
           
           
           //another player
           if(top==0){
               if(player2.empty()){win=1;break;}
               play.push_back(player2.back());
               player2.pop_back();
               top=play.back();
           }
           else
           {
               int top_now=top;
               for(int i=0;i<top_now;i++)
               {
              if(player2.empty()){win=1;break_cannot_play=1;break;}
                play.push_back(player2.back());
               player2.pop_back();
               top=play.back();
               if(top)break;
               }
               if (break_cannot_play)break;
               else if(top);
               else
               {
                   while(!play.empty())player1.push_front(play.front()),play.pop_front();
               }
           }
           
       }
      if(win==2) printf("%d %2d\n", 1, player2.size());
      else printf("%d %2d\n", 2, player1.size());
      
    }
    
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
   std::ifstream in ("input");
   std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
   std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
    int n;
    while(cin>>n)
    {
        map<char,bool>mp_active_cells;
        map<char,bool>mp_cells_in_brain;
        int m;
        cin>>m;
        string active;
        cin>>active;
        mp_active_cells[active[0]]=1,mp_active_cells[active[1]]=1,mp_active_cells[active[2]]=1;
        mp_cells_in_brain[active[0]]=1,mp_cells_in_brain[active[1]]=1,mp_cells_in_brain[active[2]]=1;
        int active_nw=3;
        std::vector<set<char> >cells_connected_to_cell(26);
        while(m--){
            string s;
            cin>>s;
            mp_cells_in_brain[s[0]]=1,mp_cells_in_brain[s[1]]=1;
            cells_connected_to_cell[s[0]-'A'].insert(s[1]);
            cells_connected_to_cell[s[1]-'A'].insert(s[0]);
        }
        int years=0;
        while(1)
        {
            if(active_nw==n)break;//brain is awake no more processing needed
            vector<char>activated_cells_in_this_year;
            for(char cell='A';cell<='Z';cell++)
            {
                if(mp_active_cells.find(cell)!=mp_active_cells.end())continue;//active cell no need to process
                if(mp_cells_in_brain.find(cell)==mp_cells_in_brain.end())continue;//not a brain cell don't process it
                int activecells_connectedTothiscell=0;
                int Idx=cell-'A';
                set<char>::iterator it=cells_connected_to_cell[Idx].begin();
                for(;it!=cells_connected_to_cell[Idx].end();it++)
                {
                    char conncetedCell=*it;
                    if(mp_active_cells.find(conncetedCell)!=mp_active_cells.end())activecells_connectedTothiscell++;
                }
                if(activecells_connectedTothiscell>=3)
                {
                    /*active_nw++;
                    mp_active_cells[cell]=1;*/ //we need to push them after the year not within the year
                    
                    activated_cells_in_this_year.push_back(cell);
                }
            }
            years++;
            if(activated_cells_in_this_year.size()==0)break;//no cells more we can activate
            
            for(int i=0;i<activated_cells_in_this_year.size();i++)
            {
                mp_active_cells[activated_cells_in_this_year[i]]=1;
            }
            active_nw+=activated_cells_in_this_year.size();
            
            
        }
        //if all cells are active brain will wake
        if(active_nw==n)cout<<"WAKE UP IN, "<<years<<", YEARS"<<endl;
        else cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
    }
    
    return 0;
}

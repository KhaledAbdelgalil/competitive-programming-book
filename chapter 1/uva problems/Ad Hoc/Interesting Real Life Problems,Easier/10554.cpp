#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ifstream in("input"); 
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf 
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    const double cal[5] = {9, 4, 4, 4, 7};
    string l;
    
    while (getline(cin, l) and l != "-")
    {
        
        pair<int,char> data[5];
        double totalFat = 0;
	double totalCalories = 0;
		
        do
        {
            
            double subTotal=0;
            stringstream ss(l);
            double totalpercent=0;
            
            for(int i=0;i<5;i++)
            {
                
                string info;
                ss>>info;
                double amount=(double)stoi(info);
                char unity = info[info.length() - 1];
                
                switch(unity)
                {
                    
                    case 'C':
                        if(i==0)
                        totalFat+=amount;
                        subTotal+=amount;
                        totalCalories+=amount;
                        break;
                        
                    case '%':
                        totalpercent+=amount;break;
                        
                    case 'g':
                        if(i==0)
                        totalFat+=amount*9;
                        subTotal+=amount*cal[i];
                        totalCalories+=amount*cal[i];
                        break;
                }
                
                data[i]=make_pair(amount,unity);
            }
        if(data[0].second=='%')
        totalFat+=data[0].first*subTotal/(100-totalpercent);
                        
         totalCalories+=subTotal*totalpercent/(100-totalpercent);   
        }while(getline(cin, l) and l != "-");

        
        cout<<(int)round(totalFat/totalCalories*100.0)<<"%"<<endl;
        
        
        
        
    }    
    
}

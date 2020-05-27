#include <bits/stdc++.h>
#include <string>

using namespace std;

struct message{
    int code;
    int note;
    int m;
    int b;
    int t;
};
int main (void){
    
    
  std::ifstream in ("input");
  std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
  std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!

  int n;
  message tmp;

  while (cin >> n)
    {
      if (n == -1)
	break;

      vector < message > messages;

    for(int i=0;i<n;i++)
    {
    	cin >> tmp.code >> tmp.note >> tmp.m >> tmp.b >> tmp.t;
    	tmp.t = ((tmp.t + 30) / 60) * 60;
    	if (tmp.t == 480)
    	  {
        	    tmp.t = 0;
        	    tmp.b++;
        	    if (tmp.b == 5)
        	     {
            		tmp.b = 1;
            		tmp.m++;
        	     }
	       }
    	messages.push_back (tmp);
    }

      for (vector < message >::iterator i = messages.begin ();
	   i != messages.end (); i++)
	   {
    	  if (i->code == 0)
    	    continue;
    
    	  for (vector < message >::iterator j = i + 1; j != messages.end ();
    	       j++)
    	    {
    	      if (i->note == j->note && i->code == 1 && j->code == 0)
    		{
    		  if (i->m == j->m && i->b == j->b && i->t == j->t)
    		    {
    		      i = messages.erase (i);
    		      i--, j--;
    		      j = messages.erase (j);
    		      j--;
    		    }
    		  break;
    		}
    	    }
       }

      cout << messages.size () << endl;
     for(int i=0;i<messages.size();i++)
      {
	    cout << messages[i].code << " " << messages[i].note << " " << messages[i].m << " " << messages[i].b << " " << messages[i].t << endl;
      }
    }

  cout << "-1" << endl;

  return 0;
}


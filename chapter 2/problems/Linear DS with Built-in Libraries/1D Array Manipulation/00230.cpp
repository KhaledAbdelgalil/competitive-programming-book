#include<bits/stdc++.h>
using namespace std;

struct book{
    string title;
    string author;
};

vector<book>books;
vector<bool>take;
vector<bool>was_borrowed;
string name_book;

bool condition(const struct book &a)
{
    if(a.title==name_book)return true;
    return false;
}
bool cmp(const struct book &a,const struct book &b)
{
    if(a.author<b.author)return true;
    else if(a.author==b.author&&a.title<b.title)return true;
    return false;
}

int main()
{
    
    std::ifstream in("input");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    
    
    string temp;
    while(getline(cin,temp)&&temp!="END")
    {
        int pos=temp.find("\" by");
        string tit=temp.substr(0,pos+1);
        string auth=temp.substr(pos+5);
       struct book b;
       b.title=tit;
       b.author=auth;
       books.push_back(b);
    }
    
    sort(books.begin(),books.end(),cmp);
    vector<bool> borrowed(books.size(), false);
    vector<bool> returned(books.size(), false);
    
    while(getline(cin,temp)&&temp!="END")
    {
        if(temp[0]=='S')
        {
            int prev=-1;
            for(int i=0;i<books.size();i++)
            {
                if(!borrowed[i])
                prev=i;
                else if(returned[i])
                {
                    if(prev==-1)
                     cout << "Put " << books[i].title << " first\n";
                    else 
                        cout << "Put " << books[i].title << " after " << books[prev].title << '\n';
                        
                    borrowed[i]=0;
                    returned[i]=0;
                    prev=i;
                }
            }
            cout<<"END"<<endl;
        }
        else if(temp[0]=='B'){
            name_book=temp.substr(7);
            auto it=find_if(books.begin(),books.end(),condition);
            int idx=it-books.begin();
            returned[idx]=0;
            borrowed[idx]=1;
        }
        else if(temp[0]=='R')
        {
            name_book=temp.substr(7);
            auto it=find_if(books.begin(),books.end(),condition);
            int idx=it-books.begin();
            returned[idx]=1;
        }
    }
}

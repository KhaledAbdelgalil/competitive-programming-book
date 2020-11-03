#include <bits/stdc++.h>
using namespace std;


/*

A)
to count total number of rectangles and squares to gether:

1- 1*1->total=1              1- 1*2->total=3
2- 2*1->total=3     ->>>>>>> 2-2*2->total = 9
3- 3*1->total=6              3- 3*2->total = 18

for n*1 grid total=n*(n+1)/2
for n*2 grid total=3*n*(n+1)/2=2*3*n*(n+1)/4
so for n*m total=n*(n+1)*m*(m+1)/4
for n=m=n
2D=>n^2 *(n+1)^2/4
3D=>n^3 *(n+1)^3/8
4D =>n^4 *(n+1^4 /16

B) to count number of squares
for 2D n*n:
n=2    4+1=5
n=3    9+3+1=14
n=4    16+9+4+1
so n^2+(n-1)^2+.........+1=n*(n+1)*(2*n+1)/6

for higher dimensions n^dimension +(n-1)^dimension


C)to count rectangles only A-B
*/
int main()
{
    std::ifstream in ("input");
    std::streambuf * cinbuf = std::cin.rdbuf ();	//save old buf 
    std::cin.rdbuf (in.rdbuf ());	//redirect std::cin to in.txt!
   
  /* //pre-processing 2D
    std::vector<long long>vect2Dsquares;
    std::vector<long long>vect2Drectangles;
    for(long long i=0;i<=100;i++){
        long long total_no=i*i*(i+1)*(i+1)/4;
        long long total_sq=i*(i+1)*(2*i+1)/6;
        vect2Drectangles.push_back(total_no-total_sq);
        vect2Dsquares.push_back(total_sq);
    }
    //pre-processing 3D
    vector<unsigned long long>vect3Dsquares,vect3Drectangles;
    for(unsigned long long i=0;i<=100;i++){
        unsigned long long total_no=i*i*i*(i+1)*(i+1)*(i+1)/8;
        unsigned long long total_sq=0;
        for(unsigned long long j=1;j<=i;j++){
            total_sq+=j*j*j;
        }
        vect3Drectangles.push_back(total_no-total_sq);
        vect3Dsquares.push_back(total_sq);
    }
    
    
    //pre-processing 4D
    vector<unsigned long long>vect4Dsquares,vect4Drectangles;
    for(unsigned long long i=0;i<=100;i++){
        unsigned long long total_no=(i*i*i*i*(i+1)*(i+1)*(i+1)*(i+1))/16;
        unsigned long long total_sq=0;
        for(unsigned long long j=1;j<=i;j++){
            total_sq+=j*j*j*j;
        }
        vect4Drectangles.push_back(total_no-total_sq);
        vect4Dsquares.push_back(total_sq);
    }
    */
    vector<unsigned long long>vect2Dsquares={0};
    vector<unsigned long long>vect2Drectangles={0};
    vector<unsigned long long>vect3Dsquares={0},vect3Drectangles={0};
    vector<unsigned long long>vect4Dsquares={0},vect4Drectangles={0};
    
    for(unsigned long long i=1;i<=100;i++){
        unsigned long long total_sq2=vect2Dsquares.back()+i*i;
        unsigned long long total_sq3=vect3Dsquares.back()+i*i*i;
        unsigned long long total_sq4=vect4Dsquares.back()+i*i*i*i;
        
        unsigned long long total2=pow(i*(i+1)/2,2.0);
        unsigned long long total3=pow(i*(i+1)/2,3.0);
        unsigned long long total4=pow(i*(i+1)/2,4.0);
        
        vect2Dsquares.push_back(total_sq2);
        vect3Dsquares.push_back(total_sq3);
        vect4Dsquares.push_back(total_sq4);
        
        vect2Drectangles.push_back(total2-total_sq2);
        vect3Drectangles.push_back(total3-total_sq3);
        vect4Drectangles.push_back(total4-total_sq4);
    }
    int n;
    while(cin>>n){
        cout<<vect2Dsquares[n]<<" "<<vect2Drectangles[n]<<" ";
        cout<<vect3Dsquares[n]<<" "<<vect3Drectangles[n]<<" ";
        cout<<vect4Dsquares[n]<<" "<<vect4Drectangles[n]<<endl;
        
    }
    return 0;
}


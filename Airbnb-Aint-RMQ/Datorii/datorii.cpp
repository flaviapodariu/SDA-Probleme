#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("datorii.in");
ofstream fout("datorii.out");
#define NMAX 15001
 
int n, agenda[NMAX];
 void update(int zi, int bani)
 {
     while(zi <= n)
     {
         agenda[zi] += bani;
         zi = zi + (zi & -zi);
     }
 }
 
 int suma(int zi)
 {
     int s = 0;
     while(zi > 0)
     {
         s += agenda[zi];
         zi = zi - (zi & -zi);
     }
 
     return s;
 }
int main()
{
    int bani,a, b, m, op;
 
    fin >> n >> m;
    for(int zi = 1 ; zi <= n ; ++zi)
      {
          fin >> bani;
          update(zi, bani);
      }
 
    for(int i = 0 ; i < m ; ++i)
    {
        fin >> op >> a >> b;
        switch(op)
        {
        case 0:
            update(a, -b); // a = ziua , b = banii
            break;
        case 1:
            fout << suma(b) - suma(a-1)<< "\n";
            break;
        }
    }
 
    return 0;
}

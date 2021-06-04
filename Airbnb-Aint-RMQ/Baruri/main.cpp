#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("baruri.in");
ofstream fout("baruri.out");
 
#define NMAX 100001
 
int n, m, baruri[NMAX];
 
void update(int pers, int bar)
{
    int i = bar;
    while(i <= n)
    {
        baruri[i] +=  pers;
        i = i + (i & -i); // merg la parinte
    }
}
 
int suma(int bar)
{
    int i = bar, s = 0;
    while(i >= 1)
    {
        s += baruri[i];
        i = i - (i & -i);
    }
 
    return s;
}
 
int main()
{
    int t, val, prieteni, bar, bar2, dist;
    fin >> t;
    while(t--)
    {
        fin >> n;
        for(int i = 1; i <= n; ++i)
        {
            fin >> val;
            update(val, i);
        }
        fin >> m;
        for(int i = 1; i <= m; ++i)
        {
            fin >> val;
            switch(val)
            {
            case 0:
                fin >> bar >> dist;
                // 0----- bar1 -------bar referinta--------bar2------n
                fout << suma(min(n, bar+dist)) - suma(bar) + suma(bar-1) - suma(max(0, bar-dist-1))<< "\n";
                break;
            case 1:
                fin >> prieteni >> bar;
                update(prieteni, bar);  //intra in bar
                break;
            case 2:
                fin >> prieteni >> bar;
                update(-prieteni, bar); // pleaca din bar
                break;
            case 3:
                fin >> prieteni >> bar >> bar2;
                update(-prieteni, bar);
                update(prieteni, bar2);
                break;
            }
        }
 
        for(int i = 1; i <= n; ++i)
            baruri[i] = 0;
    }
 
    return 0;
}

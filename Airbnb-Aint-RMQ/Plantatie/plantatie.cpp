#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("plantatie.in");
ofstream fout("plantatie.out");
#define NMAX 501
#define LOGMAX 9
int n, m;
long long fieldRMQ[NMAX][NMAX][LOGMAX];
int logg[NMAX];
 
void computeLOG()
{
   logg[1] = 0;
   for(int i = 2; i <=n; ++i)
       logg[i] = logg[i/2] +1;
}
 
void construct()
{
    for(long i = 0; i < n; ++i)
        for(long j = 0 ;j < n; ++j)
          fin >> fieldRMQ[i][j][0];
    for(long k = 1; (1<<k) <= n ; ++k)
        for(long i = 0; i + (1<<k)-1 < n; ++i)
        {
            for(long j = 0; j + (1<<k)-1 < n; ++j)
                fieldRMQ[i][j][k] = max(max(fieldRMQ[i][j][k-1],
                                            fieldRMQ[i + (1<<(k-1))][j][k-1]),
                                        max(fieldRMQ[i][j + (1<<(k-1))][k-1],
                                            fieldRMQ[i + (1<<(k-1))][j + (1<<(k-1))][k-1]));
        }
}
 
long query(long i, long j, long k)
{
   long qi = i + k;
   long qj = j + k;
   int etaj = logg[k];
 
   return max(max(fieldRMQ[i][j][etaj],
              fieldRMQ[qi - (1<<etaj)][j][etaj]),
             max(fieldRMQ[i][qj - (1<<etaj)][etaj],
              fieldRMQ[qi - (1<<etaj)][qj - (1<<etaj)][etaj]));
}
 
 
int main()
{
    fin >> n >> m;
    construct();
    computeLOG();
    while(m--)
    {   long i, j, k;
        fin >> i >> j >> k;
        fout << query(i-1, j-1, k)<< "\n";
    }
 
    return 0;
}

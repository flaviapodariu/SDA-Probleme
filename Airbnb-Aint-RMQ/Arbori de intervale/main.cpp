#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("arbint.in");
ofstream fout("arbint.out");
#define NMAX 100001

long n, m, input[NMAX], log[NMAX], rmq[NMAX][NMAX];

int main()
{
 fin >> n >> m;
 for(long i = 1; i <= n; ++i)
     fin >> a[i];
 log[1] = 0;
 for(long i = 2;i <=n; ++i)
     log[i] = log[i/2]+1;
 for(long i =1; 2*i <=n; i++)
    for(long j = 1; j <= n- 2*i+1; ++j)
    {
     long l = 1 << (i-1);
     rmq[i][j] = min(rmq[i-1][j], rmq[i-1][j+1]);
    }
  for(long i = 1; i <= ; ++i)
  {
     fin >> x >>y;
     diferenta = y-x+1;
     long l = log[diferenta];

  }

    return 0;
}

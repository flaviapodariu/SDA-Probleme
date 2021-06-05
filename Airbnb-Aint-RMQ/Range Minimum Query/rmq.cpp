#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("rmq.in");
ofstream fout("rmq.out");
 
const long NMAX = 100001;
const long LOGMAX = 18;
 
long n,m, sparse[NMAX][LOGMAX+2], logg[NMAX];
long a, b;
 
void computeLOG()
{
   logg[1] = 0;
   for(int i = 2; i <=n; ++i)
       logg[i] = logg[i/2] +1;
}
 
 
void construct()
{  // elementele de pe coloana 0 sunt chiar elementele citite la tastatura
   // prima sparse[x][0] sunt elementele minime din intervalul [x, x + 2^0)
     for(long i = 0; i < n; ++i)
        fin >> sparse[i][0];
// construiesc sparse[][] dupa coloane. ultima coloana e j-ul maxim pt care 2^j<= n
    for(long j = 1; (1<<j) <= n ; ++j)
        // ma opresc la i + (1<<j)-1 pt ca nu pot sa am un interval mai lung decat numarul coloanelor
        for(long i = 0; i + (1<<j)-1 < n; ++i)
            sparse[i][j] = min(sparse[i][j-1], sparse[i+ (1<<(j-1))][j-1]);
 
}
long query(int low, int high)
{
    long numere = high - low +1;
    long k = logg[numere];
    // sparse[low][k] = minimul din intervalul [low, low + 2^k)
    // sparse[low + numere - (1<<k)][k] = minimul din intervalul [low + 2^k, high)
    // low--------low + 2^k-----------high
    return min(sparse[low][k], sparse[low + numere - (1<<k)][k]);
 
}
 
int main()
{
    fin >> n >> m;
    construct();
    computeLOG();
 
 
    while(m--)
    {
        fin >> a >> b;
        fout << query(a-1, b-1)<< "\n";
    }
 
 
    return 0;
}

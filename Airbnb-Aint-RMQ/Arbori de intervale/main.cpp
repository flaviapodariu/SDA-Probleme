#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("arbint.in");
ofstream fout("arbint.out");
#define NMAX 100001
 
int n, m, input[NMAX], segTree[NMAX<<2];
 
void construct(int low, int high, int pos)
{
    if(low == high)
    {
        segTree[pos] = input[low];
        return;
    }
    int mid = (low+high)/2;
    construct(low, mid, 2*pos);
    construct(mid+1, high, 2*pos+1);
    segTree[pos] = max(segTree[2*pos], segTree[2*pos+1]);
}
 
 
int maxim(int qlow, int qhigh, int low, int high, int pos)
{
 
    if(qlow <= low && qhigh>= high)  //intervalul cerut include intervalul actual
        return segTree[pos];
 
    if(qlow > high || qhigh < low)   //intervalele nu se suprapun
        return -1;
 
    int mid = (low +high)/2;
    return max(maxim(qlow, qhigh, low, mid, pos*2),
                maxim(qlow, qhigh, mid+1, high, pos*2+1));
}
void update(int low, int high, int pos, int a, int b)
{
     if(low == high)
     {
         segTree[pos] = b;
         input[a] = b;
         return;
     }
     int mid = (low+high)/2;
     if(a <= mid)
        update(low, mid, pos*2,a, b);
     else
        update(mid+1, high, pos*2+1,a, b);
     segTree[pos] = max(segTree[pos*2], segTree[pos*2+1]);
 
}
int main()
{
    int op, a, b;
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        fin >> input[i];
    construct(1,n,1);
 
    for(int i = 0; i < m; ++i)
    {
        fin >> op >> a >> b;
        switch(op)
        {
        case 0:
            fout << maxim(a, b,1,n,1)<<"\n";
            break;
        case 1:
            update(1,n,1,a,b);
            break;
        }
    }
 
    return 0;
}

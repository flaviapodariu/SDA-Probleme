#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("farfurii.in");
ofstream fout("farfurii.out");

int main()
{
    long long k, kmax, n;
    fin >> n >> k;
    kmax = n *(n-1)/2;
    if(k == 0)
    {
        for(int i = 1; i <= n; ++i)
            fout << i<< " ";
        return 0;
    }

    else
    if(k == kmax)
    {
        for(int i = n; i >=1; --i)
            fout << i << " ";
        return 0;
    }

    else
    {
        int i = 1;
        while(kmax - (n-i) >= k)
        {
            fout<< i << " ";
            kmax -= n-i;
            ++i;
        }


        if(kmax == k)
            for(int j = n; j >= i ; --j)
                fout << j << " ";
        else

        if(kmax > k)
        {
            int rest = n - (kmax - k);
            fout << rest << " ";

            for(int j = n; j >= i; --j)
            {
                if(j == rest)
                   continue;
                 fout<< j<< " ";
            }

        }

    }

    return 0;
}

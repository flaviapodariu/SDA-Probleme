# Range Minimum Query


## Construire sparse table (preprocesare)

Matricea construita are n linii si log n + 1 coloane, indexate de la 0.

* sparse[i][j] contine minimul intre elementele i -> `i + 2^j - 1`, unde i < n, j < log n + 1.

* Cand citesc inputul, nu mai pastrez un vector separat, ci introduc valorile pe coloana 0 (care ne arata de fapt minimul din intervalul [i, i], deci exact numarul respectiv). In continuare, introduc minimele pe intervale in functie de valorile deja introduse pe prima coloana. 

ex. input: n = 6 elemente -> 1 5 6 4 3 2 

 x  |  0 | 1  | 2
--- | ---| ---| ---
 0  |  1 | 1  | 1 
 1  |  5 | 5  | 3    
 2  |  6 | 4  | 2 
 3  |  4 | 3  |   
 4  |  3 | 2  |   
 5  |  2 |    |   

sparse[0][1] = minimul din intervalul [0,1] => minimul dintre [0,0] si [1,1] = min(sparse[0,0], sparse[1][0]) = 1.

sparse[1][2] = minimul din intervalul [1,4] => min(sparse[1,1], sparse[3][1]) = 3.

 ### Cod construire sparse table
```c++
for(long j = 1; (1<<j) <= n ; ++j)
        for(long i = 0; i + (1<<j)-1 < n; ++i)
            sparse[i][j] = min(sparse[i][j-1], sparse[i+ (1<<(j-1))][j-1]);

```        	

* for-ul pentru coloane se opreste cand `2^j <= n` (echivalent cu j <= log n)

* for-ul pentru linii se opreste cand `i + 2^j - 1 >= n` pentru ca nu putem avea, de exemplu, un interval [3,6] daca avem numere pana la indexul 5.

* valoarea sparse[i][j] se decide calculand minimul dintre alte doua minime calculate precedent.


## Query 

Functia de query primeste low si high, limitele intervalului cerut.
Algoritmul seamana cu cel de la construire, dar pentru query trebuie sa stim:

* numarul de numere existente in interval (intotdedauna o putere a lui 2)

* k = logaritmul in baza 2 al acestui numar 

Minimul din intervalul cerut este `min(sparse[low, low +2^k-1], sparse[low+2^k][high])`.

Problema se reduce la gasirea indecsilor corespunzatori.

Primul interval: `sparse[low][k]` 

Al doilea interval: `low + numere = high + 1`, iar `high + 1 - 2^k = low + 2^k`

```c++
	
long query(int low, int high)
{
    long numere = high - low +1;
    long k = logg[numere];
    // low--------low + 2^k-----------high
    return min(sparse[low][k], sparse[low + numere - (1<<k)][k]);
 
}
```


## Complexitati

Preprocesare: O(n^2) -> pentru RMQ pe vector
             
              O(n^3) -> pentru RMQ in 2D --> problema [Plantatie](https://github.com/flaviapodariu/SDA-Probleme/tree/main/Airbnb-Aint-RMQ/Plantatie)

Query: O(1)

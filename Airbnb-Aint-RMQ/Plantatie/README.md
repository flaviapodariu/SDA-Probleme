# Plantatie

## Idee generala

Problema de RMQ (maxim in cazul asta) in 2D. Inputul vine sub forma de matrice, iar pentru a raspunde la query-uri vom avea o structura 3D.


## Construire

Primul etaj contine toate celulele matricei din input, deci citim matricea din input ca fiind primul etaj al structurii 3D.

Restul etajelor se extind pana cand `i + 2^k - 1 < n` pentru linii si pana cand `j + 2^k - 1 < n`, pentru coloane. Nu sunt luate in considerare ultimele `log k + 1` linii si coloane pentru ca pornind din acele celule cu coltul stanga sus, nu mai avem destule celule cat sa formam un patrat de latura k.

Dupa ce inserez inputul pe primul etaj, restul etajelor, le completez folosindu-ma de rezultatele anterioare, astfel:

* Maximul pe o anumita arie este maximul dintre cele 4 sub-arii. Pentru a gasi maximele de pe o sub-arie mergem un etaj mai jos si alegem coltul stanga sus corespunzator.

```c++
 max(max(fieldRMQ[i][j][k-1],  //p1
         fieldRMQ[i + (1<<(k-1))][j][k-1]), //p2
     max(fieldRMQ[i][j + (1<<(k-1))][k-1], //p3
         fieldRMQ[i + (1<<(k-1))][j + (1<<(k-1))][k-1])) //p4

 // p1  p3
//  p2  p4

```
* Functia max() accepta 2 parametrii, deci trebuie sa grupez valorile 2 cate 2.

## Query 

 Asemanator cu functia de construire, funtia de query returneaza maximul dintre maximele de pe 4 arii, iar problema se reduce la gasirea indecsilor corespunzatori.

* pentru a ajunge la etajul corect, calculez logaritmul in baza 2 a laturii patratului: `int etaj = logg[k];`

* qi este primul index de linie al patratului din query care **nu** mai face parte din patrat, deci scazand `qi - (1<<etaj)` obtin indexul liniei coltului stanga sus al sub-patratului p2 (din comentariul de mai sus), care cuprinde ultima linie a patratului mare din query. 


## Complexitate

Construire -> O(n^3)

Query &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> O(1)

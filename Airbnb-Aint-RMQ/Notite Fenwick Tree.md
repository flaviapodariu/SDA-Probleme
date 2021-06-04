# Fenwick Tree / Binary Indexed Tree

## Construire si update

In memorie se retine ca un vector, dar arborele il gandim asa:

-> Toate nodurile tin suma a n elemente, unde n este o putere a lui 2. 

-> Tree[0] = dummy node

-> Tree[nod] are tatal cu nodul numarul y, unde y este egal cu numarul obtinut prin stergerea ultimului bit 1 din reprezentarea binara a lui nod.

Mai simplu, `nod -= (nod & (-nod))` este tatal vechiului nod.


Construirea se face prin functia de update.

-> Toate numerele naturale pot fi scrise ca sume de puteri ale lui 2. Un nod tine suma unui interval in acest fel:

(Nodul nr.) 1 = 0 + 2^0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;=> intervalul incepe la 0 si continua pana la al 2^0 -lea element, deci [0,0] </br>
(Nodul nr.) 2 = 0 + 2^1&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;=> [0,1] </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3 = 2^1 + 2^0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;=> [2,2] </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4 = 0 + 2^2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;=> [0,3] </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;... </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7 = 2^2 + 2^1 + 2^0 </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;= 6 + 2^0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;=> suma trebuie restransa pentru a avea 2 termeni, deci intervalul este [6,6] </br>
              
```
                                0 - Dummy
                               /     \   \
                              /       \   \______
                             /         \         \
                       nod 1 -> 2   nod 2 -> 3   nod 4 -> 5
                       [0,0]        [0,1]        [0,3]    
                                      |            |       
                                      |            |        
                                      |            |         
                                    nod 3 -> 2    nod 5 -> 0  
                                    [2,2]         [4,4]         
 ```     
 ### Functia de update               
```c++
 void update(int index, int valoare)
 {
     while(index <= n)
     {
         Tree[index] += valoare;             // se adauga valoarea la suma pe interval
         index = index + (index & -index);  // trec la nodul urmator
     }
 }
```
## Query

Functia de query ia ca parametru limita superioara a unui interval si returneaza suma intre [0, lim]. Pentru query-uri care nu au limita inferioara = 0, trebuie sa scadem `query(limInferioara - 1)` pentru a scapa de intervalul care nu se suprapune cu cel cerut initial.

### Functia de query 
```c++

int query(int index)
 {
     int s = 0;
     while(index > 0)
     {
         s += Tree[index];                  // adaug la s suma pe interval
         index = index - (index & -index); // merg la parinte pana cand ajung la radacina dummy
     }
     return s;
 }
```

## Complexitati

Construire&nbsp;&nbsp;&nbsp;&nbsp;-> O(n)

Query&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -> O(max_height) = O(log n)


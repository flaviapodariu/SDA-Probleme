
# Baruri

## Idee generala

Folosesc un arbore indexat binar pentru a pastra eficient numarul de oameni din baruri.
Nu am mai pastrat un vector diferit pentru datele din input, am creat direct arborele.

Link catre notitele mele pentru arborele indexat binar/ Fenwick Tree [aici]()

Pentru ca barurile sunt indexate de la 1, toate intervalele existente in link cresc cu o unitate. 

ex: [3,4] = [4,5]

## Explicatie
### Update

Arborele este creat prin functia de update. Daca x persoane intra in barul y, toate nodurile care il contin in intervalele lor pe y trebuie schimbate.

```
                                0 - Dummy
                               /     \   \
                              /       \   \______
                             /         \         \
                       nod 1 -> 2   nod 2 -> 3   nod 4 -> 5
                       [1,1]        [1,2]        [1,4]    
                                      |            |       
                                      |            |        
                                      |            |         
                                    nod 3 -> 2    nod 5 -> 0  
                                    [3,3]         [5,5]         
                    
                        
```

ex: daca intra 2 persoane in barul 3, trebuie modificate valorile din nodul 3 si din nodul 4.

### Suma

Functia de query returneaza suma tuturor persoanelor care se afla pana la barul dat ca parametru, inclusiv.

ex: suma(3) = 2 + 1 + 2 = 5 persoane.

Pentru realizarea query-urilor se porneste din ultimul bar si se urca progresiv, din tata in tata, pana la radacina.

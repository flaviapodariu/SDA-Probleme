# Datorii

## Idee generala

 Problema de arbori indexati binar. Construiesc direct arborele, fara sa mai tin un vector separat pentru input.
 Link catre notitele mele pentru arborele indexat binar/ Fenwick Tree [aici](https://github.com/flaviapodariu/SDA-Probleme/blob/main/Airbnb-Aint-RMQ/Notite%20Fenwick%20Tree.md)

## Explicatie
-> datorii pe zile, 1<= zi <=N : 1 3 2 0 0 10

### Update

Fiecare nod contine o suma de bani neachitata. Banii au valoare pozitiva doar la inceput cand se introduc datoriile.
Cand clientii platesc datoriile, banii se introduc cu valoare negativa.

### Suma

Functia de query returneaza suma tuturor datoriilor pana in ziua data ca parametru, inclusiv.

ex: suma(3) = 1 + 3 + 2 = 6 lei

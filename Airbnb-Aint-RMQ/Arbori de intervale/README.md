# Arbori de intervale

# Construire

Valorile luate din input se pun ca frunze in arbore, iar restul nodurilor reprezinta maximul dintre fii lor.

ex:  input: 1 2 4 0


```
            4 
          [1,4]           max(2,4) = 4 -> maximul pe intervalul [1,4]
       /         \
      /           \
     2             4
   [1,2]         [3,4]        max(1,2) = 2; max(4,0) = 4;
   /   \         /   \
  1     2       4     0 
[1,1]  [2,2]  [3,3]  [4,4]
 ```

Indexarea este de la 1, deci formulele pt pozitii sunt:

Fiu stang -> 2 * pos;

Fiu drept -> 2 * pos + 1;

Tata -> pos/2

# Query

Se da un interval [x,y]. Exista 3 cazuri:

1. [x,y] este cuprins total in intervalul nodului curent.

2. [x,y] este cuprins partial in intervalul nodului curent.

3. [x,y] nu este cuprins deloc in intervalul nodului curent.

-> In cazul 1 returnez direct valoarea tinuta de nod. 

-> In cazul 2 trebuie sa verific ambii fii pentru a gasi partea de interval care ma intereseaza. Returnez maximul dintre fii.

-> In cazul 3 returnez -1 (inputul este pozitiv)

# Update

Prima data schimb valoarea din frunza, dupa care urc din tata in tata pana la radacina si fac schimbarile necesare. Algoritmul seamana in mare parte cu cel de construire.

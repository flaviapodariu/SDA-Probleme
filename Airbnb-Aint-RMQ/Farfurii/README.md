# Farfurii

 ## Idee generala

 Trebuie sa am un numar de inversiuni de numere x y (unde x > y), egal cu numarul de tacamuri k.

 ## Explicatie 

 -> `kmax =  n *(n-1)/2` reprezinta numarul maxim de inversiuni de numere x y, si este dat de un sir de numere in ordine strict descrescatoare:

 7 6 5 4 3 2 1

 1: toate numerele sunt mai mari decat 1, deci genereaza 6 inversiuni.
 
 2: toate numerele mai putin 1 sunt mai mari decat 2,  deci genereaza 5 inversiuni.
 
 .
 .
 .
 
 7:  0 inversiuni

 Deci suma totala este suma gauss pana la 6 : (6*7)/2 = 21.

-> Daca numerele sunt in ordine strict crescatoare, se genereaza 0 inversiuni.

-> Daca scazand din kmax toate inversiunile care pot fi generate de o anumita farfurie, obtinem un numar mai mare sau egal decat k (`kmax - (n-i) >= k`), inseamna ca acea farfurie poate fi plasata pe raft inaintea celorlalte ramase. In caz contrar, aceasta ar genera mai multe inversiuni decat tacamuri disponibile.

-> Se repeta procesul pana cand conditia de mai sus nu mai este valida, moment in care apar 2 cazuri:

1. `kmax == k` : nu mai avem combinatii de generat, deci afisez numerele in ordine descrescatoare

2. `kmax > k` : daca as plasa urmatoarea farfurie care ar veni in ordine strict crescatoare, as depasi numarul k, deci trebuie sa scap de `kmax - k` inversiuni.
Care farfurie are `kmax - k` farfurii mai mari decat ea? Pentru a obtine aranjamentul minim lexicografic, trebuie sa asez acea farfurie (care face si ultimele inversiuni), iar mai apoi aranjez toate farfuriile ramase in ordine strict descrescatoare (nu mai am nevoie de inversiuni).


 ## Sursa infoarena

 [Sursa Farfurii](https://www.infoarena.ro/job_detail/2749881?action=view-source)

# Quick sort、quick select

wikipedia [Quicksort](https://en.wikipedia.org/wiki/Quicksort) # [Generalization](https://en.wikipedia.org/wiki/Quicksort#Generalization)

> [Richard Cole](https://en.wikipedia.org/wiki/Richard_J._Cole) and David C. Kandathil, in 2004, discovered a one-parameter family of sorting algorithms, called **partition sorts**, which on average (with all input orderings equally likely) perform at most $n\log n+{O}(n)$ comparisons (close to the information theoretic lower bound) and ${\Theta }(n\log n)$ operations; at worst they perform ${\Theta }(n\log ^{2}n)$ comparisons (and also operations); these are in-place, requiring only additional ${O}(\log n)$ space. Practical efficiency and smaller variance in performance were demonstrated against optimised quicksorts (of [Sedgewick](https://en.wikipedia.org/wiki/Robert_Sedgewick_(computer_scientist)) and [Bentley](https://en.wikipedia.org/wiki/Jon_Bentley_(computer_scientist))-[McIlroy](https://en.wikipedia.org/wiki/Douglas_McIlroy)).

Quick sort、quick select都是基于in-place partition，在进行partition的时候，都涉及pivot selection strategy。
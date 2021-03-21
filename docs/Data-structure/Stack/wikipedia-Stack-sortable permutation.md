# [Stack-sortable permutation](https://en.wikipedia.org/wiki/Stack-sortable_permutation)

 In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), a **stack-sortable permutation** (also called a **tree permutation**)[[1\]](https://en.wikipedia.org/wiki/Stack-sortable_permutation#cite_note-knott-1) is a [permutation](https://en.wikipedia.org/wiki/Permutation) whose elements may be [sorted](https://en.wikipedia.org/wiki/Sorting_algorithm) by an algorithm whose internal storage is limited to a single [stack data structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)). The stack-sortable permutations are exactly the permutations that do not contain the [permutation pattern](https://en.wikipedia.org/wiki/Permutation_pattern) 231; they are counted by the [Catalan numbers](https://en.wikipedia.org/wiki/Catalan_number), and may be placed in [bijection](https://en.wikipedia.org/wiki/Bijection) with many other combinatorial objects with the same counting function including [Dyck paths](https://en.wikipedia.org/wiki/Dyck_path) and [binary trees](https://en.wikipedia.org/wiki/Binary_tree). 

## Sorting with a stack

 The problem of sorting an input sequence using a stack was first posed by [Knuth (1968)](https://en.wikipedia.org/wiki/Stack-sortable_permutation#CITEREFKnuth1968), who gave the following [linear time](https://en.wikipedia.org/wiki/Linear_time) algorithm (closely related to algorithms for the later [all nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values) problem): 

- Initialize an empty stack
- For each input value x:
  - While the stack is nonempty and *x* is larger than the top item on the stack, pop the stack to the output
  - Push *x* onto the stack
- While the stack is nonempty, pop it to the output
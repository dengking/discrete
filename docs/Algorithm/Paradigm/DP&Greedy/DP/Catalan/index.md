# Catalan 

这类问题的解空间的数量是Catalan number。



## Bijection matched parenthesis、expression tree



### wikipedia [Matrix chain multiplication](https://en.wikipedia.org/wiki/Matrix_chain_multiplication) # Generalizations

> NOTE: 
>
> 1、其实就是expression tree、对应的是完全加括号的方式

The matrix chain multiplication problem generalizes to solving a more abstract problem: given a linear sequence of objects, an associative binary operation on those objects, and a way to compute the cost of performing that operation on any two given objects (as well as all partial results), compute the minimum cost way to group the objects to apply the operation over the sequence.[[5\]](https://en.wikipedia.org/wiki/Matrix_chain_multiplication#cite_note-5) 



One somewhat contrived special case of this is [string concatenation](https://en.wikipedia.org/wiki/String_concatenation) of a list of strings. In [C](https://en.wikipedia.org/wiki/C_(programming_language)), for example, the cost of concatenating two strings of length *m* and *n* using *strcat* is O(*m* + *n*), since we need O(*m*) time to find the end of the first string and O(*n*) time to copy the second string onto the end of it. Using this cost function, we can write a dynamic programming algorithm to find the fastest way to concatenate a sequence of strings. However, this optimization is rather useless because we can straightforwardly(直截了当的) concatenate the strings in time proportional to the sum of their lengths. A similar problem exists for singly [linked lists](https://en.wikipedia.org/wiki/Linked_lists).

Another generalization is to solve the problem when parallel processors are available. In this case, instead of adding the costs of computing each factor of a matrix product, we take the maximum because we can do them simultaneously. This can drastically affect both the minimum cost and the final optimal grouping; more "balanced" groupings that keep all the processors busy are favored. There are even more sophisticated approaches.[[6\]](https://en.wikipedia.org/wiki/Matrix_chain_multiplication#cite_note-6)



## Recurrence relation(递归方程公式)

divide and conquer: partition


# wikipedia [Matrix chain multiplication](https://en.wikipedia.org/wiki/Matrix_chain_multiplication)



## More efficient algorithms

> NOTE: 
>
> 1、将问题抽象化了，寻找到了解决此类问题的通用解法

## Generalizations

> NOTE: 
>
> 1、其实就是expression tree



The matrix chain multiplication problem generalizes to solving a more abstract problem: given a linear sequence of objects, an associative binary operation on those objects, and a way to compute the cost of performing that operation on any two given objects (as well as all partial results), compute the minimum cost way to group the objects to apply the operation over the sequence.

One somewhat contrived special case of this is [string concatenation](https://en.wikipedia.org/wiki/String_concatenation) of a list of strings. In [C](https://en.wikipedia.org/wiki/C_(programming_language)), for example, the cost of concatenating two strings of length *m* and *n* using *strcat* is O(*m* + *n*), since we need O(*m*) time to find the end of the first string and O(*n*) time to copy the second string onto the end of it. Using this cost function, we can write a dynamic programming algorithm to find the fastest way to concatenate a sequence of strings. However, this optimization is rather useless because we can straightforwardly concatenate the strings in time proportional to the sum of their lengths. A similar problem exists for singly [linked lists](https://en.wikipedia.org/wiki/Linked_lists).

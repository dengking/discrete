# Iteration

我们已经研究了recursion，现在来看和recursion密切相关的另外一种在计算机科学中广泛存在的：iteration。

我觉得之所以recursion和iteration如此重要，是因为computer science中，离散是广泛存在的，在基于这些离散结构进行计算的时候，我们最最常用的就是recursion和iteration。

正如在wikipedia [Iteration](https://en.wikipedia.org/wiki/Iteration)中有这样的总结：

> In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), [iteration](https://en.wikipedia.org/wiki/Iteration) (along with the related technique of [recursion](https://en.wikipedia.org/wiki/Recursion)) is a standard element of [algorithms](https://en.wikipedia.org/wiki/Algorithm).



与iteration相关的重要概念有：

- [Iterator](https://en.wikipedia.org/wiki/Iterator)
- [Iterator pattern](https://en.wikipedia.org/wiki/Iterator_pattern)
- [Iterative method](https://en.wikipedia.org/wiki/Iterative_method)
- [Iterative deepening depth-first search](https://en.wikipedia.org/wiki/Iterative_deepening_depth-first_search)



维基百科：[Category:Iteration in programming](https://en.wikipedia.org/wiki/Category:Iteration_in_programming)

> draft: stream是一种线性结构。



不同的programming language，以不同的方式来支持iteration的方式是不同的，c中直接使用裸指针来支持iteration，c++中抽象出来iterator（参见[Iterator library](https://en.cppreference.com/w/cpp/iterator)）。python中使用magic function来支持iteration。python中并没有显式地定义iterator类型。



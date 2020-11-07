# Computation on structure

本节标题的structure，可以指abstract structure，也可以指data structure、stream。

本文讨论对structure的computation，具体而言，它表示的是对structure的操作:

1) Add: 增

2) Delete: 删

3) Update: 改

4) Query: 查

5) Traverse: 遍历

6) Swap: 交换

## Add

add的方式非常多:

1) insert

2) expand/rewrite

## Traverse

Traverse是一种基础的操作，很多其他的operation、algorithm都是建立在traverse的基础之上的。

Traverse其实对应的computation是repetition，因此有两种实现traverse的方式:

1) iteration

2)  recursion

### Traverse and functional programming apply

Traverse是functional programming中apply的基础。

在traverse的过程中，往往对structure中的node同时执行同一个computation，这是非常多的algorithm的模式。我决定functional programming就是基于这种模式。后续我们将此成为"对structure顺序执行某个computation"，或者是`apply`模型，感觉apply模型是更加简单的。

### Traverse on nonlinear structure

这种structure不一定是线性结构(sequence)，只要能够按照某种顺序访问其node即可。

对tree、graph等nonlinear structure进行traverse，如果使用sequencial algorithm，则这个过程其实就相当于flat，对tree、graph等非线性结构进行顺序遍历的过程，其实就是将它转换为一个**线性**的结构，这个过程可以简称为**flat**。**顺序遍历**非常重要，它是很多algorithm的基础。比如graph的遍历是很多graph algorithm的基础。





### List comprehension and generator

- List comprehension

https://infogalactic.com/info/List_comprehension

- Generator

https://infogalactic.com/info/Generator_(computer_programming)#C.2B.2B






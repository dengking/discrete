# Catalan number

## 计算机算法设计与分析 # 3.1 矩阵连乘问题

> NOTE: 
>
> 1、是在阅读这篇文章的时候，其中提及了Catalan number，并且结合"矩阵连乘问题"，Catalan number的递归方程是非常容易理解的。
>
> 

![](./计算机算法设计与分析-Catalan-number.jpg)





## 如何理解、分析Catalan [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation)？

wikipedia [Catalan number](https://en.wikipedia.org/wiki/Catalan_number) :

> The Catalan numbers satisfy the [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation)[[1\]](https://en.wikipedia.org/wiki/Catalan_number#cite_note-1) 
>
>  $ C_{0}=1\quad {\text{and}}\quad C_{n+1}=\sum _{i=0}^{n}C_{i}\,C_{n-i}\quad {\text{for }}n\geq 0, $ 



一、为什么是$C_{i}$ 乘以$C_{n-i}$，而不是相加呢？如何来结和具体案例对这个问题进行分析？

1、结合"矩阵连乘"的例子来理解

2、需要以"divide and conquer-原问题 子问题"

在位置`i`初，断开，则左侧子问题的解空间的个a数为$C_{i}$，右侧子问题的解空间个数为$C_{n-i}$，原问题的解空间个数是由左右两侧子问题的解组合而成，因此应该使用乘法而不是加法。

二、实际模型

1、expression tree、Parenthese-and-tree

2、noncrossing partition



## 如何解Catalan问题？

1、使用dynamic programming，参见`Dynamic-Programming`的`Catalan`章节。


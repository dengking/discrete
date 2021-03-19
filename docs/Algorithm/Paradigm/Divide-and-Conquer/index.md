# Divide-and-conquer algorithm

1、非常重要的思想、one-by-one的典范

2、原问题 和 子问题；原问题 和 子问题 之间的关系

3、"Divide-and-conquer"是非常重要的思想，它是解决后续各种问题的基础

## 递归和分治

1、Divide-and-conquer algorithm 和 recursion 是天然相关的

分治的思想是: 对于难以直接求解的问题，可以考虑把这个问题分解成若干规模较小的相同子问题，从而各个击破，分而治之。

**分治法**采用**递归函数**实现的原因: 由**分治法**产生的**子问题**和**原问题**往往是相同**性质**的，因此可以使用递归技术。而分治法的核心是把问题的规模降低，因此，在回溯函数的参数中往往有表示问题规模的参数。

> NOTE: 
>
> 1、"因此可以使用递归技术"的解释: 递归就是调用自身，也就是执行相同的操作，解决相同的问题



2、所有的recurrence relations，应该都可以使用Divide-and-conquer algorithm来实现



## TODO Divide-and-conquer algorithm的并行化

关于此，参见:

1、"wikipedia [Divide-and-conquer algorithm](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm) # Parallelism"章节

2、工程"Parallel-computing"的`Fork–join-model`章节
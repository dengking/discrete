# Divide-and-conquer algorithm

## 非常重要的计算思想

"divide-and-conquer" 简单然而强大: 

一、one-by-one的典范

二、思考原问题 和 子问题(原问题 和 子问题 之间的关系)；尤其是对于大型的问题，这是非常重要的一种解决问题的思路，典型的例子: [external sorting](https://en.wanweibaike.com/wiki-External%20sorting)。

三、它是很多其它algorithm的基石

四、distributed computing、parallel computing 都蕴含着 divide-and-conquer思想，在"Divide-and-conquer and parallel computing"中，对此进行了讨论。



## 递归和分治

1、Divide-and-conquer algorithm 和 recursion 是天然相关的

分治的思想是: 对于难以直接求解的问题，可以考虑把这个问题分解成若干规模较小的相同子问题，从而各个击破，分而治之。

**分治法**采用**递归函数**实现的原因: 由**分治法**产生的**子问题**和**原问题**往往是相同**性质**的，因此可以使用递归技术。而分治法的核心是把问题的规模降低，因此，在回溯函数的参数中往往有表示问题规模的参数。

> NOTE: 
>
> 1、"因此可以使用递归技术"的解释: 递归就是调用自身，也就是执行相同的操作，解决相同的问题



2、所有的recurrence relations，应该都可以使用Divide-and-conquer algorithm来实现



## Divide-and-conquer and parallel computing



### Parallel computing 加速 divide-and-conquer

Parallel computing、distributed computing能够加速divide-and-conquer的性能

一、"fork and join parallel divide-and-conquer"

典型的例子就是 "APUE 11.6.8 Barriers" 中的merge sort的例子。

二、"distributed computing parallel divide-and-conquer"

### 使用divide-and-conquer来分解

> NOTE: 
>
> 1、这是在阅读 "drdobbs [How Much Scalability Do You Have or Need?](https://www.drdobbs.com/parallel/how-much-scalability-do-you-have-or-need/201202924) # O(N): Scalable Throughput And the Free Lunch" 时，想到的，其中将此称为 "**natural parallelism**"。我们将此称为"fork-join-parallel-divide-and-conquer-and-merge-quicksort-natural parallelism"

1、当今"parallel computing是主流"，我们更应该使用"divide-and-conquer"来对structure进行分解，让各个sub structure被并行地计算

2、distributed computing、parallel computing 都 蕴含着 divide-and-conquer思想

### 参见

1、"wikipedia [Divide-and-conquer algorithm](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm) # Parallelism"章节

2、工程"Parallel-computing"的`Fork–join-model`章节

3、stackoverflow [difference of divide and conquer & fork and join](https://stackoverflow.com/questions/29686964/difference-of-divide-and-conquer-fork-and-join)





## TODO

programiz [Divide and Conquer Algorithm](https://www.programiz.com/dsa/divide-and-conquer)

https://softwareengineering.stackexchange.com/questions/197107/divide-and-conquer-algorithms-why-not-split-in-more-parts-than-two


https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/divide-and-conquer-algorithms


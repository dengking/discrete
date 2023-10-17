# Divide-and-Conquer&Recurrence-relation&Recursion

概述: Divide-and-Conquer的思想是思考**原问题**和**子问题**之间的关系，总结出描述问题的 [recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation) (是一种 recursive definition)，然后借助recursion来实现进而求解。

上述思想是dynamic programming、greedy algorithm的基石，它们都是从它演变而来。

"divide-and-conquer"是非常重要的计算思想，它简单然而强大: 

一、one-by-one的典范

显然，它的计算方式是one-by-one。





四、distributed computing、parallel computing 都蕴含着 divide-and-conquer思想，在"Divide-and-conquer and parallel computing"中，对此进行了讨论。



## Divide-and-Conquer和Recursion

Divide-and-conquer algorithm 它天然地适合于使用 recursion来实现: 

由于 **分治法** 产生的 **子问题** 和 **原问题** 往往是相同**性质**的，因此可以使用递归技术。分治法的核心是把问题的规模降低，因此，在回溯函数的参数中往往有表示问题规模的参数。

draft: 

1、"因此可以使用递归技术"的解释: 递归就是调用自身，也就是执行相同的操作，解决相同的问题

2、所有的recurrence relations，应该都可以使用Divide-and-conquer algorithm来实现





## Divide and conquer example

labuladong [手把手搞懂接雨水问题的多种解法](https://mp.weixin.qq.com/s/mFqrlhqYEPhRa9p4ewl3Xw)

> 对于这种问题，我们不要想整体，而应该去想局部；就像之前的文章写的动态规划问题处理字符串问题，不要考虑如何处理整个字符串，而是去思考应该如何处理每一个字符。
>
> 这么一想，可以发现这道题的思路其实很简单。具体来说，仅仅对于位置`i`，能装下多少水呢？

很多algorithm，其实都是基于解空间、原问题和子问题而构建的





## Examples



| Example                                                      | 核心思想                                                     |      |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- |
| [LeetCode-213. 打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/) 中等 | 题目要求不能抢相邻的，并且题目给出的环形数组，所以就可以分为三种情况:<br>1、`[1, n-2]`<br>2、`[0, n-2]`<br>3、`[1, n-1]`<br>然后从上述三种情况中进行择优录取。 |      |
| [LeetCode-321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number/) 困难 | 题目要求从两个数组中共取出k个数，找出最大的数，该算法依次取出所有的k个数，并进行择优录取。 |      |
|                                                              |                                                              |      |

典型的例子: [external sorting](https://en.wanweibaike.com/wiki-External%20sorting)。

> NOTE: 
>
> 这是自顶向下的思考方式

## TODO

programiz [Divide and Conquer Algorithm](https://www.programiz.com/dsa/divide-and-conquer)

https://softwareengineering.stackexchange.com/questions/197107/divide-and-conquer-algorithms-why-not-split-in-more-parts-than-two


https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/divide-and-conquer-algorithms





### 重叠子问题

对于重叠子问题，我们可以将它们的解保存下来，用于后续的使用，从而提高性能。

1、重叠子问题，参见 `Overlapping-subproblem` 章节

2、"time and space tradeoff"，参见 `Space-time-tradeoff` 章节





## Balanced

merge-sort 自己主动就保持了平衡

quick-sort要通过特殊的操作来保持平衡

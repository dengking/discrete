# Divide-and-Conquer&Recurrence-relation&Recursion

本章内容概述: 

一. Divide-and-Conquer的思想是思考**原问题**和**子问题**之间的关系，总结出描述问题的 [recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation) (是一种 recursive definition)，然后借助recursion来实现进而求解。

上述思想是dynamic programming、greedy algorithm的基石，它们都是从它演变而来。

二. Divide-and-Conquer和Recursion

Divide-and-conquer algorithm 天然地适合于使用 recursion来实现: 

- 由于 **分治法** 产生的 **子问题** 和 **原问题** 往往是相同**性质**的，因此可以使用递归技术。分治法的核心是把问题的规模降低，因此，在回溯函数的参数中往往有表示问题规模的参数。
- "因此可以使用递归技术"的解释: 递归就是调用自身，也就是执行相同的操作，解决相同的问题
- 所有的recurrence relations，应该都可以使用Divide-and-conquer algorithm来实现




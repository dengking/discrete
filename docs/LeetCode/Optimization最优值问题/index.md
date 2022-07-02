# 最值问题



## 算法

### 打擂台、枚举所有的可能性+择优

其实这种解法的前提是进行穷举，这也是最值问题的根基所在，关于这个问题

1、暴力、回溯法

2、动态规划

3、双指针、滑动队列

### 贪心

1、贪心算法



### Optimization algorithm and search algorithm

使用各种各样的[Optimization algorithm](https://en.wikipedia.org/wiki/Optimization_algorithm)来实现[Optimization](https://en.wikipedia.org/wiki/Mathematical_optimization)问题，其实其过程也可以看做是[Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm)：search for best solution，即寻找最优解，这些算法往往采用的策略是：不断地向最优解逼近，关于这个观点，在`Relation-structure-computation\Computation\index.md#Iterative method`章节中也进行了描述。

比如[Gradient descent](https://en.wikipedia.org/wiki/Gradient_descent)就是一个典型的例子：该算法的过程可以看做是不断地向目标逼近的过程，下面是说明此观点的素材：

[如何直观地解释 backpropagation 算法？ - Anonymous的回答 - 知乎]( https://www.zhihu.com/question/27239198/answer/89853077)中有这样的说明：

> 梯度下降法需要给定一个初始点，并求出该点的梯度向量，然后以负梯度方向为搜索方向，以一定的步长进行搜索，从而确定下一个迭代点，再计算该新的梯度方向，如此重复直到cost收敛。



### 借助数据结构

1、单调栈



## Monotonic-stack单调栈-VS-dynamic-programming动态规划

这是在 LeetCode [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) # [文慕阳](https://leetcode.cn/u/wen-mu-yang/) # [C++ 利用哨兵👨‍✈️，维护一个单调栈📈(图解，直观掌握)](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solution/c-li-yong-shao-bing-wei-hu-yi-ge-dan-diao-zhan-tu-/) 中提出的:



> 一眼看过去，这个题本质就是要求某个数与其右边最大的数的差值，这符合了单调栈的应用场景 当你需要高效率查询某个位置左右两侧比他大（或小）的数的位置的时候，于是我就用单调栈解决了(但是发现题解很多都是 dpdp，哈哈)。
>



可以看出，在这类问题上，DP和单调栈都可以使用。



## 习题总结


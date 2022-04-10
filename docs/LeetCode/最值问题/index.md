# 最值问题

## 解法

### 枚举所有的可能性+择优

1、暴力、回溯法

2、动态规划

### 贪心

1、贪心算法



### 借助数据结构

1、单调栈





## Monotonic-stack单调栈-VS-dynamic-programming动态规划

这是在 LeetCode [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) # [C++ 利用哨兵👨‍✈️，维护一个单调栈📈(图解，直观掌握)](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/c-li-yong-shao-bing-wei-hu-yi-ge-dan-diao-zhan-tu-/) 中提出的:



> 一眼看过去，这个题本质就是要求某个数与其右边最大的数的差值，这符合了单调栈的应用场景 当你需要高效率查询某个位置左右两侧比他大（或小）的数的位置的时候，于是我就用单调栈解决了(但是发现题解很多都是 dpdp，哈哈)。
>
> 作者：wen-mu-yang
> 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/c-li-yong-shao-bing-wei-hu-yi-ge-dan-diao-zhan-tu-/
> 来源：力扣（LeetCode）
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



可以看出，在这类问题上，DP和单调栈都可以使用。


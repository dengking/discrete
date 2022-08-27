# Monotonic stack解 "最大、最小 子序列(subsequence)"

## leetcode [402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/) #[力扣加加](https://leetcode.cn/u/fe-lucifer/) # [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode.cn/problems/remove-k-digits/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-5/) 

这就是接下来要给大家讲的四个题，其中 1081 和 316 题只是换了说法而已。

- [316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters/) (困难)
- [321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number/) (困难)
- [321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number/) (困难)
- [1081. 不同字符的最小子序列](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/) （中等）

- [402. 移掉 K 位数字](https://leetcode.cn/problems/remove-k-digits/)



### 总结

> NOTE: 
>
> 1、这个作者的总结非常好，举一反三

这四道题都是删除或者保留若干个字符，使得剩下的数字最小（或最大）或者字典序最小（或最大）。而解决问题的前提是要有一定数学前提。而基于这个数学前提，我们贪心地删除栈中相邻的字符。如果你会了这个套路，那么这四个题目应该都可以轻松解决。

> NOTE: 
>
> 1、greedy + monotonic stack

316、去除重复字母（困难），我们使用 hashmap 代替了数组的遍历查找，属于典型的空间换时间方式，可以认识到数据结构的灵活使用是多么的重要。背后的思路是怎么样的？为什么想到空间换时间的方式，我在文中也进行了详细的说明，这都是值得大家思考的问题。然而实际上，这些题目中使用的栈也都是空间换时间的思想。大家下次碰到需要空间换取时间的场景，是否能够想到本文给大家介绍的栈和哈希表呢？

321、拼接最大数（困难）则需要我们能够对问题进行分解，这绝对不是一件简单的事情。但是对难以解决的问题进行分解是一种很重要的技能，希望大家能够通过这道题加深这种分治思想的理解。 



## 我的分析



leetcode [316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters/) ( leetcode  [1081. 不同字符的最小子序列](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/) )

leetcode [402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/) 

leetcode [321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number/)

上述题目，本质上的解法应该归入greedy algorithm，它们都需要lexicographical-order、数字值的知识，下面是总结归纳：

| 题目                                                         |              |                            |                                                              |
| ------------------------------------------------------------ | ------------ | -------------------------- | ------------------------------------------------------------ |
| leetcode [402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/) | 去重K位      | "剩下的数字最小"           | 从左到右、从低位到高位，单调递增的数字序列的值是最下的，它本质上是字典序最小；<br>这道题增加了一点难度系数就是：K，这就意味着必须要删除掉K，从而得到一个长度为N-K的单调递增序列。 <br>这道题也可以归入"**定长子序列问题**"的范畴。 |
| leetcode [316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters/) | 去重重复字母 | "**返回结果的字典序最小**" | 从左到右、从低位到高位，单调递增的数字序列的值是最下的，它本质上是字典序最小；<br>这道题也可以归入"**定长子序列问题**"的范畴。 |
| leetcode  [1081. 不同字符的最小子序列](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/) |              |                            |                                                              |
| leetcode [321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number/) |              |                            | divide-and-conqure-and-merge+穷举打擂台求解最优值            |
|                                                              |              |                            |                                                              |

monolithic stack恰好能够满足解决这些问题的需求：

1、monolithic stack能够保留过去的状态，它能够找到单调递增、单调递减的序列，且这个序列是最小、最大的，因此它是非常适合于由于解决这类问题的。

2、能够保持相对位置不变，非常符合题目的要求

### 题目要求分析

#### 1、"拼接"或者 "剔除"

leetcode [321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number/) 是"拼接"生成新串

leetcode [316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters/) ( leetcode  [1081. 不同字符的最小子序列](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/) )、leetcode [402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/) 是"剔除"生成子序列。

#### 2、字典次序、数值次序

leetcode [402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/) 

leetcode [316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters/)、leetcode  [1081. 不同字符的最小子序列](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/) 



#### 3、保持相对位置不变

都要求保持相对位置不变，显然，这是非常适合于使用stack的。



## 解题思路、策略

这些题都是monotonic stack的典型应用。

leetcode [402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/) : 

1、Monotonic-stack+greedy+lexicographical-order-字典序

对于 leetcode [316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters/) ( leetcode  [1081. 不同字符的最小子序列](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/) )

1、Monotonic-stack+greedy+lexicographical-order-字典序+visited array去重+counter array

对于 leetcode [321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number/)，它是前面类型题目的升级版，它的解题策略概括为:

1、Monotonic-stack+greedy

2、divide-and-conquer-and-merge+打擂台求解最优值
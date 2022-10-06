# 等差数列

[LeetCode-413. 等差数列划分](https://leetcode.cn/problems/arithmetic-slices/) 中等、LeetCode [446. 等差数列划分 II - 子序列](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/) 困难是两道非常好的使用DP来求解计数问题的题，都是使用DP来进行求解的、divide-and-conquer-原问题和子问题；

| 题目                                                         |                      | 类比                                                         |                       |
| ------------------------------------------------------------ | -------------------- | ------------------------------------------------------------ | --------------------- |
| [LeetCode-413-等差数列划分-中等](https://leetcode.cn/problems/arithmetic-slices/) | 连续、subarray       | 最大子数组和，这道题和最大子数组和其实是方非常类似，背后的思想是相同的， 甚至连算法的优化过程都相同。 | $dp[i] = dp[i-1] + 1$ |
| [LeetCode-446-等差数列划分-II-子序列](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/) 困难 | 非连续、sub sequence | 最长递增子序列                                               | $dp[i] = dp[j] + 1$   |

上述两道题，非常的典型，可以基本上相同的DP来进行解决，并且它们的状态方程的定义是相同的：

一、两者的状态方程的定义都是`nums[i]`结尾，公差为`d`的等差数列的个数，这是依据尾项和公差能够确定一个等差数列，它们的状态转移方程的原理相同，下面是例子，这个例子在 [LeetCode-446. 等差数列划分 II - 子序列](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/) 困难 中也包含了:

> 上述状态转移方程是以$nums[i]$为尾项的等差数列的个数，下面结合具体的例子来进行理解:
>
> `6,8` {2: 1}
>
> `4,6,8`: {2: 2}
>
> $f[j][d]$ 对应的是: 在`6,8`前面加上`4`可以形成1个，显然这是可以直接从`6,8`的个数计算得到的
>
> $+1$ 对应的是: `4,6`
>
> `2,4,6,8`: {2: 3}
>
> $f[j][d]$ 对应的是: 在`4,6,8`前面加上`2`可以形成2个，显然这是可以直接从`4,6,8`的个数计算得到的
>
> $+1$ 对应的是: `2,4`

简单理解就是：你原来有多少个，那么现在加上我就可以新增多少个。



下面是对这两道题非常好的解释：

一、[LeetCode-446. 等差数列划分 II - 子序列](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/) # [liweiwei1419](https://leetcode.cn/u/liweiwei1419/) # [动态规划（Java）](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/solution/dong-tai-gui-hua-java-by-liweiwei1419-jc84/)

二、[LeetCode-446. 等差数列划分 II - 子序列](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/) # [[负雪明烛]揭秘子序列动态规划的套路](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/) 


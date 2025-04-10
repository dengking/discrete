# 连续子数组、连续子串问题

一、子串、子数组是连续的；

二、字符串其实可以看做是array of character，因此子串问题和子数组问题非常类似，很多情况下可以使用相同的算法，因此可以将它们放在一起讨论。

三、子数组问题，要追求O(N)复杂度

四、要么连在一起要么自成一派

下面是典型的例题：

1、最大子数组

2、LeetCode-413-等差数列划分-中等



## 穷举

嵌套for循环(left、right双指针)，通过嵌套的for循环，枚举中所有可能的子串、子数组情况。

典型例子:

1、最大子数组

`Expert-labuladong\1-动态规划系列\1.2-子序列类型问题\最大子数组`

实现上最简单，但是复杂度较高。

### 复杂度

与实现的方式有关:

1、$O(N^3)$​



## 动态规划

由于题目要求连续，因此在定义状态转移方程的时候，往往需要以这样的方式来进行定义:

一、labuladong [动态规划套路：最大子数组和](https://mp.weixin.qq.com/s/nrULqCsRsrPKi3Y-nUfnqg)

> **以`nums[i]`为结尾的「最大子数组和」为`dp[i]`**。
>
> ```c++
> // 要么自成一派，要么和前面的子数组合并
> dp[i] = Math.max(nums[i], nums[i] + dp[i - 1]);
> ```
>
> 

二、[LeetCode-487. 最大连续1的个数 II](https://leetcode.cn/problems/max-consecutive-ones-ii/) # [力扣官方题解](https://leetcode.cn/u/leetcode-solution/) # [方法二：动态规划](https://leetcode.cn/problems/max-consecutive-ones-ii/solution/zui-da-lian-xu-1de-ge-shu-ii-by-leetcode-solution/) 

> 1、 `dp[i][0]` 为考虑到以 `i` 为结尾未使用操作将 `[0,i]`某个 `0` 变成 `1` 的最大的连续 `1` 的个数
>
> 2、`dp[i][1]` 为考虑到以 `i` 为结尾使用操作将 `[0,i]` 某个 `0` 变成 `1` 的最大的连续 `1` 的个数
>
> 状态转移方程:
> $$
> dp[i][0]=
> \begin{cases}
> dp[i-1][0] + 1 & nums[i] \gt 1 \\
> 0 & nums[i] = 0 \\
> \end{cases}
> $$
> 和
> $$
> dp[i][1]=
> \begin{cases}
> dp[i-1][1] + 1 & nums[i] \gt 1 \\
> dp[i-1][0] + 1 & nums[i] = 0 \\
> \end{cases}
> $$
> 

### 最大子数组和

参见 `Expert-labuladong\1-动态规划系列\1.2-子序列类型问题\最大子数组` 。



### LeetCode-连续1

参见 `LeetCode-连续1` 章节。



## 双指针 double pointer

left、right双指针从中间向两边扩散



### 最长回文子串

`Expert-labuladong\Palindrome-回文\最长回文子串`

复杂度: $O(N)$ 

## 滑动窗口

参见 `滑动窗口解连续-子数组子串` 章节。



## 前缀和

### 素材

labuladong [前缀和技巧：解决子数组问题](https://mp.weixin.qq.com/s/4TxF0xVhlUO6v3teip9Jzg)，在其中有着非常好的总结:

> 前缀和不难，却很有用，主要用于处理数组区间的问题。

其实上述所谓的"数组区间"就是子数组。

## 例题

一、[LeetCode-560. 和为K的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)

### 等差子数组

[LeetCode-413. 等差数列划分](https://leetcode.cn/problems/arithmetic-slices/) 中等

动态规划 $O(N)$



## KMP、LIS、重复的子串

LIS和KMP算法的next，fail函数类似: 

1、都是单个序列

2、两者的过程是比较类似的

关于"重复的子串"，参见 "重复的子字符串系列" 章节。



KMP也是寻找模式串中的重复子串
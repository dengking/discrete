# 连续子数组、连续子串问题

一、子串、子数组是连续的；

二、字符串其实可以看做是array of character，因此子串问题和子数组问题非常类似，很多情况下可以使用相同的算法，因此可以将它们放在一起讨论。

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

二、LeetCode [487. 最大连续1的个数 II](https://leetcode-cn.com/problems/max-consecutive-ones-ii/) # [力扣官方题解](https://leetcode-cn.com/u/leetcode-solution/) # [方法二：动态规划](https://leetcode-cn.com/problems/max-consecutive-ones-ii/solution/zui-da-lian-xu-1de-ge-shu-ii-by-leetcode-solution/) 

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

### 前提条件

使用滑动窗口解决连续子数组、连续子串的最值问题的前提是问题需要具备单调性，如果问题不具备单调性，则不能够使用滑动窗口，这在下面的文章中进行了非常好的讨论:

一、labuladong [动态规划套路：最大子数组和](https://mp.weixin.qq.com/s/nrULqCsRsrPKi3Y-nUfnqg) 

### 素材

一、labuladong [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 

### 例题

一、LeetCode [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) 中等

二、LeetCode [438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/) 中等

三、LeetCode [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/) 困难

四、LeetCode [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/) 中等



## 前缀和

### 素材

labuladong [前缀和技巧：解决子数组问题](https://mp.weixin.qq.com/s/4TxF0xVhlUO6v3teip9Jzg)

## 例题

一、LeetCode [560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

### 等差子数组

LeetCode [413. 等差数列划分](https://leetcode-cn.com/problems/arithmetic-slices/) 中等

动态规划 $O(N)$



### 加油站

一、labuladong [当老司机学会了贪心算法](https://mp.weixin.qq.com/s/k-z_oewAqMYc3vpmOm4gEQ) # LeetCode [134. 加油站](https://leetcode-cn.com/problems/gas-station/)


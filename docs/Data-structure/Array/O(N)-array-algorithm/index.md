# O(N) Array algorithm

对于array的各种问题，O(N)复杂度是目标追求，即我们要追求一次遍历，就能够将问题进行求解。

那如何来实现呢？

## double pointer遍历一轮序列可以做的事情

一、使用双double pointer指针技巧，我们能够只遍历一轮数组，就完成很多看似不可能完成的事情，这在下面的章节、文章中，已经进行非常深刻的讨论: 

`Expert-labuladong\2.5-手把手刷数组题目`

二、使用区间的概念来进行理解

三、此处的序列，包括: 

1、array

2、linked list

四、本文补充一些内容，它们的实现也是可以使用double pointer来进行解释的

### quick sort partition

quick sort的partition遍历数组一轮就可以将数组分为两部分，在quick sort章节中总结了quick sort partition可以使用如下两种方式:

1、fast slow double pointer

2、left right double pointer

### binary search判定子序列

上述partition的实现，其实是使用的双指针，它的写法是非常类似于在 labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s/hWi2hTrQewL_YKioGkXQJg) 中给出的:

> **双指针**
>
> 首先，一个很简单的解法是这样的：
>
> ```C++
> bool isSubsequence(string s, string t) {
>     int i = 0, j = 0;
>     while (i < s.size() && j < t.size()) {
>         if (s[i] == t[j]) i++;
>         j++;
>     }
>     return i == s.size();
> }
> ```
>
> 其思路也非常简单，利用双指针`i, j`分别指向`s, t`，一边前进一边匹配子序列：
>
> ![图片](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4mnbVC00EzwNpKWVLic67v8fp4AviccRT7S8XlynThhhyUxhB2X63YwDSCyq2ZWcGo6cQS0HhxKiaziaQ/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)
>
> 读者也许会问，这不就是最优解法了吗，时间复杂度只需 O(N)，N 为`t`的长度。

原题是 LeetCode [392. 判断子序列](https://leetcode.cn/problems/is-subsequence/) 简单。上述算法是典型的fast-slow double pointer。

在阅读 labuladong  [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ) 时，发现其实此处的双指针更加准确地说是: fast-slow double pointer:

> 我们让慢指针`slow`走在后面，快指针`fast`走在前面探路，找到一个不重复的元素就告诉`slow`并让`slow`前进一步。这样当`fast`指针遍历完整个数组`nums`后，**`nums[0..slow]`就是不重复元素**。
>
> ```C
> int removeDuplicates(int[] nums) {
>  if (nums.length == 0) {
>      return 0;
>  }
>  int slow = 0, fast = 0;
>  while (fast < nums.length) {
>      if (nums[fast] != nums[slow]) {
>          slow++;
>          // 维护 nums[0..slow] 无重复
>          nums[slow] = nums[fast];
>      }
>      fast++;
>  }
>  // 数组长度为索引 + 1
>  return slow + 1;
> }
> ```
>
> 看下算法执行的过程：
>
> ![Image](https://mmbiz.qpic.cn/sz_mmbiz_gif/gibkIz0MVqdFXdiaWmw4sp8GT0YI41Rk5muqNGreX2FbysTeUnlAWECO1eYWc5ZZDPMYCs7ViaHkEaOfK4lI9HD7A/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)




# 滑动窗口解子串、子序列问题

## 前提条件

使用滑动窗口的前提是: "向右滑动的时候，是寻找一个可行解，向左滑动是优化解"

使用滑动窗口解决连续子数组、连续子串的最值问题的前提是问题需要具备单调性，如果问题不具备单调性，则不能够使用滑动窗口，这在下面的文章中进行了非常好的讨论:

一、labuladong [动态规划套路：最大子数组和](https://mp.weixin.qq.com/s/nrULqCsRsrPKi3Y-nUfnqg) 

二、zhuanlan [经典动态规划：最大子数组问题](https://zhuanlan.zhihu.com/p/144385162)

> NOTE: 
>
> 1、就是最大子序和 

但是，稍加分析就发现，**这道题还不能用滑动窗口算法，因为数组中的数字可以是负数**。

> NOTE: 
>
> 1、如果都是非负数，显然是能够使用滑动窗口算法的，因为它满足了滑动窗口的单调性要求

滑动窗口算法无非就是双指针形成的窗口扫描整个数组/子串，但关键是，你得清楚地知道什么时候应该移动右侧指针来扩大窗口，什么时候移动左侧指针来减小窗口。

而对于这道题目，你想想，当窗口扩大的时候可能遇到负数，窗口中的值也就可能增加也可能减少，这种情况下不知道什么时机去收缩左侧窗口，也就无法求出「最大子数组和」。

三、leetcode [560. 和为 K 的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

这个问题就是典型的不能够使用滑动窗口的

## 问题分类

这类问题有多种分类方式：

### 一、窗口是否定长？

参见`定长滑动窗口`章节。

### 二、连续还是不连续？



### 三、

1、存在性问题

2、计数问题

3、最优值问题



## 窗口表示与比较

一、目标值和窗口的比较这是滑动窗口算法的一个common issue

一般，将目标值称为`need`，将窗口称之为`window`。

二、使用lambda来表示窗口的比较

比如 Leetcode [1100. 长度为 K 的无重复字符子串](https://leetcode-cn.com/problems/find-k-length-substrings-with-no-repeated-characters/) 

### 窗口的表示

一、对于字符串相关的问题

1、Leetcode [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/) # [官方解题](https://leetcode-cn.com/problems/permutation-in-string/solution/zi-fu-chuan-de-pai-lie-by-leetcode-solut-7k7u/)

```c++
vector<int> cnt1(26), cnt2(26);
for (int i = 0; i < n; ++i) {
  ++cnt1[s1[i] - 'a'];
  ++cnt2[s2[i] - 'a'];
}
if (need == window)
  return true;
```

上述直接使用vector来表示need和window。

2、Leetcode [1100. 长度为 K 的无重复字符子串](https://leetcode-cn.com/problems/find-k-length-substrings-with-no-repeated-characters/)

```c++
    unordered_map<char, int> window;
    for (int i = 0; i < k; ++i)
    {
      ++window[s[i]];
    }
    auto isNotRepeat = [&]() -> bool
    {
      for (auto &&item : window)
      {
        if (item.second > 1)
        {
          return false;
        }
      }
      return true;
    };
```



## LeetCode例题

一、LeetCode [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) 中等

二、LeetCode [438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/) 中等

三、LeetCode [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/) 困难

四、LeetCode [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/) 中等

五、LeetCode [1839. 所有元音按顺序排布的最长子字符串](https://leetcode-cn.com/problems/longest-substring-of-all-vowels-in-order/) 中等

## 素材

一、labuladong [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 


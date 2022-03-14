# 滑动窗口解子串、子序列问题

## 前提条件

使用滑动窗口解决连续子数组、连续子串的最值问题的前提是问题需要具备单调性，如果问题不具备单调性，则不能够使用滑动窗口，这在下面的文章中进行了非常好的讨论:

一、labuladong [动态规划套路：最大子数组和](https://mp.weixin.qq.com/s/nrULqCsRsrPKi3Y-nUfnqg) 

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

窗口的表示：

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

## LeetCode例题

一、LeetCode [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) 中等

二、LeetCode [438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/) 中等

三、LeetCode [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/) 困难

四、LeetCode [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/) 中等

五、LeetCode [1839. 所有元音按顺序排布的最长子字符串](https://leetcode-cn.com/problems/longest-substring-of-all-vowels-in-order/) 中等

## 素材

一、labuladong [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 


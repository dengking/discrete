# labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s/hWi2hTrQewL_YKioGkXQJg)

> NOTE: 
>
> 一、需要注意的是:  子序列是需要保证相对位置的
>
> 二、本文描述的思路和KMP的思想是有些类似的: 预处理字符串来加速匹配

二分查找本身不难理解，难在巧妙地运用二分查找技巧。对于一个问题，你可能都很难想到它跟二分查找有关，比如前文 [最长递增子序列](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247484232&idx=1&sn=21234a9e4db908f438e1cb2e8c7ffff4&chksm=fb33630acc44ea1c91027bff20e9902e20e4269d54f3c178dc1e07f344d48d7ff1a4ca48ba39&scene=21#wechat_redirect) 就借助一个纸牌游戏衍生出二分查找解法。

今天再讲一道巧用二分查找的算法问题：如何判定字符串`s`是否是字符串`t`的子序列（可以假定`s`长度比较小，且`t`的长度非常大）。

> NOTE: 
>
> `t`的长度比较大，意味着可能需要花费更多的时间进行匹配

举两个例子：

s = "abc", t = "**a**h**b**gd**c**", return true.

s = "axc", t = "ahbgdc", return false.

题目很容易理解，而且看起来很简单，但很难想到这个问题跟二分查找有关吧？



### 一、问题分析

> NOTE: 
>
> LeetCode [392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/) 简单

首先，一个很简单的解法是这样的：

```C++
bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) i++;
        j++;
    }
    return i == s.size();
}
```

其思路也非常简单，利用双指针`i, j`分别指向`s, t`，一边前进一边匹配子序列：

![图片](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4mnbVC00EzwNpKWVLic67v8fp4AviccRT7S8XlynThhhyUxhB2X63YwDSCyq2ZWcGo6cQS0HhxKiaziaQ/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)

读者也许会问，这不就是最优解法了吗，时间复杂度只需 O(N)，N 为`t`的长度。

是的，如果仅仅是这个问题，这个解法就够好了，**不过这个问题还有 follow up**：

如果给你一系列字符串`s1,s2,...`和字符串`t`，你需要判定每个串`s`是否是`t`的子序列（可以假定`s`相对较短，`t`很长）。

```Java
boolean[] isSubsequence(String[] sn, String t);
```

你也许会问，这不是很简单吗，还是刚才的逻辑，加个 for 循环不就行了？

可以，但是此解法处理每个`s`时间复杂度仍然是 O(N)，而如果巧妙运用二分查找，可以将时间复杂度降低，大约是 O(MlogN)，M 为 s 的长度。由于 N 相对 M 大很多，所以后者效率会更高。


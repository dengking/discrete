# [LeetCode-214. 最短回文串-困难](https://leetcode.cn/problems/shortest-palindrome/)



## 我的解题

是参考的 [LeetCode-Clean KMP solution with super detailed explanation](https://leetcode.com/problems/shortest-palindrome/discuss/60113/clean-kmp-solution-with-super-detailed-explanation) 写的，下面是我的总结:

一、题目要求只能在字符串的前面添加字符来将它转换为回文串，按照这种方式，直接的做法是: 找到从0开始的最长回文串，然后在head出添加剩余串的reverse，这样就现成了一个回文串了。

二、如何查找最长回文子串？回文串的特性是: 正着读和反着读都是一样的，那我就可以将原串和它的reverse拼接起来，使用KMP查找它们的公共前缀后缀，这样就能够得到它的长度。

三、

> The trick is to build a temp string like this:
>
> > s + "#" + reverse(s)
>
> Then we run KMP on it, the value in last cell will be our solution. In this problem, we don't need to use KMP to match strings but instead we use the lookup table in KMP to find the palindrome.
>
> We add "#" here to force the match in reverse(s) starts from its first index.
>
> What we do in KMP here is trying to find a match between prefix in s and a postfix in reverse(s). The match part will be palindrome substring.

为什么加上一个 '#' 符合呢？这是因为KMP求解的最长公共前后缀是可以重叠的，而这道题中，由于temp string是有s构造出来的，我们的目标是求解s的palindrome substring，它是不允许重叠的，加上 '#' 能够有效的避免重叠。






# Longest palindromic substring

最长回文子串。

## wikipedia [Longest palindromic substring](https://en.wikipedia.org/wiki/Longest_palindromic_substring)



## Algorithms

### KMP LPS

这个algorithm是在 [LeetCode-Clean KMP solution with super detailed explanation](https://leetcode.com/problems/shortest-palindrome/discuss/60113/clean-kmp-solution-with-super-detailed-explanation) 中发现的，它仅限于"find the **longest palindrome substring** starts from index 0"，它充分运用回文串的特性对称的特性，显然经过reverse后依然维持不变:

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

进行拼接，从而将它转换为 KMP common prefix+suffix。



### DP

TODO

### Manacher's algorithm

TODO

## LeetCode

[LeetCode-5. 最长回文子串-中等](https://leetcode.cn/problems/longest-palindromic-substring/) 

[LeetCode-214. 最短回文串-困难](https://leetcode.cn/problems/shortest-palindrome/) 


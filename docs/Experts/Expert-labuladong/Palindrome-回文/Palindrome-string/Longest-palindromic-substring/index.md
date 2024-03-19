# Longest palindromic substring

最长回文子串。

## wikipedia [Longest palindromic substring](https://en.wikipedia.org/wiki/Longest_palindromic_substring)



## Algorithms

### KMP LPS

[LeetCode-Clean KMP solution with super detailed explanation](https://leetcode.com/problems/shortest-palindrome/discuss/60113/clean-kmp-solution-with-super-detailed-explanation)  

- 充分运用回文串的特性对称的特性，显然经过reverse后依然维持不变

- 进行拼接，从而将它转换为 KMP common prefix+suffix

这种algorithm仅限于"find the **longest palindrome substring** starts from index 0"



### DP

TODO

### Manacher's algorithm

TODO

## LeetCode

[LeetCode-5. 最长回文子串-中等](https://leetcode.cn/problems/longest-palindromic-substring/) 

[LeetCode-214. 最短回文串-困难](https://leetcode.cn/problems/shortest-palindrome/) 


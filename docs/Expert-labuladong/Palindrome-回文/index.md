# Palindrome-回文

"回文"是非常常见的一种算法题，它能够和各种类型的问题进行结合。

## 素材

### labuladong

| 文章                                                         | 题目                                                         |      |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- |
| labuladong [经典面试题：最长回文子串](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484471&idx=1&sn=7c26d04a1f035770920d31377a1ebd42&chksm=9bd7fa3faca07329189e9e8b51e1a665166946b66b8e8978299ba96d5f2c0d3eafa7db08b681&scene=21#wechat_redirect) | [LeetCode-5. 最长回文子串-中等](https://leetcode.cn/problems/longest-palindromic-substring/) |      |
| labuladong [子序列解题模板：最长回文子序列](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484666&idx=1&sn=e3305be9513eaa16f7f1568c0892a468&chksm=9bd7faf2aca073e4f08332a706b7c10af877fee3993aac4dae86d05783d3d0df31844287104e&scene=21#wechat_redirect) | [LeetCode-516. 最长回文子序列-中等](https://leetcode.cn/problems/longest-palindromic-subsequence/) |      |
| labuladong [如何高效判断回文单链表？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484822&idx=1&sn=44742c9a3557038c8da7150100d94db9&scene=21) |                                                              |      |
| labuladong [构造回文的最小插入次数](https://mp.weixin.qq.com/s/C14WNUpPeBMVSMqh28JdfA) |                                                              |      |
|                                                              |                                                              |      |



## LeetCode

https://leetcode.cn/problemset/all/?search=%E5%9B%9E%E6%96%87



### 回文-string

[LeetCode-面试题 01.04. 回文排列-简单](https://leetcode.cn/problems/palindrome-permutation-lcci/)

通过判断是否字符的个数为2、有一个字符的个数为1，使用"perfect hash-character-as-key-index-array-counter 数组作为字符串字符计数器"



[LeetCode-面试题 01.04. 回文排列##简单代码，简单思路##（100%，89%）](https://leetcode.cn/problems/palindrome-permutation-lcci/solution/mian-shi-ti-0104-hui-wen-pai-lie-jian-da-lxjq/) # 解题思路

主要利用count函数统计出s中所有重复次数为奇数次元素的个数，如果个数为1或0，则该字符串是一个回文串，否则就不是



[LeetCode-336. 回文对-困难](https://leetcode.cn/problems/palindrome-pairs/)





[LeetCode-1147. 段式回文-困难](https://leetcode.cn/problems/longest-chunked-palindrome-decomposition/)



[LeetCode-125. 验证回文串-简单](https://leetcode.cn/problems/valid-palindrome/)



[LeetCode-680. 验证回文字符串 Ⅱ-简单](https://leetcode.cn/problems/valid-palindrome-ii/)

删除一个使之成为回文字符串，我的第一想法是双指针。





[LeetCode-1328. 破坏回文串-中等](https://leetcode.cn/problems/break-a-palindrome/)



[LeetCode-1400. 构造 K 个回文字符串-中等](https://leetcode.cn/problems/construct-k-palindrome-strings/)

[LeetCode-1616. 分割两个字符串得到回文串-中等](https://leetcode.cn/problems/split-two-strings-to-make-palindrome/)

#### 分割回文串

[LeetCode-131. 分割回文串-中等](https://leetcode.cn/problems/palindrome-partitioning/)

[LeetCode-132. 分割回文串 II-困难](https://leetcode.cn/problems/palindrome-partitioning-ii)

[LeetCode-1278. 分割回文串 III-困难](https://leetcode.cn/problems/palindrome-partitioning-iii)

[LeetCode-175. 回文串分割 IV-困难](https://leetcode.cn/problems/palindrome-partitioning-iv)  



#### 寻找回文子串

|                                                              |                                                              |                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------ |
| [LeetCode-5. 最长回文子串-中等](https://leetcode.cn/problems/longest-palindromic-substring/) | 给你一个字符串 `s`，找到 `s` 中最长的回文子串。              | double-pointer-left-right-从中间向两边扩散 |
| [LeetCode-647. 回文子串-中等](https://leetcode.cn/problems/palindromic-substrings/) | 给你一个字符串 `s` ，请你统计并返回这个字符串中 **回文子串** 的数目。 |                                            |
|                                                              |                                                              |                                            |



[LeetCode-1542. 找出最长的超赞子字符串-困难](https://leetcode.cn/problems/find-longest-awesome-substring/)





### 构建回文-string



| LeetCode                                                     | 题目                                                         | 算法   | 来源                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------ | ------------------------------------------------------------ |
| [LeetCode-409. 最长回文串-简单](https://leetcode.cn/problems/longest-palindrome/) | 给定一个包含大写字母和小写字母的字符串 `s` ，返回 *通过这些字母构造成的 **最长的回文串*** 。 | greedy |                                                              |
| [LeetCode-214. 最短回文串-困难](https://leetcode.cn/problems/shortest-palindrome/) | 给定一个字符串 ***s***，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。 | KMP    | labuladong [构造回文的最小插入次数](https://mp.weixin.qq.com/s/C14WNUpPeBMVSMqh28JdfA) |
| [LeetCode-1312. 让字符串成为回文串的最少插入次数-困难](https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/) | 给你一个字符串 `s` ，每一次操作你都可以在字符串的任意位置插入任意字符。请你返回让 `s` 成为回文串的 **最少操作次数** 。 |        |                                                              |



#### 寻找回文子序列

[LeetCode-516. 最长回文子序列-中等](https://leetcode.cn/problems/longest-palindromic-subsequence/)

[LeetCode-730. 统计不同回文子序列-困难](https://leetcode.cn/problems/count-different-palindromic-subsequences/)

[LeetCode-1771. 由子序列构造的最长回文串的长度-困难](https://leetcode.cn/problems/maximize-palindrome-length-from-subsequences/)





### 回文-number



[LeetCode-9. 回文数-简单](https://leetcode.cn/problems/palindrome-number/)

简单的回文判断，用到了一些整数处理的技巧



[LeetCode-866. 回文素数-中等](https: //leetcode.cn/problems/prime-palindrome/)



[LeetCode-906. 超级回文数-困难](https://leetcode.cn/problems/super-palindromes/)



[LeetCode-479. 最大回文数乘积-困难](https://leetcode.cn/problems/largest-palindrome-product/)



[LeetCode-564. 寻找最近的回文数-困难](https://leetcode.cn/problems/find-the-closest-palindrome/)



### 回文-linked-list



[LeetCode-234. 回文链表-简单](https://leetcode.cn/problems/palindrome-linked-list/)

我的第一想法是fast-slow double pointer。

[LeetCode-面试题 02.06. 回文链表-简单](https://leetcode.cn/problems/palindrome-linked-list-lcci/)


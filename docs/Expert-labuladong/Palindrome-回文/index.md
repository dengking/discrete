# 回文

labuladong [经典面试题：最长回文子串](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484471&idx=1&sn=7c26d04a1f035770920d31377a1ebd42&chksm=9bd7fa3faca07329189e9e8b51e1a665166946b66b8e8978299ba96d5f2c0d3eafa7db08b681&scene=21#wechat_redirect)

labuladong [子序列解题模板：最长回文子序列](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484666&idx=1&sn=e3305be9513eaa16f7f1568c0892a468&chksm=9bd7faf2aca073e4f08332a706b7c10af877fee3993aac4dae86d05783d3d0df31844287104e&scene=21#wechat_redirect)

labuladong [如何高效判断回文单链表？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484822&idx=1&sn=44742c9a3557038c8da7150100d94db9&scene=21)

首先，寻找回文串是从中间向两端扩展，判断回文串是从两端向中间收缩。

> NOTE: 
>
> 总结的非常

## LeetCode

https://leetcode-cn.com/problemset/all/?search=%E5%9B%9E%E6%96%87



### 回文串

#### leetcode [面试题 01.04. 回文排列](https://leetcode-cn.com/problems/palindrome-permutation-lcci/) 简单

通过判断是否字符的个数为2、有一个字符的个数为1，使用"perfect hash-character-as-key-index-array-counter 数组作为字符串字符计数器"



leetcode [面试题 01.04. 回文排列##简单代码，简单思路##（100%，89%）](https://leetcode-cn.com/problems/palindrome-permutation-lcci/solution/mian-shi-ti-0104-hui-wen-pai-lie-jian-da-lxjq/) # 解题思路

主要利用count函数统计出s中所有重复次数为奇数次元素的个数，如果个数为1或0，则该字符串是一个回文串，否则就不是



#### leetcode [336. 回文对](https://leetcode-cn.com/problems/palindrome-pairs/) 困难





#### leetcode  [1147. 段式回文](https://leetcode-cn.com/problems/longest-chunked-palindrome-decomposition/) 困难



#### leetcode [125. 验证回文串](https://leetcode-cn.com/problems/valid-palindrome/) 简单



#### leetcode [680. 验证回文字符串 Ⅱ](https://leetcode-cn.com/problems/valid-palindrome-ii/) 简单

删除一个使之成为回文字符串，我的第一想法是双指针。





#### leetcode [1328. 破坏回文串](https://leetcode-cn.com/problems/break-a-palindrome/) 中等



#### leetcode  [1400. 构造 K 个回文字符串](https://leetcode-cn.com/problems/construct-k-palindrome-strings/) 中等

#### leetcode [1616. 分割两个字符串得到回文串](https://leetcode-cn.com/problems/split-two-strings-to-make-palindrome/) 中等

#### 分割回文串

leetcode [131. 分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/) 中等

leetcode [132. 分割回文串 II](https://leetcode-cn.com/problems/palindrome-partitioning-ii) 困难

leetcode [1278. 分割回文串 III](https://leetcode-cn.com/problems/palindrome-partitioning-iii) 困难

leetcode [175. 回文串分割 IV](https://leetcode-cn.com/problems/palindrome-partitioning-iv)  困难



#### 子串

leetcode [647. 回文子串](https://leetcode-cn.com/problems/palindromic-substrings/) 中等

leetcode [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/) 中等

leetcode [1542. 找出最长的超赞子字符串](https://leetcode-cn.com/problems/find-longest-awesome-substring/) 困难



#### 子序列

leetcode [516. 最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/) 中等

leetcode [730. 统计不同回文子序列](https://leetcode-cn.com/problems/count-different-palindromic-subsequences/) 困难

leetcode [1771. 由子序列构造的最长回文串的长度](https://leetcode-cn.com/problems/maximize-palindrome-length-from-subsequences/) 困难

### 回文数



#### leetcode [9. 回文数](https://leetcode-cn.com/problems/palindrome-number/) 简单

简单的回文判断，用到了一些整数处理的技巧



#### leetcode[866. 回文素数](https: //leetcode-cn.com/problems/prime-palindrome/) 中等



#### leetcode [906. 超级回文数](https://leetcode-cn.com/problems/super-palindromes/) 困难



#### leetcode [479. 最大回文数乘积](https://leetcode-cn.com/problems/largest-palindrome-product/) 困难



#### leetcode [564. 寻找最近的回文数](https://leetcode-cn.com/problems/find-the-closest-palindrome/) 困难



### 回文链表

#### leetcode [234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/) 简单

我的第一想法是fast-slow double pointer。

#### leetcode [面试题 02.06. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list-lcci/) 简单


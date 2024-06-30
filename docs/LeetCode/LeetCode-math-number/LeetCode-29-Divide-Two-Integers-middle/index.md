# [LeetCode-29. Divide Two Integers-middle](https://leetcode.cn/problems/divide-two-integers/)

这道题所考察的是binary search、quick multiplication

**乘法**可以使用**快速乘算法**(只使用**加法**)实现

```
quotient = dividend // divisor 
quotient * divisor <= dividend
```

即求解最大的满足上述条件的quotient。


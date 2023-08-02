# n-sum系列

素材:

1、labuladong [一个函数秒杀 2Sum 3Sum 4Sum 问题](https://mp.weixin.qq.com/s/fSyJVvggxHq28a0SdmZm6Q)

2、[CS-Notes/notes/Leetcode 题解 - 双指针.md](https://github.com/CyC2018/CS-Notes/blob/master/notes/Leetcode 题解 - 双指针.md) 



## LeetCode-凑sum问题

分类方式一:

一、n-sum

1、2sum

2、3sum

3、4sum

二、subarray-sum

子数组之和，常用技巧:

1、prefix-sum



三、dp-sum

1、背包dp



分类方式二: 是否有序

1、有序

2、无序



分类方式三: 是否连续



### 有序数组的两数之和



[LeetCode-167. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)

[LeetCode-剑指 Offer 57. 和为s的两个数字](https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/)

[LeetCode-633. 平方数之和](https://leetcode.cn/problems/sum-of-square-numbers/) 

这是典型的 [LeetCode-167. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/) 的升级版，这道题和LeetCode 167本质上相同，使用双指针。它增加了一个难度系数就是: 需要计算数据区间。

```c++
class Solution
{
public:
  bool judgeSquareSum(int c)
  {
    long left = 0, right = sqrt(c);
    while (left <= right) // 允许两个相同数平方和，因此加上等号
    {
      auto sum = left * left + right * right;
      if (sum == c)
      {
        return true;
      }
      else if (sum < c)
      {
        ++left;
      }
      else
      {
        --right;
      }
    }
    return false;
  }
};
```



### hash-map-as-index



[LeetCode-1. 两数之和](https://leetcode.cn/problems/two-sum/) 

[LeetCode-454. 四数相加 II](https://leetcode.cn/problems/4sum-ii/)

[LeetCode-1711. 大餐计数](https://leetcode.cn/problems/count-good-meals/) 



### subarray-sum

subarray-sum意味着是连续的。

[LeetCode-剑指 Offer 57 - II. 和为s的连续正数序列](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) 


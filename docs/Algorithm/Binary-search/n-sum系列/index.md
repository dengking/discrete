# n-sum系列

素材:

1、labuladong [一个函数秒杀 2Sum 3Sum 4Sum 问题](https://mp.weixin.qq.com/s/fSyJVvggxHq28a0SdmZm6Q)

2、[CS-Notes/notes/Leetcode 题解 - 双指针.md](https://github.com/CyC2018/CS-Notes/blob/master/notes/Leetcode 题解 - 双指针.md) 



## LeetCode题目

分类方式一:

1、两数之和

2、三数之和

3、四数之和

4、子数组之和

分类方式二:

是否有序

1、有序

2、无序



### 有序数组的两数之和



#### LeetCode [167. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)



#### LeetCode [633. 平方数之和](https://leetcode.cn/problems/sum-of-square-numbers/)

这是典型的 LeetCode [167. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/) 的升级版，这道题和LeetCode 167本质上相同，使用双指针。它增加了一个难度系数就是: 需要计算数据区间。

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


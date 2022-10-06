# [LeetCode-633. 平方数之和](https://leetcode.cn/problems/sum-of-square-numbers/)



## 我的解题



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


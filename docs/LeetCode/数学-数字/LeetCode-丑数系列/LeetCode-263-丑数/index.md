# [LeetCode-263. 丑数](https://leetcode.cn/problems/ugly-number/)



## 辗转相除法

```c++
class Solution
{
public:
  bool isUgly(int n)
  {
    if (n == 0)
    {
      return false;
    }
    if (n == 1)
    {
      return true;
    }
    auto divisable = [](int &num) -> bool
    {
      if (num % 2 == 0)
      {
        num /= 2;
        return true;
      }
      if (num % 3 == 0)
      {
        num /= 3;
        return true;
      }
      if (num % 5 == 0)
      {
        num /= 5;
        return true;
      }
      return false;
    };
    while (divisable(n))
      ;
    return n == 1;
  }
};
```


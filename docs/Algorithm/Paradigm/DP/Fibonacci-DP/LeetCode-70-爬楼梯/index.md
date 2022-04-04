# LeetCode [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) 简单



## 我的解题

在 github [CS-Notes](https://github.com/CyC2018/CS-Notes)/[notes](https://github.com/CyC2018/CS-Notes/tree/master/notes)/[**Leetcode 题解 - 动态规划.md**](https://github.com/CyC2018/CS-Notes/blob/master/notes/Leetcode%20%E9%A2%98%E8%A7%A3%20-%20%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92.md#%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97) 、emre.me [Coding Patterns: Staircase (DP)](https://emre.me/coding-patterns/staircase/) 中，都提及了这道题，这道题和fibonacci非常类似。



```C++
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <variant>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        int prev = 2, prev_prev = 1, cur = 0;
        for (int i = 3; i <= n; ++i)
        {
            cur = prev + prev_prev;
            prev_prev = prev;
            prev = cur;
        }
        return cur;
    }
};
```


# LeetCode [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs/) 简单



## 我的解题

一、在 github [CS-Notes](https://github.com/CyC2018/CS-Notes)/[notes](https://github.com/CyC2018/CS-Notes/tree/master/notes)/[**Leetcode 题解 - 动态规划.md**](https://github.com/CyC2018/CS-Notes/blob/master/notes/Leetcode%20%E9%A2%98%E8%A7%A3%20-%20%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92.md#%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97) 、emre.me [Coding Patterns: Staircase (DP)](https://emre.me/coding-patterns/staircase/) 中，都提及了这道题，这道题和fibonacci非常类似。

二、如何来思考这道题呢的解法呢？显然，这是一道计数问题，有两种方式来到第n层:

1、从第n-1层走一步

2、从第n-2层走两步

显然，按照加法原理：

```
f(n) = f(n-1) + f(n-2)
```

三、素材

1、icode9 [走楼梯的三种算法(递归，备忘录法，动态规划)](https://www.icode9.com/content-1-1251281.html)

### 完整代码

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


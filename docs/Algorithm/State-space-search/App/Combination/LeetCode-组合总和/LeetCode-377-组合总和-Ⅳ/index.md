# [LeetCode-377. 组合总和 Ⅳ](https://leetcode.cn/problems/combination-sum-iv/)



## 我的理解

是在阅读 [LeetCode-一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现](https://leetcode.cn/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/) 时，发现的这个题目。

上述做法是否考虑到选取元素的顺序？答案是肯定的。因为外层循环的遍历从 `1` 到 $\textit{target}$ 的值，内层循环是遍历数组 $\textit{nums}$ 的值，在计算 $\textit{dp}[i]$ 的值时，$\textit{nums}$ 中的每个小于等于 $i$ 的元素都可能作为元素之和等于 $i$ 的排列的最后一个元素。例如，$1$ 和 $3$ 都在数组 $\textit{nums}$ 中，计算 $\textit{dp}[4]$ 的时候，排列的最后一个元素可以是 $1$ 也可以是 $3$，因此 $\textit{dp}[1]$ 和 $\textit{dp}[3]$ 都会被考虑到，即不同的顺序都会被考虑到。



### 结合具体的例子

```
nums = [1,2,3], target = 4
```



```
target = 1
num = 1
dp[1] = dp[1-1] = dp[0] = 1
```



```
target = 2

num = 1
dp[2] += dp[2-1] = dp[1] = 0 + 1 = 1 # 对应序列1，1

num = 2
dp[2] += dp[2-2] = dp[0] = 1 + 1 = 2 # 对应序列2
```



```
target = 3

num = 1
dp[3] += dp[3-1] = dp[2] = 2 # 对应序列1，1, 1;2,1

num = 2
dp[3] += dp[3-2] = dp[1] = 2 + 1 = 3 # 对应序列2,1

num = 3
dp[3] += dp[3-3] = dp[0] = 3 + 1 = 4 # 对应序列3
```

显然，1，2和2，1分别被计数了一次。



```
target = 4

num = 1
dp[4] += dp[3-1] = dp[2] = 1 # 对应序列1，1

num = 2
dp[4] += dp[3-2] = dp[1] = 1 # 对应序列2

num = 3
dp[4] += dp[3-3] = dp[0] = 1 # 对应序列2
```



```
target = 5

num = 1
dp[5] += dp[3-1] = dp[2] = 1 # 对应序列1，1

num = 2
dp[5] += dp[3-2] = dp[1] = 1 # 对应序列2

num = 3
dp[5] += dp[3-3] = dp[0] = 1 # 对应序列2
```



考虑各种考虑各种coin组合。

### 第一次解题

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>

using namespace std;

class Solution
{
public:
  int combinationSum4(vector<int> &nums, int target)
  {
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; ++i)
    {
      for (auto &&num : nums)
      {
        if (i >= num)
          dp[i] += dp[i - num];
      }
    }
    return dp[target];
  }
};

int main()
{
}
```

上述程序在如下测试用例无法通过：

```
[10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111]
999
```

发生的运行时错误如下：

```c++
Line 9: Char 27: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:18:27
```



这是因为，在dp运行过程中，肯定有一个数非常大，但是最终的结果却并不需要这个数；那如何来改呢？

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>

using namespace std;

class Solution
{
public:
  int combinationSum4(vector<int> &nums, int target)
  {
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
      for (int &num : nums)
      {
        if (num <= i && dp[i - num] < INT_MAX - dp[i])
        {
          dp[i] += dp[i - num];
        }
      }
    }
    return dp[target];
  }
};

int main()
{
}
```


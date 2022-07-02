# leetcode [1155. 掷骰子的N种方法](https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/)

## leetcode [宫水三叶](https://leetcode.cn/u/ac_oier/) # [【动态规划/背包问题】运用分组背包进行求解](https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/solution/dong-tai-gui-hua-bei-bao-wen-ti-yun-yong-axtf/)

> NOTE:
>
> 按照 [宫水三叶](https://leetcode.cn/u/ac_oier/) 的分析，这个题目应该属于分组背包问题。

### 分组背包

在 [分组背包问题](https://leetcode.cn/link/?target=https%3A%2F%2Fmp.weixin.qq.com%2Fs%3F__biz%3DMzU4NDE3MTEyMA%3D%3D%26mid%3D2247487504%26idx%3D1%26sn%3D9ac523ec0ac14c8634a229f8c3f919d7%26chksm%3Dfd9cbb0fcaeb32196b80a40e4408f6a7e2651167e0b9e31aa6d7c6109fbc2117340a59db12a1%26token%3D1936267333%26lang%3Dzh_CN%23rd) 中我们提到，**分组背包**不仅仅有「组内物品最多选择一个」的情况，还存在「组内物品必须选择一个」的情况。

对于本题，可以将每个**骰子**看作一个**物品组**，且每次 **必须** 从物品组中选择一个物品（所掷得的数值大小视作具体物品）。

这样就把问题转换为：**用 d 个骰子（物品组）进行掷，掷出总和（取得的总价值）为 t 的方案数**。

虽然，我们还没专门讲过「背包问题求方案数」，但基本分析与「背包问题求最大价值」并无本质区别。

我们可以套用「分组背包求最大价值」的状态定义来微调：**`f[i][j]` 表示考虑前 `i` 个物品组，凑成价值为 `j` 的方案数**。

为了方便，我们令物品组的编号从 11 开始，因此有显而易见的初始化条件 `f[0][0] = 1`。代表在不考虑任何物品组的情况下，只有凑成总价值为 00 的方案数为 11，凑成其他总价值的方案不存在。

> NOTE:
>
> 这是典型的空问题

**不失一般性考虑 `f[i][j]`该如何转移，也就是考虑第 `i` 个物品组有哪些决策**。

根据题意，对于第 `i` 个物品组而言，可能决策的方案有：

第 i 个骰子的结果为 1，有 `f[i][j] = f[i - 1][j - 1]f[i][j]=f[i−1][j−1]`

第 i 个骰子的结果为 2，有 `f[i][j] = f[i - 1][j - 2]f[i][j]=f[i−1][j−2]`

...

第 i 个骰子的结果为 m，有 `f[i][j] = f[i - 1][j - m]f[i][j]=f[i−1][j−m]`

`f[i][j]` 则是上述所有可能方案的方案数总和，即有：

即有：

$$
f[i][j] = \sum_{k = 1}^{m}f[i - 1][j - k], j >= k
$$

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

static constexpr int MOD = 1000000000 + 7;
class Solution
{
public:
  int numRollsToTarget(int n, int k, int target)
  {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j <= target; ++j)
      {
        for (int l = 1; l <= min(j, k); l++)
        {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
        }
      }
    }
    return dp[n][target];
  }
};

int main()
{
  Solution s;
  cout << s.numRollsToTarget(1, 6, 3) << endl;
  cout << s.numRollsToTarget(2, 6, 7) << endl;
  cout << s.numRollsToTarget(30, 30, 500) << endl;
}
```



## leetcode [MaughamL3](https://leetcode.cn/u/maugahm-4/) # [Java题解 动态规划法](https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/solution/javati-jie-cong-jian-dan-di-gui-dao-ya-s-3jg7/)

### 思路一：简单递归



```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

class Solution
{
public:
  int numRollsToTarget(int n, int k, int target)
  {
    int res = 0;
    std::function<void(int, int)> dfs = [&](int index, int target_sum)
    {
      if (index == n)
      {
        if (target_sum == 0)
          ++res;
      }
      else
      {
        for (int i = 1; i <= k; ++i)
        {
          dfs(index + 1, target_sum - i);
        }
      }
      return;
    };
    dfs(0, target);
    return res;
  }
};

int main()
{
  Solution s;
  cout << s.numRollsToTarget(1, 6, 3) << endl;
  cout << s.numRollsToTarget(2, 6, 7) << endl;
  cout << s.numRollsToTarget(30, 30, 500) << endl;
}
```

> NOTE:
>
> 上述算法其实是非常慢的，最后一条会执行很久才能够得到结果

### 思路二：自顶向下的动态规划






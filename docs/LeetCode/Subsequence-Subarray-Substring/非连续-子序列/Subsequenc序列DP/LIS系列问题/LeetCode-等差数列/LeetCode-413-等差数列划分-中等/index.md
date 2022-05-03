# LeetCode [413. 等差数列划分](https://leetcode-cn.com/problems/arithmetic-slices/) 中等

一、这个问题是典型的存在**重叠子问题**的: 

1、已知一个子数组的公差为`d`，如果一个新的元素与数组的最后一个元素的公差为`d`，那么它们就形成了一个更大的**等差子数组**。

例子是: `[1, 2, 3]` ，当新增一个元素 `4`，显然是可以形成一个更大的**等差子数组**。

2、已知一个子数组的公差为`d`，如果一个新的元素与数组的最后一个元素的公差**不**为`d`，那么它们就**无法**形成了一个更大的**等差子数组**。

例子是: `[1, 2, 3]` ，当新增一个元素 `5`，由于前面三个元素形成的子数组的公差`d`，下一个新的子数组应该是从前面的子数组的最后一个元素开始，即从`3`开始，显然，这是有助于我们缩小问题规模的。



对于存在重叠子问题的，我们在设计算法的时候，需要据此进行优化: 因此，一个直观的写法是: 保存当前的公差`d`。

二、这道题和最大子数组和基本上思想相同。


## 穷举 $O(N^3)$



```C++
// #include <bits/stdc++.h>
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
#include <queue>
#include <deque>
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
  int numberOfArithmeticSlices(vector<int> &nums)
  {
    int count = 0;
    int len = nums.size();
    for (int start = 0; start <= len - 3; ++start) // 起始位置
    {
      for (int end = start + 2; end < len; ++end) // 终止位置
      {
        bool match = true;
        int diff = nums[start] - nums[start + 1];
        for (int i = start + 1; i < end; ++i) // 校验是否合法
        {
          if (nums[i] - nums[i + 1] == diff)
          {
            continue;
          }
          else
          {
            match = false;
            break;
          }
        }
        if (match)
        {
          ++count;
        }
      }
    }
    return count;
  }
};

// Driver code
int main()
{

  Solution solu;
  vector<int> nums = {2, 4, 6, 8, 10};
  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

上述冗余计算在于: 每次都需要重新计算公差。



## 动态规划  $O(N)$

这个解法是参考的leetcode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 的写法的：

```c++
// #include <bits/stdc++.h>
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
#include <queue>
#include <deque>
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
  int numberOfArithmeticSlices(vector<int> &nums)
  {
    // 弱等差数列的个数
    vector<unordered_map<long long, int>> dp(nums.size());
    int res = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
      auto diff = 1LL * nums[i] - nums[i - 1];
      if (dp[i - 1].count(diff))
      {
        auto cnt = dp[i - 1][diff];
        dp[i][diff] += cnt;
        dp[i][diff] += 1;
        res += cnt;
      }
      else
      {
        dp[i][diff] += 1;
      }
    }
    return res;
  }
};

// Driver code
int main()
{

  Solution solu;
  vector<int> nums = {2, 4, 6, 8, 10};
  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## [官方解题](https://leetcode-cn.com/problems/arithmetic-slices/solution/deng-chai-shu-lie-hua-fen-by-leetcode-so-g7os/)

### 方法一: 差分 + 计数-$O(N^2)$

考虑一个比较直观的做法：

1、我们枚举等差数列的最后两项 $\textit{nums}[i - 1]$ 以及 $\textit{nums}[i]$ ，那么等差数列的公差 $d$  即为 $\textit{nums}[i - 1] - \textit{nums}[i]$ ；

2、随后我们使用一个指针 $j$ 从 $i - 2 $开始逆序地遍历数组的前缀部分 $\textit{nums}[0 .. i-2]$：

- 如果 $\textit{nums}[j] - \textit{nums}[j + 1] = d$，那么说明 $\textit{nums}[j], \cdots, \textit{nums}[i]$ 组成了一个长度至少为 $3$ 的等差数列，答案增加 $1$；

- 否则更小的 $j$ 也无法作为等差数列的首个位置了，我们直接退出遍历。

```c++
// #include <bits/stdc++.h>
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
#include <queue>
#include <deque>
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
  int numberOfArithmeticSlices(vector<int> &nums)
  {
    int count = 0;
    int len = nums.size();
    if (len < 3)
    {
      return count;
    }
    for (int i = len - 2; i >= 1; --i)
    {
      int diff = nums[i] - nums[i + 1];
      for (int j = i - 1; j >= 0; --j)
      {
        if (nums[j] - nums[j + 1] == diff)
        {
          ++count;
        }
        else
        {
          break; // "要么连在一起，要么自成一派"
        }
      }
    }
    return count;
  }
};

// Driver code
int main()
{

  Solution solu;
  vector<int> nums = {2, 4, 6, 8, 10};
  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

> NOTE:
>
> "要么连在一起，要么自成一派"



#### 优化: $O(N)$

> NOTE: 
>
> 一、这种思路还是动态规划的思路，需要从"divide-and-conquer-原问题和子问题"的思想来进行思考， $t_i$ 记录的是以第 $i$ 个元素结尾的等差子数组的个数，那如何根据  $t_i$ 推导出 $t_{i+1}$ 呢？其实这个推导过程和 LeetCode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 困难 的推导过程类似。
>
> 二、"要么连在一起，要么自成一派"，这和最大子数组和是类似的，这说明: 子数组的题目，很多都可以基于这个思路来做。这个思路是非常适合于子数组问题的，因为子数组问题要求连续性，显然，一旦与前面相邻的元素无法满足限制条件的时候，那么就可以自成一派，形成以自己打头的子数组，这样说能够降低问题的规模大。
>
> 三、对于子数组的问题，需要追求O(N) 的算法复杂度。
>
> 四、

如果我们已经求出了 $\textit{nums}[i - 1]$​ 以及 $\textit{nums}[i]$​ 作为**等差数列**的最后两项时，答案增加的次数 $t_i$​，那么能否快速地求出 $t_{i+1}$ 呢？

> NOTE:
>
> 需要注意的是：由于题目要求的是子数组，即元素是连续的，所以上面枚举的是  $\textit{nums}[i - 1]$ 以及 $\textit{nums}[i]$ 这两个连续的元素。

答案是可以的：

如果 $\textit{nums}[i] - \textit{nums}[i + 1] = d$，那么在这一轮遍历中，$j$ 会遍历到与上一轮相同的位置，答案增加的次数相同，并且额外多出了 $\textit{nums}[i-1], \textit{nums}[i], \textit{nums}[i+1]$ 这一个等差数列，因此有：

$$
t_{i+1} = t_{i} + 1
$$
如果 $\textit{nums}[i] - \textit{num}[i + 1] \neq d$，那么 $j$ 从初始值 $i-1$ 开始就会直接退出遍历，答案不会增加，因此有：
$$
t_{i+1} = 0
$$
这样一来，我们通过上述简单的递推，即可在 $O(1)$ 的时间计算等差数列数量的增量，总时间复杂度减少至 $O(n)$。




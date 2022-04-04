# leetcode [1155. 掷骰子的N种方法](https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum/)

## leetcode [MaughamL3](https://leetcode-cn.com/u/maugahm-4/) # [Java题解 动态规划法](https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum/solution/javati-jie-cong-jian-dan-di-gui-dao-ya-s-3jg7/)

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


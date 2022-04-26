# leetcode [698. 划分为k个相等的子集](https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/)

## 我的解题

一、是按照 labuladong [回溯算法牛逼！](https://mp.weixin.qq.com/s/fsLKaWBvSWtM0jA-CfOxyA) 中，"以数字的视角" 的方式写的，素材如下：

1、labuladong [集合划分问题：排列组合中的回溯思想（修订版）](https://mp.weixin.qq.com/s/5GO2ZITncVArdm4KITBd9g)

2、labuladong [回溯算法牛逼！](https://mp.weixin.qq.com/s/fsLKaWBvSWtM0jA-CfOxyA) 

二、这是一个典型的存在性问题，因此只要找到一个解即可

三、一般的写法都会超时，看了 labuladong 的解法，其中使用的一个技巧就是先进行**排序**预处理，这样来提高算法的效率。

> 有之前的铺垫，相信这段代码是比较容易理解的。这个解法虽然能够通过，但是耗时比较多，其实我们可以再做一个优化。
>
> 主要看`backtrack`函数的递归部分：
>
> ```java
> for (int i = 0; i < bucket.length; i++) {
>     // 剪枝
>     if (bucket[i] + nums[index] > target) {
>         continue;
>     }
> 
>     if (backtrack(nums, index + 1, bucket, target)) {
>         return true;
>     }
> }
> ```
>
> **如果我们让尽可能多的情况命中剪枝的那个 if 分支，就可以减少递归调用的次数，一定程度上减少时间复杂度**。
>
> 如何尽可能多的命中这个 if 分支呢？要知道我们的`index`参数是从 0 开始递增的，也就是递归地从 0 开始遍历`nums`数组。
>
> 如果我们提前对`nums`数组排序，把大的数字排在前面，那么大的数字会先被分配到`bucket`中，对于之后的数字，`bucket[i] + nums[index]`会更大，更容易触发剪枝的 if 条件。
>
> 所以可以在之前的代码中再添加一些代码：
>
> ```java 
> public boolean canPartitionKSubsets(int[] nums, int k) {
>     // 其他代码不变
>     // ...
>     /* 降序排序 nums 数组 */
>     Arrays.sort(nums);
>     int i = 0, j = nums.length - 1;
>     for (; i < j; i++, j--) {
>         // 交换 nums[i] 和 nums[j]
>         int temp = nums[i];
>         nums[i] = nums[j];
>         nums[j] = temp;
>     }
>     /*******************/
>     return backtrack(nums, 0, bucket, target);
> }
> ```
>
> 由于 Java 的语言特性，这段代码通过先升序排序再反转，达到降序排列的目的。

### 回溯法-超时

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
  bool canPartitionKSubsets(vector<int> &nums, int k)
  {
    if (nums.size() < k) // 无法分为k份
      return false;
    auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) // 无法均匀分配
    {
      return false;
    }
    int target = sum / k;      // 每个桶的目标装载量
    vector<int> buckets(k, 0); // 桶

    return dfs(0, nums, buckets, k, target);
  }
  bool dfs(int index, vector<int> &nums, vector<int> &buckets, int k, int target)
  {
    if (index == nums.size())
    {
      return isOK(buckets, target);
    }
    for (int i = 0; i < k; ++i)
    {
      if (buckets[i] + nums[index] > target) // 剪枝掉
      {
        continue;
      }
      buckets[i] += nums[index]; // 将第index个物品分配到第i个槽子
      if (dfs(index + 1, nums, buckets, k, target))
      {
        return true; // 存在性问题，只要找到一个即可终止
      }
      buckets[i] -= nums[index]; // 回溯、有借有还
    }
    return false;
  }

  bool isOK(vector<int> &nums, int target)
  {
    return std::all_of(nums.begin(), nums.end(), [&](int i)
                       { return i == target; });
  }
};

int main()
{
  Solution s;
  vector<int> nums{4, 3, 2, 3, 5, 2, 1};
  int k = 4;
  s.canPartitionKSubsets(nums, k);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

### 回溯发-先排序预处理-超时

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
  bool canPartitionKSubsets(vector<int> &nums, int k)
  {
    if (nums.size() < k) // 无法分为k份
      return false;
    auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) // 无法均匀分配
    {
      return false;
    }
    int target = sum / k;      // 每个桶的目标装载量
    vector<int> buckets(k, 0); // 桶
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    return dfs(0, nums, buckets, k, target);
  }
  bool dfs(int index, vector<int> &nums, vector<int> &buckets, int k, int target)
  {
    if (index == nums.size())
    {
      return isOK(buckets, target);
    }
    for (int i = 0; i < k; ++i)
    {
      if (buckets[i] + nums[index] > target) // 剪枝掉
      {
        continue;
      }
      buckets[i] += nums[index]; // 将第index个物品分配到第i个槽子
      if (dfs(index + 1, nums, buckets, k, target))
      {
        return true; // 存在性问题，只要找到一个即可终止
      }
      buckets[i] -= nums[index]; // 回溯、有借有还
    }
    return false;
  }

  bool isOK(vector<int> &nums, int target)
  {
    return std::all_of(nums.begin(), nums.end(), [&](int i)
                       { return i == target; });
  }
};

int main()
{
  Solution s;
  vector<int> nums{4, 3, 2, 3, 5, 2, 1};
  int k = 4;
  s.canPartitionKSubsets(nums, k);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```


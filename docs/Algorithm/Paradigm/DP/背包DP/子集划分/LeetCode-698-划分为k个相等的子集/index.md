# [LeetCode-698. 划分为k个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/)

## 我的解题-回溯法

一、是按照 labuladong [回溯算法牛逼！](https://mp.weixin.qq.com/s/fsLKaWBvSWtM0jA-CfOxyA) 中，"以数字的视角" 的方式写的，素材如下：

1、labuladong [集合划分问题：排列组合中的回溯思想（修订版）](https://mp.weixin.qq.com/s/5GO2ZITncVArdm4KITBd9g)

2、labuladong [回溯算法牛逼！](https://mp.weixin.qq.com/s/fsLKaWBvSWtM0jA-CfOxyA) 

二、这是一个典型的存在性问题，因此只要找到一个解即可

三、一般的写法都会超时，看了 labuladong 的解法，其中使用的一个技巧就是先进行**排序**预处理，这样来提高算法的效率。

> NOTE:
>
> 有之前的铺垫，相信这段代码是比较容易理解的。这个解法虽然能够通过，但是耗时比较多，其实我们可以再做一个优化。
>
> 主要看`backtrack`函数的递归部分：
>
> ```java
> for (int i = 0; i < bucket.length; i++) {
>  // 剪枝
>  if (bucket[i] + nums[index] > target) {
>      continue;
>  }
> 
>  if (backtrack(nums, index + 1, bucket, target)) {
>      return true;
>  }
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
>  // 其他代码不变
>  // ...
>  /* 降序排序 nums 数组 */
>  Arrays.sort(nums);
>  int i = 0, j = nums.length - 1;
>  for (; i < j; i++, j--) {
>      // 交换 nums[i] 和 nums[j]
>      int temp = nums[i];
>      nums[i] = nums[j];
>      nums[j] = temp;
>  }
>  /*******************/
>  return backtrack(nums, 0, bucket, target);
> }
> ```
>
> 由于 Java 的语言特性，这段代码通过先升序排序再反转，达到降序排列的目的。

这个做法 [随机过程随机过](https://leetcode.cn/u/sui-ji-guo-cheng-sui-ji-guo/) # [划分为k个相等的子集（Day17）](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/solution/hua-fen-wei-kge-by-sui-ji-guo-cheng-sui-jfaao/) 中有着更好的总结：

> **如果首先将数组降序排序，能够实现更早地剪枝，提高效率**

四、现在按照三中labuladong 的解法依然会超时，如果继续采用回溯法，那么就需要考虑增加**剪枝条件**，看了一下其他人的答案，在 [随机过程随机过](https://leetcode.cn/u/sui-ji-guo-cheng-sui-ji-guo/) # [划分为k个相等的子集（Day17）](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/solution/hua-fen-wei-kge-by-sui-ji-guo-cheng-sui-jfaao/) 中给出了非常好的解答：

> 还有一个关键是剪枝，尤其是 `if (bucket[i] == 0)` 这一个剪枝条件的理解
> 因为不断的把数字放入子集（bucket[i] += nums[index]）中，然后再从子集中拿出来（撤销操作，bucket[i] -= nums[index]）。如果出现把这个桶（子集）中所有的数字都拿出来，即 bucket[i] == 0 的情况，证明这个数循环了一圈都没有找到合适的数去配队凑成 target ，所以后面的都不用在看了，必定凑不成题目说的那种。直接 break 操作。

虽然这种写法能够通过，但是它的原理为觉得是错误的，因为：可能在后续是能够找到合适的。

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

之前，这种解法是可以AC的，但是现在无法AC了。

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

### 回溯法-先排序预处理 + 剪枝

这是看了在 [随机过程随机过](https://leetcode.cn/u/sui-ji-guo-cheng-sui-ji-guo/) # [划分为k个相等的子集（Day17）](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/solution/hua-fen-wei-kge-by-sui-ji-guo-cheng-sui-jfaao/) 中的代码写的：

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
      if (buckets[i] == 0)
      {
        // nums[index] 找不到可以凑成 target 的数
        break;
      }
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





## 回溯法: [LFool](https://leetcode.cn/u/lfool/) # [经典回溯算法：集合划分问题](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/solution/by-lfool-d9o7/)





## [官方解题](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/solution/hua-fen-wei-kge-xiang-deng-de-zi-ji-by-leetcode/)



## [小火柴🥰](https://leetcode.cn/u/smallmatch/) # [集合类状态压缩解法](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/solution/ji-he-lei-zhuang-tai-ya-suo-jie-fa-by-sm-dg7m/)



## [琴棋书画](https://leetcode.cn/u/qin-qi-shu-hua-2/) # [状压dfs](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/solution/zhuang-ya-dfs-by-qin-qi-shu-hua-2-xxfz/)
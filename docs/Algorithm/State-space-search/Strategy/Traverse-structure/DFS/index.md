# DFS 

DFS是一个非常繁杂的主题，涉及到的内容非常多，本文对DFS的内容进行梳理概括。

下面提供了分析DFS算法的几种方式:

1、structure

2、处理节点次序

3、问题类别

## Structure

第一种方式是根据structure来进行划分，需要注意的是，此处的structure包括concrete structure也包括abstract structure。

| 分类                     | 章节              |
| ------------------------ | ----------------- |
| DFS-linked-list          | `DFS-linked-list` |
| DFS-tree                 | `DFS-tree`        |
| DFS-graph                | `DFS-graph`       |
| DFS-state-solution-space |                   |

上述结构从上到下逐步复杂。



## 处理节点次序

| 次序/order |      |      |
| ---------- | ---- | ---- |
| pre-order  |      |      |
| in-order   |      |      |
| post-order |      |      |



## 问题类别

本节根据问题的类别进行讨论:

### DFS解计数问题



### DFS-subset-tree



### DFS-解最优值问题



| 题目                                                         |      |      |
| ------------------------------------------------------------ | ---- | ---- |
| [LeetCode-337-打家劫舍-III-中等](https://leetcode.cn/problems/house-robber-iii/) |      |      |
| [LeetCode-787-K 站中转内最便宜的航班-中等](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) |      |      |
|                                                              |      |      |



## 一些特殊的topic

一、dfs-return-value

二、prunc

三、dfs-last

## DFS生成tree

[LeetCode-386-字典序排数](https://leetcode.cn/problems/lexicographical-numbers/)

剪枝n-ary-tree来生成字典树，对字典树进行pre-order traversal





## n-ary-tree 和 subset-tree

subset-tree其实是一种n-ary-tree。

[LeetCode-698. 划分为k个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/)



### n-ary-tree 和 subset-tree需要保存子集题目汇总

有一些subset-tree的DFS，需要保存子集中的元素，然后进行判断，这种题目，后续，我们统一使用 `std::vector<int> track` 来表示子集，下面是例子:

1、[LeetCode-491. 递增子序列](https://leetcode.cn/problems/increasing-subsequences/) 中等

dfs-last


2、[LeetCode-446. 等差数列划分 II - 子序列](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/) 困难

dfs解计数问题，这道题计数的方式和 [LeetCode-787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/)  中的不同。

dfs-subset-tree

dfs解计数问题

3、菊厂机试的第三道题


4、[LeetCode-698. 划分为k个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/)

这道题是n-ary-tree，它使用bucket将每个子集都保存了下来。




## 回溯法剪枝典型题目

### [LeetCode-698. 划分为k个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/)

dfs解存在性问题，典型写法如下：

```c++

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

```





## 二叉树的最近公共祖先

labuladong [用 Git 来讲讲二叉树最近公共祖先](https://mp.weixin.qq.com/s/9RKzBcr3I592spAsuMH45g) 

dfs-with return

## 执行过程

对于tree的BFS，最终肯定会回到root node。



[LeetCode-491. 递增子序列](https://leetcode.cn/problems/increasing-subsequences/) 中等

dfs-last

## DFS pre-order:

base case

prune 剪枝

## DFS post order

post-action

bottum-up

### 例题:

[LeetCode-剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

labuladong [用 Git 来讲讲二叉树最近公共祖先](https://mp.weixin.qq.com/s/9RKzBcr3I592spAsuMH45g) 

labuladong [美团面试官：你对二叉树后续遍历一无所知](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247490891&idx=1&sn=677a7e887fa551e994ba73bcb2538cea&scene=21#wechat_redirect)

其中使用的技巧和打家劫舍三非常类似。



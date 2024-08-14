# DFS 

DFS是一个非常繁杂的主题，涉及到的内容非常多，本文对DFS的内容进行梳理概括。

下面提供了分析DFS算法的几种方式:

1. structure

2. 处理节点次序

3. 问题类别

## Structure

第一种方式是根据structure来进行划分，需要注意的是，此处的structure指的是discrete structure，它包括了concrete structure(linked list、tree、graph)和virtual abstract structure(state-solution-space)。

| 分类                     | 章节              |
| ------------------------ | ----------------- |
| DFS-linked-list          | `DFS-linked-list` |
| DFS-tree                 | `DFS-tree`        |
| DFS-graph                | `DFS-graph`       |
| DFS-state-solution-space |                   |

上述结构从上到下逐步复杂。

TODO: 需要补充从linked list到tree到graph的traverse的差异，并且补充通用的框架

素材:

wikipedia [Tree traversal](https://en.wikipedia.org/wiki/Tree_traversal) 

wikipedia [Graph traversal](https://en.wikipedia.org/wiki/Graph_traversal) 

wikipedia [Depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) 

## DFS执行过程分析

draft: 对于concrete structure(linked list、tree、graph)的DFS，最终肯定会回到start node。

### DFS-return

可以沿着current path，以bottom-up的方式将返回值逐步传播到起始地方，下面是一些例子:

#### DFS-return-base-case

disjoint-set: root node

TODO: 补充例子，从形状上来看，它所返回的其实是last node

dfs linked list: tail node

TODO: 补充例子



## Vertex orderings / 处理节点次序

由于tree的结构的复杂度处于 linked list 和 graph之间，因此使用它来描述 vertex ordering 是最合适的，其它的类比即可

素材: 

wikipedia [Tree traversal # Depth-first search](https://en.wikipedia.org/wiki/Tree_traversal#Depth-first_search) 

> To traverse binary trees with depth-first search, perform the following operations at each node:[[3\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-3)[[4\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-4)
>
> 1. If the current node is empty then return.
>
> 2. Execute the following three operations in a certain order:
>
>    **N**: Visit the current node.
>
>    **L**: Recursively traverse the current node's left subtree.
>
>    **R**: Recursively traverse the current node's right subtree.

wikipedia [Depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) 

| 次序/order             | tree    | graph |
| ---------------------- | ------- | ----- |
| **Pre-order**          | **NLR** |       |
| **In-order**           | **LNR** | No    |
| **Post-order**         | **LRN** |       |
| **Reverse pre-order**  | **NRL** |       |
| **Reverse post-order** | **RLN** |       |
| **Reverse in-order**   | **RNL** |       |



## DFS pre-order



### Pre-action

pre-action: 在recursively traverse the current node's [children|adjacent nodes] **前**执行的操作，一般包括:

- base case

- prune 剪枝

## DFS post order



### Post-action+return value=produce

post-action: 在recursively traverse the current node's [children|adjacent nodes] **后**执行的操作，一般包括:

- produce bottum-up





### 例题:

[LeetCode-剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

labuladong [用 Git 来讲讲二叉树最近公共祖先](https://mp.weixin.qq.com/s/9RKzBcr3I592spAsuMH45g) 

labuladong [美团面试官：你对二叉树后续遍历一无所知](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247490891&idx=1&sn=677a7e887fa551e994ba73bcb2538cea&scene=21#wechat_redirect)

其中使用的技巧和打家劫舍三非常类似。



## 问题类别

本节根据问题的类别进行讨论:

### DFS解计数问题



### DFS-subset-tree



### DFS-解最优值问题



[LeetCode-337-打家劫舍-III-中等](https://leetcode.cn/problems/house-robber-iii/) 

[LeetCode-787-K 站中转内最便宜的航班-中等](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 





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



[LeetCode-491. 递增子序列](https://leetcode.cn/problems/increasing-subsequences/) 中等




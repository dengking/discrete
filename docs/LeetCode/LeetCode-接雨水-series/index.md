# LeetCode-接雨水

素材: 

- labuladong [手把手搞懂接雨水问题的多种解法](https://mp.weixin.qq.com/s/mFqrlhqYEPhRa9p4ewl3Xw) 



## [LeetCode-11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/) 



### 穷举 $O(N^2)$

search space: upper triangular square matrix(上三角方阵)

```c++

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;

        for (int left = 0; left < height.size(); ++left)
        {
            for (int right = left + 1; right < height.size(); ++right)
            {
                res = max(res, (right - left) * min(height[left], height[right]));
            }
        }
        return res;
    }
};

int main()
{
}

```



### Left right double pointer $O(N)$

我是结合如下两篇文章才完全搞懂这个解法的:

- [Krahets](https://leetcode.cn/u/jyd/) # [11. 盛最多水的容器（双指针，清晰图解）](https://leetcode.cn/problems/container-with-most-water/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/)  

  使用数学化的语言对这个问题进行了较好的描述，但是它对这个算法为什么正确的解释是不够好的

- [nettee](https://leetcode.cn/u/nettee/) # [O(n) 双指针解法：理解正确性、图解原理（C++/Java）](https://leetcode.cn/problems/container-with-most-water/solutions/94102/on-shuang-zhi-zhen-jie-fa-li-jie-zheng-que-xing-tu/) 

  它从搜索空间的角度进行分析，对这个算法为什么正确的解释是比较好的



#### [Krahets](https://leetcode.cn/u/jyd/) # [11. 盛最多水的容器（双指针，清晰图解）](https://leetcode.cn/problems/container-with-most-water/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/) 

由于可容纳水的高度由两板中的 **短板** 决定，因此可得如下 **面积公式** ：
$$
S(i, j) = min(h[i], h[j]) × (j - i)
$$


在每个状态下，无论长板或短板向中间收窄一格，都会导致水槽 **底边宽度** -1 变短：

1、若向内 **移动短板** ，水槽的短板 $min(h[i], h[j])$ 可能变大，因此下个水槽的面积 **可能增大** 。

2、若向内 **移动长板** ，水槽的短板 $min(h[i], h[j])$ 不变或变小，因此下个水槽的面积 **一定变小** 。

> NOTE:
>
> 一、由于可容纳水的高度由两板中的 **短板** 决定，因此就可以得到上述结论
>
> 二、上述是approximation



#### [nettee](https://leetcode.cn/u/nettee/) # [O(n) 双指针解法：理解正确性、图解原理（C++/Java）](https://leetcode.cn/problems/container-with-most-water/solutions/94102/on-shuang-zhi-zhen-jie-fa-li-jie-zheng-que-xing-tu/) 

这道题目看似简单，做起来才发现不容易。分治法、动态规划都用不上，要想得到 O(n) 的解法只有使用**双指针**一条路。即使看了答案知道了双指针解法，你也可能并不清楚这个解法为什么正确。为什么双指针往中间移动时，不会漏掉某些情况呢？

要理解这道题的正确性和原理，需要从背后的 **缩减搜索空间** 的思想去考虑题解。

用一句话概括双指针解法的要点：**指针每一次移动，都意味着排除掉了一个柱子**。

##### 图解双指针解法的原理

下面我们用更直观的方法来看看`“排除掉一根柱子”、“指针移动”`究竟代表着什么。

在这道题中，假设一共有 $n$ 根柱子，编号 $0, 1, \dots, n-1$，高度分别为 $H_0,H_1,\dots,H_{n−1}$。我们要寻找的是两根柱子 $i,j$，它们需要满足的约束条件是：

- i、j 都是合法的柱子下标，即 $0 \le i < n$, $0 \le j < n$
- i 在 j 的左边，即 $i<j$

而我们希望从中找到容纳水面积最大的柱子 $(i,j)$。以 $n=8$ 为例，这时候全部的搜索空间是：

> NOTE:
>
> 白色空间就是解空间

![search-space](https://pic.leetcode-cn.com/bbca2fea8e093fef61ecfe822e2668646a24f8bbc7a7a8f10eb0428ead6b1893.jpg)

由于 i、j 的**约束条件**的限制，搜索空间是**白色的倒三角部分**。可以看到，搜索空间的大小是 $O(n^2)$ 数量级的。如果用**暴力解法**求解，一次只检查一个单元格，那么时间复杂度一定是 $O(n^2)$。要想得到 $O(n)$ 的解法，我们就需要能够一次排除多个单元格。那么我们来看看，本题的双指针解法是如何削减搜索空间的：

一开始，我们检查右上方单元格 $(0, 7)$，即考虑最左边的 **0 号柱子**和最右边的 **7 号柱子**，计算它们之间容纳水的面积。然后我们比较一下两根柱子的高度，关注其中较短的一根。

![check-0-7](https://pic.leetcode-cn.com/6237e665691939c321d2e0362b46af86c65a26f2da358ee441a96a4928270597.jpg)

假设左边的 **0 号柱子**较短。根据刚才的推理，**0 号柱子**目前的水面高度已经到了上限。由于 **7 号柱子**已经是离 **0 号柱子**最远的了，水的宽度也最大，如果换其他的柱子和 0 号柱子配对，水的宽度只会更小，高度也不会增加，容纳水的面积只会更小。也就是说，**0 号柱子**和 $6, 5, \dots, 1$ 号柱子的配对都可以排除掉了。记录了 $(0, 7)$ 这组柱子的结果之后，就可以排除 **0 号柱子**了。这相当于 i=0 的情况全部被排除。对应于双指针解法的代码，就是 $i++$；对应于搜索空间，就是削减了一行的搜索空间，如下图所示。

![remove-i-0](https://pic.leetcode-cn.com/6196f179edd049fd38dcbc2a6301c055d83f253863777d7e76d5061fe35abab0.jpg)

排除掉了**搜索空间**中的一行之后，我们再看剩余的搜索空间，仍然是倒三角形状。我们检查右上方的单元格 $(1, 7)$，即考虑 **1 号柱子**和 **7 号柱子**，计算它们之间容纳水的面积。然后，比较两根柱子的高度。

![check-1-7](https://pic.leetcode-cn.com/ca441e528ec9ece8f38f7c213633e3d871da8e8c3083740ce06723c97329c02f.jpg)

假设此时 7 号柱子较短。同理， 7 号柱子已经是离 1 号柱子最远的了，如果换其他的柱子和 1 号柱子配对，水的宽度变小，高度也不会增加，容纳水的面积只会更小。也就是说，7 号柱子和 $2, 3, \dots, 6$ 号柱子的配对都可以排除掉了。记录了 $(1, 7)$ 这组柱子的结果之后，就可以排除 7 号柱子了。这相当于 $j=7$ 的情况全部被排除。对应于双指针解法的代码，就是 `j--`；对应于搜索空间，就是削减了一列的搜索空间，如下图所示。

可以看到，无论柱子 `i` 和 `j` 哪根更长，我们都可以排除掉一行或者一列的搜索空间。经过 n 步以后，就能排除所有的搜索空间，检查完所有的可能性。搜索空间的减小过程如下面动图所示：



#### C++

```C++

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;

        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            res = max(res, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return res;
    }
};

int main()
{
}

```

## 从搜索空间的角度来分析O(n) 的双指针解法

[LeetCode-11. 盛最多水的容器-Medium](https://leetcode.cn/problems/container-with-most-water/) 

[LeetCode-167. Two Sum II - Input array is sorted-Medium](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)

[LeetCode-240. Search a 2D Matrix II-Medium](https://leetcode.cn/problems/search-a-2d-matrix-ii/) 

相同点:

- 它们的解空间都是 upper triangular square matrix(上三角方阵)

[nettee](https://leetcode.cn/u/nettee/) [一张图告诉你 O(n) 的双指针解法的本质原理（C++/Java）](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solutions/87919/yi-zhang-tu-gao-su-ni-on-de-shuang-zhi-zhen-jie-fa/)





## [LeetCode-42. 接雨水](https://leetcode.cn/problems/trapping-rain-water/)



### C++



是按照 [详解一道高频面试题：接雨水](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=5&sn=8a69b2ca4d48e8b4db2b153a405c6e52&scene=21#wechat_redirect) 中的解法写的

写法一: 

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
  int trap(vector<int> &height)
  {

    int lmax = height.front(), rmax = height.back();
    int left = 1, right = height.size() - 2;

    int res = 0;

    while (left <= right)
    {
      if (lmax < rmax)
      {
        res += max(lmax - height[left], 0);
        lmax = max(lmax, height[left]);

        ++left;
      }
      else
      {
        res += max(rmax - height[right], 0);
        rmax = max(rmax, height[right]);
        --right;
      }
    }
    return res;
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



写法二:

```c++
class Solution
{
public:
  int trap(vector<int> &height)
  {
    if (height.empty())
      return 0;
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;

    int l_max = height[0];
    int r_max = height[n - 1];

    while (left <= right)
    {
      l_max = max(l_max, height[left]);
      r_max = max(r_max, height[right]);

      // res += min(l_max, r_max) - height[i]
      if (l_max < r_max)
      {
        res += l_max - height[left];
        left++;
      }
      else
      {
        res += r_max - height[right];
        right--;
      }
    }
    return res;
  }
};

```


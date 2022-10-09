# [LeetCode-剑指 Offer 57 - II. 和为s的连续正数序列](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) 

输入一个正整数 `target` ，输出所有和为 `target` 的连续正整数序列（至少含有两个数）。



## 我的解题



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
  vector<vector<int>> findContinuousSequence(int target)
  {
    vector<vector<int>> res;
    for (int i = 1; i < target; ++i)
    {
      int sum = 0;
      int start = i;
      vector<int> v;
      while (sum < target)
      {
        sum += start;
        v.push_back(start);
        start++;
      }
      if (sum == target && v.size() > 1)
      {
        res.push_back(move(v));
      }
    }
    return res;
  }
};

int main()
{
}
```



## [官方解题](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/mian-shi-ti-57-ii-he-wei-sde-lian-xu-zheng-shu-x-2/) 

### 方法一：枚举 + 暴力

```c++
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        int sum = 0, limit = (target - 1) / 2; // (target - 1) / 2 等效于 target / 2 下取整
        for (int i = 1; i <= limit; ++i) {
            for (int j = i;; ++j) {
                sum += j;
                if (sum > target) {
                    sum = 0;
                    break;
                } else if (sum == target) {
                    res.clear();
                    for (int k = i; k <= j; ++k) {
                        res.emplace_back(k);
                    }
                    vec.emplace_back(res);
                    sum = 0;
                    break;
                }
            }
        }
        return vec;
    }
};

```



### [方法三：双指针(滑动窗口)](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/mian-shi-ti-57-ii-he-wei-sde-lian-xu-zheng-shu-x-2/) 



我们用两个指针 $l$ 和 $r$ 表示当前枚举到的以 $l$ 为起点到 $r$ 的区间，$\textit{sum}$ 表示 $[l,r]$ 的区间和，由求和公式可 $O(1)$ 求得为 $\textit{sum}=\frac{(l+r) \times (r-l+1)}{2}$，起始 $l=1,r=2$。

一共有三种情况：

1、如果 $\textit{sum}<\textit{target}$ 则说明指针 $r$ 还可以向右拓展使得 $sum$ 增大，此时指针 $r$ 向右移动，即 $r+=1$

2、如果 $sum>target$ 则说明以 $l$ 为起点不存在一个 $r$ 使得 $sum=target$ ，此时要枚举下一个起点，指针 $l$ 向右移动，即$l+=1$

3、如果 $\textit{sum}==\textit{target}$ 则说明我们找到了以 $l$ 为起点得合法解 $[l,r]$ ，我们需要将 $[l,r]$ 的序列放进答案数组，且我们知道以 $l$ 为起点的合法解最多只有一个，所以需要枚举下一个起点，指针 $l$ 向右移动，即 $l+=1$



此方法其实是对方法一的优化，因为方法一是没有考虑区间与区间的信息可以复用，只是单纯的枚举起点，然后从起点开始累加，而该方法就是考虑到了如果已知 $[l,r]$ 的区间和等于 $\textit{target}$ ，那么枚举下一个起点的时候，区间 $[l+1,r]$ 的和必然小于 $\textit{target}$，我们就不需要再从 $l+1$ 再开始重复枚举，而是从 $r+1$ 开始枚举，充分的利用了已知的信息来优化时间复杂度。

终止条件即为 $l>=r$ 的时候，这种情况的发生指针 $r$ 移动到了$\lfloor\frac{\textit{target}}{2}\rfloor+1$的位置，导致 $l<r$ 的时候区间和始终大于 $target$ 。

>  NOTE:
>
> 一、上述解法显然是sliding-window+binary-search。
>
> 二、对于上述解法，我的一个疑问是**for循环**的循环条件，我有如下疑问:
>
> 1、为什么这样写？
>
> 由于题目要求至少两个元素，并且它的区间规则是左闭右闭，因此它需要$l<r$，因为这样能够保证区间中至少有两个元素。
>
> 2、这样写正确吗？它能否保证循环最终能够停止下来？
>
> 
>
> 由于题目要求序列长度至少大于 $2$，枚举的上界为 $\lfloor\frac{\textit{target}}{2}\rfloor$。

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
  vector<vector<int>> findContinuousSequence(int target)
  {
    vector<vector<int>> res;
    vector<int> v;
    for (int l = 1, r = 2; l < r;)
    {
      int sum = (l + r) * (r - l + 1) / 2;
      if (sum == target)
      {
        v.clear();
        for (int i = l; i <= r; ++i)
        {
          v.push_back(i);
        }
        res.push_back(v);
        ++l; // 此处千万不要忘记
      }
      else if (sum < target)
      {
        ++r;
      }
      else // sum > target
      {
        ++l;
      }
    }
    return res;
  }
};

int main()
{
}
```




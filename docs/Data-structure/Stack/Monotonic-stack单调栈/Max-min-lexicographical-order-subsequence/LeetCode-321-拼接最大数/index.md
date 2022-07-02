# leetcode [321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number/) 困难

现在从这两个数组中选出 `k (k <= m + n)` 个数字拼接成一个新的数。

> NOTE:
>
> `k (k <= m + n)` 这个条件比较重要

## [官方解题](https://leetcode.cn/problems/create-maximum-number/solution/pin-jie-zui-da-shu-by-leetcode-solution/)



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
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
  {
    int m = nums1.size(), n = nums2.size();
    vector<int> maxSubsequence(k, 0);
    // start 和 end表示从第一个array nums1中选取的元素的个数的范围
    // 由于题目的前提条件是: k <= m + n，因此两个数组中的元素是必然能够凑足k个的
    // start的值如何来决定呢？需要注意的是：它的最小值不是1，由于我们最终要凑够k个元素，因此它的最小值就是将nums2中的元素全部选中，然后此时最少要从nums1中选择几个元素
    int start = max(0, k - n), end = min(k, m); 
    for (int i = start; i <= end; i++)
    {
      vector<int> subsequence1(MaxSubsequence(nums1, i));
      vector<int> subsequence2(MaxSubsequence(nums2, k - i));
      vector<int> curMaxSubsequence(merge(subsequence1, subsequence2));
      if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0)
      {
        maxSubsequence.swap(curMaxSubsequence);
      }
    }
    return maxSubsequence;
  }

  vector<int> MaxSubsequence(vector<int> &nums, int k)
  {
    int length = nums.size();
    vector<int> stack(k, 0);
    int top = -1;
    int remain = length - k;
    for (int i = 0; i < length; i++)
    {
      int num = nums[i];
      while (top >= 0 && stack[top] < num && remain > 0)
      {
        top--;
        remain--;
      }
      if (top < k - 1)
      {
        stack[++top] = num;
      }
      else
      {
        remain--;
      }
    }
    return stack;
  }

  vector<int> merge(vector<int> &subsequence1, vector<int> &subsequence2)
  {
    int x = subsequence1.size(), y = subsequence2.size();
    if (x == 0)
    {
      return subsequence2;
    }
    if (y == 0)
    {
      return subsequence1;
    }
    int mergeLength = x + y;
    vector<int> merged(mergeLength);
    int index1 = 0, index2 = 0;
    for (int i = 0; i < mergeLength; i++)
    {
      if (compare(subsequence1, index1, subsequence2, index2) > 0)
      {
        merged[i] = subsequence1[index1++];
      }
      else
      {
        merged[i] = subsequence2[index2++];
      }
    }
    return merged;
  }

  int compare(vector<int> &subsequence1, int index1, vector<int> &subsequence2, int index2)
  {
    int x = subsequence1.size(), y = subsequence2.size();
    while (index1 < x && index2 < y)
    {
      int difference = subsequence1[index1] - subsequence2[index2];
      if (difference != 0)
      {
        return difference;
      }
      index1++;
      index2++;
    }
    return (x - index1) - (y - index2);
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

​	

## [力扣加加](https://leetcode.cn/u/fe-lucifer/) # [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode.cn/problems/create-maximum-number/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-7/) 

> NOTE: 
>
> 一、这个解题是非常好的，它是"divide-and-conquer-and-merge"非常经典的例题，它的base就是 leetcode [402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/) 
>
> 

和第一道题类似，只不不过这一次是两个**数组**，而不是一个，并且是求最大数。

最大最小是无关紧要的，关键在于是两个数组，并且要求从两个数组选取的元素个数加起来一共是 k。

然而在一个数组中取 k 个数字，并保持其最小（或者最大），我们已经会了。但是如果问题扩展到两个，会有什么变化呢？

实际上，问题本质并没有发生变化。假设我们从 nums1 中取了 k1 个，从 num2 中取了 k2 个，其中 k1 + k2 = k。而 k1 和 k2 这 两个子问题我们是会解决的。由于这两个子问题是相互独立的，因此我们只需要分别求解，然后将结果合并即可。

假如 k1 和 k2 个数字，已经取出来了。那么剩下要做的就是将这个长度分别为 k1 和 k2 的数字，合并成一个长度为 k 的数组合并成一个最大的数组。

以题目的 `nums1 = [3, 4, 6, 5] nums2 = [9, 1, 2, 5, 8, 3] k = 5` 为例。以题目的 `nums1 = [3, 4, 6, 5] nums2 = [9, 1, 2, 5, 8, 3] k = 5` 为例。

运用第一题的方法，我们计算出应该取 `nums1` 的 `[6]`，并取 `nums2` 的 `[9,5,8,3]`。如何将 `[6]` 和 `[9,5,8,3]`，使得数字尽可能大，并且保持相对位置不变呢？

实际上这个过程有点类似`归并排序`中的**治**，而上面我们分别计算 num1 和 num2 的最大数的过程类似`归并排序`中的**分**。

![img](https://pic.leetcode.cn/276105e4f130a04413b466232b0a79537902b2d6e8bf016f2c84e6ff8e3af3de.jpg)

代码：

> 我们将从 num1 中挑选的 k1 个数组成的数组称之为 A，将从 num2 中挑选的 k2 个数组成的数组称之为 B，

```python
def merge(A, B):
    ans = []
    while A or B:
        bigger = A if A > B else B
        ans.append(bigger[0])
        bigger.pop(0)
    return ans


```

> NOTE:
>
> 上述算法其实非常简单，其实就是first-second双指针

这里需要说明一下。 在很多编程语言中：**如果 A 和 B 是两个数组，当前仅当 A 的首个元素字典序大于 B 的首个元素，A > B 返回 true，否则返回 false**。

以合并 [6] 和 [9,5,8,3] 为例，图解过程如下：

![img](https://pic.leetcode.cn/dcae5d6f7feb6e8adb14ad15292f052771d6dfdf1e682d6e657f69b6a404479e.jpg)

### 具体算法：

### 完整code



```c++
class Solution:
    def maxNumber(self, nums1, nums2, k):

        def pick_max(nums, k):
            stack = []
            drop = len(nums) - k
            for num in nums:
                while drop and stack and stack[-1] < num:
                    stack.pop()
                    drop -= 1
                stack.append(num)
            return stack[:k]

        def merge(A, B):
            ans = []
            while A or B:
                bigger = A if A > B else B
                ans.append(bigger.pop(0))
            return ans

        return max(merge(pick_max(nums1, i), pick_max(nums2, k-i)) for i in range(k+1) if i <= len(nums1) and k-i <= len(nums2))

```

> NOTE:
>
> 一、通过上述code可以看出，它是典型的divide-and-conqure-merge+打擂台取最优值，它的base是 leetcode [402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/) 。
>
> 二、它的merge算法：每次从字典序更大的array中取出一个元素。





## 我的解题-存在bug

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
  /**
   * @brief 按照递减的顺序将nums1和nums2进行合并
   *
   * @param nums1
   * @param nums2
   * @return vector<int>
   */
  vector<int> merge(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> res;
    int first = 0, second = 0;
    while (first < nums1.size() && second < nums2.size())
    {
      if (nums1[first] > nums2[second])
      {
        res.push_back(nums1[first]);
        ++first;
      }
      else
      {
        res.push_back(nums2[second]);
        ++second;
      }
    }
    while (first < nums1.size())
    {
      res.push_back(nums1[first]);
      ++first;
    }
    while (second < nums2.size())
    {
      res.push_back(nums2[second]);
      ++second;
    }
    return res;
  }
  /**
   * @brief 选择长度为k的数字，它的字典许要尽可能地大
   *
   * @param nums1
   * @param k
   * @return vector<int>
   */
  vector<int> select(vector<int> &nums, int k)
  {
    vector<int> mono_stack;
    int max_delete_cnt = nums.size() - k;
    if (max_delete_cnt <= 0) // 不需要删除元素
    {
      return nums;
    }
    for (auto &&num : nums)
    {
      while (!mono_stack.empty() && num > mono_stack.back() && max_delete_cnt > 0)
      {
        max_delete_cnt--;
        mono_stack.pop_back();
      }
      mono_stack.push_back(num);
    }
    for (; max_delete_cnt > 0; --max_delete_cnt)
    {
      mono_stack.pop_back();
    }
    return mono_stack;
  }

public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
  {
    vector<int> res;
    for (int m = 1; m <= nums1.size(); ++m)
    {
      for (int n = k - m; n <= nums2.size(); ++n)
      {
        if (m > 0 && n > 0)
        {
          auto first = select(nums1, m);
          auto second = select(nums2, n);
          auto third = merge(first, second);
          res = max(res, third);
        }
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums{5, 1, 1};
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



上述算法的bug在merge函数中，下面是例子：

```
输入
[6,7]
[6,0,4]
5
输出
[6,6,7,0,4]
预期结果
[6,7,6,0,4]
```

我的merge函数是按照merge sort的写法写的，通过上述例子可以看出，它是不符合这道题的要求的，那以什么样的算法来实现呢？在 [力扣加加](https://leetcode.cn/u/fe-lucifer/) # [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode.cn/problems/create-maximum-number/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-7/) 中，给出了算法：

```c++s
class Solution:
    def maxNumber(self, nums1, nums2, k):

        def pick_max(nums, k):
            stack = []
            drop = len(nums) - k
            for num in nums:
                while drop and stack and stack[-1] < num:
                    stack.pop()
                    drop -= 1
                stack.append(num)
            return stack[:k]

        def merge(A, B):
            ans = []
            while A or B:
                bigger = A if A > B else B
                ans.append(bigger.pop(0))
            return ans

        return max(merge(pick_max(nums1, i), pick_max(nums2, k-i)) for i in range(k+1) if i <= len(nums1) and k-i <= len(nums2))


```



## 我的解题

一、一开始想仿照[力扣加加](https://leetcode.cn/u/fe-lucifer/) # [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode.cn/problems/create-maximum-number/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-7/) 中merge函数的写法

```c++
  vector<int> merge(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> res;
    vector<int> *bigger = nullptr;
    while (!nums1.empty() || !nums2.empty())
    {
      if (nums1 > nums2)
      {
        bigger = &nums1;
      }
      else
      {
        bigger = &nums2;
      }
      bigger->pop_front();
    }
    return res;
  }
```

但是C++中，`std::vector`不支持`pop_front`。所以上述写法是无效的，因此还是需要像 [官方解题](https://leetcode.cn/problems/create-maximum-number/solution/pin-jie-zui-da-shu-by-leetcode-solution/) 中的实现一个`compare` 函数。





```c++

class Solution
{
  /**
   * @brief 按照递减的顺序将nums1和nums2进行合并
   *
   * @param nums1
   * @param nums2
   * @return vector<int>
   */
  vector<int> merge(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> res;
    res.reserve(nums1.size() + nums2.size());
    int first = 0, second = 0;
    while (first < nums1.size() || second < nums2.size())
    {
      if (compare(nums1, first, nums2, second) > 0)
      {
        res.push_back(nums1[first]);
        ++first;
      }
      else
      {
        res.push_back(nums2[second]);
        ++second;
      }
    }
    return res;
  }
  /// 这是为了支持merge函数而添加的
  int compare(vector<int> &nums1, int index1, vector<int> &nums2, int index2)
  {
    int first = index1, second = index2;
    while (first < nums1.size() && second < nums2.size())
    {
      int diff = nums1[first] - nums2[second];
      if (diff != 0)
      {
        return diff;
      }
      ++first;
      ++second;
    }
    return (nums1.size() - index1) - (nums2.size() - index2);
  }
  /**
   * @brief 选择长度为k的数字，它的字典许要尽可能地大
   *
   * @param nums1
   * @param k
   * @return vector<int>
   */
  vector<int> select(vector<int> &nums, int k)
  {
    vector<int> mono_stack;
    int max_delete_cnt = nums.size() - k;
    if (max_delete_cnt <= 0) // 不需要删除元素
    {
      return nums;
    }
    for (auto &&num : nums)
    {
      while (!mono_stack.empty() && num > mono_stack.back() && max_delete_cnt > 0)
      {
        max_delete_cnt--;
        mono_stack.pop_back();
      }
      mono_stack.push_back(num);
    }
    for (; max_delete_cnt > 0; --max_delete_cnt)
    {
      mono_stack.pop_back();
    }
    return mono_stack;
  }

public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
  {
    vector<int> res;
    int m = nums1.size(), n = nums2.size();
    int start = max(0, k - n), end = min(k, m);
    for (int i = start; i <= end; ++i)
    {
      auto first = select(nums1, i);
      auto second = select(nums2, k - i);
      auto merged = merge(first, second);
      if (res < merged)
      {
        res.swap(merged);
      }
    }
    return res;
  }
};

```


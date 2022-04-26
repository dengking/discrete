# leetcode [321. 拼接最大数](https://leetcode-cn.com/problems/create-maximum-number/)

## [力扣加加](https://leetcode-cn.com/u/fe-lucifer/) # [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode-cn.com/problems/create-maximum-number/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-7/)

> NOTE: 
>
> 一、这个解题是非常好的，它是"divide-and-conquer-and-merge"非常经典的例题，它的base就是 leetcode [402. 移掉K位数字](https://leetcode-cn.com/problems/remove-k-digits/) 
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

![img](https://pic.leetcode-cn.com/276105e4f130a04413b466232b0a79537902b2d6e8bf016f2c84e6ff8e3af3de.jpg)

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

![img](https://pic.leetcode-cn.com/dcae5d6f7feb6e8adb14ad15292f052771d6dfdf1e682d6e657f69b6a404479e.jpg)

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
> 通过上述code可以看出，它是典型的divide-and-conqure-merge+打擂台取最优值，它的base是 leetcode [402. 移掉K位数字](https://leetcode-cn.com/problems/remove-k-digits/) 。

## 我的解答

```C++
#include <bits/stdc++.h>
using namespace std;

using index_t = size_t;
class Solution
{
public:
	/**
	 * @brief 从 nums 中挑出k个最大的，并保持相对位置不变
	 *
	 * @param nums
	 * @return
	 */
	vector<int> pickMax(vector<int> &nums, size_t k)
	{
		vector<int> ret;
		size_t len = nums.size();
		size_t delete_count = len - k;

		for (auto &&num : nums)
		{
			while (ret.size() > 0 && delete_count > 0 && ret.back() < num)
			{
				ret.pop_back();
				--delete_count;
			}
			ret.push_back(num);
		}
		for (; delete_count > 0; --delete_count)
		{
			ret.pop_back();
		}
		return ret;

	}
	vector<int> merge(const vector<int> &nums1, const vector<int> &nums2)
	{
		vector<int> ret;
		index_t i1 = 0, i2 = 0;
		while (i1 < nums1.size() && i2 < nums2.size())
		{
			if (nums1[i1] > nums2[i2])
			{
				ret.push_back(nums1[i1]);
				++i1;
			}
			else
			{
				ret.push_back(nums2[i2]);
				++i2;
			}
		}
		while (i1++ < nums1.size())
		{
			ret.push_back(nums1[i1]);
		}
		while (i2++ < nums2.size())
		{
			ret.push_back(nums2[i2]);
		}
		return ret;
	}
	friend bool operator>(const vector<int> &nums1, const vector<int> &nums2)
	{
		if (nums1.size() == nums2.size())
		{
			for (index_t i = 0; i < nums1.size(); ++i)
			{
				if (nums1[i] > nums2[i])
				{
					return true;
				}
			}
			return false;
		}
		else if (nums1.size() > nums2.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, size_t k)
	{
		vector<int> max;
		for (index_t i = 0; i < k; ++i)
		{
			if (i <= nums1.size() && k - i <= nums2.size())
			{
				auto temp = merge(pickMax(nums1, i), pickMax(nums2, k - i));
				if (max < temp)
				{
					max = temp;
				}
			}
		}
		return max;
	}
};
ostream& operator<<(ostream &s, vector<int> v)
{
	for (auto &&i : v)
	{
		s << i;
	}
	return s;
}

// Driven Program
int main()
{
	Solution s;
	vector<int> nums1 = { 3, 4, 6, 5 };
	vector<int> nums2 = { 9, 1, 2, 5, 8, 3 };
	size_t k = 5;
	cout << s.maxNumber(nums1, nums2, k) << endl;

	nums1 = { 6, 7 };
	nums2 = { 6, 0, 4 };
	k = 5;
	cout << s.maxNumber(nums1, nums2, k) << endl;

	nums1 = { 3, 9 };
	nums2 = { 8, 9 };
	k = 3;
	cout << s.maxNumber(nums1, nums2, k) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## 二刷

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
    if (max_delete_cnt == 0)
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


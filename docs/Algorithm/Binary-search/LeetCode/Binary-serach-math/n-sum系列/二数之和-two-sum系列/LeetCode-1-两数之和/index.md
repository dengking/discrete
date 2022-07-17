# LeetCode [1. 两数之和](https://leetcode.cn/problems/two-sum/)



## 我的解题

### 暴力搜索

```C++
/* Program to implement a stack
 using two queue */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		size_t len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					return {i, j};
				}
			}
		}
		return {-1, -1};
	}
};
ostream& operator<<(ostream &stream, vector<int> v)
{
	for (auto &&i : v)
		stream << i;
	return stream;
}
// Driver code
int main()
{

	Solution s;
	vector<int> nums { 2, 7, 11, 15 };
	cout << s.twoSum(nums, 9) << endl;

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

也能够AC。



### hash table

典型的以空间换时间。

```C++
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i)
    {
      auto it = hashtable.find(target - nums[i]);
      if (it != hashtable.end())
      {
        return {it->second, i};
      }
      hashtable[nums[i]] = i;
    }
    return {};
  }
};

ostream &operator<<(ostream &stream, vector<int> v)
{
  for (auto &&i : v)
    stream << i;
  return stream;
}
// Driver code
int main()
{

  Solution s;
  vector<int> nums{2, 7, 11, 15};
  cout << s.twoSum(nums, 9) << endl;

  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



它的实现是有一点技巧的:

1、上述使用了hash table，那么就需要考虑重复的元素，比如像 `nums = [3,3], target = 6` 这样的用例，并且题目要求:

> You may assume that each input would have exactly one solution, and you may not use the same element twice.
>
> 来源：力扣（LeetCode）
> 链接：https://leetcode.cn/problems/two-sum
> 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

通过上述程序可以看出，它并没有按照 labuladong [Two Sum 问题的核心思想](https://mp.weixin.qq.com/s/3CMQaY1mO1Iqt4j30bUVcA) 中的作为，提前index，而是在`for`中，对于已经access过的element才添加到hash map中

另外题目要求是two sum，即只会涉及两个数，因此，如果第一次已经access了一个，第二次再次遇到相同值的时候，也能够取到第一次的元素的准确位置。

上述这种策略，对于更多的数，貌似是行不通的。

2、方法一是从后面的数中找数，方法二是: 一次遍历，从过往的数据中，找数。


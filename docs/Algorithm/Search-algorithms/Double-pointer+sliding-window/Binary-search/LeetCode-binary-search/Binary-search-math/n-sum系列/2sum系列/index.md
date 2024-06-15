# 二数之和-two-sum系列

## [LeetCode-1. 两数之和](https://leetcode.cn/problems/two-sum/)



这个题考察了hash map、multiple hash map，nums中是可以出现重复元素，但是题目明确要求"you may not use the same element twice"，所以需要考虑在map中找到自己、与自己相同的元素的情况，所以可以看到在循环体中有对两个数是否相同的判断，如果相同，则需要进行特殊处理。

### 解法1: 暴力搜索

这种做法可以概括为: 从后面的数中找目标数。

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



### 解法2: 先hash index，然后loop: `std::unordered_map<int, std::vector<int>>` 

### C++

使用 `std::unordered_map<int, std::vector<int>>` 来处理相同值。

```c++
#include <unordered_map>
#include <iostream>
#include <format>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, std::vector<int>> nums_map;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            if (nums_map.count(num))
            {
                nums_map[num].push_back(i);
            }
            else
            {
                std::vector<int> indexes{i};
                nums_map[num] = indexes;
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            int num2 = target - num;
            if (nums_map.count(num2))
            {
                std::vector<int> &indexes = nums_map[num2];
                if (num == num2)
                {
                    if (indexes.size() >= 2)
                    {
                        return {i, indexes[1]};
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    return {i, indexes[0]};
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution s;
    std::vector<int> nums{3, 2, 4};
    s.twoSum(nums, 6);
    int debug = 0;
}
```

### Python

```python
from typing import *


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num2index: Dict[int, List] = {}
        for index in range(0, len(nums)):
            num = nums[index]
            if num not in num2index:
                num2index[num] = []
            num2index[num].append(index)

        for index in range(0, len(nums)):
            num1 = nums[index]
            num2 = target - num1
            if num2 not in num2index:
                continue
            if num1 == num2:
                if len(num2index[num1]) == 1:
                    continue
                else:
                    return [index, num2index[num2][1]]
            else:
                return [index, num2index[num2][0]]

```



### 解法3: 解法2: 先hash index，然后loop: `std::unordered_multimap<int, int>`

```c++
#include <unordered_map>
#include <iostream>
#include <format>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_multimap<int, int> nums_map;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            nums_map.insert({num, i});
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            int num2 = target - num;
            if (nums_map.count(num2))
            {
                auto indexes = nums_map.equal_range(num2);
                if (num == num2)
                {
                    if (std::distance(indexes.first, indexes.second) >= 2)
                    {
                        for (auto it = indexes.first; it != indexes.second; it++)
                        {
                            if (it->second != i)
                            {
                                return {i, it->second};
                            }
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    return {i, indexes.first->second};
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution s;
    std::vector<int> nums{3, 2, 4};
    s.twoSum(nums, 6);
    int debug = 0;
}
```



### 解法4: loop内进行hash index

#### C++

典型的以空间换时间。

```C++
#include <unordered_map>
#include <iostream>
#include <format>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> nums_index;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = nums_index.find(target - nums[i]);
            if (it != nums_index.end())
            {
                return {it->second, i};
            }
            nums_index[nums[i]] = i;
        }
        return {};
    }
};

std::ostream &operator<<(std::ostream &stream, std::vector<int> v)
{
    for (auto &&i : v)
        stream << i;
    return stream;
}
// Driver code
int main()
{

    Solution s;
    std::vector<int> nums{2, 7, 11, 15};
    cout << s.twoSum(nums, 9) << endl;

    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

int main()
{
    Solution s;
    std::vector<int> nums{3, 2, 4};
    s.twoSum(nums, 6);
    int debug = 0;
}
```



这种做法可以概括为: 一次遍历，从过往的数据中，找数： 

1、上述使用了hash table，那么就需要考虑重复的元素，比如像 `nums = [3,3], target = 6` 这样的用例，并且题目要求:

> You may assume that each input would have exactly one solution, and you may not use the same element twice.
>
> 来源：力扣（LeetCode）
> 链接：https://leetcode.cn/problems/two-sum
> 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



> ```
> Input: nums = [3,3], target = 6
> Output: [0,1]
> ```



通过上述程序可以看出，它并没有按照 labuladong [Two Sum 问题的核心思想](https://mp.weixin.qq.com/s/3CMQaY1mO1Iqt4j30bUVcA) 中的做法，提前index，而是在`for`中，对于已经access过的element才添加到hash map中，另外题目要求是two sum，即只会涉及两个数，因此，如果第一次已经access了一个，第二次再次遇到相同值的时候，也能够取到第一次的元素的准确位置。

上述这种策略，对于更多的数，貌似是行不通的。



#### Python

```python
from typing import *


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num2index: Dict[int, int] = {}
        for index in range(0, len(nums)):
            num = nums[index]
            num1 = target - num
            if num1 in num2index:
                return [index, num2index[num1]]
            num2index[num] = index
        return []

```



## [LeetCode-167. Two Sum II - Input array is sorted](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)



## [LeetCode-170. 两数之和 III - 数据结构设计](https://leetcode.cn/problems/two-sum-iii-data-structure-design/)


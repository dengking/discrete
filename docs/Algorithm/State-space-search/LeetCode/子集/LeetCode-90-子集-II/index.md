# leetcode [90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)

需要理解题意，题目中的"解集 **不能** 包含重复的子集"不是指"子集"中，不包含重复元素，而是指不能包含重复的子集，比如: `nums = [1,2,2]`

子集 `[1, 2]`，中的`2`可以取自第2个、第3个。

子集 `[2]`，可以取自第2个、第三个。

上述两种都是重复子集。



## [官方解题](https://leetcode-cn.com/problems/subsets-ii/solution/zi-ji-ii-by-leetcode-solution-7inq/)

### 方法一：迭代法实现子集枚举

> 一、将重复元素看做是同一个元素
>
> 对于有两个重复元素的
>
> 11、00 
>
> 10、01 所有取一个元素的，都是重复的，只能够取一个
>
> 对于有三个重复元素的
>
> 111、000
>
> 100、010、001 所有取一个元素的，都是重复的，三者之中，只能怪取一个
>
> 011、101、110 所有取两个元素的，都是重复的，三者之中，只能怪取一个
>
> 对于有四个重复元素的
>
> 1111、0000
>
> 1000、0100、0010、0001 所有取一个元素的，都是重复的，四个之中，只能怪取一个
>
> ......
>
> 显然，对于n个重复元素，取n个、取0个，都是不会产生重复的，其他情况都会产生重复；
>
> 在这些可能产生重复的情况中，需要约定一个规则，只取其中的一个: 
>
> **所有`01`模式的，都要drop调**
>
> 可以看到，一旦运用了上述drop规则，则所有可能的重复情况中，都只有`10`模式的会被选择，其他的情况，都会包含`01`，都会被drop调。

我们可以通过判断这种情况，来避免生成重复的子集。代码实现时，可以先将数组排序；迭代时，若发现没有选择上一个数，且当前数字与上一个数相同，则可以跳过当前生成的子集。



```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 作者：LeetCode-Solution
 链接：https://leetcode-cn.com/problems/subsets-ii/solution/zi-ji-ii-by-leetcode-solution-7inq/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */
class Solution
{
public:
	vector<int> t;
	vector<vector<int>> ans;

	vector<vector<int>> subsetsWithDup(vector<int> &nums)
	{
		sort(nums.begin(), nums.end()); // 必须要先排序，将重复的元素放到一起
		int n = nums.size();
		for (int mask = 0; mask < (1 << n); ++mask)
		{
			t.clear();
			bool flag = true;
			for (int i = 0; i < n; ++i)
			{
				if (mask & (1 << i))
				{
					/**
					 * `mask >> (i - 1)` 表示的是右移动 i-1 位
					 * `mask >> (i - 1) & 1` 表示的是取第 i-1 为的bit值
					 */
					if (i > 0 && (mask >> (i - 1) & 1) == 0 && nums[i] == nums[i - 1]) // 出现了 `01` 模式，则需要drop掉
					{
						flag = false;
						break;
					}
					t.push_back(nums[i]);
				}
			}
			if (flag)
			{
				ans.push_back(t);
			}
		}
		return ans;
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, const vector<Args...> &v)
{
	stream << "[";
	for (auto &&i : v)
	{
		stream << i << ",";
	}
	stream << "]";
	return stream;
}
int main()
{
	vector<int> nums { 1, 2, 2 };

	Solution s;
	vector<vector<int>> subsets = s.subsetsWithDup(nums);
	cout << subsets.size() << endl;
	cout << subsets << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

输出如下:

```C++
6
[[],[1,],[2,],[1,2,],[2,2,],[1,2,2,],]
```

### 方法二：递归法实现子集枚举



```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 作者：LeetCode-Solution
 链接：https://leetcode-cn.com/problems/subsets-ii/solution/zi-ji-ii-by-leetcode-solution-7inq/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */
class Solution
{
public:
	vector<int> t;
	vector<vector<int>> ans;

	void dfs(bool choosePre, int cur, vector<int> &nums)
	{
		if (cur == nums.size())
		{
			ans.push_back(t);
			return;
		}
		/**
		 * 不选择 `nums[cur]`
		 */
		dfs(false, cur + 1, nums);

		/**
		 * 选择`nums[cur]`；但是在选择之前，需要需要首先判断`01`模式，如果是`01`模式，则需要drop调
		 *
		 */
		if (!choosePre && cur > 0 && nums[cur - 1] == nums[cur])
		{
			return;
		}
		t.push_back(nums[cur]);
		dfs(true, cur + 1, nums);
		t.pop_back();
	}

	vector<vector<int>> subsetsWithDup(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		dfs(false, 0, nums);
		return ans;
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, const vector<Args...> &v)
{
	stream << "[";
	for (auto &&i : v)
	{
		stream << i << ",";
	}
	stream << "]";
	return stream;
}
int main()
{
	vector<int> nums { 1, 2, 2 };

	Solution s;
	vector<vector<int>> subsets = s.subsetsWithDup(nums);
	cout << subsets.size() << endl;
	cout << subsets << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 作者：LeetCode-Solution
 链接：https://leetcode-cn.com/problems/subsets-ii/solution/zi-ji-ii-by-leetcode-solution-7inq/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */
class Solution
{
public:
	vector<int> t;
	vector<vector<int>> ans;

	vector<vector<int>> subsetsWithDup(vector<int> &nums)
	{
		sort(nums.begin(), nums.end()); // 必须要先排序，让重复的、值相等的元素集中到连续的位置
		int len = nums.size();
		for (int mask = 0; mask < (1 << len); ++mask)
		{
			t.clear();
			bool drop_flag = false; // 是否将当前的combination给丢掉
			// 开始往t中添加数据
			for (int i = 0; i < len; ++i)
			{
				if (mask & (1 << i)) // 如果mask的第i为的bit值为1，表示对应的元素被选中了
				{
					if (i > 0 && nums[i] == nums[i - 1] && (mask & (1 << (i - 1))) == 0)
					{
						drop_flag = true; // 需要将当前的combination给丢掉
						break;
					}
					t.push_back(nums[i]);
				}
			}
			if (!drop_flag)
			{
				ans.push_back(t);
			}
		}
		return ans;
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, const vector<Args...> &v)
{
	stream << "[";
	for (auto &&i : v)
	{
		stream << i << ",";
	}
	stream << "]";
	return stream;
}
int main()
{
	vector<int> nums { 1, 2, 2 };

	Solution s;
	vector<vector<int>> subsets = s.subsetsWithDup(nums);
	cout << subsets.size() << endl;
	cout << subsets << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```


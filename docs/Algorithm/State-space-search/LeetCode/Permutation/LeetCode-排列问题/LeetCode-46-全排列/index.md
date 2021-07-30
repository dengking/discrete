# leetcode [46. 全排列](https://leetcode-cn.com/problems/permutations/)



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{

	vector<vector<int>> res;
public:
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<int> track;
		dfs(nums, 0);
		return res;
	}
	/**
	 * @brief
	 *
	 * @param nums
	 * @param i
	 * @param track
	 */
	void dfs(vector<int> &nums, int k)
	{
		if (k == nums.size())
		{
			res.push_back(nums);
			return;
		}
		else
		{
			for (int i = k; i < nums.size(); ++i)
			{
				swap(nums[k], nums[i]);
				dfs(nums, k + 1);
				swap(nums[i], nums[k]);
			}
		}
	}

};
int main()
{
	Solution solu;
}

```



## labuladong 的解法

下面是在上labuladong [回溯算法详解](https://mp.weixin.qq.com/s/nMUHqvwzG2LmWA9jMIHwQQ)、labuladong [回溯算法团灭排列/组合/子集问题](https://mp.weixin.qq.com/s/qT6WgR6Qwn7ayZkI3AineA) 中，给出的解法: 



```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{

	vector<vector<int>> res;
public:
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<int> track;
		dfs(nums, track);
		return res;
	}
	/**
	 * @brief
	 *
	 * @param nums
	 * @param i
	 * @param track
	 */
	void dfs(vector<int> &nums, vector<int> &track)
	{
		if (track.size() == nums.size())
		{
			res.push_back(track);
			return;
		}
		else
		{
			for (int i = 0; i < nums.size(); ++i)
			{
				/**
				 * 剪枝
				 */
				if (contain(track, nums[i]))
				{
					continue;
				}
				track.push_back(nums[i]);
				dfs(nums, track);
				track.pop_back();
			}
		}
	}
	bool contain(vector<int> &track, int target)
	{
		for (auto &&n : track)
		{
			if (n == target)
			{
				return true;
			}
		}
		return false;
	}
};
int main()
{
	Solution solu;
}

```


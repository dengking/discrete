# LeetCode [1337. 矩阵中战斗力最弱的 K 行](https://leetcode-cn.com/problems/the-k-weakest-rows-in-a-matrix/) 简单



## 我的解题



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	struct Status
	{
		int row { 0 };
		int count { 0 };
		bool operator<(const Status &r) const
		{
			if (count != r.count)
			{
				return count < r.count;
			}
			else
			{
				return row < r.row;
			}

		}
	};
public:
	vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
	{
		priority_queue<Status> q; // max heap
		int len = mat.size();
		for (int i = 0; i < len; ++i)
		{
			Status s;
			s.row = i;
			for (auto &&c : mat[i])
			{
				if (c == 1)
				{
					++s.count;
				}
				else
				{
					break;
				}
			}
			q.push(s);
			if (q.size() > k)
			{
				q.pop(); // 淘汰掉大的元素，剩下的就是小的
			}
		}
		vector<int> res;
		while (!q.empty())
		{
			res.push_back(q.top().row);
			q.pop();
		}
		reverse(res.begin(), res.end()); // 必须要reverse，因为题目要求是从小到大
		return res;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

需要注意的是，题目最终的要求是从小到大排列，所以需要 `reverse(res.begin(), res.end());`

## 官方解题



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
	{
		int m = mat.size(), n = mat[0].size();
		vector<pair<int, int>> power;
		for (int i = 0; i < m; ++i)
		{
			int l = 0, r = n - 1, pos = -1;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (mat[i][mid] == 0)
				{
					r = mid - 1;
				}
				else
				{
					pos = mid;
					l = mid + 1;
				}
			}
			power.emplace_back(pos + 1, i);
		}

		priority_queue q(greater<pair<int, int>>(), move(power));
		vector<int> ans;
		for (int i = 0; i < k; ++i)
		{
			ans.push_back(q.top().second);
			q.pop();
		}
		return ans;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```


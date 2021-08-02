# LeetCode [743. 网络延迟时间](https://leetcode-cn.com/problems/network-delay-time/) 中等



## 第一次解题 BFS

这个题目其实是要求解从源点出发到达所有的其它节点的距离，显然是可以通过遍历的方式来实现的，我们可以采用BFS。

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int networkDelayTime(vector<vector<int>> &times, int n, int k)
	{
		int maxDelayTime = -1; // 最大的网络延时
		vector<bool> visited(n, false);
		// pair<int, int> 节点编号、源节点到该节点的延时
		queue<pair<int, int>> q; // 队列
		q.push( { k, 0 });
		visited[n] = true;
		while (!q.empty())
		{
			pair<int, int> curr_node = q.front();
			q.pop();
			for (auto &&edge : times)
			{
				if (edge[0] == curr_node.first && !visited[edge[1]]) // 表示源点是v
				{
					pair<int, int> next_node { edge[1], curr_node.second + edge[2] };
					q.push(next_node); // 将目标节点放到queue中
					maxDelayTime = max(maxDelayTime, next_node.second);
				}
			}
		}
		return maxDelayTime;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

结果测试，在下面的用例中，无法通过:

```C++
输入：
[[1,2,1],[2,3,2],[1,3,2]]
3
1
输出：
3
预期结果：
2
```

后来看标准答案，方知道应该采用dijkstra算法；



### LeetCode [C++ BFS](https://leetcode-cn.com/problems/network-delay-time/solution/c-bfs-by-qiank-rv2f/)



## 第二次解题

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int networkDelayTime(vector<vector<int>> &times, int n, int k)
	{
		static constexpr int INF = INT_MAX / 2;
		vector<vector<int>> graph(n, vector<int>(n, INF));
		for (auto &&edge : times)
		{
			int src = edge[0], dest = edge[1], weight = edge[2];
			graph[src - 1][dest - 1] = weight;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // 最大堆
		vector<bool> used(n, false); // 是否已经找到了节点的最短距离
		vector<int> distances(n, INF); // 从src到各节点的距离
		q.emplace(0, k - 1);
		distances[k - 1] = 0;
		while (!q.empty())
		{
			int curr = q.top().second;
			q.pop();
			used[curr] = true;
			for (int i = 0; i < n; ++i)
			{
				int weight = graph[curr][i];
				if (!used[i])
				{
					int dist = distances[curr] + weight;
					if (dist < distances[i])
					{
						q.emplace(dist, i);
						distances[i] = dist;
					}
				}
			}
		}
		int delayTime = *max_element(distances.begin(), distances.end());
		return delayTime == INF ? -1 : delayTime;
	}
};

int main()
{
	vector<vector<int>> times { { 2, 1, 1 }, { 2, 3, 1 }, { 3, 4, 1 } };
	int n = 4;
	int k = 2;
	Solution s;
	cout << s.networkDelayTime(times, n, k) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



## [官方解题](https://leetcode-cn.com/problems/network-delay-time/solution/wang-luo-yan-chi-shi-jian-by-leetcode-so-6phc/)、使用dijkstra算法



### 不使用 `priority_queue`



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int networkDelayTime(vector<vector<int>> &times, int n, int k)
	{
		const int inf = INT_MAX / 2;
		vector<vector<int>> g(n, vector<int>(n, inf)); // graph
		for (auto &t : times)
		{
			int x = t[0] - 1, y = t[1] - 1;
			g[x][y] = t[2];
		}

		vector<int> dist(n, inf);
		dist[k - 1] = 0;
		vector<int> used(n);
		for (int i = 0; i < n; ++i)
		{
			int x = -1;
			for (int y = 0; y < n; ++y) // 选择出最短距离
			{
				if (!used[y] && (x == -1 || dist[y] < dist[x]))
				{
					x = y;
				}
			}
			used[x] = true;
			for (int y = 0; y < n; ++y)
			{
				dist[y] = min(dist[y], dist[x] + g[x][y]);
			}
		}

		int ans = *max_element(dist.begin(), dist.end());
		return ans == inf ? -1 : ans;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



### 使用`priority_queue`



```c++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int networkDelayTime(vector<vector<int>> &times, int n, int k)
	{
		const int inf = INT_MAX / 2;
		vector<vector<pair<int, int>>> g(n);
		for (auto &t : times)
		{
			int x = t[0] - 1, y = t[1] - 1;
			g[x].emplace_back(y, t[2]);
		}

		vector<int> dist(n, inf);
		dist[k - 1] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
		q.emplace(0, k - 1);
		while (!q.empty())
		{
			auto p = q.top();
			q.pop();
			int time = p.first, x = p.second;
			if (dist[x] < time)
			{
				continue;
			}
			for (auto &e : g[x])
			{
				int y = e.first, d = dist[x] + e.second;
				if (d < dist[y])
				{
					dist[y] = d;
					q.emplace(d, y);
				}
			}
		}

		int ans = *max_element(dist.begin(), dist.end());
		return ans == inf ? -1 : ans;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```


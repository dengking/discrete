# LeetCode [743. 网络延迟时间](https://leetcode-cn.com/problems/network-delay-time/) 中等

这个题目有一个特别需要注意的地方：

> 有 `n` 个网络节点，标记为 `1` 到 `n`

它的标记是从1开始的，而不是从0开始的，因此需要进行一次转换。

对于节点标记是从0-N的这种问题，adjacent list有两种选择：

1、`unordered_map<int, vector<vector<int> > > graph;`

2、`vector<vector<int>> g(n, vector<int>(n, inf)); // graph`

显然相比之下，第二种方式是更好的。

## 我的解题

这是参考的 [官方解题](https://leetcode-cn.com/problems/network-delay-time/solution/wang-luo-yan-chi-shi-jian-by-leetcode-so-6phc/) 写的：

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



## [官方解题](https://leetcode-cn.com/problems/network-delay-time/solution/wang-luo-yan-chi-shi-jian-by-leetcode-so-6phc/) 使用dijkstra算法

根据题意，从节点 `k` 发出的信号，到达节点 `x` 的时间就是节点 `k` 到节点 `x` 的最短路的长度。因此我们需要求出节点 `k` 到其余所有点的最短路，其中的最大值就是答案。若存在从 `k` 出发无法到达的点，则返回 -1。

### 不使用 `priority_queue`

> NOTE: 
>
> 下面的这种写法不好，不建议采用



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int networkDelayTime(vector<vector<int>> &times, int n, int k)
	{
		const int inf = INT_MAX / 2;
		vector<vector<int>> g(n, vector<int>(n, inf)); // graph，这种表示方式记录的是从source到所有的n个节点的距离，它可以通过inf开判定两个节点之间是否可达
		for (auto &t : times)
		{
			int x = t[0] - 1, y = t[1] - 1; // 需要注意标号到下标的转换
			g[x][y] = t[2]; // 从节点x到节点y的距离为t[2]
		}

		vector<int> dist(n, inf);
		dist[k - 1] = 0; // 需要注意标号到下标的转换
		vector<int> used(n); // 这是visited array
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

> NOTE:
>
> 这种写法较好，建议采用

```c++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int networkDelayTime(vector<vector<int>> &times, int n, int k)
	{
		const int inf = INT_MAX / 2;
		vector<vector<pair<int, int>>> g(n); // 在graph中，pair.fist 是节点index， pair.second是当前节点的parent到它的weight
		for (auto &t : times)
		{
			int x = t[0] - 1, y = t[1] - 1; // 需要注意标号到下标的转换
			g[x].emplace_back(y, t[2]);
		}

		vector<int> dist(n, inf);
		dist[k - 1] = 0; // 需要注意标号到下标的转换
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q; // 这是min heap
		q.emplace(0, k - 1); // 在priority_queue中，pair.first 是当前节点的parent到它的weight，pair.second 是节点index
		while (!q.empty())
		{
			auto p = q.top(); // q是当前节点
			q.pop();
			int time = p.first, x = p.second;
			if (dist[x] < time)
			{
				continue;
			}
			for (auto &e : g[x]) // 对于所有的临接节点
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

## [XingHe](https://leetcode-cn.com/u/QRhqcDD90G/) # [c++/python3/java （1）朴素dijkstra算法 （2）最小堆+visited+dijkstra算法](https://leetcode-cn.com/problems/network-delay-time/solution/cpython3java-1po-su-dijkstrasuan-fa-2zui-ks36/)

### （二）最小堆+visited+dijkstra算法

```c++
class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        //---------------------最小堆+visited+朴素dijkstra算法 -----------------------//
        int INF = 1e9;
        unordered_map<int, vector<pair<int, int>>> adjvex;
        for (auto v : times)
        {
            int x = v[0],  y = v[1],  cost = v[2];
            x --;
            y --;
            adjvex[x].push_back({y, cost});
        }

        int start = k - 1;
        vector<int> dist(n, INF);
        vector<bool> visited(n, false);
        dist[start] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minHeap;
        minHeap.push({0, start});
        while (!minHeap.empty())
        {
            auto [d, x] = minHeap.top();
            minHeap.pop();
            if (visited[x] == true)
                continue;
            visited[x] = true;
            for (auto [y, cost] : adjvex[x])
            {
                if (dist[x] + cost < dist[y])
                {
                    dist[y] = dist[x] + cost;
                    minHeap.push({dist[y], y});
                }
            }
        }

        //---- 最后一个到达的，是求max
        int res = *max_element(dist.begin(), dist.end());  
        return (res != INF ? res : -1);

    }   
};

```


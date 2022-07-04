# [LeetCode-743. 网络延迟时间-中等](https://leetcode.cn/problems/network-delay-time/) 

这个题目有一个特别需要注意的地方：

> 有 `n` 个网络节点，标记为 `1` 到 `n`

它的标记是从1开始的，而不是从0开始的，因此需要进行一次转换。

对于节点标记是从0-N的这种问题，adjacent list有两种选择：

1、`unordered_map<int, vector<vector<int> > > graph;`

2、`vector<vector<int>> g(n, vector<int>(n, inf)); // graph`

显然相比之下，第二种方式是更好的。





## [官方解题](https://leetcode.cn/problems/network-delay-time/solution/wang-luo-yan-chi-shi-jian-by-leetcode-so-6phc/) 使用dijkstra算法

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
		vector<vector<pair<int, int>>> g(n); // 在graph中，pair.fist 是节点index， pair.second是parent到它的weight
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

## [XingHe](https://leetcode.cn/u/QRhqcDD90G/) # [c++/python3/java （1）朴素dijkstra算法 （2）最小堆+visited+dijkstra算法](https://leetcode.cn/problems/network-delay-time/solution/cpython3java-1po-su-dijkstrasuan-fa-2zui-ks36/)

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



## 我的解题

这是参考的

1、 [官方解题](https://leetcode.cn/problems/network-delay-time/solution/wang-luo-yan-chi-shi-jian-by-leetcode-so-6phc/) 

参考了它的graph表示方式；

2、[XingHe](https://leetcode.cn/u/QRhqcDD90G/) # [c++/python3/java （1）朴素dijkstra算法 （2）最小堆+visited+dijkstra算法](https://leetcode.cn/problems/network-delay-time/solution/cpython3java-1po-su-dijkstrasuan-fa-2zui-ks36/) #（二）最小堆+visited+dijkstra算法

参考了它的visited array；

写的，比较符合我的审美的一个程序:

```C++
#include <iostream>
#include <vector>
#include <queue>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <set>
#include <map>
#include <climits> // INT_MAX
using namespace std;

class Solution
{
public:
  int networkDelayTime(vector<vector<int> > &times, int n, int k)
  {
    vector<vector<pair<int, int> > > graph(n); // 在graph中，pair.fist 是节点index， pair.second是parent到它的weight
    for (auto &&edge : times)
    {
      int src_i = edge[0] - 1, dest_i = edge[1] - 1; // 需要注意标号到下标的转换
      int weight = edge[2];
      graph[src_i].emplace_back(dest_i, weight);
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q; // 最小堆
                                                                                          // 在priority_queue中，pair.first 是parent到它的weight，pair.second 是节点index
    vector<bool> visited(n, false);                                                       // 是否已经找到了节点的最短距离
    vector<int> distances(n, INT_MAX);                                                    // 从src到各节点的距离
    int start_i = k - 1;
    q.emplace(0, start_i); // 将source放入到queue中
    distances[start_i] = 0;
    while (!q.empty())
    {
      auto src_node = q.top();
      int src_i = src_node.second;
      q.pop();
      if (visited[src_i])
      {
        continue;
      }
      visited[src_i] = true;
      for (auto &&dest_node : graph[src_i]) // 访问所有的邻接节点
      {
        int dest_i = dest_node.first;
        int weight = dest_node.second;
        int dist = distances[src_i] + weight; // 从当前节点到该节点

        if (dist < distances[dest_i])
        {
          q.push({dist, dest_i}); // 使用dis进行排序
          distances[dest_i] = dist;
        }
      }
    }
    int delayTime = *max_element(distances.begin(), distances.end());
    return delayTime == INT_MAX ? -1 : delayTime;
  }
};

int main()
{
  Solution s;
}

```


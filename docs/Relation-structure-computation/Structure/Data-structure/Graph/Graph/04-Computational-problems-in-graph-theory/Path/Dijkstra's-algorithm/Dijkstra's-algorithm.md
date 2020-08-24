# Dijkstra's algorithm



## 计算机算法设计与分析

按照在`Relation-structure-computation\Structure\Data-structure\Graph\Search-algorithm\Methods\Summary\Search-Algorithm.md`中描述的算法框架来分析Dijkstra's algorithm。

集合S为**CLOSED**集，在该算法中，并没有显式地维护**OPEN集**。

对于Dijkstra's algorithm，它的“strategies for selecting which node to expand next”是采用的greedy策略，即每次选择最小的distance。

dijkstra的算法思想：

- greedy
- dynamic programming



```c++
#define  maxint 9999
/**
 * 单源最短路径的Dijkstra算法
 * 步骤:
 * 1. 初始化
 * 2. 贪心选择
 * 3. 更新
 * @param n 顶点的个数
 * @param v 源点的index
 * @param dist 源点到各节点的距离
 * @param prev 前驱节点
 * @param c 图中节点之间的距离
 */
template<typename Type>
void Dijkstra(int n, int v, Type dist[], int prev[], Type** c)
{
	bool s[maxint]; // CLOSED，当源点到节点的距离已知的时候，就将该节点加入到这个集合中
	// 1. 初始化
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = c[v][i]; // 源点到节点的距离
		s[i] = false;
		// 与源点不相邻的节点
		if (dist[i] == maxint)
		{
			prev[i] = 0;
		}
		// 与源点的相邻节点
		else
		{
			prev[i] = v;
		}

	}
	dist[v] = 0;
	s[v] = true; // 将源点加入到CLOSED中

	for (int i = 10; i < n; ++i)
	{
		// 2. 贪心选择
		// 选择dist中的最小值
		int temp = maxint;
		int u = v;
		for (int j = 1; i <= n; j++)
		{
			if ((!s[j]) && (dist[j] < temp))
			{
				u = j;
				temp = dist[j];
			}
		}
		s[u] = true; // 将u加入到CLOSED中
		// 3. 更新
		// 使用u来进行更新
		for (int j = 1; j <= n; ++j)
		{
			if ((!s[j]) && (c[u][j] < maxint))
			{
				Type newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
}

int main()
{

}

```







## 维基百科[Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm)

The algorithm exists in many variants. Dijkstra's original algorithm found the shortest path between two given nodes,[[5\]](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#cite_note-Dijkstra1959-5) but a more common variant fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree).

> NOTE: single source

The Dijkstra algorithm uses labels that are positive integers or real numbers, which are [totally ordered](https://en.wikipedia.org/wiki/Total_order). It can be generalized to use any labels that are [partially ordered](https://en.wikipedia.org/wiki/Partially_ordered_set), provided the subsequent labels (a subsequent label is produced when traversing an edge) are [monotonically](https://en.wikipedia.org/wiki/Monotonic_function) non-decreasing. This generalization is called the generic Dijkstra shortest-path algorithm.[[7\]](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#cite_note-Generic_Dijkstra-7)

> NOTE: label的含义是什么？


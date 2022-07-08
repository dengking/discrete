# Graph representation



## wikipedia [Graph (abstract data type)#Representations](https://en.wikipedia.org/wiki/Graph_(abstract_data_type)) 

| 表示方式                                                     | example                                                      | representation              |
| ------------------------------------------------------------ | ------------------------------------------------------------ | --------------------------- |
| [Adjacency list](https://en.wikipedia.org/wiki/Adjacency_list) （邻接链表） | ![](./weight01.gif)                                          | ![](./adjacency-list.gif)   |
| [Adjacency matrix](https://en.wikipedia.org/wiki/Adjacency_matrix) （邻接矩阵） | ![](./weight01.gif)                                          | ![](./adjacent-matrix.jpg)  |
| [Incidence matrix](https://en.wikipedia.org/wiki/Incidence_matrix) （关联矩阵） | [![img](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fc/Weighted_undirected_graph.svg/220px-Weighted_undirected_graph.svg.png)](https://en.wikipedia.org/wiki/File:Weighted_undirected_graph.svg) | ![](./incidence-matrix.jpg) |

> NOTE: 
>
> 一、上述三种方式都能够表示weighed graph和unweighted graph。
>
> 二、在原文中还给出了在使用上述三种表示方式下执行一些典型操作时的算法复杂度。



## mathcs.emory [Representing weighted graphs](http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/11-Graph/weighted.html)

> NOTE: 如何来表示一个weighted graph？正如在Summary章节所述，即需要考虑structure也需要考虑property（也就是这里说的weight）

### Weighted graphs

**Weighted graph** = a **graph** whose **edges** have **weights**

![](./weight01.gif)



The **weight** of an **edge** can **represent**:

- **Cost or distance**
- **Capacity** = the **maximim amount of flow** that can be **transported** from one place to another

### Adjacency list

Each **node** in the **adjacency graph** will **contain:**

- A **neighbor node ID** (this **field** was **already** discussed previously)
- A `cost` field (this field is new)

#### Example

**Graph:**

![](./weight01.gif)

**Representation:**

![](./adjacency-list.gif)



Class used to represent (define) **edges**:

```java


   /* ==========================================
      Edges is stored as Node of a linked list
      ========================================== */         
   public class Edge
   {
      int  NodeID;     // The neighbor node
      double Weight;   // Weight of edge
      Node next;       // Link variable
   }  
```



Class used to represent (define) a graph:

```java
   /* =============================================================
      The graph is an array of Edge (Edge[i] = all edges of node i)
      ============================================================== */         
   public class Graph
   {
       public Edge[] graph;    // Array of Edges      
   }
```

### Adjacency matrix

> NOTE: 原文称之为 "Adjacency array"

Representing a weighted graph using an adjacency array:

- If there is no edge between node i and node j, the value of the array element `a[i][j] = some very large value`

- Otherwise, `a[i][j]` is a floating value that is equal to the weight of the `edge (i, j)`

#### Example

![](./weight01.gif)

Representation:

```

           0  1  2  3  4  5  6  7  8
         +-                         -+
         | *  3  *  2  *  *  *  *  4 |    // 0         
         | 3  *  *  *  *  *  *  4  * |    // 1
         | *  *  *  6  *  1  *  2  * |    // 2
         | 2  *  6  *  1  *  *  *  * |    // 3
    M =  | *  *  *  1  *  *  *  *  8 |    // 4
         | *  *  1  *  *  *  8  *  * |    // 5
         | *  *  *  *  *  8  *  *  * |    // 6
         | *  4  2  *  *  *  *  *  * |    // 7
         | 4  *  *  *  8  *  *  *  * |    // 8
         +-                         -+

                   * = a very large value (infinite)
```



Class used to represent a graph using an adjacency matrix:

```java
   public class Graph
   {

      /* =======================================
         The edges of the graph
         ======================================= */
      double[][] M;      // M[i][j] = weight of edge (i,j)      

      ...
   }
```



## Summary

### Weighted graph 如何表示两点不相连？

一、Incidence-matrix、Adjacency-matrix

通过特殊值来标记不相连，一般有如下选择: 

|           | 解释               | 适用场景         |
| --------- | ------------------ | ---------------- |
| infinite  | a very large value | 目标值是最大值时 |
| -infinite | a very small value | 目标值是最小值时 |

这种表示方式在一定程度上是能够简化程序的，典型的例子就是使用 [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) 算法解 [LeetCode-743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/) ，下面完整代码:

```c++
class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2)); // 节点的标号是从1开始的，所以使用n+1
    for (auto &it : times)
      dp[it[0]][it[1]] = it[2];
    for (int i = 1; i <= n; i++)
      dp[i][i] = 0; //自己到自己为0

    for (int i = 1; i <= n; i++) // 节点的标号是从1开始的
    {
      for (int j = 1; j <= n; j++)
      {
        for (int k = 1; k <= n; k++) // 中转节点
        {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++)
      ret = max(ret, dp[k][i]);
    return ret == INT_MAX / 2 ? -1 : ret;
  }
};
```



二、Adjacency-list

这种表示方式相对比较简单: 如果"adjacent vertices" 或者 "terminal vertices" 中不包含目标节点，那么就不相连。



### 从relation的角度来分析graph representation

使用graph来表示relation，relation是有属性的，所以graph需要能够表示出这些relation的属性，各种algorithm其实就是基于relation和relation的属性的。

这就是graph、representation、property、algorithm。



## 其他素材

khanacademy [Representing graphs](https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs)


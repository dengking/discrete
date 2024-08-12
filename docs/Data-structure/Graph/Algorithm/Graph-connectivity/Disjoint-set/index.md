# Disjoint-set/union–find data structure

## 素材

1. baike [并查集](https://baike.baidu.com/item/%E5%B9%B6%E6%9F%A5%E9%9B%86/9388442?fr=aladdin)

2. zhuanlan.zhihu [算法学习笔记(1) : 并查集](https://zhuanlan.zhihu.com/p/93647900/)

3. labuladong [Union-Find 并查集算法详解](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484751&idx=1&sn=a873c1f51d601bac17f5078c408cc3f6&scene=21#wechat_redirect)



## wikipedia [Disjoint-set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure) 

In [computer science](https://en.wanweibaike.com/wiki-Computer_science), a **disjoint-set data structure**, also called a **union–find data structure** or **merge–find set**, is a data structure that stores a collection of [disjoint](https://en.wanweibaike.com/wiki-Disjoint_sets) (non-overlapping) sets. Equivalently, it stores a [partition of a set](https://en.wanweibaike.com/wiki-Partition_of_a_set) into disjoint subsets. 

> NOTE: 显然它是由"a collection of [disjoint](https://en.wanweibaike.com/wiki-Disjoint_sets) (non-overlapping) sets"组成
>



### Representation

While there are several ways of implementing **disjoint-set data structures**, in practice they are often identified with a particular implementation called a **disjoint-set forest**. This is a specialized type of [forest](https://en.wikipedia.org/wiki/Forest_(graph_theory)) which performs unions and finds in near-constant [amortized time](https://en.wikipedia.org/wiki/Amortized_analysis). 

Each node in a **disjoint-set forest** consists of a pointer and some auxiliary information, either a size or a rank (but not both). 

The pointers are used to make [parent pointer trees](https://en.wikipedia.org/wiki/Parent_pointer_tree), where each node that is not the root of a tree points to its parent. To distinguish root nodes from others, their parent pointers have invalid values, such as a **circular reference** to the node or a **sentinel value**. 

> NOTE. 我们平时所见的tree都是children pointer，但是disjoint-set data structure比较特殊，它是 [parent pointer tree](https://en.wikipedia.org/wiki/Parent_pointer_tree) ，一般的实现方式会使用array来保存 [parent pointer tree](https://en.wikipedia.org/wiki/Parent_pointer_tree) ，这和 heap一样。

Each tree represents a set stored in the forest, with the members of the set being the nodes in the tree. Root nodes provide **set representatives**: Two nodes are in the same set if and only if the roots of the trees containing the nodes are equal.

> NOTE: "set representative"是一个非常重要的概念，它其实就是disjoint set、subset、sub tree的root node，这是因为union-find set 需要使用**set representative** (**root node**) 来判断两个元素是否属于同一个set，因此它就需要验证path逆流而上去找到它们的root node，即它们的set representative，所以union-find set使用parent pointer。
>

Nodes in the forest can be stored in any way convenient to the application, but a common technique is to store them in an array. In this case, parents can be indicated by their array index.



### ADT、Operations

It provides operations for :

1. adding new sets

2. merging sets (replacing them by their [union](https://en.wanweibaike.com/wiki-Union_(set_theory))), 

3. finding a representative member of a set. 

> NOTE:
>
> 一. "set representative"是一个非常重要的概念

4. find out efficiently if any two elements are in the same or different sets.



Disjoint-set data structures support three operations: 

Making a new set containing a new element; 

Finding the representative of the set containing a given element; 

Merging two sets.

#### Making new sets



```pseudocode
function MakeSet(x) is
    if x is not already in the forest then
        x.parent := x
        x.size := 1     // if nodes store size
        x.rank := 0     // if nodes store rank
    end if
end function
```



#### Finding set representatives

The `Find` operation follows the chain of parent pointers from a specified query node *x* until it reaches a root element. This root element represents the set to which *x* belongs and may be *x* itself. `Find` returns the root element it reaches.

> NOTE:
>
> 一. stop-condition:
>
> 1. top-down: leaf node; `child` pointer is null
>
> 2. bottom-up: root node; `parent` pointer is self

Performing a `Find` operation presents an important opportunity for improving the forest. The time in a `Find` operation is spent chasing parent pointers, so a flatter tree leads to faster `Find` operations. When a `Find` is executed, there is no faster way to reach the root than by following each parent pointer in succession. However, the parent pointers visited during this search can be updated to point closer to the root. Because every element visited on the way to a root is part of the same set, this does not change the sets stored in the forest. But it makes future `Find` operations faster, not only for the nodes between the query node and the root, but also for their descendants. This updating is an important part of the disjoint-set forest's amortized performance guarantee.

There are several algorithms for `Find` that achieve the asymptotically optimal time complexity. One family of algorithms, known as **path compression**, makes every node between the query node and the root point to the root. 



##### 实现方式一: simple recursion

Path compression can be implemented using a simple recursion as follows:

```pseudocode
function Find(x) is
    if x.parent ≠ x then
        x.parent := Find(x.parent) # 将x.parent设置为它的parent所在set 的root
        return x.parent
    else // stop condition
        return x
    end if
end function
```

> NOTE:
>
> 一. bottom-up
>
> 需要注意的是，上述写法其实并没有优化tree



##### 实现方式二: two passes iteration

This implementation makes two passes, one up the tree and one back down. It requires enough scratch memory to store the path from the query node to the root (in the above pseudocode, the path is implicitly represented using the call stack). This can be decreased to a constant amount of memory by performing both passes in the same direction. The constant memory implementation walks from the query node to the root twice, once to find the root and once to update pointers:

> NOTE: 上面的这段话是对下面的算法进行的解释，这个实现是two passes
>

```pseudocode
function Find(x) is
    root := x
    while root.parent ≠ root do # 首先找到root
        root := root.parent
    end while

    while x.parent ≠ root do // 将所有的节点的parent都更新为root
        parent := x.parent
        x.parent := root
        x := parent
    end while

    return root
end function
```



##### 实现方式: one-pass

[Tarjan](https://en.wikipedia.org/wiki/Robert_E._Tarjan) and [Van Leeuwen](https://en.wikipedia.org/wiki/Jan_van_Leeuwen) also developed one-pass `Find` algorithms that retain the same worst-case complexity but are more efficient in practice.[[4\]](https://en.wikipedia.org/wiki/Disjoint-set_data_structure#cite_note-Tarjan1984-4) These are called **path splitting** and **path halving**. Both of these update the parent pointers of nodes on the path between the query node and the root. 



##### 实现方式三: one-pass-**Path splitting** 

> NOTE: 其实方式一、方式二、方式三都属于"**path splitting**"，它是每次都走一步
>

**Path splitting** replaces every parent pointer on that path by a pointer to the node's grandparent:

```pseudocode
function Find(x) is
    while x.parent ≠ x do
        (x, x.parent) := (x.parent, x.parent.parent) # 类似于python tuple assignment，它的运行逻辑是先读取，再更新
    end while
    return x
end function
```



##### 实现方式四: one-pass-**Path halving** 

**Path halving** works similarly but replaces only every other parent pointer:

> NOTE:
>
> 一. **halving** 的意思是 "**二等分**"、"减半" 
>
> 二. "路径减半的工作原理类似，但只替换所有其他父指针"，它是一次走两步，由于root node是self-reference，因此它能够保证最终肯定能够在root node停止下来

```pseudocode
function Find(x) is
    while x.parent ≠ x do
        x.parent := x.parent.parent
        x := x.parent
    end while
    return x
end function
```



#### Merging two sets

The operation `Union(x, y)` replaces the set containing *x* and the set containing *y* with their union. `Union` first uses `Find` to determine the roots of the trees containing *x* and *y*. If the roots are the same, there is nothing more to do. Otherwise, the two trees must be merged. This is done by either setting the parent pointer of *x*'s root to *y*'s, or setting the parent pointer of *y*'s root to *x*'s.

The choice of which node becomes the parent has consequences for the complexity of future operations on the tree. If it is done carelessly, trees can become excessively tall. For example, suppose that `Union` always made the tree containing *x* a subtree of the tree containing *y*. Begin with a forest that has just been initialized with elements $1,2,3,\ldots ,n$, and execute `Union(1, 2)`, `Union(2, 3)`, ..., `Union(n - 1, n)`. The resulting forest contains a single tree whose root is *n*, and the path from 1 to *n* passes through every node in the tree. For this forest, the time to run `Find(1)` is *O*(*n*).

In an efficient implementation, tree height is controlled using **union by size** or **union by rank**. Both of these require a node to store information besides just its **parent pointer**. This information is used to decide which root becomes the new parent. Both strategies ensure that trees do not become too deep.

> NOTE: 目标是让树的高度尽可能地小

##### Union by size

In the case of union by size, a node stores its size, which is simply its number of descendants (including the node itself). When the trees with roots *x* and *y* are merged, the node with more descendants becomes the parent. If the two nodes have the same number of descendants, then either one can become the parent. In both cases, the size of the new parent node is set to its new total number of descendants.

```pseudocode
function Union(x, y) is
    // Replace nodes by roots
    x := Find(x)
    y := Find(y)

    if x = y then
        return  // x and y are already in the same set
    end if

    // If necessary, swap variables to ensure that
    // x has at least as many descendants as y
    if x.size < y.size then
        (x, y) := (y, x)
    end if

    // Make x the new root
    y.parent := x
    // Update the size of x
    x.size := x.size + y.size
end function
```



##### Union by rank

> NOTE: 需要注意: rank不是height的，rank所表达的是"upper bound for its height"，并且"The height of a node can change during a `Find` operation"

For union by rank, a node stores its *rank*, which is an **upper bound for its height**. When a node is initialized, its rank is set to zero. To merge trees with roots *x* and *y*, first compare their ranks. If the ranks are different, then the larger rank tree becomes the parent, and the ranks of *x* and *y* do not change. If the ranks are the same, then either one can become the parent, but the new parent's rank is incremented by one. While the rank of a node is clearly related to its height, storing ranks is more efficient than storing heights. The height of a node can change during a `Find` operation, so storing ranks avoids the extra effort of keeping the height correct. 

```pseudocode
function Union(x, y) is
    // Replace nodes by roots
    x := Find(x)
    y := Find(y)

    if x = y then
        return  // x and y are already in the same set
    end if

    // If necessary, rename variables to ensure that
    // x has rank at least as large as that of y
    if x.rank < y.rank then
        (x, y) := (y, x)
    end if

    // Make x the new root
    y.parent := x
    // If necessary, increment the rank of x
    if x.rank = y.rank then
        x.rank := x.rank + 1
    end if
end function
```

#### Retrieve all members of a set

如何获得disjoint-set中的各个set(connected component)? 这是我在做 [LeetCode-130. Surrounded Regions-中等](https://leetcode.cn/problems/surrounded-regions/) 的时候想到的一个问题。实现方式是circular linked list，具体实现涉及如下操作:

- 将两个环形linked list合并为一个大的环形linked list: 可以想象有两个旋转方向相同的circular linked list，分别给定两者中的任何一个node，让这两个node分别指向对方的next的就可以构成一个更大的、旋转方向相同的circular linked list。
- 遍历circular linked list

素材:

- stackoverflow [Printing out nodes in a disjoint-set data structure in linear time](https://stackoverflow.com/questions/22945058/printing-out-nodes-in-a-disjoint-set-data-structure-in-linear-time) # [A](https://stackoverflow.com/a/22945492/23877800) : 详细阐明了思路 

  > Each node should have a `next` pointer to the **next node** in the set it is in. The nodes in a set should form a *circular linked list*.
  >
  > When a singleton set is first created, the node's `next` pointer points to itself.
  >
  > When you merge set with node `X` and set with node `Y` (and you've already checked that those sets are different by normalizing to set representatives), you merge the **circular linked lists**, which you can do by simply swapping `X.next` and `Y.next`; so this is a `O(1)` operation.
  >
  > To list all the elements in the set containing node `X`, traverse the **circular linked list** starting from `X`.

- stackoverflow [Union-Find: retrieve all members of a set efficiently](https://stackoverflow.com/questions/23055236/union-find-retrieve-all-members-of-a-set-efficiently) # [A](https://stackoverflow.com/a/23061520) : 按照前面的思路给出了伪代码 

  > 
  >
  > ```pseudocode
  > MAKE-SET(x)
  >     x.p = x
  >     x.rank = 0
  >     x.link = x        # Circular linked list
  > 
  > UNION(x,y)
  >     sx = FIND-SET(x)
  >     sy = FIND-SET(y)
  >     if sx != sy
  >         LINK(sx, sy)
  > 
  > LINK(x,y)             # x,y都是之前的set的root
  >     temp = y.link     # Concatenation
  >     y.link = x.link   # of the two
  >     x.link = temp     # circular lists，新形成的list也是circular list
  >     if x.rank > y.rank
  >         y.p = x
  >     else x.p = y
  >          if x.rank == y.rank
  >              y.rank = y.rank + 1
  > 
  > FIND-SET(x)
  >     if x != x.p
  >         x.p = FIND-SET(x.p)
  >     return x.p
  > 
  > PRINT-SET(x)
  >     root = x
  >     PRINT(x)
  >     while x.link != root
  >         x = x.link
  >         PRINT(x)
  > ```
  >
  > 

#### Deletion of edges

Note that the implementation as disjoint-set forests doesn't allow the deletion of edges, even without path compression or the rank heuristic. However, there exist modern implementations that allow for constant-time deletion.

Sharir and Agarwal report connections between the worst-case behavior of disjoint-sets and the length of [Davenport–Schinzel sequences](https://en.wanweibaike.com/wiki-Davenport–Schinzel_sequence), a combinatorial structure from computational geometry.

## Implementation

### C++

````C++
#include <vector>

/// @brief
class DisjointSet {
    std::vector<int> parent_;
    std::vector<int> next_; // 构成circular linked list
    std::vector<int> size_;
    std::vector<int> rank_;
    std::size_t set_cnt_{0}; // disjoint set的个数
public:
    DisjointSet(std::size_t n) : parent_(n), set_cnt_{n} {
        for (int i = 0; i < n; ++i) {
            parent_[i] = i; // 初始化的时候，每个节点都是一棵单点树
            size_[i] = 1;
            rank_[i] = 0;
            next_[i] = i;// 构成circular linked list
        }
    }

    /// @brief 使用recursion的方式实现find set representative/root
    /// @param idex
    /// @return
    int find_by_recursion(int idx) {
        if (parent_[idx] != idx) {
            // 在向上寻找的过程中同时进行优化: 它会将从idx到set representative/root的这条路上的所有的节点都设置为指向set representative/root
            parent_[idx] = find_by_recursion(parent_[idx]);
        }
        // 需要注意，它返回的是修改后的值
        return parent_[idx];

    }

    /// @brief 使用iteration的方式实现find set representative/root
    /// @param idx
    /// @return
    int find_by_two_pass_iteration(int idx) {
        int root = idx;
        while (parent_[root] != root) // 找到set representative/root
        {
            root = parent_[root];
        }
        // 优化: 它会将从idx到set representative/root的这条路上的所有的节点都设置为指向set representative/root
        while (parent_[idx] != idx) {
            int parent = parent_[idx];
            parent_[idx] = root;
            idx = parent;
        }
        return root;
    }

    /// @brief
    /// @param idx
    /// @return
    int find_by_path_split(int idx) {
        while (parent_[idx] != idx) {
            int grandparent = parent_[parent_[idx]];
            int parent = parent_[idx];
            // Path splitting replaces every parent pointer on that path by a pointer to the node's grandparent
            parent_[idx] = grandparent;
            idx = parent;               // iteration
        }
        return idx;
    }

    int find_by_path_halving(int idx) {
        while (parent_[idx] != idx) {
            int grandparent = parent_[parent_[idx]];
            // Path halving works similarly but replaces only every other parent pointer
            parent_[idx] = grandparent;
            idx = parent_[idx];         // iteration
        }
        return idx;
    }

    /// @brief 判断idx是否是set representative/root
    /// @param
    /// @return
    bool is_root(int idx) {
        return parent_[idx] == idx;
    }

    void Union(int i, int j) {
        int i_root = find_by_path_split(i);
        int j_root = find_by_path_split(j);
        if (i_root != j_root) {
            link(i_root, j_root);
            parent_[i_root] = j_root;
            --set_cnt_;
        }
    }

    /// @brief union by size
    /// @param i
    /// @param j
    void union_by_size(int i, int j) {
        int i_root = find_by_path_split(i);
        int j_root = find_by_path_split(j);
        if (i_root != j_root) {
            link(i_root, j_root);
            if (size_[i_root] < size_[j_root]) {
                parent_[i_root] = j_root;
                size_[j_root] += size_[i_root];
            } else {
                parent_[j_root] = i_root;
                size_[i_root] += size_[j_root];
            }
            --set_cnt_;
        }
    }

    /// @brief union by rank
    /// @param i
    /// @param j
    void union_by_rank(int i, int j) {
        int i_root = find_by_path_split(i);
        int j_root = find_by_path_split(j);
        if (i_root != j_root) {
            link(i_root, j_root);
            if (rank_[i_root] < rank_[j_root]) {
                parent_[i_root] = j_root;
            } else if (rank_[i_root] > rank_[j_root]) {
                parent_[j_root] = i_root;
            } else {
                parent_[j_root] = i_root;
                rank_[i_root] += 1;
            }
            --set_cnt_;
        }
    }

private:
    /// 合并ihej所在地的circular linked list
    /// \param i
    /// \param j
    void link(int i, int j) {
        int tmp = next_[j];
        next_[j] = next_[i];
        next_[i] = tmp;
    }
};

int main() {
}

````

### Python

```python
class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  # Path compression
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

```



## Applications

### Application of disjoint set in graph theory

> NOTE: 本段内容融合了 wikipedia [Disjoint-set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure) 和 gpt-4o

The **Disjoint Set (or Union-Find) algorithm** is a versatile and efficient data structure used in various graph-related problems. Here are some common applications of the **Disjoint Set algorithm** in graph theory:

#### [Connected components](https://en.wikipedia.org/wiki/Connected_component_(graph_theory)) of an [undirected graph](https://en.wikipedia.org/wiki/Undirected_graph) 

> NOTE: 
>
> disjoint-set中的set正好和connected-component相对应
>
> 在labuladong [Union-Find 并查集算法详解](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484751&idx=1&sn=a873c1f51d601bac17f5078c408cc3f6&scene=21#wechat_redirect) 将这种application称之为 "动态连通性"

**Disjoint-set** data structures model the [partitioning of a set](https://en.wikipedia.org/wiki/Partition_of_a_set), for example to keep track of the [connected components](https://en.wikipedia.org/wiki/Connected_component_(graph_theory)) of an [undirected graph](https://en.wikipedia.org/wiki/Undirected_graph). This model can then be used to determine whether two vertices belong to the same component, or whether adding an edge between them would result in a cycle. 

Finding connected components in an undirected graph using the Disjoint Set (Union-Find) algorithm involves iterating through all edges and using the Union-Find structure to group vertices into connected components.

```python
class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  # Path compression
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

def find_connected_components(edges, n):
    ds = DisjointSet(n)
    
    # Perform union operation for each edge
    for u, v in edges:
        ds.union(u, v)
    
    # Find the root of each vertex
    components = {}
    for vertex in range(n):
        root = ds.find(vertex)
        if root not in components:
            components[root] = []
        components[root].append(vertex)
    
    return list(components.values())

# Example usage
edges = [(0, 1), (1, 2), (3, 4)]
n = 5  # Number of vertices
connected_components = find_connected_components(edges, n)
print("Connected Components:", connected_components)
```



#### Cycle Detection in Undirected Graphs

> NOTE: 
>
> 一. 前面的"whether adding an edge between them would result in a cycle" [LeetCode-684. Redundant Connection](https://leetcode.cn/problems/redundant-connection/) 考察的正是这个应用 

The **Disjoint Set algorithm** can be used to detect cycles in an undirected graph. By iterating through all edges and using the Union-Find structure to keep track of connected components, we can determine if adding an edge would form a cycle.

```python
class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

def has_cycle(edges, n):
    ds = DisjointSet(n)
    for u, v in edges:
        if ds.find(u) == ds.find(v):
            return True
        ds.union(u, v)
    return False

# Example usage
edges = [(0, 1), (1, 2), (2, 0), (3, 4)]
n = 5  # Number of vertices
print("Graph has cycle:", has_cycle(edges, n))
```



#### [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal's_algorithm) for finding the [minimum spanning tree](https://en.wikipedia.org/wiki/Minimum_spanning_tree) of a graph

Disjoint-set data structures play a key role in [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal's_algorithm) for finding the [minimum spanning tree](https://en.wikipedia.org/wiki/Minimum_spanning_tree) of a graph. The importance of minimum spanning trees means that disjoint-set data structures underlie a wide variety of algorithms. 

```python
class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

def kruskal(edges, n):
    ds = DisjointSet(n)
    mst = []
    edges.sort(key=lambda x: x[2])  # Sort edges by weight

    for u, v, weight in edges:
        if ds.find(u) != ds.find(v):
            ds.union(u, v)
            mst.append((u, v, weight))

    return mst

# Example usage
edges = [(0, 1, 10), (0, 2, 6), (0, 3, 5), (1, 3, 15), (2, 3, 4)]
n = 4  # Number of vertices
mst = kruskal(edges, n)
print("Minimum Spanning Tree:", mst)
```

This data structure is used by the [Boost Graph Library](https://en.wanweibaike.com/wiki-Boost_Graph_Library) to implement its [Incremental Connected Components](http://www.boost.org/libs/graph/doc/incremental_components.html) functionality. It is also a key component in implementing [Kruskal's algorithm](https://en.wanweibaike.com/wiki-Kruskal's_algorithm) to find the [minimum spanning tree](https://en.wanweibaike.com/wiki-Minimum_spanning_tree) of a graph.

### [Unification](https://en.wikipedia.org/wiki/Unification_(computer_science))

The Union–Find algorithm is used in high-performance implementations of [unification](https://en.wikipedia.org/wiki/Unification_(computer_science)).



### [Hoshen-Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen–Kopelman_algorithm) 

The [Hoshen-Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen–Kopelman_algorithm) uses a Union-Find in the algorithm.

> NOTE: [LeetCode-130. Surrounded Regions-中等](https://leetcode.cn/problems/surrounded-regions/)



### Others

In addition, disjoint-set data structures also have applications to symbolic computation, as well in compilers, especially for [register allocation](https://en.wikipedia.org/wiki/Register_allocation) problems.

## 从relation的角度来看待disjoint set

这在wikipedia [Hoshen–Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen%E2%80%93Kopelman_algorithm) # [Union-find algorithm](https://en.wikipedia.org/wiki/Hoshen%E2%80%93Kopelman_algorithm#Union-find_algorithm) 中有着很好的解释:

> This algorithm is a simple method for computing [equivalence classes](https://en.wikipedia.org/wiki/Equivalence_class). Calling the function `union(x,y)` returns whether items `x` and `y` are members of the same **equivalence class**. Because **equivalence relations** are [transitive](https://en.wikipedia.org/wiki/Transitive_relation), all the items equivalent to `x` are equivalent to all the items equivalent to `y`. Thus for any item `x`, there is a set of items which are all equivalent to `x` (called the equivalence class). A second function `find(x)` returns a representative member of the equivalence class to which `x` belongs.

对于由transitive relation组成的connected-component。



## LeetCode

https://leetcode.cn/tag/union-find/problemset/

[LeetCode-128. Longest Consecutive Sequence-中等](https://leetcode.cn/problems/longest-consecutive-sequence/)

1. 对于非连续的数，parent关系使用map来进行存储。

2. 连续的数就是一个set



[LeetCode-130. Surrounded Regions-中等](https://leetcode.cn/problems/surrounded-regions/)

[Hoshen–Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen%E2%80%93Kopelman_algorithm) 

### [LeetCode-684. Redundant Connection](https://leetcode.cn/problems/redundant-connection/) 

n个节点至少有n-1条边才能够将它们连接起来，而这道题中，至少存在一条冗余的边，因此边的个数至少为n，所以可以将disjoint set的节点的个数设置为边的个数+1

```python
from typing import *


class DisjointSet:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]
        self.size = [1] * n

    def union(self, i, j) -> bool:
        i_root = self.find(i)
        j_root = self.find(j)
        if i_root != j_root:
            if self.size[i_root] < self.size[j_root]:
                i_root, j_root = j_root, i_root
            # 始终用i_root表示新的root
            self.parent[j_root] = i_root
            self.size[i_root] += self.size[j_root]
            return True
        else:
            return False

    def find(self, i) -> int:
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        disjoint_set = DisjointSet(len(edges) + 1)
        redundant_edges = []
        for edge in edges:
            if not disjoint_set.union(edge[0], edge[1]):
                redundant_edges.append(edge)
        if len(redundant_edges) > 0:
            return redundant_edges[-1]
        return []

```


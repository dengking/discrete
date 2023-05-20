# Disjoint-set data structure、union–find data structure

一、我们平时所见的tree都是children pointer，但是disjoint-set data structure比较特殊，它是 [parent pointer tree](https://en.wikipedia.org/wiki/Parent_pointer_tree) ，一般的实现方式会使用array来保存 [parent pointer tree](https://en.wikipedia.org/wiki/Parent_pointer_tree) ，这和 heap一样。

二、disjoint-set中的set正好和connected-component相对应



## wikipedia [Disjoint-set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure) 

In [computer science](https://en.wanweibaike.com/wiki-Computer_science), a **disjoint-set data structure**, also called a **union–find data structure** or **merge–find set**, is a data structure that stores a collection of [disjoint](https://en.wanweibaike.com/wiki-Disjoint_sets) (non-overlapping) sets. Equivalently, it stores a [partition of a set](https://en.wanweibaike.com/wiki-Partition_of_a_set) into disjoint subsets. 

> NOTE: 
>
> 一、显然它是由"a collection of [disjoint](https://en.wanweibaike.com/wiki-Disjoint_sets) (non-overlapping) sets"组成



### Representation

While there are several ways of implementing **disjoint-set data structures**, in practice they are often identified with a particular implementation called a **disjoint-set forest**. This is a specialized type of [forest](https://en.wikipedia.org/wiki/Forest_(graph_theory)) which performs unions and finds in near-constant [amortized time](https://en.wikipedia.org/wiki/Amortized_analysis). 

Each node in a **disjoint-set forest** consists of a pointer and some auxiliary information, either a size or a rank (but not both). 

The pointers are used to make [parent pointer trees](https://en.wikipedia.org/wiki/Parent_pointer_tree), where each node that is not the root of a tree points to its parent. To distinguish root nodes from others, their parent pointers have invalid values, such as a circular reference to the node or a sentinel value. 

Each tree represents a set stored in the forest, with the members of the set being the nodes in the tree. Root nodes provide **set representatives**: Two nodes are in the same set if and only if the roots of the trees containing the nodes are equal.

> NOTE:
>
> 一、"set representative"是一个非常重要的概念，它其实就是disjoint set、subset、sub tree的root node，这是因为union-find set 需要使用**set representative** (**root node**) 来判断两个元素是否属于同一个set，因此它就需要验证path逆流而上去找到它们的root node，即它们的set representative，所以union-find set使用parent pointer。

Nodes in the forest can be stored in any way convenient to the application, but a common technique is to store them in an array. In this case, parents can be indicated by their array index.



### ADT、Operations

It provides operations for :

1、adding new sets

2、merging sets (replacing them by their [union](https://en.wanweibaike.com/wiki-Union_(set_theory))), 

3、finding a representative member of a set. 

> NOTE:
>
> 一、"set representative"是一个非常重要的概念

4、find out efficiently if any two elements are in the same or different sets.



Disjoint-set data structures support three operations: Making a new set containing a new element; Finding the representative of the set containing a given element; and Merging two sets.

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
> 一、stop-condition:
>
> 1、top-down: leaf node
>
> 2、bottom-up: root node

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
> 一、bottom-up
>
> 需要注意的是，上述写法其实并没有优化tree



##### 实现方式二: two passes iteration

This implementation makes two passes, one up the tree and one back down. It requires enough scratch memory to store the path from the query node to the root (in the above pseudocode, the path is implicitly represented using the call stack). This can be decreased to a constant amount of memory by performing both passes in the same direction. The constant memory implementation walks from the query node to the root twice, once to find the root and once to update pointers:

> NOTE:
>
> 一、上面的这段话是对下面的算法进行的解释，这个实现是two passes

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

> NOTE:
>
> 一、其实方式一、方式二、方式三都属于"**path splitting**"，它是每次都走一步

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
> 一、**halving** 的意思是 **二等分** 
>
> 二、"路径减半的工作原理类似，但只替换所有其他父指针"，它是一次走两步，由于root node是self-reference，因此它能够保证最终肯定能够在root node停止下来

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

##### Union by size

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



### Applications

Disjoint-set data structures model the [partitioning of a set](https://en.wikipedia.org/wiki/Partition_of_a_set), for example to keep track of the [connected components](https://en.wikipedia.org/wiki/Connected_component_(graph_theory)) of an [undirected graph](https://en.wikipedia.org/wiki/Undirected_graph). This model can then be used to determine whether two vertices belong to the same component, or whether adding an edge between them would result in a cycle. 

> NOTE: 
>
> 一、在labuladong [Union-Find 并查集算法详解](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484751&idx=1&sn=a873c1f51d601bac17f5078c408cc3f6&scene=21#wechat_redirect) 将这种application称之为 "动态连通性"

The Union–Find algorithm is used in high-performance implementations of [unification](https://en.wikipedia.org/wiki/Unification_(computer_science)).

Disjoint-set data structures play a key role in [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal's_algorithm) for finding the [minimum spanning tree](https://en.wikipedia.org/wiki/Minimum_spanning_tree) of a graph. The importance of minimum spanning trees means that disjoint-set data structures underlie a wide variety of algorithms. 

In addition, disjoint-set data structures also have applications to symbolic computation, as well in compilers, especially for [register allocation](https://en.wikipedia.org/wiki/Register_allocation) problems.



This data structure is used by the [Boost Graph Library](https://en.wanweibaike.com/wiki-Boost_Graph_Library) to implement its [Incremental Connected Components](http://www.boost.org/libs/graph/doc/incremental_components.html) functionality. It is also a key component in implementing [Kruskal's algorithm](https://en.wanweibaike.com/wiki-Kruskal's_algorithm) to find the [minimum spanning tree](https://en.wanweibaike.com/wiki-Minimum_spanning_tree) of a graph.

Note that the implementation as disjoint-set forests doesn't allow the deletion of edges, even without path compression or the rank heuristic. However, there exist modern implementations that allow for constant-time deletion.

Sharir and Agarwal report connections between the worst-case behavior of disjoint-sets and the length of [Davenport–Schinzel sequences](https://en.wanweibaike.com/wiki-Davenport–Schinzel_sequence), a combinatorial structure from computational geometry.



## 从relation的角度来看待disjoint set

这在wikipedia [Hoshen–Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen%E2%80%93Kopelman_algorithm) # [Union-find algorithm](https://en.wikipedia.org/wiki/Hoshen%E2%80%93Kopelman_algorithm#Union-find_algorithm) 中有着很好的解释:

> This algorithm is a simple method for computing [equivalence classes](https://en.wikipedia.org/wiki/Equivalence_class). Calling the function `union(x,y)` returns whether items `x` and `y` are members of the same **equivalence class**. Because **equivalence relations** are [transitive](https://en.wikipedia.org/wiki/Transitive_relation), all the items equivalent to `x` are equivalent to all the items equivalent to `y`. Thus for any item `x`, there is a set of items which are all equivalent to `x` (called the equivalence class). A second function `find(x)` returns a representative member of the equivalence class to which `x` belongs.

对于由transitive relation组成的connected-component。



## 素材

1、baike [并查集](https://baike.baidu.com/item/%E5%B9%B6%E6%9F%A5%E9%9B%86/9388442?fr=aladdin)

2、zhuanlan.zhihu [算法学习笔记(1) : 并查集](https://zhuanlan.zhihu.com/p/93647900/)

3、labuladong [Union-Find 并查集算法详解](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484751&idx=1&sn=a873c1f51d601bac17f5078c408cc3f6&scene=21#wechat_redirect)



## LeetCode

https://leetcode.cn/tag/union-find/problemset/

一、[LeetCode-128. Longest Consecutive Sequence-中等](https://leetcode.cn/problems/longest-consecutive-sequence/)

1、对于非连续的数，parent关系使用map来进行存储。

2、连续的数就是一个set



二、[Hoshen–Kopelman algorithm](https://en.wikipedia.org/wiki/Hoshen%E2%80%93Kopelman_algorithm) 

[LeetCode-130. Surrounded Regions-中等](https://leetcode.cn/problems/surrounded-regions/)
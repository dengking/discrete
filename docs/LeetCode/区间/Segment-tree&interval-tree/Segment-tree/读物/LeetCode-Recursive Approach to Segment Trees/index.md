# [LeetCode-Recursive Approach to Segment Trees](https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/) 

### What is a Segment Tree?

A segment tree is a binary tree where each node represents an interval. Generally a node would store one or more properties of an interval which can be queried later.

![A typical Segment Tree](https://leetcode.com/articles/Figures/segtree_intro_1.png)

### Why do we require it? (or What's the point of this?)

Many problems require that we give results based on query over a range or segment of available data. This can be a tedious and slow process, especially if the number of queries is large and repetitive. A segment tree let's us process such queries efficiently in logarithmic order of time.



Segment Trees have applications in areas of computational geometry and [geographic information systems.](https://en.wikipedia.org/wiki/Geographic_information_systems) For example, we may have a large number of points in space at certain distances from a central reference/origin point. Suppose we have to lookup the points which are in a certain range of distances from our origin. An ordinary lookup table would require a linear scan over all the possible points or all possible distances (think hash-maps). Segment Trees lets us achieve this in logarithmic time with much less space cost. Such a problem is called [Planar Range Searching](https://en.wikipedia.org/wiki/Range_searching). Solving such problems efficiently is critical, especially when dealing with dynamic data which changes fast and unpredictably (for example, a radar system for air traffic.)

> NOTE: 
>
> 一、翻译如下:
>
> "段树在计算几何和地理信息系统领域有应用。例如，我们可能在距中心参考/原点一定距离的空间中有大量点。假设我们必须查找距原点一定距离范围内的点。一个普通的查找表需要对所有可能的点或所有可能的距离进行线性扫描（想想哈希图）。 Segment Trees 让我们在对数时间内以更少的空间成本实现这一目标。这样的问题称为平面范围搜索。有效解决此类问题至关重要，尤其是在处理快速且不可预测的动态数据时（例如，用于空中交通的雷达系统）"。

We will solve the [Range Sum Query problem](https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/#range-sum-queries) later in this editorial as an example of how Segment Trees help us save loads on runtime costs.

![An example Segment Tree](https://leetcode.com/articles/Figures/segtree_example_1.png) We will use the above tree as a practical example of what a Range Sum Query segment tree looks and behaves like.

### How do we make one?

Let our data be in an array `arr[]` of size n.

1、The root of our **segment tree** typically represents the entire interval of data we are interested in. This would be `arr[0:n-1]`.

2、Each leaf of the tree represents a range comprising of just a single element. Thus the leaves represent `arr[0]`, `arr[1]` and so on till `arr[n-1]`.

3、The internal nodes of the tree would represent the **merged** or **union** result of their children nodes.

4、Each of the children nodes could represent approximately half of the range represented by their parent.

A **segment tree** for an n element range can be comfortably represented using an array of size $\approx 4 \ast n$. ([Stack Overflow](http://stackoverflow.com/q/28470692/2844164) has a good discussion as to why. If you are not convinced, fret not. We will discuss it later on.)

> NOTE:
>
> 一、"fret not"的意思是"别担心"
>
> 二、存储方案: "`arr[]` of size n"中的n个元素肯定是leaf node，complete binary tree like heap
>
> index 0: 第i层有 $2^i$ 个节点，第i层元素的起始下标: 


![Children for a specific node are located at well defined indexes](https://leetcode.com/articles/Figures/segtree_intro_2.png)

Segment trees are very intuitive and easy to use when built recursively.

### Recursive methods for Segment Trees

We will use the array `tree[]` to store the nodes of our segment tree (initialized to all zeros). The following scheme (`0` - based indexing) is used:

1、The node of the tree is at index 0. Thus `tree[0]` is the root of our tree.

2、The children of `tree[i]` are stored at `tree[2*i+1]` and `tree[2*i+2]`.

3、We will pad our `arr[]` with extra `0` or `null` values so that $n=2^k$ (where $n$ is the final length of `arr[]` and *k* is a non-negative integer.)


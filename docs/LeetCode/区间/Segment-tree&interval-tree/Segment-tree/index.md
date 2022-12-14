# Segment tree

segment=线段

interval=区间

## wikipedia [Segment tree](https://en.wikipedia.org/wiki/Segment_tree)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **segment tree,** also known as a **statistic tree**, is a [tree](https://en.wikipedia.org/wiki/Tree_(data_structure)) [data structure](https://en.wikipedia.org/wiki/Data_structure) used for storing information about [intervals](https://en.wikipedia.org/wiki/Interval_(mathematics)), or segments. It allows querying which of the stored segments contain a given point. It is, in principle, a static structure; that is, it's a structure that cannot be modified once it's built. A similar data structure is the [interval tree](https://en.wikipedia.org/wiki/Interval_tree).

> NOTE:
>
> 一、"storing information about [intervals](https://en.wikipedia.org/wiki/Interval_(mathematics))" 让我想到了  [interval tree](https://en.wikipedia.org/wiki/Interval_tree) 中的 [augmented tree](https://en.wikipedia.org/wiki/Interval_tree#Augmented_tree) 实现方式中的"extra annotation"



### Structure description

> NOTE:
>
> 一、构建方式: 自底向上+两两合并

Let *S* be a set of intervals, or segments. Let *p*1, *p*2, ..., *pm* be the list of distinct interval endpoints, sorted from left to right. Consider the partitioning of the real line induced by those points. The regions of this partitioning are called *elementary intervals*. Thus, the elementary intervals are, from left to right:
$$
(-\infty ,p_{1}),[p_{1},p_{1}],(p_{1},p_{2}),[p_{2},p_{2}],\dots ,(p_{m-1},p_{m}),[p_{m},p_{m}],(p_{m},+\infty)
$$
That is, the list of elementary intervals consists of open intervals between two consecutive endpoints $p_i$ and $p_{i+1}$, alternated with closed intervals consisting of a single endpoint. Single points are treated themselves as intervals because the answer to a query is not necessarily the same at the interior of an elementary interval and its endpoints.

Given a set *I* of intervals, or segments, a segment tree *T* for *I* is structured as follows:

1、*T* is a [binary tree](https://en.wikipedia.org/wiki/Binary_tree).

2、Its [leaves](https://en.wikipedia.org/wiki/Leaf_node) correspond to the elementary intervals induced by the endpoints in *I*, in an ordered way: 

the leftmost leaf corresponds to the leftmost interval, and so on. 

The elementary interval corresponding to a leaf *v* is denoted Int(*v*).

3、The [internal nodes](https://en.wikipedia.org/wiki/Internal_node) of *T* correspond to intervals that are the [union](https://en.wikipedia.org/wiki/Union_(set_theory)) of elementary intervals: the interval Int(*N*) corresponding to node *N* is the union of the intervals corresponding to the leaves of the tree rooted at *N*. That implies that Int(*N*) is the union of the intervals of its two children.

4、Each node or leaf *v* in *T* stores the interval Int(*v*) and a set of intervals, in some data structure. This canonical subset of node *v* contains the intervals [*x*, *x′*] from *I* such that [*x*, *x′*] contains Int(*v*) and does not contain Int(parent(*v*)). That is, each node in *T* stores the segments that span through its interval, but do not span through the interval of its parent.



## cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)



## geeksforgeeks [Segment Tree | Sum of given range](https://www.geeksforgeeks.org/segment-tree-sum-of-given-range/)





## LeetCode segment tree

1、cn:

LeetCode.cn [segment tree](https://leetcode.cn/tag/segment-tree/problemset/)

2、en:

[LeetCode-segment tree](https://leetcode.com/tag/segment-tree/) 



## [LeetCode-Recursive Approach to Segment Trees](https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/)

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
> 段树在计算几何和地理信息系统领域有应用。例如，我们可能在距中心参考/原点一定距离的空间中有大量点。假设我们必须查找距原点一定距离范围内的点。一个普通的查找表需要对所有可能的点或所有可能的距离进行线性扫描（想想哈希图）。 Segment Trees 让我们在对数时间内以更少的空间成本实现这一目标。这样的问题称为平面范围搜索。有效解决此类问题至关重要，尤其是在处理快速且不可预测的动态数据时（例如，用于空中交通的雷达系统）。

We will solve the [Range Sum Query problem](https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/#range-sum-queries) later in this editorial as an example of how Segment Trees help us save loads on runtime costs.

![An example Segment Tree](https://leetcode.com/articles/Figures/segtree_example_1.png) We will use the above tree as a practical example of what a Range Sum Query segment tree looks and behaves like.

### How do we make one?

Let our data be in an array `arr[]` of size n.

1、The root of our **segment tree** typically represents the entire interval of data we are interested in. This would be `arr[0:n-1]`.

2、Each leaf of the tree represents a range comprising of just a single element. Thus the leaves represent `arr[0]`, `arr[1]` and so on till `arr[n-1]`.

3、The internal nodes of the tree would represent the **merged** or **union** result of their children nodes.

4、Each of the children nodes could represent approximately half of the range represented by their parent.

A segment tree for an n element range can be comfortably represented using an array of size $\approx 4 \ast n$. ([Stack Overflow](http://stackoverflow.com/q/28470692/2844164) has a good discussion as to why. If you are not convinced, fret not. We will discuss it later on.)

<details style="box-sizing: border-box; display: block; color: rgba(0, 0, 0, 0.65); font-family: -apple-system, &quot;system-ui&quot;, &quot;Segoe UI&quot;, &quot;PingFang SC&quot;, &quot;Hiragino Sans GB&quot;, &quot;Microsoft YaHei&quot;, &quot;Helvetica Neue&quot;, Helvetica, Arial, sans-serif, &quot;Apple Color Emoji&quot;, &quot;Segoe UI Emoji&quot;, &quot;Segoe UI Symbol&quot;; font-size: 14px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255); text-decoration-thickness: initial; text-decoration-style: initial; text-decoration-color: initial;"><summary style="box-sizing: border-box; display: list-item; touch-action: manipulation;">But how?</summary><span class="katex" style="box-sizing: border-box; font: 1.21em / 1.2 KaTeX_Main, &quot;Times New Roman&quot;, serif; text-indent: 0px; text-rendering: auto;"><span class="katex-mathml" style="box-sizing: border-box; position: absolute; clip: rect(1px, 1px, 1px, 1px); padding: 0px; border: 0px; height: 1px; width: 1px; overflow: hidden;"><math><semantics><annotation encoding="application/x-tex"></annotation></semantics></math></span><span class="katex-html" aria-hidden="true" style="box-sizing: border-box;"><span class="base" style="box-sizing: border-box; position: relative; white-space: nowrap; width: min-content; display: inline-block;"><span class="strut" style="box-sizing: border-box; display: inline-block; height: 0.65952em; vertical-align: 0em;"></span><span class="mord mathdefault" style="box-sizing: border-box; font-family: KaTeX_Math; font-style: italic;"></span></span></span></span><span class="katex" style="box-sizing: border-box; font: 1.21em / 1.2 KaTeX_Main, &quot;Times New Roman&quot;, serif; text-indent: 0px; text-rendering: auto;"><span class="katex-mathml" style="box-sizing: border-box; position: absolute; clip: rect(1px, 1px, 1px, 1px); padding: 0px; border: 0px; height: 1px; width: 1px; overflow: hidden;"><math><semantics><annotation encoding="application/x-tex"></annotation></semantics></math></span><span class="katex-html" aria-hidden="true" style="box-sizing: border-box;"><span class="base" style="box-sizing: border-box; position: relative; white-space: nowrap; width: min-content; display: inline-block;"><span class="strut" style="box-sizing: border-box; display: inline-block; height: 1em; vertical-align: -0.25em;"></span><span class="mopen" style="box-sizing: border-box;"></span><span class="mord" style="box-sizing: border-box;"></span><span class="mspace" style="box-sizing: border-box; display: inline-block; margin-right: 0.222222em;"></span><span class="mbin" style="box-sizing: border-box;"></span><span class="mspace" style="box-sizing: border-box; display: inline-block; margin-right: 0.222222em;"></span></span><span class="base" style="box-sizing: border-box; position: relative; white-space: nowrap; width: min-content; display: inline-block;"><span class="strut" style="box-sizing: border-box; display: inline-block; height: 0.74285em; vertical-align: -0.08333em;"></span><span class="mord mathdefault" style="box-sizing: border-box; font-family: KaTeX_Math; font-style: italic;"></span><span class="mspace" style="box-sizing: border-box; display: inline-block; margin-right: 0.222222em;"></span><span class="mbin" style="box-sizing: border-box;"></span><span class="mspace" style="box-sizing: border-box; display: inline-block; margin-right: 0.222222em;"></span></span><span class="base" style="box-sizing: border-box; position: relative; white-space: nowrap; width: min-content; display: inline-block;"><span class="strut" style="box-sizing: border-box; display: inline-block; height: 1em; vertical-align: -0.25em;"></span><span class="mord" style="box-sizing: border-box;"></span><span class="mclose" style="box-sizing: border-box;"></span></span></span></span><span class="katex" style="box-sizing: border-box; font: 1.21em / 1.2 KaTeX_Main, &quot;Times New Roman&quot;, serif; text-indent: 0px; text-rendering: auto;"><span class="katex-mathml" style="box-sizing: border-box; position: absolute; clip: rect(1px, 1px, 1px, 1px); padding: 0px; border: 0px; height: 1px; width: 1px; overflow: hidden;"><math><semantics><annotation encoding="application/x-tex"></annotation></semantics></math></span><span class="katex-html" aria-hidden="true" style="box-sizing: border-box;"><span class="base" style="box-sizing: border-box; position: relative; white-space: nowrap; width: min-content; display: inline-block;"><span class="strut" style="box-sizing: border-box; display: inline-block; height: 1em; vertical-align: -0.25em;"></span><span class="mopen" style="box-sizing: border-box;"></span><span class="mord" style="box-sizing: border-box;"></span><span class="mspace" style="box-sizing: border-box; display: inline-block; margin-right: 0.222222em;"></span><span class="mbin" style="box-sizing: border-box;"></span><span class="mspace" style="box-sizing: border-box; display: inline-block; margin-right: 0.222222em;"></span></span><span class="base" style="box-sizing: border-box; position: relative; white-space: nowrap; width: min-content; display: inline-block;"><span class="strut" style="box-sizing: border-box; display: inline-block; height: 0.74285em; vertical-align: -0.08333em;"></span><span class="mord mathdefault" style="box-sizing: border-box; font-family: KaTeX_Math; font-style: italic;"></span><span class="mspace" style="box-sizing: border-box; display: inline-block; margin-right: 0.222222em;"></span><span class="mbin" style="box-sizing: border-box;"></span><span class="mspace" style="box-sizing: border-box; display: inline-block; margin-right: 0.222222em;"></span></span><span class="base" style="box-sizing: border-box; position: relative; white-space: nowrap; width: min-content; display: inline-block;"><span class="strut" style="box-sizing: border-box; display: inline-block; height: 1em; vertical-align: -0.25em;"></span><span class="mord" style="box-sizing: border-box;"></span><span class="mclose" style="box-sizing: border-box;"></span></span></span></span></details>

![Children for a specific node are located at well defined indexes](https://leetcode.com/articles/Figures/segtree_intro_2.png)

Segment trees are very intuitive and easy to use when built recursively.

## TODO

zhihu [LeetCode . 线段树专题](https://zhuanlan.zhihu.com/p/85846796)

zhihu [线段树(Segment Tree)(上)](https://zhuanlan.zhihu.com/p/436326746)

zhihu [线段树(Segment Tree)专题](https://zhuanlan.zhihu.com/p/40151999)

zhihu [线段树（segment tree)、区间树(interval tree)](https://zhuanlan.zhihu.com/p/105368572)
# cs166.1196 [Building Suffix Arrays](https://web.stanford.edu/class/archive/cs/cs166/cs166.1196/lectures/04/Small04.pdf) 

[Slides04](https://web.stanford.edu/class/archive/cs/cs166/cs166.1196/lectures/04/Slides04.pdf)

[Small04](https://web.stanford.edu/class/archive/cs/cs166/cs166.1196/lectures/04/Small04.pdf)



## Key Intuition(Page-3)

The efficiency in a suffix tree is largely due to 

1. keeping the suffixes in sorted order, and 
2. exposing branching words.

## New Stuff!(Page-8)

## Suffix tree = suffix array + LCP array(Page-10~16)

> NOTE:
>
> 一、原文的这一大段所讲述的是suffix tree和suffix array + LCP array的对应关系，结论在 Page11 中



![](./DFS-Patricia-tree.png)

> NOTE:
>
> 一、DFS Patricia tree
>
> 上图非常地揭示了suffix tree 和 suffix array+LCP array的对应关系，细致入微。

### Suffix tree和suffix array + LCP array的相互转换(Page11)

![](./suffix-tree=suffix-array+LCP-array.png)

#### Page-12~16

原文这一大段是在结合具体的例子说明suffix tree = suffix array + LCP array。

## A Linear-Time Algorithm(Page-17)

> NOTE:
>
> 一、原文这一段所描述的是从 suffix array + LCP array 构建 suffix tree:
>
> suffix array->LCP array->Cartesian tree

- Construct the **LCP array** for the **suffix array**.
- Construct a **Cartesian tree** from that **LCP array**.
- Run a DFS over the **Cartesian tree**, adding in the suffixes in the order they appear whenever a node has a missing child.
- Fuse together any parent and child nodes with the same number in them.
- Assign labels to the edges based on the LCP values.
- Total time: O(m).



## Constructing Suffix Arrays(Page-18)

### The Timeline(Page-19~28)

原文这里按照时间顺序罗列了关于suffix tree、suffix array、LCP array的各种算法。



### Some Observations about Suffix Arrays(Page-29~42)

Observation: We can partition the suffix array into ***buckets***, where each bucket consists of all suffixes starting with the same first character

### S-type suffix(Page-43)

We'll call the suffix at position 4 an S-type suffix (S for smaller), since it lexicographically precedes the suffix at the position immediately after it.

![](./S-type-suffix-example.png)

### L-type suffix(Page-51)

![](./L-type-suffix-example.png)



### Base case: sentinel(Page-73)

By definition, the suffix starting at the sentinel is considered an **S-type suffix**. 

![](./sentinel-S-type-suffix.png)

### S-type suffix、L-type suffix definition(Page-75~96)

![](./S-type-suffix-L-type-suffix-theorem.png)

We can tag each suffix as **S-type** or **L-type** in time O(m) by scanning Text from **right-to-left** and applying the above rules.

>  NOTE:
>
> 一、典型的recursive definition。



### Sort bucket by S-type、L-type

> NOTE:
>
> 一、
>
> inter-bucket sorting: 根据starting character即可
>
> inner-bucket sorting: 根据S-type、L-type可以大致排出相对位置

![](./inner-bucket-sorting-by-S-type-L-type-theorem.png)



> NOTE:
>
> 一、在同一个bucket内，显然它们的starting character是相同的，那么大小就由后面的substring决定了，S-type、L-type所表示的就是starting character和它后面的character 之间的大小关系，显然:
>
> - 如果是L-type，那么显然后面的character比starting character要小，显然在bucket内部要排在前面
> - 如果是S-type，那么显然后面的character比starting character要大，显然在bucket内部要排在后面

#### Example1(Page-113)

![](./inner-bucket-sorting-by-S-type-L-type-example-1.png)



#### Example2(Page-120)

![](./inner-bucket-sorting-by-S-type-L-type-example-2.png)



## Where We Stand(Page-128)

1. We can efficiently classify each suffix as either S-type or L-type in time O(m).
2. We know a good amount about the relative positioning of the suffixes:
   1. All suffixes are bucketed by their first character.
   2. All L-type suffixes come before all S-type suffixes.
3. If we can get everything relatively positioned within its group, we’re done!



## SA-IS at a Glance(Page-129)

There are three core insights that collectively give us the SA-IS algorithm.

First: There is a proper subset of the suffixes that, if sorted, can be used to recover the order of all the remaining suffixes.

> NOTE:
>
> 一、从后面的内容可知: LMS suffixes

Second: Those suffixes can be broken apart into **blocks** of characters such that the order of the suffixes depends purely on the order of the **blocks**.

Third: With the proper preprocessing, those suffixes can be sorted via a recursive call on a smaller input string.

### First(Page-133)

#### LMS suffixes(Page-133)

These suffixes are called LMS suffixes (LeftMost S-type). A suffix is an LMS suffix if it’s S-type and the suffix before it is L-type.

![](./LMS-suffixes.png)



Key Theorem: If we can get the LMS suffixes - and just the LMS suffixes - in sorted order, then we can, in time O(m), get all the other suffixes in order as well.

The algorithm for doing this is called induced sorting. This is the "IS" in SA-IS.

#### LMS suffixes sorting(Page-133)



![](./K-way-merge-LMS-suffixes-example-1.png)



#### Induced sorting

Key Theorem: If we can get the **LMS suffixes** – and just the LMS suffixes – in sorted order, then we can, in time O(m), get all the other suffixes in order as well.

The algorithm for doing this is called **induced sorting**. This is the “IS” in SA-IS.

This is a multiway merge! Each list is sorted, and we want to unify them all together.
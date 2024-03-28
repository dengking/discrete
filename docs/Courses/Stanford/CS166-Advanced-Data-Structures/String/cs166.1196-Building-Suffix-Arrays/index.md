# cs166.1196 [Building Suffix Arrays](https://web.stanford.edu/class/archive/cs/cs166/cs166.1196/lectures/04/Small04.pdf) 

[Slides04](https://web.stanford.edu/class/archive/cs/cs166/cs166.1196/lectures/04/Slides04.pdf)

[Small04](https://web.stanford.edu/class/archive/cs/cs166/cs166.1196/lectures/04/Small04.pdf)



## Key Intuition(Page-3)

The efficiency in a suffix tree is largely due to 

1. keeping the suffixes in sorted order, and 
2. exposing branching words.

## New Stuff!(Page-8)

![](./DFS-Patricia-tree.png)

> NOTE:
>
> 一、DFS Patricia tree
>
> 上图非常地揭示了suffix tree 和 suffix array+LCP array的对应关系，细致入微。

## Suffix Arrays(Page-4)

### Storing Suffix Arrays(Page-5)



## LCP Arrays(Page-6)



## Runtime Analysis(Page-7)



## Constructing Suffix Arrays(Page-16)



### Some Observations about Suffix Arrays(Page-19)

Observation: We can partition the suffix array into ***buckets***, where each bucket consists of all suffixes starting with the same first character



## Where We Stand(Page-31)

1. We can efficiently classify each suffix as either S-type or L-type in time O(m).
2. We know a good amount about the relative positioning of the suffixes:
   1. All suffixes are bucketed by their first character.
   2. All L-type suffixes come before all S-type suffixes.
3. If we can get everything relatively positioned within its group, we’re done!



## SA-IS at a Glance(Page-32)

There are three core insights that collectively give us the SA-IS algorithm.

First: There is a proper subset of the suffixes that, if sorted, can be used to recover the order of all the remaining suffixes.



### First(Page-33)

#### LMS suffixes

These suffixes are called LMS suffixes (LeftMost S-type). A suffix is an LMS suffix if it’s S-type and the suffix before it is L-type.



#### Induced sorting

Key Theorem: If we can get the **LMS suffixes** – and just the LMS suffixes – in sorted order, then we can, in time O(m), get all the other suffixes in order as well.

The algorithm for doing this is called **induced sorting**. This is the “IS” in SA-IS.

This is a multiway merge! Each list is sorted, and we want to unify them all together.
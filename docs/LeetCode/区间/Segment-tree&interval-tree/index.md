# Segment tree、interval tree、Fenwick tree

segment=线段

interval=区间



## stackoverflow [What are the differences between segment trees, interval trees, binary indexed trees and range trees?](https://stackoverflow.com/questions/17466218/what-are-the-differences-between-segment-trees-interval-trees-binary-indexed-t)



### [A](https://stackoverflow.com/a/17504505)

All these data structures are used for solving different problems:

1、**Segment tree** stores intervals, and optimized for "*which of these intervals contains a given point*" queries.

2、**Interval tree** stores intervals as well, but optimized for "*which of these intervals overlap with a given interval*" queries. It can also be used for point queries - similar to segment tree.

3、**Range tree** stores points, and optimized for "*which points fall within a given interval*" queries.

4、**Binary indexed tree** stores items-count per index, and optimized for "*how many items are there between index m and n*" queries.



## stackoverflow [Fenwick tree vs Segment tree](https://stackoverflow.com/questions/64190332/fenwick-tree-vs-segment-tree)
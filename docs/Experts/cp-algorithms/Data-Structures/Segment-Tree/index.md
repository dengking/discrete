# cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)



### [Generalization to higher dimensions](https://cp-algorithms.com/data_structures/segment_tree.html#generalization-to-higher-dimensions)

A Segment Tree can be generalized quite natural to higher dimensions. If in the one-dimensional case we split the indices of the array into **segments**, then in the two-dimensional we make an ordinary **Segment Tree** with respect to the first indices, and for each segment we build an ordinary Segment Tree with respect to the second indices.

#### Simple 2D Segment Tree

So we build a 2D Segment Tree: first the Segment Tree using the first coordinate (  $x$ ), then the second (  $y$ ).

# cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)

A Segment Tree is a data structure that stores information about array intervals as a tree. This allows answering range queries over an array efficiently, while still being flexible enough to allow quick modification of the array. This includes finding the sum of consecutive array elements $a[l \dots r]$ , or finding the minimum element in a such a range in  $O(\log n)$  time. Between answering such queries, the Segment Tree allows modifying the array by replacing one element, or even changing the elements of a whole subsegment (e.g. assigning all elements  $a[l \dots r]$  to any value, or adding a value to all element in the subsegment).

> NOTE:
>
> 一、segment tree是否只能够建立于array之上？

In general, a Segment Tree is a very flexible data structure, and a huge number of problems can be solved with it. Additionally, it is also possible to apply more complex operations and answer more complex queries (see Advanced versions of Segment Trees). In particular the Segment Tree can be easily generalized to larger dimensions. For instance, with a two-dimensional Segment Tree you can answer sum or minimum queries over some subrectangle of a given matrix in only  $O(\log^2 n)$  time.



One important property of Segment Trees is that they require only a linear amount of memory. The standard Segment Tree requires  $4n$  vertices for working on an array of size  $n$ .



## [Advanced versions of Segment Trees](https://cp-algorithms.com/data_structures/segment_tree.html#advanced-versions-of-segment-trees)

### More complex queries

It can be quite easy to change the Segment Tree in a direction, such that it computes different queries (e.g. computing the minimum / maximum instead of the sum), but it also can be very nontrivial.

#### Finding the maximum

Let us slightly change the condition of the problem described above: instead of querying the sum, we will now make maximum queries.

The tree will have exactly the same structure as the tree described above. We only need to change the way $t[v]$  is computed in the  $\text{build}$  and  $\text{update}$  functions. $t[v]$  will now store the maximum of the corresponding segment. And we also need to change the calculation of the returned value of the  $\text{sum}$  function (replacing the summation by the maximum).

Of course this problem can be easily changed into computing the minimum instead of the maximum.

Instead of showing an implementation to this problem, the implementation will be given to a more complex version of this problem in the next section.

#### Finding the maximum and the number of times it appears

This task is very similar to the previous one. In addition of finding the maximum, we also have to find the number of occurrences of the maximum.

```c++
#include<utility>
#include<algorithm>
#include<float.h>

using namespace std;
pair<int, int> t[4 * MAXN];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first)
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

/**
 *
 * @param a array
 * @param v vertex of root node
 * @param tl left
 * @param tr right
 */
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2; // middle
    return combine(get_max(v * 2, tl, tm, l, min(r, tm)),
                   get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

/**
 * update array[pos] to be new_val
 * @param v vertex of root node
 * @param tl
 * @param tr
 * @param pos
 * @param new_val
 */
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}
```

#### Compute the greatest common divisor / least common multiple

> NOTE:
>
> 一、最大公约数
>
> 二、最小公倍数

In this problem we want to compute the GCD / LCM of all numbers of given ranges of the array.

This interesting variation of the Segment Tree can be solved in exactly the same way as the Segment Trees we derived for sum / minimum / maximum queries: it is enough to store the GCD / LCM of the corresponding vertex in each vertex of the tree. Combining two vertices can be done by computing the GCD / LCM of both vertices.

#### Counting the number of zeros, searching for the  $k$ -th zero



### [Generalization to higher dimensions](https://cp-algorithms.com/data_structures/segment_tree.html#generalization-to-higher-dimensions)

A Segment Tree can be generalized quite natural to higher dimensions. If in the one-dimensional case we split the indices of the array into **segments**, then in the two-dimensional we make an ordinary **Segment Tree** with respect to the first indices, and for each segment we build an ordinary Segment Tree with respect to the second indices.

#### Simple 2D Segment Tree

So we build a 2D Segment Tree: first the Segment Tree using the first coordinate (  $x$ ), then the second (  $y$ ).

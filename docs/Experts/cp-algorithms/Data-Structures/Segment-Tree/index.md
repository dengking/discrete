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
>
> 三、
>
> [geeksforgeeks-Range LCM Queries](https://www.geeksforgeeks.org/range-lcm-queries/) 
>
> [quora-**How can you find the LCM of numbers in a given range [l,r] in an array of size n?**](https://www.quora.com/How-can-you-find-the-LCM-of-numbers-in-a-given-range-l-r-in-an-array-of-size-n) 

In this problem we want to compute the GCD / LCM of all numbers of given ranges of the array.

This interesting variation of the **Segment Tree** can be solved in exactly the same way as the **Segment Trees** we derived for sum / minimum / maximum queries: it is enough to store the GCD / LCM of the corresponding vertex in each vertex of the tree. Combining two vertices can be done by computing the GCD / LCM of both vertices. 



#### Counting the number of zeros, searching for the  $k$ -th zero

In this problem we want to find the number of zeros in a given range, and additionally find the index of the  
$k$ -th zero using a second function.

Again we have to change the store values of the tree a bit: This time we will store the number of zeros in each segment in  
$t[]$ . It is pretty clear, how to implement the   $\text{build}$ ,   $\text{update}$  and  $\text{count\_zero}$  functions, we can simply use the ideas from the sum query problem. Thus we solved the first part of the problem.

Now we learn how to solve the problem of finding the $k$ -th zero in the array $a[]$ . To do this task, we will descend the Segment Tree, starting at the root vertex, and moving each time to either the left or the right child, depending on which segment contains the $k$ -th zero. In order to decide to which child we need to go, it is enough to look at the number of zeros appearing in the segment corresponding to the left vertex. If this precomputed count is greater or equal to $k$ , it is necessary to descend to the left child, and otherwise descent to the right child. Notice, if we chose the right child, we have to subtract the number of zeros of the left child from $k$ .

In the implementation we can handle the special case,  $a[]$  containing less than $k$  zeros, by returning -1.

```c++
int find_kth(int v, int tl, int tr, int k) {
    if (k > t[v])
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (t[v*2] >= k)
        return find_kth(v*2, tl, tm, k);
    else 
        return find_kth(v*2+1, tm+1, tr, k - t[v*2]);
}
```

#### Searching for an array prefix with a given amount

The task is as follows: for a given value $x$  we have to quickly find smallest index $i$  such that the sum of the first $i$  elements of the array $a[]$  is greater or equal to $x$  (assuming that the array $a[]$  only contains non-negative values).

This task can be solved using binary search, computing the sum of the prefixes with the **Segment Tree**. However this will lead to a $O(\log^2 n)$  solution.

Instead we can use the same idea as in the previous section, and find the position by descending the tree: by moving each time to the left or the right, depending on the sum of the left child. Thus finding the answer in $O(\log n)$  time.

> NOTE:
>
> 一、是指前面的 "Counting the number of zeros, searching for the  $k$ -th zero" 中描述的方法？

#### Searching for the first element greater than a given amount

The task is as follows: for a given value $x$  and a range $a[l \dots r]$  find the smallest $i$  in the range $a[l \dots r]$ , such that $a[i]$  is greater than $x$ .

This task can be solved using binary search over max prefix queries with the Segment Tree. However, this will lead to a $O(\log^2 n)$  solution.

Instead, we can use the same idea as in the previous sections, and find the position by descending the tree: by moving each time to the left or the right, depending on the maximum value of the left child. Thus finding the answer in $O(\log n)$  time.

```c++
int get_first(int v, int lv, int rv, int l, int r, int x) {
    if(lv > r || rv < l) return -1;
    if(l <= lv && rv <= r) {
        if(t[v] <= x) return -1;
        while(lv != rv) {
            int mid = lv + (rv-lv)/2;
            if(t[2*v] > x) {
                v = 2*v;
                rv = mid;
            }else {
                v = 2*v+1;
                lv = mid+1;
            }
        }
        return lv;
    }

    int mid = lv + (rv-lv)/2;
    int rs = get_first(2*v, lv, mid, l, r, x);
    if(rs != -1) return rs;
    return get_first(2*v+1, mid+1, rv, l ,r, x);
}
```

#### Finding subsegments with the maximal sum



How to build a tree with such data? Again we compute it in a recursive fashion: we first compute all four values for the left and the right child, and then combine those to archive the four values for the current vertex. Note the answer for the current vertex is either:

### Saving the entire subarrays in each vertex

This is a separate subsection(部分) that stands apart from the others, because at each vertex of the **Segment Tree** we don't store information about the corresponding segment in compressed form (sum, minimum, maximum, ...), but store all elements of the segment. Thus the root of the Segment Tree will store all elements of the array, the left child vertex will store the first half of the array, the right vertex the second half, and so on.

In its simplest application of this technique we store the elements in sorted order. In more complex versions the elements are not stored in lists, but more advanced data structures (sets, maps, ...). But all these methods have the common factor, that each vertex requires linear memory (i.e. proportional to the length of the corresponding segment).

The first natural question, when considering these Segment Trees, is about memory consumption. Intuitively this might look like $O(n^2)$  memory, but it turns out that the complete tree will only need $O(n \log n)$  memory. Why is this so? Quite simply, because each element of the array falls into $O(\log n)$  segments (remember the height of the tree is $O(\log n)$ ).

So in spite of the apparent extravagance of such a **Segment Tree**, it consumes only slightly more memory than the usual **Segment Tree**.

Several typical applications of this data structure are described below. It is worth noting the similarity of these **Segment Trees** with 2D data structures (in fact this is a 2D data structure, but with rather limited capabilities).





### [Generalization to higher dimensions](https://cp-algorithms.com/data_structures/segment_tree.html#generalization-to-higher-dimensions)

A **Segment Tree** can be generalized quite natural to higher dimensions. If in the one-dimensional case we split the indices of the array into **segments**, then in the two-dimensional we make an ordinary **Segment Tree** with respect to the first indices, and for each segment we build an ordinary **Segment Tree** with respect to the second indices.



#### Simple 2D Segment Tree

A matrix $a[0 \dots n-1, 0 \dots m-1]$  is given, and we have to find the sum (or minimum/maximum) on some submatrix   $a[x_1 \dots x_2, y_1 \dots y_2]$ , as well as perform modifications of individual matrix elements (i.e. queries of the form   $a[x][y] = p$ ).

> NOTE:
>
> 一、$a[0 \dots n-1, 0 \dots m-1]$ 表示matrix是 $m \times n$ 

So we build a 2D **Segment Tree**: first the **Segment Tree** using the first coordinate (  $x$ ), then the second (  $y$ ).

To make the construction process more understandable, you can forget for a while that the matrix is two-dimensional, and only leave the first coordinate. We will construct an ordinary one-dimensional **Segment Tree** using only the first coordinate. But instead of storing a number in a segment, we store an entire **Segment Tree**: i.e. at this moment we remember that we also have a second coordinate; but because at this moment the first coordinate is already fixed to some interval   $[l \dots r]$ , we actually work with such a strip   $a[l \dots r, 0 \dots m-1]$  and for it we build a **Segment Tree**.

Here is the implementation of the construction of a **2D Segment Tree**. It actually represents two separate blocks: the construction of a **Segment Tree** along the $x$  coordinate ( $\text{build}_x$ ), and the $y$  coordinate ( $\text{build}_y$ ). For the leaf nodes in $\text{build}_y$  we have to separate two cases: when the current segment of the first coordinate   $[tlx \dots trx]$  has length 1, and when it has a length greater than one. In the first case, we just take the corresponding value from the matrix, and in the second case we can combine the values of two **Segment Trees** from the left and the right son in the coordinate   $x$ .

##### Build

```c++
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m-1);
}
```

Such a **Segment Tree** still uses a linear amount of memory, but with a larger constant: $16 n m$ . It is clear that the described procedure $\text{build}_x$  also works in linear time.

##### Query

Now we turn to processing of queries. We will answer to the two-dimensional query using the same principle: first break the query on the first coordinate, and then for every reached vertex, we call the corresponding **Segment Tree** of the second coordinate.

```c++
int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
         + sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y(vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
         + sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
}
```

This function works in $O(\log n \log m)$  time, since it first descends the tree in the first coordinate, and for each traversed vertex in the tree it makes a query in the corresponding **Segment Tree** along the second coordinate.

##### Modify

Finally we consider the modification query. We want to learn how to modify the Segment Tree in accordance with the change in the value of some element $a[x][y] = p$ . It is clear, that the changes will occur only in those vertices of the first Segment Tree that cover the coordinate $x$  (and such will be
$O(\log n)$ ), and for Segment Trees corresponding to them the changes will only occurs at those vertices that covers the coordinate  
$y$  (and such will be  
$O(\log m)$ ). Therefore the implementation will be not very different form the one-dimensional case, only now we first descend the first coordinate, and then the second.

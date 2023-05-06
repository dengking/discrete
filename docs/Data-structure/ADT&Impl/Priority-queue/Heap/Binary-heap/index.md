# Binary heap



## wikipedia [Binary heap](https://en.wikipedia.org/wiki/Binary_heap)

A **binary heap** is a [heap](https://en.wikipedia.org/wiki/Heap_(data_structure)) [data structure](https://en.wikipedia.org/wiki/Data_structure) that takes the form of a [binary tree](https://en.wikipedia.org/wiki/Binary_tree). Binary heaps are a common way of implementing [priority queues](https://en.wikipedia.org/wiki/Priority_queue).[[1\]](https://en.wikipedia.org/wiki/Binary_heap#cite_note-clrs-1): 162–163  The binary heap was introduced by [J. W. J. Williams](https://en.wikipedia.org/wiki/J._W._J._Williams) in 1964, as a data structure for [heapsort](https://en.wikipedia.org/wiki/Heapsort).

A binary heap is defined as a binary tree with two additional constraints:[[3\]](https://en.wikipedia.org/wiki/Binary_heap#cite_note-3)

1、**Shape property**: a binary heap is a *[complete binary tree](https://en.wikipedia.org/wiki/Complete_binary_tree)*; that is, all levels of the tree, except possibly the last one (deepest) are fully filled, and, if the last level of the tree is not complete, the nodes of that level are filled from left to right.

2、**Heap property**: the key stored in each node is either greater than or equal to (≥) or less than or equal to (≤) the keys in the node's children, according to some [total order](https://en.wikipedia.org/wiki/Total_order).

> NOTE:
>
> 一、思考：为什么按照这种方式存储元素能够保证下标的连续
>
> ![](./binary-heap.jpg)
>
> 这是由binary heap的"Shape property"而决定的，它是完全二叉树-> $2^n$ ，从上面的例子可以看出它们具有非常好的数学对应关系，这非常简单而强大
>
> 二、heap的complexity也是由它的"Shape property"而决定的
>
> 三、heap的"Shape property"保证了heap是"balanced"



Heaps：

1、where the parent key is greater than or equal to (≥) the child keys are called *max-heaps*; 

2、where it is less than or equal to (≤) are called *min-heaps*. 

Efficient ([logarithmic time](https://en.wikipedia.org/wiki/Logarithmic_time)) algorithms are known for the two operations needed to implement a priority queue on a binary heap: inserting an element, and removing the smallest or largest element from a min-heap or max-heap, respectively. 

Binary heaps are also commonly employed in the [heapsort](https://en.wikipedia.org/wiki/Heapsort) [sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm), which is an in-place algorithm because binary heaps can be implemented as an [implicit data structure](https://en.wikipedia.org/wiki/Implicit_data_structure), storing keys in an array and using their relative positions within that array to represent child–parent relationships.



### Heap operations

Both the insert and remove operations modify the heap to conform to the **shape property** first, by adding or removing from the end of the heap. Then the **heap property** is restored by traversing up or down the heap. Both operations take O(log *n*) time.

> NOTE:
>
> 一、这段话总结得非常好，它其实给出了编码实现的一个重要的思路
>
> 二、它的complexity是由树高所决定的



#### Insert

To add an element to a heap, we can perform this algorithm:

1、Add the element to the bottom level of the heap at the leftmost open space.

2、Compare the added element with its parent; if they are in the correct order, stop.

3、If not, swap the element with its parent and return to the previous step.

Steps 2 and 3, which restore the heap property by comparing and possibly swapping a node with its parent, are called *the up-heap* operation (also known as *bubble-up*, *percolate-up*, *sift-up*, *trickle-up*, *swim-up*, *heapify-up*, or *cascade-up*).

#### Extract

The procedure for deleting the root from the heap (effectively extracting the maximum element in a max-heap or the minimum element in a min-heap) while retaining the heap property is as follows:

1、Replace the root of the heap with the last element on the last level.

2、Compare the new root with its children; if they are in the correct order, stop.

3、If not, swap the element with one of its children and return to the previous step. (Swap with its smaller child in a min-heap and its larger child in a max-heap.)

Steps 2 and 3, which restore the heap property by comparing and possibly swapping a node with one of its children, are called the *down-heap* (also known as *bubble-down*, *percolate-down*, *sift-down*, *sink-down*, *trickle down*, *heapify-down*, *cascade-down*, *extract-min* or *extract-max*, or simply *heapify*) operation.

```pseudocode
// Perform a down-heap or heapify-down operation for a max-heap
// A: an array representing the heap, indexed starting at 1
// i: the index to start at when heapifying down
Max-Heapify(A, i):
    left ← 2×i
    right ← 2×i + 1
    largest ← i
    
    if left ≤ length(A) and A[left] > A[largest] then:
        largest ← left

    if right ≤ length(A) and A[right] > A[largest] then:
        largest ← right
    
    if largest ≠ i then:
        swap A[i] and A[largest]
        Max-Heapify(A, largest)
```

#### Insert then extract

Inserting an element then extracting from the heap can be done more efficiently than simply calling the insert and extract functions defined above, which would involve both an `upheap` and `downheap` operation. Instead, we can do just a `downheap` operation, as follows:



#### Search

Finding an arbitrary element takes O(n) time.

#### Delete

TODO

#### Decrease or increase key

TODO

### Building a heap

#### Williams' method

Building a heap from an array of *n* input elements can be done by starting with an empty heap, then successively inserting each element. This approach, called Williams' method after the inventor of binary heaps, is easily seen to run in *O*(*n* log *n*) time: it performs *n* insertions at *O*(log *n*) cost each.

#### [Floyd](https://en.wikipedia.org/wiki/Robert_W._Floyd)'s method

Williams' method is suboptimal. A faster method (due to [Floyd](https://en.wikipedia.org/wiki/Robert_W._Floyd)[[8\]](https://en.wikipedia.org/wiki/Binary_heap#cite_note-heapbuildjalg-8)) starts by arbitrarily putting the elements on a **binary tree**, respecting the **shape property** (the tree could be represented by an array, see below). Then starting from the lowest level and moving upwards, sift the root of each subtree downward as in the deletion algorithm until the heap property is restored. More specifically if all the subtrees starting at some height $h$ have already been "heapified" (the bottommost level corresponding to ℎ=0![h=0](https://wikimedia.org/api/rest_v1/media/math/render/svg/ffe239e1050529410001cc1c0b3245945bc69709)), the trees at height ℎ+1![h+1](https://wikimedia.org/api/rest_v1/media/math/render/svg/d6bdac90f1b229b8d6c70a3f207926e61c5c68f3) can be heapified by sending their root down along the path of maximum valued children when building a max-heap, or minimum valued children when building a min-heap.



### Derivation of index equations



## Code

### Java

labuladong [图文详解二叉堆，实现优先级队列](https://mp.weixin.qq.com/s/o7tdyLiYm668dpUWd-x7Lg)

其中对heap的实现，进行了非常好的描述，完整的Java代码如下:

```Java
public class MaxPQ < Key extends Comparable < Key >> {
    // 存储元素的数组
    private Key[] pq;
    // 当前priority queue中的元素个数
    private int N = 0;
    public MaxPQ(int cap) {
        pq = (Key[]) new Comparable[cap + 1];
    }
    /**
     * 返回当前队列中的最大元素
     */
    public Key max() {
        return pq[1];
    }
    /**
     * 插入元素e
     */
    public void insert(Key e) {
        N++;
        // 先把新元素加到最后
        pq[N] = e;
        // 然后让它上浮到正确的位置
        swim(N);
    }
    /**
     * 删除并返回当前队列中的最大元素
     */
    public Key delMax() {
        // 最大堆的堆顶就是最大元素
        Key max = pq[1];
        // 把这个最大元素换到最后，删除之
        exch(1, N);
        pq[N] = null;
        N--;
        // 让 pq[1] 下沉到正确位置
        sink(1);
        return max;
    }
    /**
     * 上浮第k个元素，以维护最大堆性质
     */
    private void swim(int k) {
        // 如果浮到栈顶，就不能再上浮了
        while (k > 1 && less(parent(k), k)) {
            // 如果第k个元素比上层大
            // 将k换上去
            exch(parent(k), k);
            k = parent(k); // 迭代
        }
    }
    /**
     * 下沉第k个元素，以维护最大堆性质
     */
    private void sink(int k) {
        // 如果沉到堆底，就沉不下去了
        while (left(k) <= N) {
            // 先假设左边的节点较大
            int older = left(k);
            // 如果右边的节点存在，比一下大小
            if (right(k) <= N && less(older, right(k)))
                older = right(k);
            // 节点 k 比俩孩子都大，就不必下沉了
            if (less(older, k)) break;
            // 否则，不符合最大堆的结构，下沉 k 节点
            exch(k, older);
            k = older; // 迭代
        }
    }
    /**
     * 交换数组中的两个元素
     */
    private void exch(int i, int j) {
        Key temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }
    /**
     * pq[i] 是否比 pq[j] 小
     */
    private boolean less(int i, int j) {
        return pq[i].compareTo(pq[j]) < 0;
    }
    // 父节点的索引
    private int parent(int root) {
        return root / 2;
    }
    // 左孩子的索引
    private int left(int root) {
        return root * 2;
    }
    // 右孩子的索引
    private int right(int root) {
        return root * 2 + 1;
    }
};

```


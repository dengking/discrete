# Heap(data structure)

参考文章:

1、infogalactic [Heap (data structure)](https://infogalactic.com/info/Heap_(data_structure))

2、labuladong [图文详解二叉堆，实现优先级队列](https://mp.weixin.qq.com/s/o7tdyLiYm668dpUWd-x7Lg)

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



## wikipedia [Heap (data structure)](https://en.wikipedia.org/wiki/Heap_(data_structure))



## wikipedia [Binary heap](https://en.wikipedia.org/wiki/Binary_heap)

> NOTE:
>
> 1、https://infogalactic.com/info/Binary_heap
>
> 2、内容和 infogalactic [Heap (data structure)](https://infogalactic.com/info/Heap_(data_structure)) 中的有些重复
>
> 



## TODO

wikipedia [Fibonacci heap](https://en.wikipedia.org/wiki/Fibonacci_heap)

wikipedia [Binomial heap](https://en.wikipedia.org/wiki/Binomial_heap)


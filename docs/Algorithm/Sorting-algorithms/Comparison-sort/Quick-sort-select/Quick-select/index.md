# Quick select

参考内容:

1、labuladong [快排亲兄弟：快速选择算法详解](https://mp.weixin.qq.com/s/TRO3FOKT90Mpvn3hQWVBAQ) 	

2、wikipedia [Quickselect](https://en.wikipedia.org/wiki/Quickselect) 



## wikipedia [Quickselect](https://en.wikipedia.org/wiki/Quickselect) 



```pseudocode
// Returns the k-th smallest element of list within left..right inclusive
// (i.e. left <= k <= right).
function select(list, left, right, k) is
    if left = right then   // If the list contains only one element,
        return list[left]  // return that element
    pivotIndex  := ...     // select a pivotIndex between left and right,
                           // e.g., left + floor(rand() % (right − left + 1))
    pivotIndex  := partition(list, left, right, pivotIndex)
    // The pivot is in its final sorted position
    if k = pivotIndex then
        return list[k]
    else if k < pivotIndex then
        return select(list, left, pivotIndex − 1, k)
    else
        return select(list, pivotIndex + 1, right, k) 
```



## C++

```c++
#include<iostream>

int RandomizedPartition(int a[], int p, int r) {
    int i = Random(p, r);
    std::swap(a[i], a[p]);
    return Patiton(a, p, r);
}

/**
 * 元素选择问题：查找序列a中第k大的元素，p是起始下标，r是终止下标
 * @param a
 * @param p
 * @param r
 * @param k
 * @return
 */
int RandomizedSelect(int a[], int p, int r, int k) {
    //如果仅有一个元素，则第k大的元素就是这个元素
    if (p == r) return a[p];
    int i = RandomizedPartition(a, p, r);//首先随机地对a中元素进行分组，返回基准的下标
    int j = i - p + 1;//从a[p]到a[i]的长度，表示有多少个元素比a[i]小
    if (k <= j) {
        //如果k比j要小，则k肯定出现在i的左半段。注意此处千万要和快速排序的函数区分开来：此处i必须为i，切记写成i-1.因为需要求的是第k小的元素，前面的判断条件是k〈=j，如果k=j，那么a[i]即为所求
        return RandomizedSelect(a, p, i, k);
    } else {
        return RandomizedSelect(a, i, k, k - j);
    }
}
```


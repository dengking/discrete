[TOC]

# [Bubble Sort](https://www.hackerearth.com/zh/practice/algorithms/sorting/bubble-sort/tutorial/)


bubble sort每次找出剩余元素中最大或最小的，它的实现方式是让剩余的所有未排序的元素进行打擂台（相邻两个元素两两进行比较，较大者），从而找出这些元素中，最大的或最小的。显然对于`n`个元素，只需要找出前`n-1`个最大或最小的元素，剩下的那个就是最小的或最大的；

```
void bubble_sort( int A[ ], int n ) {
    int temp;
    for(int k = 0; k< n-1; k++) {
        // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

        for(int i = 0; i < n-k-1; i++) {
            if(A[ i ] > A[ i+1] ) {
                // here swapping of positions is being done.
                temp = A[ i ];
                A[ i ] = A[ i+1 ];
                A[ i + 1] = temp;
            }
        }
    }
}
```
在实现上，它使用的是嵌套循环，外层的循环表示寻找第`k`大或第`k`小的元素，内层循环则是使用打擂台的方式寻找出第`k`的或第`k`小的元素（这就是冒泡的过程）；显然外层循环决定了内存循环的数据范围；

该算法是最最简单的基于遍历的算法；
```
void bubble_sort(int arr[], int n){
    int temp = 0;
    int count = 0;
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
```
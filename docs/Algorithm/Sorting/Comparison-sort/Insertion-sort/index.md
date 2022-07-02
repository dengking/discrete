# Insertion sort

"insertion sort"即 "插入排序"。

对于insertion sort而言，寻找"插入点"是关键。

## LeetCode 147 [对链表进行插入排序](https://leetcode.cn/problems/insertion-sort-list/solution/dui-lian-biao-jin-xing-cha-ru-pai-xu-by-leetcode-s/)

插入排序的基本思想是，维护一个有序序列，初始时有序序列只有一个元素，每次将一个新的元素插入到有序序列中，将有序序列的长度增加 11，直到全部元素都加入到有序序列中。

> NOTE: 
>
> 总结得非常好



## wikipedia [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)

**Insertion sort** is a simple [sorting algorithm](https://infogalactic.com/info/Sorting_algorithm) that builds the final [sorted array](https://infogalactic.com/info/Sorted_array) (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as [quicksort](https://infogalactic.com/info/Quicksort), [heapsort](https://infogalactic.com/info/Heapsort), or [merge sort](https://infogalactic.com/info/Merge_sort). However, insertion sort provides several advantages:

1、Simple implementation: [Bentley](https://infogalactic.com/info/Jon_Bentley) shows a three-line [C](https://infogalactic.com/info/C_(programming_language)) version, and a five-line optimized version

2、Efficient for (quite) small data sets, much like other quadratic sorting algorithms

3、More efficient in practice than most other simple quadratic (i.e., [O](https://infogalactic.com/info/Big_O_notation)(*n*2)) algorithms such as [selection sort](https://infogalactic.com/info/Selection_sort) or [bubble sort](https://infogalactic.com/info/Bubble_sort)

4、[Adaptive](https://infogalactic.com/info/Adaptive_sort), i.e., efficient for data sets that are already substantially sorted: the [time complexity](https://infogalactic.com/info/Time_complexity) is *O*(*nk*) when each element in the input is no more than *k* places away from its sorted position

5、[Stable](https://infogalactic.com/info/Stable_sort); i.e., does not change the relative order of elements with equal keys

6、[In-place](https://infogalactic.com/info/In-place_algorithm); i.e., only requires a constant amount O(1) of additional memory space

7、[Online](https://infogalactic.com/info/Online_algorithm); i.e., can sort a list as it receives it

## baike [插入排序](https://baike.baidu.com/item/%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F/7214992?fr=aladdin#4)



## Source code

### LeetCode [复习基础排序算法（Java）](https://leetcode.cn/problems/sort-an-array/solution/fu-xi-ji-chu-pai-xu-suan-fa-java-by-liweiwei1419/)

#### Java

```Java
public class Solution {
    // 插入排序：稳定排序，在接近有序的情况下，表现优异
    public int[] sortArray(int[] nums) {
        int len = nums.length;
        // 循环不变量：将 nums[i] 插入到区间 [0, i) 使之成为有序数组
        for (int i = 1; i < len; i++) {
            // 先暂存这个元素，然后之前元素逐个后移，留出空位
            int temp = nums[i];
            int j = i;
            // 注意边界 j > 0
            while (j > 0 && nums[j - 1] > temp) {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = temp;
        }
        return nums;
    }
}

```

#### C++

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> sortArray(vector<int> &numbers)
	{
		int len = numbers.size();
		for (int i = 1; i < len; ++i)
		{
			int temp = numbers[i];
			int j = i; // number[j]是一个空闲的位置
			while (j > 0 && numbers[j - 1] > temp)
			{
				numbers[j] = numbers[j - 1];
				--j;
			}
			numbers[j] = temp; // 插入到正确的位置
		}
		return numbers;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



### runoob [插入排序](https://www.runoob.com/data-structures/insertion-sort.html)

```java 
/**
 * 插入排序
 */
public class InsertionSort {
    //核心代码---开始
    public static void sort(Comparable[] arr){

        int n = arr.length;
        for (int i = 0; i < n; i++) {
            // 寻找元素 arr[i] 合适的插入位置
           for( int j = i ; j > 0 ; j -- )
                if( arr[j].compareTo( arr[j-1] ) < 0 )
                    swap( arr, j , j-1 );
                else
                    break;
        }
    }
    //核心代码---结束
    private static void swap(Object[] arr, int i, int j) {
        Object t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    public static void main(String[] args) {

        int N = 20000;
        Integer[] arr = SortTestHelper.generateRandomArray(N, 0, 100000);
        InsertionSort.sort(arr);
        for( int i = 0 ; i < arr.length ; i ++ ){
            System.out.print(arr[i]);
            System.out.print(' ');
        }
    }
}
```




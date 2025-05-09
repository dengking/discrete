# Merge sort

一. merge sort 和 segment tree非常类似: 

1. 它不需要考虑balanced问题，因为它的一分为二是等分

2. merge sort是典型的一分为二(top-down-pre-order-action)然后两两组和(bottom-up-post-order-action)，它是dfs recursion的典型的模板，这一点它和segment tree非常类似。

二. labuladong [东哥手把手带你套框架刷通二叉树|第一期](https://mp.weixin.qq.com/s/izZ5uiWzTagagJec6Y7RvQ) 

再说说归并排序的逻辑，若要对`nums[lo..hi]`进行排序，我们先对`nums[lo..mid]`排序，再对`nums[mid+1..hi]`排序，最后把这两个有序的子数组合并，整个数组就排好序了。

归并排序的代码框架如下：

```Java
void sort(int[] nums, int lo, int hi) {
    int mid = (lo + hi) / 2;
    sort(nums, lo, mid);
    sort(nums, mid + 1, hi);

    /****** 后序遍历位置 ******/
    // 合并两个排好序的子数组
    merge(nums, lo, mid, hi);
    /************************/
}
```

先对左右子数组排序，然后合并（类似合并有序链表的逻辑），你看这是不是二叉树的后序遍历框架？另外，这不就是传说中的分治算法嘛，不过如此呀。

如果你一眼就识破这些排序算法的底细，还需要背这些算法代码吗？这不是手到擒来，从框架慢慢扩展就能写出算法了。

说了这么多，旨在说明，二叉树的算法思想的运用广泛，甚至可以说，只要涉及递归，都可以抽象成二叉树的问题。



## wikipedia [Merge sort](https://en.wikipedia.org/wiki/Merge_sort)





## [LeetCode-912. 排序数组](https://leetcode.cn/problems/sort-an-array/) 

### 递归

#### C++

```C++
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    std::vector<int> tmp; // 保存临时排序结果

public:
    vector<int> sortArray(vector<int> &nums)
    {
        tmp.resize((int)nums.size(), 0);
        sortArray(nums, 0, nums.size() - 1);
        return nums;
    }
    void sortArray(vector<int> &nums, int lo, int hi)
    {
        if (lo >= hi) // base case
        {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        sortArray(nums, lo, mid);
        sortArray(nums, mid + 1, hi);
        std::vector<int> merged = merge(nums, lo, mid, mid + 1, hi);
        std::copy(merged.begin(), merged.end(), nums.begin() + lo);
    }

private:
    std::vector<int> merge(vector<int> &nums, int lo1, int hi1, int lo2, int hi2)
    {
        int first = lo1;
        int second = lo2;
        while (first <= hi1 && second <= hi2)
        {
            if (nums[first] < nums[second])
            {
                tmp.push_back(nums[first++]);
            }
            else
            {
                tmp.push_back(nums[second++]);
            }
        }
        while (first <= hi1)
        {
            tmp.push_back(nums[first++]);
        }
        while (second <= hi2)
        {
            tmp.push_back(nums[second++]);
        }
        return tmp;
    }
};
```



#### Python

```python
from typing import *


class Solution:
    def sort(self, nums: List[int]):
        self.merge_sort(nums, 0, len(nums) - 1)

    def merge_sort(self, nums: List[int], lo: int, hi: int):
        if hi > lo:
            mid = (lo + hi) // 2
            self.merge_sort(nums, lo, mid)
            self.merge_sort(nums, mid + 1, hi)
            self.merge(nums, lo, mid, mid + 1, hi)
        else:
            return

    def merge(self, nums: List[int], lo_1: int, hi_1: int, lo_2: int, hi_2: int):
        l = []
        first = lo_1
        second = lo_2
        while first <= hi_1 and second <= hi_2:
            if nums[first] < nums[second]:
                l.append(nums[first])
                first += 1
            else:
                l.append(nums[second])
                second += 1
        if first <= hi_2:
            l += nums[first:hi_1 + 1]
        if second <= hi_2:
            l += nums[first:hi_2 + 1]
        nums[lo_1:hi_2 + 1] = l


if __name__ == "__main__":
    solu = Solution()
    l = [4, 3, 2, 1]
    solu.sort(l)
    print(l)

    l = [2, 1]
    solu.sort(l)
    print(l)

    l = [1]
    solu.sort(l)
    print(l)

```



### 非递归的实现方式

此算法是根据递归版本的归并排序算法改编而来，具体的改编思路如下：

算法`MergeSort`利用递归机制，实现了把待排序数组一分为二，然后在二分为四，依次分割，直到待排序的集合中只有一个元素为止，然后不断地合并两个排好序的数组段，合并操作由函数Merge来完成，真正实现排序的过程也是在这个函数中发生的。

因此我们消解递归的思路就是：使用其它方法来进行划分，不用递归来划分。 

`void MergePass(int a[],int b[],int s,int n)`的理解：

| 2s   | 2s   | 2s   | ………  |      |
| ---- | ---- | ---- | ---- | ---- |
|      |      |      |      |      |



```C++
#include<iostream>
using namespace std;

void MergeSort(int a[], int n); //a是待排序数组，n是数组a的长度
void Merge(int a[], int b[], int left, int m, int right);
void MergePass(int a[], int b[], int s, int n); //a是待排序数组，n是数组a的长度,s是子段的长度，此函数把部分有序的序列放到了数组b中

/**
 * @brief
 *
 * @param a 待排序数组
 * @param n 是数组a的长度
 */
void MergeSort(int a[], int n)
{
	int *b = new int[n];
	int s = 1; //s定义的是子段的长度，初始时，子段长度为1，则自然有序
	while (s < n)
	{
		MergePass(a, b, s, n); //合并到数组b中
		s += s;
		MergePass(b, a, s, n);
		s += s;
	}
}
/**
 * @brief a是待排序数组，n是数组a的长度,s是子段的长度，此函数把部分有序的序列放到了数组b中
 *
 * @param a
 * @param b
 * @param s
 * @param n
 */
void MergePass(int a[], int b[], int s, int n) //
{
	int i = 0;
	while (i <= n - 2 * s)
	{ //此循环能够使循环次数k满足k*（2*s）<=n的k取到最大值。
	  //它实现这个控制的思路是按照逆向思维方式：n-2*s标识的是使数组剩余2*s长度的起始下标，显然一旦i超过了这个值，则while中按照2*s为单位进行排序就是不合法的，所以要跳出循环
		Merge(a, b, i, i + s - 1, i + 2 * s - 1);		//注意对于这个过程的理解请参考文档
		i = i + 2 * s;
	}		//只有当i>n-2*s才弹出循环
	if (i + s < n)
	{		//也就是剩余的子段的长度比s要大
		Merge(a, b, i, i + s - 1, n - 1);		//注意对于这个过程的理解请参考文档
	}
	else
	{
		for (int k = i; i < n; i++)
		{
			b[k++] = a[i];
		}
	}
}

void Merge(int a[], int b[], int left, int m, int right)
{		//合并a[left:i]和a[m+1:right]到b[left，right]
	int i = left, j = m + 1;
	int k = left;		//i是指向第一段的指针，j是指向第二段的指针，k原来作为数组b的下标
	while ((i <= m) && (j <= right))
	{		//这个while循环原来把a[left:i]和a[m+1:right]中的数据按序放进数组b中
		if (a[i] < a[j])
		{         //注意循环的控制条件，把它翻译成自然语言就是：只要两段数组有一段放完了，那么另外一段是有序的，无需比较直接可以放进数组b中
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	if (i <= m)
	{         //i<=m说明导致跳出while循环的原因是j>right，即第二段已经完全放到b中了
		for (; i <= m; i++)
			b[k++] = a[i];
	}
	else
	{
		for (; j <= right; j++)
			b[k++] = a[j];
	}
}

```



## See also

hackerearth [Merge Sort](https://www.hackerearth.com/zh/practice/algorithms/sorting/merge-sort/tutorial/)


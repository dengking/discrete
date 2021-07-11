# double pointer遍历一轮序列可以做的事情

一、使用双double pointer指针技巧，我们能够只遍历一轮数组，就完成很多看似不可能完成的事情，这在下面的章节、文章中，已经进行非常深刻的讨论: 



二、使用区间的概念来进行理解

三、此处的序列，包括: 

1、array

2、linked list

四、本文补充一些内容，它们的实现也是可以使用double pointer来进行解释的

## quick sort partition: fast slow double pointer

quick sort的partition遍历数组一轮就可以将数组分为两部分

```C
#include <stdio.h>
#include <stdlib.h>

/*Displays the array, passed to this method*/
void display(int arr[], int n)
{

	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

/*Swap function to swap two values*/
void swap(int *first, int *second)
{

	int temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * @brief i指向的是右侧大于pivot的第一个元素，显然，它记录的是右半段的左侧边界；
 * pivot的过程其实是不断地将右侧区间中的不属于它的元素、即属于左侧区间的元素拿到左侧区间，
 * 那么它如何实现呢？其实方法非常简答: 让出一个位置的元素给左侧区间来存放刚刚找到的这个元素
 *
 * @param A
 * @param start
 * @param end
 * @return
 */
int partition(int A[], int start, int end)
{
	int i = start + 1;
	int piv = A[start];            //make the first element as pivot element.
	for (int j = start + 1; j <= end; j++)
	{
		/*rearrange the array by putting elements which are less than pivot
		 on one side and which are greater that on other. */

		if (A[j] < piv)
		{
			swap(A[i], A[j]);
			i += 1;
		}
	}
	swap(A[start], A[i - 1]);  //put the pivot element in its proper place.
	return i - 1;                      //return the position of the pivot
}

/*This is where the sorting of the array takes place
 arr[] --- Array to be sorted
 lower --- Starting index
 upper --- Ending index
 */
void quickSort(int arr[], int lower, int upper)
{

	if (upper > lower)
	{

		// partitioning index is returned by the partition method , partition element is at its correct poition

		int partitionIndex = partition(arr, lower, upper);

		// Sorting elements before and after the partition index
		quickSort(arr, lower, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, upper);
	}
}

int main()
{

	int n;
	printf("Enter size of array:\n");
	scanf("%d", &n); // E.g. 8

	printf("Enter the elements of the array\n");
	int i;
	int *arr = (int*) malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Original array: ");
	display(arr, n); // Original array : 10 11 9 8 4 7 3 8

	quickSort(arr, 0, n - 1);

	printf("Sorted array: ");
	display(arr, n); // Sorted array : 3 4 7 8 8 9 10 11
	getchar();
	return 0;
}
// gcc test.c

```

上述partition的实现，其实是使用的双指针，它的写法是非常类似于在 labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s/hWi2hTrQewL_YKioGkXQJg) 中给出的:

> **一、问题分析**
>
> > NOTE: 
> >
> > LeetCode [392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/) 简单
>
> **双指针**
>
> 首先，一个很简单的解法是这样的：
>
> ```C++
> bool isSubsequence(string s, string t) {
>     int i = 0, j = 0;
>     while (i < s.size() && j < t.size()) {
>         if (s[i] == t[j]) i++;
>         j++;
>     }
>     return i == s.size();
> }
> ```
>
> 其思路也非常简单，利用双指针`i, j`分别指向`s, t`，一边前进一边匹配子序列：
>
> ![图片](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4mnbVC00EzwNpKWVLic67v8fp4AviccRT7S8XlynThhhyUxhB2X63YwDSCyq2ZWcGo6cQS0HhxKiaziaQ/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)
>
> 读者也许会问，这不就是最优解法了吗，时间复杂度只需 O(N)，N 为`t`的长度。



后来在阅读 labuladong  [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ) 时，发现其实此处的双指针更加准确地说是: fast-slow double pointer:

> 我们让慢指针`slow`走在后面，快指针`fast`走在前面探路，找到一个不重复的元素就告诉`slow`并让`slow`前进一步。这样当`fast`指针遍历完整个数组`nums`后，**`nums[0..slow]`就是不重复元素**。
>
> ```C
> int removeDuplicates(int[] nums) {
>     if (nums.length == 0) {
>         return 0;
>     }
>     int slow = 0, fast = 0;
>     while (fast < nums.length) {
>         if (nums[fast] != nums[slow]) {
>             slow++;
>             // 维护 nums[0..slow] 无重复
>             nums[slow] = nums[fast];
>         }
>         fast++;
>     }
>     // 数组长度为索引 + 1
>     return slow + 1;
> }
> ```
>
> 看下算法执行的过程：
>
> ![Image](https://mmbiz.qpic.cn/sz_mmbiz_gif/gibkIz0MVqdFXdiaWmw4sp8GT0YI41Rk5muqNGreX2FbysTeUnlAWECO1eYWc5ZZDPMYCs7ViaHkEaOfK4lI9HD7A/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



结合quick sort的partition来看，它其实就是运用了fast slow double pointer，下面是使用这个technique对它的修改:


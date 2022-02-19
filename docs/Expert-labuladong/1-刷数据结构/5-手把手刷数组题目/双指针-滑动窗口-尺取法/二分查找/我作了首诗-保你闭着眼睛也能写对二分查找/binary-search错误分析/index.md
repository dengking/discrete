# 错误分析

按照 **labuladong** [我作了首诗，保你闭着眼睛也能写对二分查找](https://mp.weixin.qq.com/s/M1KfTfNlu4OCK8i9PSAmug) 中对于binary search采用左闭右开时，写法如下:

```C++
#include <iostream>
#include <vector>

int binary_search(std::vector<int> &nums, int target)
{
	int left = 0, right = nums.size();
	while (left < right)
	{
		int mid = left + (right - left - 1) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid; // 左闭右开，因此此处是mid
		}
	}
    return nums[left] == target ? left : -1;   
}
```

作者特别强调:

> `while(left < right)`的终止条件是`left == right`，写成区间的形式就是`[left, right]`，或者带个具体的数字进去`[2, 2]`，**这时候区间非空**，还有一个数 2，但此时 while 循环终止了。也就是说这区间`[2, 2]`被漏掉了，索引 2 没有被搜索，如果这时候直接返回 -1 就是错误的。
>
> 当然，如果你非要用`while(left < right)`也可以，我们已经知道了出错的原因，就打个补丁好了：
>
> ```c++
>     //...
>     while(left < right) {
>         // ...
>     }
>     return nums[left] == target ? left : -1;
> ```

作者的上述分析是有错误的:

1、`nums[left] == target` 是可能导致运行时错误的

2、从 [glibc](https://code.woboq.org/userspace/glibc/)/[bits](https://code.woboq.org/userspace/glibc/bits/)/[stdlib-bsearch.h](https://code.woboq.org/userspace/glibc/bits/stdlib-bsearch.h.html) 的实现来看，是可以不加 `nums[left] == target` 的



## 例子一: 数组`[2]`，查找`0`

显然，演算流程如下:

left=0, right=1, mid=0，`array[mid] > target`, 则target位于mid的左边，置`right=mid`

left=0, right=0，由于采用的是左开右闭，right是无效索引，所以`left==right`时，表示区间已经为空，不满足循环条件，退出。

执行 `nums[left] == target` 检查，显然这一步是多余的。

## 例子二: 数组`[2]`，查找`3`

显然，演算流程如下:

left=0, right=1, mid=0，`array[mid] < 3`, 则target位于mid的右边，置`left=mid+1`

left=mid+1=1, right=1，由于采用的是左开右闭，right是无效索引，所以`left==right`时，表示区间已经为空了。

执行 `nums[left] == target` 检查，显然会造成memory error: access-outside-of-array，完整程序如下:

```C++
#include <iostream>
#include <vector>

int binary_search(std::vector<int> &nums, int target)
{
	int left = 0, right = nums.size();
	while (left < right)
	{
		int mid = left + (right - left - 1) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
    return nums[left] == target ? left : -1;   
}

int main()
{
	std::vector<int> a = { 2 };
	int target = 3;

	std::cout << binary_search(a, target) << std::endl;
}
// g++ test.cpp -g -fsanitize=address -fno-omit-frame-pointer

```

运行时错误如下:

```
=================================================================

==28436==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000014 at pc 0x56376cf105dd bp 0x7ffceb27ebf0 sp 0x7ffceb27ebe0

READ of size 4 at 0x602000000014 thread T0

    #0 0x56376cf105dc in binary_search(std::vector<int, std::allocator<int> >&, int) /home/dengkai/Desktop/test.cpp:23

    #1 0x56376cf10775 in main /home/dengkai/Desktop/test.cpp:31

    #2 0x7f6fee9e1fcf in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

    #3 0x7f6fee9e207c in __libc_start_main_impl ../csu/libc-start.c:409

    #4 0x56376cf103a4 in _start (/home/dengkai/Desktop/a.out+0x23a4)


```

## 例子三: 

```c++
#include <iostream>
#include <vector>
int binary_search(std::vector<int> &nums, int target)
{
	int left = 0, right = nums.size();
	while (left < right)
	{
		int mid = left + (right - left - 1) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
    return nums[left] == target ? left : -1;   
}
int main()
{
	std::vector<int> a = { -1, 0, 3, 5, 9, 12 };
	int target = 9;
	std::cout << binary_search(a, target) << std::endl;

	std::vector<int> a2 = { -1, 0, 3, 5, 9, 9, 9, 12 };
	std::cout << binary_search(a2, target) << std::endl;
}
// g++ test.cpp -g -fsanitize=address -fno-omit-frame-pointer

```

运行上述程序，是能够找到正确的索引。通过前面的例子:

例子一中，`nums[left] == target` 是多余的；

例子二中，`nums[left] == target` 是会导致错误的；

我们可以想想: 能否将 它去除？下面是测试程序:

```C++
#include <iostream>
#include <vector>
int binary_search(std::vector<int> &nums, int target)
{
	int left = 0, right = nums.size();
	while (left < right)
	{
		int mid = left + (right - left - 1) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
    return -1;   
}
int main()
{
	std::vector<int> a = { -1, 0, 3, 5, 9, 12 };
	int target = 9;
	std::cout << binary_search(a, target) << std::endl;

	std::vector<int> a2 = { -1, 0, 3, 5, 9, 9, 9, 12 };
	std::cout << binary_search(a2, target) << std::endl;
}
// g++ test.cpp -g -fsanitize=address -fno-omit-frame-pointer

```

运行结果如下:

```
4
5
```

显然都成功找到了。

## 总结

通过前面的分析可知: 左闭右开的写法相比于左闭右闭会复杂很多:

一、如果按照区间的概念来进行理解，那么当循环退出的时候，表示区间已经为空了，那么此时在循环外应该可以不用执行`nums[left] == target`，但是通过上面的例子三可知，如果不执行，是可能遗漏的。

上述三个例子恰好描述了三种情况:

1、例子一: 循环退出的时候，left是有效值，left在循环体内已经检查过，因此可以不用在进行检查

2、例子二: 循环退出的时候，left是无效值，此时执行检查，会导致运行时错误

3、例子三: 循环退出的时候，left是有效值，left在循环体中检查过，因此可以不用在进行检查

 

### 正确的程序

```C++
#include <iostream>
#include <vector>
int binary_search(std::vector<int> &nums, int target)
{
	int left = 0, right = nums.size();
	while (left < right)
	{
		int mid = left + (right - left - 1) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return -1;
}
int main()
{
    std::vector<int> a = { 2 };
	std::cout << binary_search(a, 0) << std::endl;

	std::cout << binary_search(a, 3) << std::endl;
	
    a = { -1, 0, 3, 5, 9, 12 };
	std::cout << binary_search(a, 9) << std::endl;

	a = { -1, 0, 3, 5, 9, 9, 9, 12 };
	std::cout << binary_search(a, 9) << std::endl;
}
// g++ test.cpp -g -fsanitize=address -fno-omit-frame-pointer

```

输出如下:

```C++
-1
-1
4
4
```


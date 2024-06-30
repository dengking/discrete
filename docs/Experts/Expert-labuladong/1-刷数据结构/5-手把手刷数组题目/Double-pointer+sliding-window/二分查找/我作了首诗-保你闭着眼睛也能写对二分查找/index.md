# **labuladong** [我作了首诗，保你闭着眼睛也能写对二分查找](https://mp.weixin.qq.com/s/M1KfTfNlu4OCK8i9PSAmug) 

> 一、为了描述方便，使用range来表示**搜索区间**，原文中始终强调range，因为while的条件是基于range，while循环体也是对range进行操作
>
> 二、二分搜索能够保证，`left`、`right`不断地向target(**逼近** approximation)，这是binary search的核心特性，后续的三种形式都是以此为前提的。
>
> 三、由于是双指针(left、right)，即存在两个元素，渐渐地range的长度会缩减为2(即此时left pointer 和 right pointer**相遇**)，然后缩减为1(即此时left pointer 和 right pointer**重叠**)。
>
> 1、寻找左边界的二分搜索和寻找右边界的二分搜索就是利用的这个特性。
>
> 2、寻找左边界的二分搜索和寻找右边界的二分搜索中，当`nums[mid] == target`时，它会将`nums[mid]`从range中剔除，因此，当while退出的时候，肯定是因为range为0了，即`left == right`
>
> 3、对于寻找左侧边界的二分搜索，当while退出的时候，如果存在target，那么它就指向target。
>
> 
>
> 四、`while`的编写: `while`的条件是区间非空，即当搜索区间非空的时候(只有一个元素也是非空的)，需要进行搜索，`while`的退出:
>
> 1、未找到target，最终循环条件不满足，range为空
>
> 2、找到target，从循环中break
>
> 其实以只有一个元素的数组来思考while循环的编写是最最方便的: 
>
> 1、左闭右闭, 区间非空的条件是 left <= right
>
> 初始化: left=0, right=0
>
> 2、左闭右开, 区间非空的条件是 left < right，需要注意是不能够取等于的，因为是左闭右开，当取等于的时候，区间已经空了
>
> 初始化: left=0, right=1
>
> **搜索区间的界定是要统一的，在开始搜索前和搜索中，在搜索中，需要不断地变化搜索区间，需要始终保持区间策略的一致**
>
> 六、最终统一为**左闭右闭**的形式，在最后面给出了完整的程序，下面是一些分析:
>
> 对于区间，非常容易理解；
>
> 对于基本的二分搜索，非常容易理解；
>
> 难点是left bound 和 right bound的return value的处理；
>
> 1、要么存在
>
> 最终left、right肯定会逼近目标元素，最终的终止条件是left > right，即left ==  right + 1 ，即left在right的右侧；
>
> 对于**left bound**: 当命中target的时候，不断地缩小right，最终，right错过target，指向target的左侧，当循环条件不满足，即left ==  right + 1，left指向target，因此最终返回left；由于算法最终返回left，并且算法中执行left + 1，当target不存在的时候是可能越界的，因此在返回left之前是需要进行越界保护的，因此需要考虑left超过array的范围（overflow）。
>
> 对于**right bound**: 当命中target的时候，不断地增大left，最终，left错过target，指向target的右侧，当循环条件不满足，即left ==  right + 1，right指向target，因此最终返回right；由于算法最终返回right，并且算法中执行right - 1，当target不存在的时候是可能越界的，因此在返回right之前是需要进行越界保护的，因此需要考虑right超过array的范围（underflow）。
>
> 2、要么不存在: 
>
> target比所有的都小，因此最终left、right都位于左侧
>
> 对于**left bound**: 最终返回的是left，此时left是安全的，不会越界；
>
> 对于**right bound**: 最终返回的是right，此时right是不安全的，可能越界(比如left为0，那么right就是-1)，显然这是越界；
>
> target比所有的都大，因此最终left、right都位于右侧
>
> 对于**left bound**: 最终返回的是left，此时left是不安全的，可能越界；
>
> 对于**right bound**: 最终返回的是right，此时right是安全的，不会越界
>
> 可以看到: 可能的情况是非常多的

本文就来探究几个最常用的二分查找场景：寻找一个数、寻找左侧边界、寻找右侧边界。而且，我们就是要深入细节，比如不等号是否应该带等号，`mid` 是否应该加一等等。



## 零、二分查找框架

> NOTE: 
>
> 可以看到，下面的code中，`...`主要是对边界的划分，或者使用作者的概念: **搜索区间**
>
> 

```C++
int binarySearch(int[] nums, int target)
{
	int left = 0, right = ...;

	while(...)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
		{
			...
		}
		else if (nums[mid] < target)
		{
			left = ...
		}
		else if (nums[mid] > target)
		{
			right = ...
		}
	}
	return ...;
}

```



**分析二分查找的一个技巧是：不要出现 else，而是把所有情况用 else if 写清楚，这样可以清楚地展现所有细节**。本文都会使用 else if，旨在讲清楚，读者理解后可自行简化。

其中`...`标记的部分，就是可能出现细节问题的地方，当你见到一个二分查找的代码时，首先注意这几个地方。后文用实例分析这些地方能有什么样的变化。

### 防止sum overflow

另外声明一下，计算 mid 时需要防止溢出，代码中`left + (right - left) / 2`就和`(left + right) / 2`的结果相同，但是有效防止了`left`和`right`太大直接相加导致溢出。

## 一、寻找一个数（基本的二分搜索）

这个场景是最简单的，肯能也是大家最熟悉的，即搜索一个数，如果存在，返回其索引，否则返回 -1。

```c++
int binarySearch(int[] nums, int target) {
    int left = 0; 
    int right = nums.length - 1; // 注意

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid; 
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
    }
    return -1;
}
```

> NOTE: 
>
> 一、完整测试程序如下:
>
> ```C++
> #include <iostream>
> #include <vector>
> int binary_search(std::vector<int> &nums, int target)
> {
> 	int left = 0, right = nums.size() - 1;
> 	while (left <= right)
> 	{
> 		int mid = left + (right - left) / 2;
> 		if (nums[mid] == target)
> 		{
> 			return mid;
> 		}
> 		else if (nums[mid] < target)
> 		{
> 			left = mid + 1;
> 		}
> 		else
> 		{
> 			right = mid - 1;
> 		}
> 	}
> 	return -1;
> }
> int main()
> {
> 	std::vector<int> a = { -1, 0, 3, 5, 9, 12 };
> 	int target = 9;
> 	std::cout << binary_search(a, target) << std::endl;
> 
> 	std::vector<int> a2 = { -1, 0, 3, 5, 9, 9, 9, 12 };
> 	std::cout << binary_search(a2, target) << std::endl;
> }
> // g++ test.cpp -g
> 
> ```
>
> 

### 1、为什么 while 循环的条件中是 <=，而不是 <？

答：因为初始化`right`的赋值是`nums.length - 1`，即最后一个元素的索引，而不是`nums.length`。



这二者可能出现在不同功能的二分查找中，区别是：前者相当于两端都闭区间`[left, right]`，后者相当于左闭右开区间`[left, right)`，因为索引大小为`nums.length`是越界的。

我们这个算法中使用的是前者`[left, right]`两端都闭的区间。**这个区间其实就是每次进行搜索的区间**。

什么时候应该停止搜索呢？当然，找到了目标值的时候可以终止：

```c++
    if(nums[mid] == target)
        return mid; 
```

但如果没找到，就需要 while 循环终止，然后返回 -1。那 while 循环什么时候应该终止？**搜索区间为空的时候应该终止**，意味着你没得找了，就等于没找到嘛。

#### 终止条件: 搜索区间为空时

`while(left <= right)`的终止条件是`left == right + 1`，写成区间的形式就是`[right + 1, right]`，或者带个具体的数字进去`[3, 2]`，可见**这时候区间为空**，因为没有数字既大于等于 3 又小于等于 2 的吧。所以这时候 while 循环终止是正确的，直接返回 -1 即可。

`while(left < right)`的终止条件是`left == right`，写成区间的形式就是`[left, right]`，或者带个具体的数字进去`[2, 2]`，**这时候区间非空**，还有一个数 2，但此时 while 循环终止了。也就是说这区间`[2, 2]`被漏掉了，索引 2 没有被搜索，如果这时候直接返回 -1 就是错误的。

当然，如果你非要用`while(left < right)`也可以，我们已经知道了出错的原因，就打个补丁好了：

```c++
    //...
    while(left < right) {
        // ...
    }
    return nums[left] == target ? left : -1;
```


> NOTE: 
> 一、作者上面这段话是有误的，在"binary-search错误分析"章节中进行了详细的分析。

### 2、为什么`left = mid + 1`，`right = mid - 1`？

**我看有的代码是`right = mid`或者`left = mid`，没有这些加加减减，到底怎么回事，怎么判断？**

答：这也是二分查找的一个难点，不过只要你能理解前面的内容，就能够很容易判断。

刚才明确了「搜索区间」这个概念，而且本算法的搜索区间是两端都闭的，即`[left, right]`。那么当我们发现索引`mid`不是要找的`target`时，下一步应该去搜索哪里呢？

当然是去搜索`[left, mid-1]`或者`[mid+1, right]`对不对？**因为`mid`已经搜索过，应该从搜索区间中去除**。

### 3、此算法有什么缺陷？

答：至此，你应该已经掌握了该算法的所有细节，以及这样处理的原因。但是，这个算法存在局限性。

比如说给你有序数组`nums = [1,2,2,2,3]`，`target`为 2，此算法返回的索引是 2，没错。但是如果我想得到`target`的左侧边界，即索引 1，或者我想得到`target`的右侧边界，即索引 3，这样的话此算法是无法处理的。

这样的需求很常见，**你也许会说，找到一个 target，然后向左或向右线性搜索不行吗？可以，但是不好，因为这样难以保证二分查找对数级的复杂度了**。

我们后续的算法就来讨论这两种二分查找的算法。

## 二、寻找左侧边界的二分搜索

以下是最常见的代码形式，其中的标记是需要注意的细节：

```C++
int left_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0;
    int right = nums.length; // 注意

    while (left < right) { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            right = mid; // 此时区间[left, mid)
        } else if (nums[mid] < target) {
            left = mid + 1; // 此时区间为 [mid+1, right)
        } else if (nums[mid] > target) {
            right = mid; // 注意，此时区间为[left, mid)
        }
    }
    return left;
}
```

### 1、为什么 while 中是`<`而不是`<=`?

答：用相同的方法分析，因为`right = nums.length`而不是`nums.length - 1`。因此每次循环的「搜索区间」是`[left, right)`左闭右开。

`while(left < right)`终止的条件是`left == right`，此时搜索区间`[left, left)`为空，所以可以正确终止。

PS：这里先要说一个搜索左右边界和上面这个算法的一个区别，也是很多读者问的：**刚才的`right`不是`nums.length - 1`吗，为啥这里非要写成`nums.length`使得「搜索区间」变成左闭右开呢**？

因为对于搜索左右侧边界的二分查找，这种写法比较普遍，我就拿这种写法举例了，保证你以后看到这类代码可以理解。其实你非要用两端都闭的写法反而更简单，我会在后面写相关的代码，把三种二分搜索都用一种两端都闭的写法统一起来，你耐心往后看就行了。

> NOTE: 
>
> 简而言之: 左闭右闭也是可以的

### 2、为什么没有返回 -1 的操作？如果`nums`中不存在`target`这个值，怎么办？

答：因为要一步一步来，先理解一下这个「左侧边界」(即 `left`)有什么特殊含义：

#### 「左侧边界」的特殊含义

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdF2MS89jteHAY2C2mRL0DVRowh3kgaqw71XZGx9XM3wsVgYOLPUsD8kHKuic3PuhzVahdo410B8Pdw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

对于这个数组，算法会返回 1。这个 1 的含义可以这样解读：`nums`中小于 2 的元素有 1 个。

比如对于有序数组`nums = [2,3,5,7]`,`target = 1`，算法会返回 0，含义是：`nums`中小于 1 的元素有 0 个。

再比如说`nums = [2,3,5,7], target = 8`，算法会返回 4，含义是：`nums`中小于 8 的元素有 4 个。

#### `return -1`

综上可以看出，函数的返回值（即`left`变量的值）取值区间是闭区间`[0, nums.length]`，所以我们简单添加两行代码就能在正确的时候 `return -1`：

```c++
while (left < right) {
    //...
}
// target 比所有数都大
if (left == nums.length) return -1;
// 类似之前算法的处理方式
return nums[left] == target ? left : -1;
```

#### 完整测试程序

```C++
#include <iostream>
#include <vector>
int left_search(std::vector<int> &nums, int target)
{
	int left = 0, right = nums.size();
	while (left < right)
	{
		int mid = left + (right - left - 1) / 2; // 这里是需要注意的，是非常容易遗漏 -1的
		if (nums[mid] == target)
		{
			right = mid;
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
	if (left == nums.size())
		return -1;

	return nums[left] == target ? left : -1;
}
int main()
{
	std::vector<int> a = { -1, 0, 3, 5, 9, 12 };
	int target = 9;
	std::cout << left_search(a, target) << std::endl;

	std::vector<int> a2 = { -1, 0, 3, 5, 9, 9, 9, 12 };
	std::cout << left_search(a2, target) << std::endl;
}
// g++ test.cpp -g -fsanitize=address -fno-omit-frame-pointer

```



### 3、为什么`left = mid + 1`，`right = mid`？和之前的算法不一样？

答：这个很好解释，因为我们的「搜索区间」是`[left, right)`左闭右开，所以当`nums[mid]`被检测之后，下一步的搜索区间应该去掉`mid`分割成两个区间，即`[left, mid)`或`[mid + 1, right)`。

> NOTE: 
>
> 1、保持区间策略的一致

### 4、为什么该算法能够搜索左侧边界？

答：关键在于对于`nums[mid] == target`这种情况的处理：

```c++
    if (nums[mid] == target)
        right = mid;
```

可见，找到 target 时不要立即返回，而是缩小「搜索区间」的上界`right`，在区间`[left, mid)`中继续搜索，即不断向左收缩，达到锁定左侧边界的目的。

#### 终止条件

> 一、与  "一、寻找一个数（基本的二分搜索）" 中不同的是，在上述程序中，while中并没有return语句，因此，它的退出条件是`left == right`，与"一、寻找一个数（基本的二分搜索）" 中不同，因此，当`while`退出的时候，`left == right`，即range为空。
>
> 例子为`[1,2,2,2,5]`，搜索`2`
>
> 二、前面对返回值`left`的含义进行了解释
>
> 当`nums[mid] == target`时，它将`right`设置为`mid`，其实，此时它是在将mid处的元素从range给剥离出去

### 5、为什么返回`left`而不是`right`？

答：都是一样的，因为 while 终止的条件是`left == right`。

### 6、能不能想办法把`right`变成`nums.length - 1`，也就是继续使用两边都闭的「搜索区间」？

这样就可以和第一种二分搜索在某种程度上统一起来了。

答：当然可以，只要你明白了「搜索区间」这个概念，就能有效避免漏掉元素，随便你怎么改都行。

#### 修改为两侧闭区间

下面我们严格根据逻辑来修改：

因为你非要让搜索区间两端都闭，所以`right`应该初始化为`nums.length - 1`，while 的终止条件应该是`left == right + 1`，也就是其中应该用`<=`：

```c++
int left_bound(int[] nums, int target) {
    // 搜索区间为 [left, right]
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // if else ...
    }
```

因为搜索区间是两端都闭的，且现在是搜索左侧边界，所以`left`和`right`的更新逻辑如下：

```c++
if (nums[mid] < target) {
    // 搜索区间变为 [mid+1, right]
    left = mid + 1;
} else if (nums[mid] > target) {
    // 搜索区间变为 [left, mid-1]
    right = mid - 1;
} else if (nums[mid] == target) {
    // 收缩右侧边界
    right = mid - 1;
}
```

由于 while 的退出条件是`left == right + 1`，所以当`target`比`nums`中所有元素都大时，会存在以下情况使得索引越界：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdF2MS89jteHAY2C2mRL0DVRSFibG5qepG9K5ftAbyy47mJOOuYbZXDSnM7mmhSibGmg6gbzEAFvib78A/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

因此，最后返回结果的代码应该检查越界情况：

```c++
if (left >= nums.length || nums[left] != target)
    return -1;
return left;
```

至此，整个算法就写完了，完整代码如下：

```c++
int left_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    // 搜索区间为 [left, right]
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            // 搜索区间变为 [mid+1, right]
            left = mid + 1;
        } else if (nums[mid] > target) {
            // 搜索区间变为 [left, mid-1]
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 收缩右侧边界
            right = mid - 1;
        }
    }
    // 检查出界情况
    if (left >= nums.length || nums[left] != target)
        return -1;
    return left;
}
```

这样就和第一种二分搜索算法统一了，都是两端都闭的「搜索区间」，而且最后返回的也是`left`变量的值。只要把住二分搜索的逻辑，两种形式大家看自己喜欢哪种记哪种吧。

#### 完整测试程序

```C++
#include <iostream>
#include <vector>
int left_search(std::vector<int> &nums, int target)
{
	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
		{
			right = mid - 1;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (left >= nums.size() || nums[left] != target)
		return -1;

	return left;
}
int main()
{
	std::vector<int> a = { -1, 0, 3, 5, 9, 12 };
	int target = 9;
	std::cout << left_search(a, target) << std::endl;

	std::vector<int> a2 = { -1, 0, 3, 5, 9, 9, 9, 12 };
	std::cout << left_search(a2, target) << std::endl;
}
// g++ test.cpp -g

```



## 三、寻找右侧边界的二分查找

类似寻找左侧边界的算法，这里也会提供两种写法，还是先写常见的左闭右开的写法，只有两处和搜索左侧边界不同，已标注：

```C++
int right_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0, right = nums.length;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // 注意
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    return left - 1; // 注意
}
```

### 2、为什么最后返回`left - 1`而不像左侧边界的函数，返回`left`？

而且我觉得这里既然是搜索右侧边界，应该返回`right`才对。

答：首先，while 循环的终止条件是`left == right`，所以`left`和`right`是一样的，你非要体现右侧的特点，返回`right - 1`好了。

至于为什么要减一，这是搜索右侧边界的一个特殊点，关键在这个条件判断：

```C++
if (nums[mid] == target) {
    left = mid + 1;
    // 这样想: mid = left - 1
```

> NOTE: 
>
> 这是非常容易出错的

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdF2MS89jteHAY2C2mRL0DVRSIZGjOUN3sFU4MhvRd41OibpUSeickSfL8I3X8T2SzyhcSMfA3ukwCmg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

因为我们对`left`的更新必须是`left = mid + 1`，就是说 while 循环结束时，`nums[left]`一定不等于`target`了，而`nums[left-1]`可能是`target`。

至于为什么`left`的更新必须是`left = mid + 1`，同左侧边界搜索，就不再赘述。

### 3、为什么没有返回 -1 的操作？如果`nums`中不存在`target`这个值，怎么办？

答：类似之前的左侧边界搜索，因为 while 的终止条件是`left == right`，就是说`left`的取值范围是`[0, nums.length]`，所以可以添加两行代码，正确地返回 -1：

```c++
while (left < right) {
    // ...
}
if (left == 0) return -1;
return nums[left-1] == target ? (left-1) : -1;
```

### 4、是否也可以把这个算法的「搜索区间」也统一成两端都闭的形式呢？

**这样这三个写法就完全统一了，以后就可以闭着眼睛写出来了**。

答：当然可以，类似搜索左侧边界的统一写法，其实只要改两个地方就行了：

```c++
int right_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 这里改成收缩左侧边界即可
            left = mid + 1;
        }
    }
    // 这里改为检查 right 越界的情况，见下图
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}
```

当`target`比所有元素都小时，`right`会被减到 -1，所以需要在最后防止越界：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdF2MS89jteHAY2C2mRL0DVR08CtFnmk0q3eLpP3QicvuM7fLpSeiboy9ckic3LN1LQ9wGPAicdj72ZNKA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

至此，搜索右侧边界的二分查找的两种写法也完成了，其实将「搜索区间」统一成两端都闭反而更容易记忆，你说是吧？

#### 完整测试程序

```C++
#include <iostream>
/**
 * @brief
 *
 * @param nums 数组
 * @param length 数组长度
 * @param target
 * @return
 */
int right_bound(int *nums, int length, int target)
{
	int left = 0, right = length - 1;
	// 搜索区间为 [left, right]
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] < target)
		{
			// 搜索区间变为 [mid+1, right]
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			// 搜索区间变为 [left, mid-1]
			right = mid - 1;
		}
		else if (nums[mid] == target)
		{
			// 收缩左侧边界
			left = mid + 1;
		}
	}
	// 检查出界情况
	if (right >= length || nums[right] != target)
		return -1;
	return right;
}

int main()
{
	int a[] = { -1, 0, 3, 5, 9, 12 };
	int target = 9;
	std::cout << right_bound(a, sizeof(a) / sizeof(a[0]), target) << std::endl;

	int a2[] = { -1, 0, 3, 5, 9, 9, 9, 12 };
	std::cout << right_bound(a2, sizeof(a2) / sizeof(a2[0]), target) << std::endl;
}
// g++ test.cpp -g
```



## 四、逻辑统一

来梳理一下这些细节差异的因果逻辑：

**第一个，最基本的二分查找算法**：

```
因为我们初始化 right = nums.length - 1
所以决定了我们的「搜索区间」是 [left, right]
所以决定了 while (left <= right)
同时也决定了 left = mid+1 和 right = mid-1

因为我们只需找到一个 target 的索引即可
所以当 nums[mid] == target 时可以立即返回
```

> NOTE: 
>
> 1、始终保持区间策略的一致

**第二个，寻找左侧边界的二分查找**：

```
因为我们初始化 right = nums.length
所以决定了我们的「搜索区间」是 [left, right)
所以决定了 while (left < right)
同时也决定了 left = mid + 1 和 right = mid

因为我们需找到 target 的最左侧索引
所以当 nums[mid] == target 时不要立即返回
而要收紧右侧边界以锁定左侧边界
```

**第三个，寻找右侧边界的二分查找**：

```
因为我们初始化 right = nums.length
所以决定了我们的「搜索区间」是 [left, right)
所以决定了 while (left < right)
同时也决定了 left = mid + 1 和 right = mid

因为我们需找到 target 的最右侧索引
所以当 nums[mid] == target 时不要立即返回
而要收紧左侧边界以锁定右侧边界

又因为收紧左侧边界时必须 left = mid + 1
所以最后无论返回 left 还是 right，必须减一
```



### 完整程序

对于寻找左右边界的二分搜索，常见的手法是使用左闭右开的「搜索区间」，**我们还根据逻辑将「搜索区间」全都统一成了两端都闭，便于记忆，只要修改两处即可变化出三种写法**：

```C++
int binary_search(int[] nums, int target) {
    int left = 0, right = nums.length - 1; 
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1; 
        } else if(nums[mid] == target) {
            // 直接返回
            return mid;
        }
    }
    // 直接返回
    return -1;
}

int left_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定左侧边界
            right = mid - 1;
        }
    }
    // 最后要检查 left 越界的情况
    if (left >= nums.length || nums[left] != target)
        return -1;
    return left;
}


int right_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定右侧边界
            left = mid + 1;
        }
    }
    // 最后要检查 right 越界的情况
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}
```

如果以上内容你都能理解，那么恭喜你，二分查找算法的细节不过如此。

通过本文，你学会了：

1、分析二分查找代码时，不要出现 else，全部展开成 else if 方便理解。

2、注意「搜索区间」和 while 的终止条件，如果存在漏掉的元素，记得在最后检查。

3、如需定义左闭右开的「搜索区间」搜索左右边界，只要在`nums[mid] == target`时做修改即可，搜索右侧时需要减一。

4、如果将「搜索区间」全都统一成两端都闭，好记，只要稍改`nums[mid] == target`条件处的代码和返回的逻辑即可，**推荐拿小本本记下，作为二分搜索模板**。

现在可以去把我做的诗多读几遍，体会体会其中的味道，加深理解，哈哈哈！
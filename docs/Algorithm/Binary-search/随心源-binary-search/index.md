# [随心源](https://leetcode.cn/u/sui-xin-yuan/) binary search

1、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [34. 蓝红二分法单模板秒杀二分查找](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/solution/lan-hong-hua-fen-fa-dan-mo-ban-miao-sha-e7r40/) 

2、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [1201. 蓝红二分法分左右](https://leetcode.cn/problems/ugly-number-iii/solution/by-sui-xin-yuan-o8zd/) 

3、[随心源](https://leetcode.cn/u/sui-xin-yuan/) # [二分查找模块全解](https://leetcode.cn/circle/article/xYBtLt/) 



## [六款二分查找模板，哪款才是你的菜？](https://leetcode.cn/circle/discuss/ObmjbJ/)

> NOTE:
>
> 一、这篇文章虽然给出了多种binary-search的写法，个人觉得只需要掌握其中一种即可，我最最熟悉的就是"模板一: 左闭右闭"

### 模板介绍

### 模板一: 左闭右闭

#### normal

```c++
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
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
            right = mid - 1;
        }
    }

    // End Condition: left > right
    return -1;
}

```

查找等于 `target` 的第一个元素下标，即查找 `target` 左边界。

#### left bound

```c++
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    // End Condition: left > right
    if (left != nums.size() && nums[left] == target)
        return left;
    return -1;
}

```

#### right bound

查找等于 `target` 的最后一个元素下标，即查找 `target` 右边界。

```c++
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    // End Condition: left > right
    if (right != -1 && nums[right] == target)
        return right;
    return -1;
}

```



### 模板二: 左闭右开

Python中bisect源码实现模板，右边界可对应C++中end迭代器。

左闭右开的区间分割方式在数学和计算机中都极为普遍。

#### normal

```c++
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size();
    while (left < right)
    {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
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

    // Post-processing:
    // End Condition: left == right
    if (left != nums.size() && nums[left] == target)
        return left;
    return -1;
}

```



#### left bound

查找等于 `target` 的第一个元素下标，即查找 `target` 左边界。



```c++
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size();
    while (left < right)
    {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left == right
    if (left != nums.size() && nums[left] == target)
        return left;
    return -1;
}

```



#### right bound

查找等于 `target` 的最后一个元素下标，即查找 `target` 右边界。



```c++
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size();
    while (left < right)
    {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left == right
    if (left != nums.size() && nums[left] == target)
        return left;
    if (left > 0 && nums[left - 1] == target)
        return left - 1;
    return -1;
}

```



## [二分查找模块全解](https://leetcode.cn/circle/article/xYBtLt/) 



### 二分查找入门


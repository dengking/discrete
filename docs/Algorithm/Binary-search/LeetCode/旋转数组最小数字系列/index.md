# 旋转数组的最小值



| 题目                                                         |                                |
| ------------------------------------------------------------ | ------------------------------ |
| [153. 寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/) | 元素值 **互不相同**的数组      |
| [154. 寻找旋转排序数组中的最小值 II](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/) | 可能存在 **重复** 元素值的数组 |
| [剑指 Offer 11. 旋转数组的最小数字](https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/) | 这道题和154一模一样            |

两段分别单调递增。

**二分查找**会拿**目标值**和 `nums[mid]` 进行比较以此来判断**目标值**是位于**前半段**还是**后半段**，如果忽视 `nums[mid]==target` 的情况，其实二分查找是不断的向**目标值**靠拢的。这一点，left-bound和right-bound更加突出。

**二分查找**本质上是通过比较 `nums[mid]` 和pivot，从而决定是否舍弃left或right之外的元素，从而不断地向目标靠近。

**二分查找**选择的pivot是target，这个系列的题目选择的pivot是后半段的最大值，通过`nums[mid]` 和pivot进行比较，可以判断pivot位于`nums[mid]` 左边还是右边，是否舍弃left或right之外的元素，从而不断地向目标靠近。



这两道题的本质和**二分查找**类似，它利用**前段元素**肯定是大于**后段元素**、最小值肯定位于后段、前段元素和后段元素是单调递增的特性，通过`nums[mid]`和后段元素最大值进行比较，从而可以很快判断`nums[mid]`是位于目标值左边还是右边、**前段**还是位于**后段**，然后决定是否舍弃left或right之外的元素，从而不断地向目标靠近。关于此，在 [寻找旋转排序数组中的最小值 # 官方解题](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-5irwp/) 中给出了很好的图示。

这个系列其实是可以看作是一种泛化的二分查找。

[寻找旋转排序数组中的最小值 # 官方解题](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-5irwp/) 

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else {
                low = pivot + 1;
            }
        }
        return nums[low];
    }
};
```

由于数组不包含重复元素，并且只要当前的区间长度不为 1，$\it pivot$ 就不会与 $\it high $重合；

> NOTE:
>
> 一、上述解法也超越了我对二分查找的认知，下面的写法是基于左闭右闭的，但是它是while条件是`low < high`
>
> 二、由于题目说了不存在重复的元素，因此上面这道题是不需要考虑相等的情况的



下面是我的写法:

```c++

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] < nums[right])
      {
        right = mid;
      }
      else if (nums[mid] > nums[right])
      {
        left = mid + 1;
      }
      else // 由于题目限制数组各个元素互不相同，因此nums[mid] == nums[right] 的唯一情况是 left == right，也就是它们指向同一个元素
      {
        break;
      }
    }
    return nums[left];
  }
};
```



[寻找旋转排序数组中的最小值 II # 官方解题](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/solution/xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-de-zui--16/)

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return nums[low];
    }
};

```

> NOTE:
>
> 上述写法就非常类似于`left_bound`



这道题和二分查找还是有种很大的却别的，因为二分查找的目标的目标不一定存在于数组中，因此它需要检查最后一个元素是否是目标值，因此二分查找的经典写法是`while(left == right)`，而这个系列的题目，它是要寻找最小值，显然这个最小值是肯定存在的，因此它只需要不断地进行逼近，当只剩下一个元素的时候，那这个元素一定是最小值，因此的循环条件是 `while (low < high)`，其实如果从这个角度来看的话，那么这个算法是比较好理解的: 不断的舍弃掉比最小值大的元素，那么剩下的元素肯定是最小值了。

这种用法其实是二分查找的一个简单变形。
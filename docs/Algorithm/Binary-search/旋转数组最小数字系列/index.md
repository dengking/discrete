# 旋转数组的最小值



leetcode [剑指 Offer 11. 旋转数组的最小数字](https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)





| 题目                                                         |                                |      |
| ------------------------------------------------------------ | ------------------------------ | ---- |
| [153. 寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/) | 元素值 **互不相同**的数组      |      |
| [154. 寻找旋转排序数组中的最小值 II](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/) | 可能存在 **重复** 元素值的数组 |      |
|                                                              |                                |      |

两段分别低调递增。

前段段元素肯定是大于后段的元素，最小值肯定位于后段。

**二分查找**会拿**目标值**和 `nums[mid]` 进行比较以此来判断**目标值**是位于**前半段**还是**后半段**，如果忽视 `nums[mid]==target` 的情况，其实二分查找是不断的向**目标值**靠拢的。这一点，left-bound和right-bound更加突出。

二分查找选择的pivot是target，这个系列的题目选择的pivot是后半段的最大值，通过`nums[mid]` 和pivot进行比较，可以判断是否舍弃left或right之外的元素


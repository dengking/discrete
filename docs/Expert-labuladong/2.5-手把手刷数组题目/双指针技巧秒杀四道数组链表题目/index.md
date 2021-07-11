# labuladong  [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ)

> NOTE: 
>
> leetcode [26. 删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)
>
> leetcode [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/) 
>
> 在 labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A) 中已经介绍了

## 有序数组/链表去重

> NOTE: 
>
> 1、fast 和 slow 之间的区域是可以使用的自由区域
>
> 2、它让我想起了"Erase-remove-idiom"
>
> 3、在 labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A) 中，已经对这个topic进行了深入的分析，此处略过。



## 移除元素

> NOTE:
>
> 1、其实它的实现思路是非常简单的: 将所有不等于待删除值的元素(需要保留的元素)都移到`[0, slow]`内

### leetcode [27. 移除元素](https://leetcode-cn.com/problems/remove-element/)



如果`fast`遇到需要去除的元素，则直接跳过，否则就告诉`slow`指针，并让`slow`前进一步。

这和前面说到的数组去重问题解法思路是完全一样的，就不画 GIF 了，直接看代码：

```Java
int removeElement(int[] nums, int val) {
    int fast = 0, slow = 0;
    while (fast < nums.length) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}
```

**注意这里和有序数组去重的解法有一个重要不同**，我们这里是先给`nums[slow]`赋值然后再给`slow++`，这样可以保证`nums[0..slow-1]`是不包含值为`val`的元素的，最后的结果数组长度就是`slow`。

## 移动零

### leetcode [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/)

这是力扣第 283 题，我来描述下题目：

给你输入一个数组`nums`，请你**原地修改**，将数组中的所有值为 0 的元素移到数组末尾，函数签名如下：

```java
void moveZeroes(int[] nums);
```

比如说给你输入`nums = [0,1,4,0,2]`，你的算法没有返回值，但是会把`nums`数组原地修改成`[1,4,2,0,0]`。

结合之前说到的几个题目，你是否有已经有了答案呢？

题目让我们将所有 0 移到最后，其实就相当于移除`nums`中的所有 0，然后再把后面的元素都赋值为 0 即可。

所以我们可以复用上一题的`removeElement`函数：

```java
void moveZeroes(int[] nums) {
    // 去除 nums 中的所有 0
    // 返回去除 0 之后的数组长度
    int p = removeElement(nums, 0);
    // 将 p 之后的所有元素赋值为 0
    for (; p < nums.length; p++) {
        nums[p] = 0;
    }
}

// 见上文代码实现
int removeElement(int[] nums, int val);
```

至此，四道「原地修改」的算法问题就讲完了，其实核心还是快慢指针技巧，你学会了吗？



#### [官方解题](https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/)

> NOTE: 
>
> 相比于 labuladong  [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ) 中给出的答案，官方的显然更优，在 `LeetCode-283-移动零` 章节中，对 [官方解题](https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/) 进行了说明。
>
> ```C++
> class Solution {
> public:
>     void moveZeroes(vector<int>& nums) {
>         int n = nums.size(), left = 0, right = 0;
>         while (right < n) {
>             if (nums[right]) {
>                 swap(nums[left], nums[right]);
>                 left++;
>             }
>             right++;
>         }
>     }
> };
> 
> 
> ```
>
> 
>
> 




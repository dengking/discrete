# LeetCode [540. 有序数组中的单一元素](https://leetcode.cn/problems/single-element-in-a-sorted-array/) 中等

假定target的下标为`x`，

在`x`的左边: 

1、如果y为偶数，a[y] == a[y+1]

2、如果y为奇数，a[y] == a[y-1]

在`x`的右边:

1、如果y为偶数，a[y] == a[y-1]

2、如果y为奇数，a[y] == a[y+1]

何时判断找到了目标呢？

二分查找来判断当前位于目标的左边还是右边。

```C++
int left = 0;
int right = 0;

while(left < right):
    int mid = (left + right) / 2;
    if(mid>>1 == 0) // 偶数
    {
        nums[mid] == nums[y+1] 
    }else{
        
    }
```


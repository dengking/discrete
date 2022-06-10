# LeetCode [135. 分发糖果](https://leetcode.cn/problems/candy/)

从左到右单调递增子数组、从左到右单调递减子数组，比如下面的:

例子一:

```
5,7,8,3,4,2,1
```

`5,7,8` 就是 单调递增子数组，显然8最少需要3个糖果，这可以通过从左到右遍历

`4,2,1` 就是 单调递减子数组，显然4最少需要3个糖果，这可以通过从右到左遍历

例子二:

```
5,6,7,6,5,4,3,2,1
```

`5,6,7` 就是 单调递增子数组，显然7最少需要3个糖果，这可以通过从左到右遍历

`7,6,5,4,3,2,1` 就是 单调递减子数组，显然7最少需要7个糖果，这可以通过从右到左遍历

在LeetCode [406. 根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height/) 的解题 [Gnakuw](https://leetcode.cn/u/nehzil/) # [【贪心思想「模拟队列插入图解」】](https://leetcode.cn/problems/queue-reconstruction-by-height/solution/by-nehzil-1z3g/) 中也提及了本题的解题思路。



## [Krahets](https://leetcode.cn/u/jyd/) # [分发糖果 （贪心思想，线性复杂度，清晰图解）](https://leetcode.cn/problems/candy/solution/candy-cong-zuo-zhi-you-cong-you-zhi-zuo-qu-zui-da-/)


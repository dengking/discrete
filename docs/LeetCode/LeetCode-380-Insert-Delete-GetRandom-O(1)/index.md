# LeetCode [380. Insert Delete GetRandom O(1)](https://leetcode.cn/problems/insert-delete-getrandom-o1/) 中等

一、https://leetcode.cn/problems/insert-delete-getrandom-o1/solution/by-ac_oier-tpex/1504113

> 总结一下：这其实考察的是**链表**和**数组**的特点，想要把他们优点兼具，要么链表+hash，要么数组+hash，但这两种结合还是有瑕疵，需要一些细节处理，比如链表+hash，不好按idx查找，也是这个原因我们选择了数组+hash。。。。 这是个知识点，学到了！

二、删除交换

**LeetCode** [【宫水三叶】数据结构运用题](https://leetcode.cn/problems/insert-delete-getrandom-o1/solution/by-ac_oier-tpex/) 

> 哈希表 + 删除交换

这个总结非常好



三、weixin 宫水三叶 [【月度刷题计划同款】巧用哈希表实现随机操作](https://mp.weixin.qq.com/s/bNFJT1JJcaFOi8iSnld22Q)

> **为了确保严格 $O(1)$，我们不能「使用拒绝采样」和「在数组非结尾位置添加/删除元素」。**
>
> 因此我们需要申请一个足够大的数组 `nums`（利用数据范围为 $2 * 10^5$），并使用变量 `idx` 记录当前使用到哪一位（即下标在 $[0, idx]$ 范围内均是存活值）。



四、C++随机数操作

参见 cppreference [Pseudo-random number generation](https://en.cppreference.com/w/cpp/numeric/random)


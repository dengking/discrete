# labuladong [手把手搞懂接雨水问题的多种解法](https://mp.weixin.qq.com/s/mFqrlhqYEPhRa9p4ewl3Xw)

接雨水这道题目挺有意思，在面试题中出现频率还挺高的，本文就来步步优化，讲解一下这道题：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdETSibChZ6NaonURayySXExwkiaibkEUf1MleYZqhmb8LibB6xlAhRWKKJj6FVE9546U1NYZ9ibnicNpiceQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



就是用一个数组表示一个条形图，问你这个条形图最多能接多少水，函数签名如下：

```c++
int trap(int[] height);
```

下面就来由浅入深介绍**暴力解法 -> 备忘录解法 -> 双指针解法**，在 O(N) 时间 O(1) 空间内解决这个问题。

## 一、暴力解法

### Sub problem

对于这种问题，我们不要想整体，而应该去想局部；就像之前的文章写的动态规划问题处理字符串问题，不要考虑如何处理整个字符串，而是去思考应该如何处理每一个字符。

这么一想，可以发现这道题的思路其实很简单。具体来说，仅仅对于位置`i`，能装下多少水呢？

> NOTE: 
>
> 一、上述讲述的是分析问题的思路(参见`How-to-analysis`章节)，它体现了:
>
> 1、divide and conquer
>
> 2、problem and sub problem

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdETSibChZ6NaonURayySXExwniaqbgtaIrYhZ9X17T0JJ2QNrXdibHudUqKic9S8J9fD3qvJPicBcbqYtA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

能装 2 格水，因为`height[i]`的高度为 0，而这里最多能盛 2 格水，2-0=2。

为什么位置`i`最多能盛 2 格水呢？因为，位置`i`能达到的水柱高度和其左边的最高柱子、右边的最高柱子有关，我们分别称这两个柱子高度为`l_max`和`r_max`；**位置 i 最大的水柱高度就是`min(l_max, r_max)`。**

更进一步，对于位置`i`，能够装的水为：

```
water[i] = min(
               # 左边最高的柱子
               max(height[0..i]),  
               # 右边最高的柱子
               max(height[i..end]) 
            ) - height[i]
```

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdETSibChZ6NaonURayySXExwV9XKokzchEdjnbSqf5Pfj9AANJpDTJyicUemKcVc2b4A2ydFqb9rhPg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)这就是本问题的核心思路，我们可以简单写一个暴力算法：

```c++
int trap(vector<int>& height) {
    int n = height.size();
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
        int l_max = 0, r_max = 0;
        // 找右边最高的柱子
        for (int j = i; j < n; j++)
            r_max = max(r_max, height[j]);
        // 找左边最高的柱子
        for (int j = i; j >= 0; j--)
            l_max = max(l_max, height[j]);
        // 如果自己就是最高的话，
        // l_max == r_max == height[i]
        res += min(l_max, r_max) - height[i];
    }
    return res;
}
```

有之前的思路，这个解法应该是很直接粗暴的，时间复杂度 O(N^2)，空间复杂度 O(1)。但是很明显这种计算`r_max`和`l_max`的方式非常笨拙，一般的优化方法就是**备忘录**。

> NOTE: 
>
> 1、下面的我第一次写的错误的程序:
>
> ```C++
> #include<vector>
> #include<iostream>
> #include <algorithm>    // std::max
> using namespace std;
> 
> int trap(vector<int> &height)
> {
> 	int res = 0;
> 	int len = height.size();
> 
> 	int l_max = height[0];
> 	int r_max = 0;
> 	/**
> 	 * i 从 1 开始，是因为第0个，肯定无法积水
> 	 */
> 	for (int i = 1; i < height.size(); ++i)
> 	{
> 
> 		l_max = max(l_max, height[i - 1]);
> 
> 		for (int j = i + 1; j < len; j++)
> 		{
> 			r_max = max(r_max, height[j]);
> 		}
> 		if (l_max > height[i] && r_max > height[i])
> 		{
> 			res += (min(l_max, r_max) - height[i]);
> 		}
> 	}
> 	return res;
> }
> 
> int main()
> {
> 	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
> 	cout << trap(height);
> }
> // g++ --std=c++11 test.cpp
> 
> ```
>
> 它的错误之处在于在于将`int r_max = 0;`放在了`for`循环之外，这就导致了`r_max`一直是`height[0:i]`的最大值，而不是我们设计的`height[i+1:-1]`的最大值。
>
> 下面是正确的代码:
>
> ```C++
> #include<vector>
> #include<iostream>
> #include <algorithm>    // std::max
> using namespace std;
> 
> int trap(vector<int> &height)
> {
> 	int res = 0;
> 	int len = height.size();
> 
> 	int l_max = height[0];
> 
> 	/**
> 	 * i 从 1 开始，是因为第0个，肯定无法积水
> 	 */
> 	for (int i = 1; i < height.size(); ++i)
> 	{
> 
> 		l_max = max(l_max, height[i - 1]);
> 		int r_max = 0;
> 		for (int j = i + 1; j < len; j++)
> 		{
> 			r_max = max(r_max, height[j]);
> 		}
> 		if (l_max > height[i] && r_max > height[i])
> 		{
> 			res += (min(l_max, r_max) - height[i]);
> 		}
> 	}
> 	return res;
> }
> 
> int main()
> {
> 	vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
> 	cout << trap(height) << "\n";
> }
> // g++ --std=c++11 test.cpp
> 
> ```
>
> 

## 二、备忘录优化

之前的暴力解法，不是在每个位置`i`都要计算`r_max`和`l_max`吗？我们直接把结果都提前计算出来，别傻不拉几的每次都遍历，这时间复杂度不就降下来了嘛。

**我们开两个数组`r_max`和`l_max`充当备忘录，`l_max[i]`表示位置`i`左边最高的柱子高度，`r_max[i]`表示位置`i`右边最高的柱子高度**。预先把这两个数组计算好，避免重复计算：

```c++
int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int n = height.size();
    int res = 0;
    // 数组充当备忘录
    vector<int> l_max(n), r_max(n);
    // 初始化 base case
    l_max[0] = height[0];
    r_max[n - 1] = height[n - 1];
    // 从左向右计算 l_max
    for (int i = 1; i < n; i++)
        l_max[i] = max(height[i], l_max[i - 1]);
    // 从右向左计算 r_max
    for (int i = n - 2; i >= 0; i--) 
        r_max[i] = max(height[i], r_max[i + 1]);
    // 计算答案
    for (int i = 1; i < n - 1; i++) 
        res += min(l_max[i], r_max[i]) - height[i];
    return res;
}
```

这个优化其实和暴力解法思路差不多，就是避免了重复计算，把时间复杂度降低为 O(N)，已经是最优了，但是空间复杂度是 O(N)。下面来看一个精妙一些的解法，能够把空间复杂度降低到 O(1)。

## 三、双指针解法

> NOTE: 
>
> 1、只要确保左侧、右侧有更高的，那么就可以积水，不管中间有没有更加高的，可能中间有更高的，但是它能够积水的量是取决于较小值，而不是较高值。因此当需要计算当前current pointer的积水深度，计算方式为: `min(l_max, r_max) - height[current]`。
>
> 下面程序中的`if (l_max < r_max)` 其实就是为了取得`min(l_max, r_max)`。 
>
> 下面的这种算法就运用了这种思路。
>
> 2、左右指针中，也有current pointer
>
> 3、原文没有介绍的是，当`height[current]`与max height相等的时候，则它们的差肯定是0，即它的积水肯定是0
>
> 4、这种写法的一个优势是: **`l_max`是`height[0..left]`中最高柱子的高度，`r_max`是`height[right..n-1]`的最高柱子的高度**
>
> 因此，求解`l_max`、`r_max`是可以增量式的，即下面所说的**边走边算**，显然这比前面的为求解最大值，而遍历整个要有很大的优势
>
> 先计算`l_max`、`r_max`，然后计算**积水深度**，那一侧的跟小，就先计算哪一侧的积水深度。
>
> 必须要逐个计算，即one-by-one。
>
> 5、当`max_height` 和 current pointer的height相同的时候，并不会积水，即积水深度为0，因此仍然可以使用上述算法进行计算积水深度。
>
> 6、如何滑动`left`、`right` pointer？
>
> 7、

这种解法的思路是完全相同的，但在实现手法上非常巧妙，我们这次也不要用备忘录提前计算了，而是用双指针**边走边算**，节省下空间复杂度。

### `l_max`和`r_max`分别表示什么意义呢？

首先，看一部分代码：

```c++
int trap(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;

    int l_max = height[0];
    int r_max = height[n - 1];

    while (left <= right) {
        l_max = max(l_max, height[left]);
        r_max = max(r_max, height[right]);
        left++; right--;
    }
}
```

对于这部分代码，请问`l_max`和`r_max`分别表示什么意义呢？

很容易理解，**`l_max`是`height[0..left]`中最高柱子的高度，`r_max`是`height[right..n-1]`的最高柱子的高度**。

### 解法

明白了这一点，直接看解法：

```c++
int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;

    int l_max = height[0];
    int r_max = height[n - 1];

    while (left <= right) {
        l_max = max(l_max, height[left]);
        r_max = max(r_max, height[right]);

        // res += min(l_max, r_max) - height[i]
        if (l_max < r_max) {
            res += l_max - height[left];
            left++; 
        } else {
            res += r_max - height[right];
            right--;
        }
    }
    return res;
}
```

> NOTE: 
>
> 1、循环体内，每次只有一个pointer移动
>
> [1,1,3,1]
>
> l_max = 1, r_max = 1
>
> 

你看，其中的核心思想和之前一模一样，换汤不换药。但是细心的读者可能会发现次解法还是有点细节差异：

### 两种接法的差异

#### 备忘录解法

之前的备忘录解法，`l_max[i]`和`r_max[i]`分别代表`height[0..i]`和`height[i..n-1]`的最高柱子高度。

```c++
res += min(l_max[i], r_max[i]) - height[i];
```



![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdETSibChZ6NaonURayySXExwHfNV1P1kGltmiatQKxBxAFl14XTYy4ChxaDe6KbBCKo9VjvVkXldXXg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)但是双

#### 双指针解法

指针解法中，`l_max`和`r_max`代表的是`height[0..left]`和`height[right..n-1]`的最高柱子高度。比如这段代码：

```c++
if (l_max < r_max) {
    res += l_max - height[left];
    left++; 
} 
```



![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdETSibChZ6NaonURayySXExwU44iahfarfibnVHibIyVibXwLUEZrPuN1K1xT56osz10pJO9LcxmicKEnkA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

此时的`l_max`是`left`指针左边的最高柱子，但是`r_max`并不一定是`left`指针右边最高的柱子，这真的可以得到正确答案吗？

其实这个问题要这么思考，我们只在乎`min(l_max, r_max)`。**对于上图的情况，我们已经知道`l_max < r_max`了，至于这个`r_max`是不是右边最大的，不重要。重要的是`height[i]`能够装的水只和较低的`l_max`之差有关**：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdETSibChZ6NaonURayySXExwiaUOrQ7MY4bZt20SCD4OAqOeicaBwzBfMiaCfAWtsDJBociaeTf2vEOHKw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

这样，接雨水问题就解决了，学会了吗？三连安排！
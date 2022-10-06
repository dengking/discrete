# labuladong [经典动态规划：0-1背包问题的变体](https://mp.weixin.qq.com/s/OzdkF30p5BHelCi6inAnNg)

上篇文章 [经典动态规划：0-1 背包问题](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485064&idx=1&sn=550705eb67f5e71487c8b218382919d6&chksm=9bd7f880aca071962a5a17d0f85d979d6f0c5a5ce32c84b8fee88e36d451f9ccb3bb47b88f78&scene=21#wechat_redirect) 详解了通用的 0-1 背包问题，今天来看看背包问题的思想能够如何运用到其他算法题目。

> NOTE: 
>
> [LeetCode-416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/) 中等
>
> 

## 一、问题分析

先看一下题目：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdH4BiajD8HeXJSPSVviccPkjLAJxmP9Kto2Uqwjtv0AOYx9brfPaeSicxYPpjFzKarQygiaKGHYyV7F4w/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



那么对于这个问题，我们可以先对集合求和，得出`sum`，把问题转化为背包问题：

**给一个可装载重量为`sum/2`的背包和`N`个物品，每个物品的重量为`nums[i]`。现在让你装物品，是否存在一种装法，能够恰好将背包装满**？

你看，这就是背包问题的模型，甚至比我们之前的经典背包问题还要简单一些，**下面我们就直接转换成背包问题**，开始套前文讲过的背包问题框架即可。

## 二、解法分析

### **第一步要明确两点，「状态」和「选择」**。

这个前文 [经典动态规划：0-1 背包问题](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485064&idx=1&sn=550705eb67f5e71487c8b218382919d6&chksm=9bd7f880aca071962a5a17d0f85d979d6f0c5a5ce32c84b8fee88e36d451f9ccb3bb47b88f78&scene=21#wechat_redirect) 已经详细解释过了，状态就是「背包的容量」和「可选择的物品」，选择就是「装进背包」或者「不装进背包」。

> NOTE: 
>
> 我之前一直把dp table记录的值称为**状态**，显然它是随着**选择**而变化的；选择想来，其实所谓**状态**其实就是"变量"，它既包括自变量，有包括因变量。

### **第二步要明确`dp`数组的定义**。

按照背包问题的套路，可以给出如下定义：

`dp[i][j] = x`表示，对于前`i`个物品，当前背包的容量为`j`时，若`x`为`true`，则说明可以恰好将背包装满，若`x`为`false`，则说明不能恰好将背包装满。

比如说，如果`dp[4][9] = true`，其含义为：对于容量为 9 的背包，若只是用前 4 个物品，可以有一种方法把背包恰好装满。

或者说对于本题，含义是对于给定的集合中，若只对前 4 个数字进行选择，存在一个子集的和可以恰好凑出 9。

根据这个定义，我们想求的最终答案就是`dp[N][sum/2]`。

#### base case

> NOTE: 
>
> 这个base case是容易出现错误的地方，我第一次写的时候就弄错了；
>
> 首先明白"装满"的含义: 所谓装满，即背包中没有空间了，即此时它的空间是0；对于这个问题，它要求的是能否装满，显然，当空间剩余0的时候，就能够装满了，显然需要将`dp[..][0] = true`。
>
> 至于 `dp[0][..] = false`，显然剩余空间非0，表示没有装满，显然就应该是false；
>
> 另外需要注意的是: `dp[0][0]`的值必须是`true`，表示装满了。
>
> 

base case 就是`dp[..][0] = true`和`dp[0][..] = false`，因为背包没有空间的时候，就相当于装满了，而当没有物品可选择的时候，肯定没办法装满背包。

### **第三步，根据「选择」，思考状态转移的逻辑**。

回想刚才的`dp`数组含义，可以根据「选择」对`dp[i][j]`得到以下状态转移：

如果不把`nums[i]`算入子集，**或者说你不把这第`i`个物品装入背包**，那么是否能够恰好装满背包，取决于上一个状态`dp[i-1][j]`，继承之前的结果。

如果把`nums[i]`算入子集，**或者说你把这第`i`个物品装入了背包**，那么是否能够恰好装满背包，取决于状态`dp[i - 1][j-nums[i-1]]`。

首先，由于`i`是从 1 开始的，而数组索引是从 0 开始的，所以第`i`个物品的重量应该是`nums[i-1]`，这一点不要搞混。

`dp[i - 1][j-nums[i-1]]`也很好理解：你如果装了第`i`个物品，就要看背包的剩余重量`j - nums[i-1]`限制下是否能够被恰好装满。

换句话说，如果`j - nums[i-1]`的重量可以被恰好装满，那么只要把第`i`个物品装进去，也可恰好装满`j`的重量；否则的话，重量`j`肯定是装不满的。

### **最后一步，把伪码翻译成代码，处理一些边界情况**。

以下是我的 C++ 代码，完全翻译了之前的思路，并处理了一些边界情况：

```C++
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) sum += num;
    // 和为奇数时，不可能划分成两个和相等的集合
    if (sum % 2 != 0) return false;
    int n = nums.size();
    sum = sum / 2;
    vector<vector<bool>> 
        dp(n + 1, vector<bool>(sum + 1, false));
    // base case
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - nums[i - 1] < 0) {
               // 背包容量不足，不能装入第 i 个物品
                dp[i][j] = dp[i - 1][j]; 
            } else {
                // 装入或不装入背包
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j-nums[i-1]];
            }
        }
    }
    return dp[n][sum];
}
```

## 三、进行状态压缩

再进一步，是否可以优化这个代码呢？**注意到`dp[i][j]`都是通过上一行`dp[i-1][..]`转移过来的**，之前的数据都不会再使用了。

所以，我们可以进行状态压缩，将二维`dp`数组压缩为一维，节约空间复杂度：

```C++
bool canPartition(vector<int>& nums) {
    int sum = 0, n = nums.size();
    for (int num : nums) sum += num;
    if (sum % 2 != 0) return false;
    sum = sum / 2;
    vector<bool> dp(sum + 1, false);
    // base case
    dp[0] = true;

    for (int i = 0; i < n; i++) 
        for (int j = sum; j >= 0; j--) 
            if (j - nums[i] >= 0) 
                dp[j] = dp[j] || dp[j - nums[i]];

    return dp[sum];
}
```

> NOTE: 
>
> 需要注意，上述程序看起来简短，实际上蕴藏玄机，我第一次写的时候，就出现了错误；它的玄机在:
>
> ```C++
> for (int j = sum; j >= 0; j--)
> ```
>
> 它是从后往前进行计算，这样它就可以使用"上一行"的值了
>
> 需要对比前后代码才能够体会它的奥妙。

这就是状态压缩，其实这段代码和之前的解法思路完全相同，只在一行`dp`数组上操作，`i`每进行一轮迭代，`dp[j]`其实就相当于`dp[i-1][j]`，所以只需要一维数组就够用了。

**唯一需要注意的是`j`应该从后往前反向遍历，因为每个物品（或者说数字）只能用一次，以免之前的结果影响其他的结果**。

至此，子集切割的问题就完全解决了，时间复杂度 O(n*sum)，空间复杂度 O(sum)。 
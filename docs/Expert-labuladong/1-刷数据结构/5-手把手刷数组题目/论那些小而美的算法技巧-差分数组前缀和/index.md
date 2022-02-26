# labuladong [论那些小而美的算法技巧：差分数组/前缀和](https://mp.weixin.qq.com/s/9L6lz0XDZ9gi-d_iPrSs8Q) 

差分数组技巧是前文 [前缀和技巧详解](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484488&idx=1&sn=848f76e86fce722e70e265d0c6f84dc3&chksm=9bd7fa40aca07356a6f16db72f5a56529044b1bdb2dcce2de4efe59e0338f0c313de682aef29&scene=21#wechat_redirect) 写过的前缀和技巧的兄弟。

## 前缀和

**前缀和主要适用的场景是原始数组不会被修改的情况下，频繁查询某个区间的累加和**。

没看过前文没关系，这里简单介绍一下前缀和，核心代码就是下面这段：

```Java
class PrefixSum {
    // 前缀和数组
    private int[] prefix;

    /* 输入一个数组，构造前缀和 */
    public PrefixSum(int[] nums) {
        prefix = new int[nums.length + 1];
        // 计算 nums 的累加和
        for (int i = 1; i < prefix.length; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }

    /* 查询闭区间 [i, j] 的累加和 */
    public int query(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }
}
```

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFicoB9v8FldTQsBqMehNXag9WbxYLpUbSo5YI1Y80ia8IMdiaXWn3tOSAibmhSwib1HBJCEAX241KJVsg/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

`prefix[i]`就代表着`nums[0..i-1]`所有元素的累加和，如果我们想求区间`nums[i..j]`的累加和，只要计算`prefix[j+1] - prefix[i]`即可，而不需要遍历整个区间求和。

## 差分数组

本文讲一个和前缀和思想非常类似的算法技巧「差分数组」，**差分数组的主要适用场景是频繁对原始数组的某个区间的元素进行增减**。

比如说，我给你输入一个数组`nums`，然后又要求给区间`nums[2..6]`全部加 1，再给`nums[3..9]`全部减 3，再给`nums[0..4]`全部加 2，再给…

一通操作猛如虎，然后问你，最后`nums`数组的值是什么？

常规的思路很容易，你让我给区间`nums[i..j]`加上`val`，那我就一个 for 循环给它们都加上呗，还能咋样？这种思路的时间复杂度是 O(N)，由于这个场景下对`nums`的修改非常频繁，所以效率会很低下。

这里就需要差分数组的技巧，类似前缀和技巧构造的`prefix`数组，我们先对`nums`数组构造一个`diff`差分数组，**`diff[i]`就是`nums[i]`和`nums[i-1]`之差**：

```Java
int[] diff = new int[nums.length];
// 构造差分数组
diff[0] = nums[0];
for (int i = 1; i < nums.length; i++) {
    diff[i] = nums[i] - nums[i - 1];
}
```

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFicoB9v8FldTQsBqMehNXagficybOeOaib653BnBQQOValk5UHPTjO3HiaLwDaicibI5V1fCzlFsYVfwUw/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

## 从差分数组反推原数组

通过这个`diff`差分数组是可以反推出原始数组`nums`的，代码逻辑如下：

```Java
int[] res = new int[diff.length];
// 根据差分数组构造结果数组
res[0] = diff[0];
for (int i = 1; i < diff.length; i++) {
    res[i] = res[i - 1] + diff[i];
}
```

> NOTE:
>
> 需要注意的是: 差分数组的第0个元素始终都是对应的原数组的值，而不是差值，这是比较特殊的

## 使用差分数组进行区间快速操作

**这样构造差分数组`diff`，就可以快速进行区间增减的操作**，如果你想对区间`nums[i..j]`的元素全部加 3，那么只需要让`diff[i] += 3`，然后再让`diff[j+1] -= 3`即可：


![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFicoB9v8FldTQsBqMehNXagNIQm2SFJKUqJ4lLLkyeiansEJwsL4TTqPcuSAibdFFUjGXy0XmiaFlicUQ/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

**原理很简单，回想`diff`数组反推`nums`数组的过程，`diff[i] += 3`意味着给`nums[i..]`所有的元素都加了 3，然后`diff[j+1] -= 3`又意味着对于`nums[j+1..]`所有元素再减 3，那综合起来，是不是就是对`nums[i..j]`中的所有元素都加 3 了**？

只要花费 O(1) 的时间修改`diff`数组，就相当于给`nums`的整个区间做了修改。多次修改`diff`，然后通过`diff`数组反推，即可得到`nums`修改后的结果。

> NOTE: 
>
> 显然让两数之差增大有两种方式: 
>
> 1、增大 *被减数*
>
> 2、减小 *减数*
>
> 对差分数组的修改我们选择的是对*被减数*的修改；
>
> 由于差分数组的定义是环环相扣的:
>
> ```python
> diff[i] = nums[i] - nums[i - 1];
> ```
>
> 因此对 `diff[i]` 的修改，相当于原数组中，`i`后面的所有数都被修改了，因为: 
>
> 如果让 `diff[i]` 加上 `inc`，那么就意味着 `nums[i]` 加上了 `inc`；而`diff[i+1]` 又要维持不变，因此需要让`nums[i+1]` 加上了 `inc`。
>
> 当涉及区间的时候，我们只需要在区间的起止减小相反的修改即可。
>
> 

### 把差分数组抽象成一个类

现在我们把差分数组抽象成一个类，包含`increment`方法和`result`方法：

```java
class Difference {
    // 差分数组
    private int[] diff;

    public Difference(int[] nums) {
        assert nums.length > 0;
        diff = new int[nums.length];
        // 构造差分数组
        diff[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    /* 给闭区间 [i,j] 增加 val（可以是负数）*/
    public void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.length) {
            diff[j + 1] -= val;
        }
    }

    public int[] result() {
        int[] res = new int[diff.length];
        // 根据差分数组构造结果数组
        res[0] = diff[0];
        for (int i = 1; i < diff.length; i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
}
```

这里注意一下`increment`方法中的 if 语句：

```
public void increment(int i, int j, int val) {
    diff[i] += val;
    if (j + 1 < diff.length) {
        diff[j + 1] -= val;
    }
}
```

当`j+1 >= diff.length`时，说明是对`nums[i]`及以后的整个数组都进行修改，那么就不需要再给`diff`数组减`val`了。
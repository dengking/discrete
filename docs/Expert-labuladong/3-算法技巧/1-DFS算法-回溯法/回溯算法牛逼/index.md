# labuladong [回溯算法牛逼！](https://mp.weixin.qq.com/s/fsLKaWBvSWtM0jA-CfOxyA)



## leetcode [698. 划分为k个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/)

本文就来看一道非常经典的回溯算法问题，子集划分问题，可以帮你更深刻理解回溯算法的思维，得心应手地写出回溯函数。

题目非常简单：

给你输入一个数组`nums`和一个正整数`k`，请你判断`nums`是否能够被平分为元素和相同的`k`个子集。

函数签名如下：

```Java
boolean canPartitionKSubsets(int[] nums, int k);
```

## 一、思路分析

把装有`n`个数字的数组`nums`分成`k`个和相同的集合，你可以想象将`n`个数字分配到`k`个「桶」里，最后这`k`个「桶」里的数字之和要相同。

前文 [回溯算法框架套路](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484709&idx=1&sn=1c24a5c41a5a255000532e83f38f2ce4&chksm=9bd7fb2daca0723be888b30345e2c5e64649fc31a00b05c27a0843f349e2dd9363338d0dac61&scene=21#wechat_redirect) 说过，回溯算法的关键在哪里？

关键是要知道怎么「做选择」，这样才能利用递归函数进行穷举。

那么回想我们这个问题，将`n`个数字分配到`k`个桶里，我们可以有两种视角：

**视角一，如果我们切换到这`n`个数字的视角，每个数字都要选择进入到`k`个桶中的某一个**。

**视角二，如果我们切换到这`k`个桶的视角，对于每个桶，都要遍历`nums`中的`n`个数字，然后选择是否将当前遍历到的数字装进自己这个桶里**。

## 二、以数字的视角

> NOTE: 
>
> 每个数字选择进入哪个桶中

用 for 循环迭代遍历`nums`数组大家肯定都会：

```Java
for (int index = 0; index < nums.length; index++) {
    System.out.println(nums[index]);
}
```



递归遍历数组你会不会？其实也很简单：

```Java
void traverse(int[] nums, int index) {
    if (index == nums.length) {
        return;
    }
    System.out.println(nums[index]);
    traverse(nums, index + 1);
}
```

只要调用`traverse(nums, 0)`，和 for 循环的效果是完全一样的。

那么回到这道题，以数字的视角，选择`k`个桶，用 for 循环写出来是下面这样：

```Java
// k 个桶（集合），记录每个桶装的数字之和
int[] bucket = new int[k];

// 穷举 nums 中的每个数字
for (int index = 0; index < nums.length; index++) {
    // 穷举每个桶
    for (int i = 0; i < k; i++) {
        // nums[index] 选择是否要进入第 i 个桶
        // ...
    }
}
```



如果改成递归的形式，就是下面这段代码逻辑：

```Java
// k 个桶（集合），记录每个桶装的数字之和
int[] bucket = new int[k];

// 穷举 nums 中的每个数字
void backtrack(int[] nums, int index) {
    // base case
    if (index == nums.length) {
        return;
    }
    // 穷举每个桶
    for (int i = 0; i < bucket.length; i++) {
        // 选择装进第 i 个桶
        bucket[i] += nums[index];
        // 递归穷举下一个数字的选择
        backtrack(nums, index + 1);
        // 撤销选择
        bucket[i] -= nums[index];
    }
}
```



虽然上述代码仅仅是穷举逻辑，还不能解决我们的问题，但是只要略加完善即可：

```Java
// 主函数
public boolean canPartitionKSubsets(int[] nums, int k) {
    // 排除一些基本情况
    if (k > nums.length) return false;
    int sum = 0;
    for (int v : nums) sum += v;
    if (sum % k != 0) return false;

    // k 个桶（集合），记录每个桶装的数字之和
    int[] bucket = new int[k];
    // 理论上每个桶（集合）中数字的和
    int target = sum / k;
    // 穷举，看看 nums 是否能划分成 k 个和为 target 的子集
    return backtrack(nums, 0, bucket, target);
}

// 递归穷举 nums 中的每个数字
boolean backtrack(
    int[] nums, int index, int[] bucket, int target) {

    if (index == nums.length) { // 所有的数都放完了
        // 检查所有桶的数字之和是否都是 target
        for (int i = 0; i < bucket.length; i++) {
            if (bucket[i] != target) {
                return false;
            }
        }
        // nums 成功平分成 k 个子集
        return true;
    }

    // 穷举 nums[index] 可能装入的桶
    for (int i = 0; i < bucket.length; i++) {
        // 剪枝，桶装装满了
        if (bucket[i] + nums[index] > target) {
            continue;
        }
        // 将 nums[index] 装入 bucket[i]
        bucket[i] += nums[index];
        // 递归穷举下一个数字的选择
        if (backtrack(nums, index + 1, bucket, target)) {
            return true;
        }
        // 撤销选择
        bucket[i] -= nums[index];
    }

    // nums[index] 装入哪个桶都不行
    return false;
}
```

> NOTE: 
>
> 一、思考为什么？
>
> ```Java
> // 递归穷举下一个数字的选择
> if (backtrack(nums, index + 1, bucket, target)) {
>     return true;
> }
> ```
>
> 这是因为，这道题是一个判断是否存在的问题，因此，只要找到了一个解，就可以返回了
>
> 二、
>
> ```C++
> if (i == nums.size()) // 所有的数都放完了
> ```
>
> 

## 三、以桶的视角

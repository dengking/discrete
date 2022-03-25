# labuladong [一个函数秒杀 2Sum 3Sum 4Sum 问题](https://mp.weixin.qq.com/s/fSyJVvggxHq28a0SdmZm6Q)



## 一、twoSum 问题

```C++
vector<int> twoSum(vector<int> &nums, int target)
{
	// 先对数组排序
	sort(nums.begin(), nums.end());
	// 左右指针
	int lo = 0, hi = nums.size() - 1;
	while (lo < hi)
	{
		int sum = nums[lo] + nums[hi];
		// 根据 sum 和 target 的比较，移动左右指针
		if (sum < target)
		{
			lo++;
		}
		else if (sum > target)
		{
			hi--;
		}
		else if (sum == target)
		{
			return
			{	nums[lo], nums[hi]};
		}
	}
	return {};
}

```

> NOTE: 
>
> 1、sort + binary search

### 不能出现重复对

**`nums` 中可能有多对儿元素之和都等于 `target`，请你的算法返回所有和为 `target` 的元素对儿，其中不能出现重复**。

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHfxtp5qR5JP6yLfVXia191D2KbvkgzyHqOMzlhESPJDeqHcVuzk20AKXHQXGCicmRjJeck5Stkom6A/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

所以，可以对双指针的 while 循环做出如下修改：

```c++
while (lo < hi) {
    int sum = nums[lo] + nums[hi];
    // 记录索引 lo 和 hi 最初对应的值
    int left = nums[lo], right = nums[hi];
    if (sum < target)      lo++;
    else if (sum > target) hi--;
    else {
        res.push_back({left, right});
        // 跳过所有重复的元素
        while (lo < hi && nums[lo] == left) lo++;
        while (lo < hi && nums[hi] == right) hi--;
    }
}
```

这样就可以保证一个答案只被添加一次，重复的结果都会被跳过，可以得到正确的答案。不过，受这个思路的启发，其实前两个 if 分支也是可以做一点效率优化，跳过相同的元素：

```c++
vector<vector<int>> twoSumTarget(vector<int>& nums, int target) {
    // nums 数组必须有序
    sort(nums.begin(), nums.end());
    int lo = 0, hi = nums.size() - 1;
    vector<vector<int>> res;
    while (lo < hi) {
        int sum = nums[lo] + nums[hi];
        int left = nums[lo], right = nums[hi];
        if (sum < target) {
            while (lo < hi && nums[lo] == left) lo++;
        } else if (sum > target) {
            while (lo < hi && nums[hi] == right) hi--;
        } else {
            res.push_back({left, right});
            while (lo < hi && nums[lo] == left) lo++;
            while (lo < hi && nums[hi] == right) hi--;
        }
    }
    return res;
}
```

这样，一个通用化的 `twoSum` 函数就写出来了，请确保你理解了该算法的逻辑，我们后面解决 `3Sum` 和 `4Sum` 的时候会复用这个函数。

这个函数的时间复杂度非常容易看出来，双指针操作的部分虽然有那么多 while 循环，但是时间复杂度还是 `O(N)`，而排序的时间复杂度是 `O(NlogN)`，所以这个函数的时间复杂度是 `O(NlogN)`。

## 二、3Sum 问题

> NOTE:
>
> 这个题目要求不能够重复，因此不能在已经搜索过的数之继续搜索。

这是力扣第 15 题「三数之和」：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHfxtp5qR5JP6yLfVXia191DmcfkrrtBteLhUlke0mv5fGRt6bE5fweDJrpggFatKhh5K1KtOgBSiag/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

题目就是让我们找 `nums` 中和为 0 的三个元素，返回所有可能的三元组（triple），函数签名如下：

```c++
vector<vector<int>> threeSum(vector<int>& nums);
```

这样，我们再泛化一下题目，不要光和为 0 的三元组了，计算和为 `target` 的三元组吧，同上面的 `twoSum` 一样，也不允许重复的结果：

```c++
vector<vector<int>> threeSum(vector<int>& nums) {
    // 求和为 0 的三元组
    return threeSumTarget(nums, 0);
}

vector<vector<int>> threeSumTarget(vector<int>& nums, int target) {
    // 输入数组 nums，返回所有和为 target 的三元组
}
```

这个问题怎么解决呢？**很简单，穷举呗**。现在我们想找和为 `target` 的三个数字，那么对于第一个数字，可能是什么？`nums` 中的每一个元素 `nums[i]` 都有可能！
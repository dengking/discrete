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
> 1、binary search
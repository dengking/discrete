# [303. 区域和检索 - 数组不可变](https://leetcode-cn.com/problems/range-sum-query-immutable/) 简单

## 使用左闭右闭的方式来定义prefix sum 

一、下面使用左闭右闭的方式来进行定义: 

```C++
prefixSum[0] = num[0]
prefixSum[i] = prefixSum[i - 1] + num[i]

sum[i, j] = prefixSum[j] - prefixSum[i - 1] 
```

通过后面的code可知，上述定义是有错误的，错误在于当 i 为 0的时候，当i为0时，上述定义就会导致负数索引，这在很多语言中都是错误的。

### 第一次的code

我第一次写的code如下:

```C++
class NumArray {
	vector<int> preSum_;
public:
	NumArray(vector<int>& nums) {
		preSum_.resize(nums.size());
		preSum_[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			preSum_[i] = preSum_[i - 1] + nums[i];
		}
	}
	// [left, right]
	int sumRange(int left, int right) {
		return preSum_[right] - preSum_[left - 1];
	}
};
```

上述代码运行时错误如下:

```C++
Line 1038: Char 34: runtime error: addition of unsigned offset to 0x603000000280 overflowed to 0x60300000027c (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_vector.h:1043:34
```

错误原因在于:

`sumRange(0, 1)`，则执行  `preSum_[left - 1]` 就会触发异常。

### 第二次的code

```C++
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class NumArray {
	vector<int> preSum_;
public:
	NumArray(vector<int>& nums) {
		preSum_.resize(nums.size());
		preSum_[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			preSum_[i] = preSum_[i - 1] + nums[i];
		}
	}
	// [left, right]
	int sumRange(int left, int right) {
		if (left > 0)
			return preSum_[right] - preSum_[left - 1];
		else {
			return preSum_[right];
		}
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main()
{
	
	vector<int> nums{ -2, 0, 3, -5, 2, -1 };
	NumArray s(nums);
	cout << s.sumRange(0, 2) << endl;
	cout << s.sumRange(2, 5) << endl;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```



由于数组的index涉及到减法，就需要处理0的问题，因为0减去一个数后是负数，而 [std::vector<T,Allocator>::operator[]](https://en.cppreference.com/w/cpp/container/vector/operator_at) 的入参类似是`size_type`:

```C++
reference operator[]( size_type pos );
```

根据 stackoverflow [vector::size_type in C++](https://stackoverflow.com/questions/4849632/vectorintsize-type-in-c) # [A](https://stackoverflow.com/a/4849646/10173843) 可知:

> `size_type` is a *(static) member type* of the type `vector<int>`. Usually, it is a `typedef` for `std::size_t`, which itself is usually a `typedef` for `unsigned int` or `unsigned long long`.

因此此时就会触发第一次的code中的异常。更好的做法是按照 labuladong [小而美的算法技巧：前缀和数组](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=2&sn=19a2609f33eadbbda1f6b75e2298d931&scene=21#wechat_redirect) 中使用的是另外一种定义方式，它避免了"index subtraction"的问题。
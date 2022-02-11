# leetcode [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/)



## 我的解答



```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	void moveZeroes(vector<int> &nums)
	{
		int n = nums.size(), left = 0, right = 0;
		while (right < n)
		{
			if (nums[right])
			{
				swap(nums[left], nums[right]);
				left++;
			}
			right++;
		}
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, vector<Args...> &v)
{
	for (auto &&i : v)
	{
		stream << i << " ";
	}
	return stream;
}
int main()
{
	vector<int> nums { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

	Solution s;
	s.moveZeroes(nums);

	cout << nums << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```



## [官方解题](https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/)

> NOTE: 
>
> 相比于 labuladong  [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ) 中给出的答案，官方的显然更优。
>
> 

使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。

> NOTE: 
>
> 1、两个指针之间就是待移动的元素，显然，当右指针到底末尾的时候，此时，所有的待移动元素都移到了末尾

右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。

注意到以下性质：

左指针左边均为非零数；

右指针左边直到左指针处均为零。

> NOTE: 
>
> 1、上面这段话说的比较绕，它想表达的含义其实就是两个指针之间

因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变。


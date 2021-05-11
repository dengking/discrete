# labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A)

> NOTE: 
>
> 1、典型的double pointer-fast slow pointer
>
> 2、使用这个algorithm的前提是: 数组是有序的，这样重复的元素就处于相邻的位置上；如果数组无序，则无法使用此算法
>
> 3、让`[0、slow]`包含所有的不重复元素，fast指针在前进过程中，一旦发现了`array[fast]`和`array[slow]`不相等，则说明需要扩展`[0、slow]`区间了
>
> 4、这个算法让我想到了C++ remove erase idiom





## Remove erase + 双指针(double pointer(fast slow))

其实，**对于数组相关的算法问题，有一个通用的技巧：要尽量避免在中间删除元素，那我就先想办法把这个元素换到最后去**。

这样的话，最终待删除的元素都拖在数组尾部，一个一个 pop 掉就行了，每次操作的时间复杂度也就降低到 O(1) 了。

按照这个思路呢，又可以衍生出解决类似需求的通用方式：双指针技巧。具体一点说，应该是快慢指针。

我们让慢指针`slow`走在后面，快指针`fast`走在前面探路，找到一个不重复的元素就告诉`slow`并让`slow`前进一步。

这样当`fast`指针遍历完整个数组`nums`后，**`nums[0..slow]`就是不重复元素，之后的所有元素都是重复元素**。

### Array

> NOTE: 
>
> 1、当`nums[fast] != nums[slow]`，就让`slow`往前走一步，然后将`slow`所指向的位置的值更新为`fast`所指向位置的值，这样当下一次循环的时候，如果`fast`又遇到了相同值，由于 `nums[fast] == nums[slow]`，显然下面的`if(nums[fast] != nums[slow])`就不会成功。
>
> 

![Image](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kjKDY327Vjgh9xjMKhdRwkXNWK1M1RuP04RjpdVEqe3UJ4koJ7yiaibCdibposGicY0ZxDMKhN0R6cCg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



看下算法执行的过程：

![Image](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4kjKDY327Vjgh9xjMKhdRwkNrHlatFV4e3gVBNhQz8w4AdWzJQjZbiahEGcq8Bua5vam4ab6TY5OnA/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)



#### Java source code

```java
int removeDuplicates(int[] nums) {
  int n = nums.length;
  if (n == 0) {
    return 0;
  }
  int slow = 0, fast = 1;
  while (fast < n) {
    if (nums[fast] != nums[slow]) {
      ++slow;
      nums[slow] = nums[fast];

    }
    ++fast;
  }
  return slow + 1;
}
```



#### C++ source code

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		int slow = 0, fast = 1;
		while (fast < n)
		{
			if (nums[fast] != nums[slow])
			{
				++slow;
				nums[slow] = nums[fast];
			}
			++fast;
		}
		return slow + 1;
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
	cout << s.removeDuplicates(nums) << endl;

	cout << nums << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```



### Linked list

再简单扩展一下，如果给你一个有序链表，如何去重呢？其实和数组是一模一样的，唯一的区别是把数组赋值操作变成操作指针而已：

![Image](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kjKDY327Vjgh9xjMKhdRwkU4y2mY8jWaOGJXgm2qvHv3IWoQ8XVcdhqtiaiciajO6Y4MDr84yll7E2w/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



对于链表去重，算法执行的过程是这样的：

![Image](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4kjKDY327Vjgh9xjMKhdRwkCU5OeeFaodzyERZwzVwAAU8DhJpcZDK3uddUsRyBibBG5ics8Wm0Vsyw/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)



最后，近期准备写写一些简单实用的数组/链表技巧。那些稍困难的技巧（比如动态规划）虽然秀，但毕竟在现实生活中不容易遇到。恰恰是一些简单常用的技巧，能够在不经意间，让人发现你是个高手 ^_^。



#### C++ source code

> NOTE: 
>
> 参见: 
>
> 1、`LeetCode-83-删除排序链表中的重复元素` 章节
>
> 2、leetcode [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/) 
>
> 

## Leetcode [26. 删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

这篇文章讲讲如何对一个有序数组去重，先看下题目：

> NOTE: 
>
> 1、原题: leetcode [26. 删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

![Image](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kjKDY327Vjgh9xjMKhdRwkpMc8yECrN67efS23St1iabEyH68FCsos3RyrgiaNwfMia6OqqzBxWDNBg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)
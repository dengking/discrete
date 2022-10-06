# How-to-write-iteration

## while循环

下面是非常好的例子：

1、quick sort

2、[LeetCode-68. 文本左右对齐-困难](https://leetcode-cn.com/problems/text-justification/) 

3、贪心算法 质数因式分解 最大数

4、双指针就是非常典型的循环书写范本

5、wikipedia [All nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values)

Stack-sortable-permutation

6、[LeetCode-剑指 Offer 18. 删除链表的节点](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/)

```C++
//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
					val(x), next(NULL)
	{
	}
	ListNode(int x, ListNode *next) :
					val(x), next(next)
	{
	}
};

class Solution
{
public:
	ListNode* deleteNode(ListNode *head, int val)
	{
		if (head->val == val)
		{
			ListNode *new_haed = head->next;
			// delete head;
			return new_haed;
		}
		ListNode *previous = head, *current = head->next;
		while (current && current->val != val) // current 放在此处是为了避免空指针异常
		{
			previous = current;
			current = current->next;
		}
		if (current)
		{
			previous->next = current->next;
			// delete current;
		}
		return head;
	}
};
```

## 循环数组防止越界

### for

非常安全

### while

下面是典型的例子

#### [LeetCode-31. 下一个排列](https://leetcode-cn.com/problems/next-permutation/)

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) // 加上 i>=0，就是为了防止数组越界
        {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

```

显然，当循环退出当时候，复合条件之一肯定是不满足当：

1、`i >= 0` 的否定 `i < 0`

2、`nums[i] >= nums[i + 1]` 的否定 `nums[i] < nums[i + 1]`

#### labuladong [经典面试题：最长回文子串](https://mp.weixin.qq.com/s/ux6VSWAPwgOS32xlScr2kQ)

![image](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lLwdm05DtOeOPia4eSQF3HJ35jOicswr8BxewicbXvjKK3tpERQqORIqmJwddx7AXwxhjDm4QBicUoQw/640?wx_fmt=png\&wxfrom=5\&wx_lazy=1\&wx_co=1)

#### [LeetCode-剑指 Offer 11. 旋转数组的最小数字](https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)

```

class Solution
{
public:
  int minArray(vector<int> &numbers)
  {
    int i = 0;
    while (i + 1 <= numbers.size() - 1) //避免越界
    {
      if (numbers[i] > numbers[i + 1])
      {
        return numbers[i + 1];
      }
      ++i;
    }
    return numbers[0]; //运行到这里，说明是单调递增到，因此最小的元素就是第0个
  }
};

```



## 循环防止空指针异常

### [LeetCode-556. 下一个更大元素 III-中等](https://leetcode-cn.com/problems/next-greater-element-iii/) # [c++超100的数学解法](https://leetcode-cn.com/problems/next-greater-element-iii/solution/cchao-100de-shu-xue-jie-fa-by-ffreturn-rccw/) 

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int nextGreaterElement(int n)
	{
		string s = to_string(n);
		int nn = s.size();
		// 如果只有1个，直接返回失败
		if (nn <= 1)
		{
			return -1;
		}
		// 先找到最小的数字, 从n-2开始无必然有数字可以比较
		int i = nn - 2;
		for (; i >= 0; --i) // i>=0就是为了避免数组越界，
		{
			if (s[i] < s[i + 1])
			{
				break;
			}
		}

		// 数组已经是递增，则无法有更大数，返回失败
		if (i < 0)
		{
			return -1;
		}

		// 找到比 s[i] 稍大的 数字 s[j]
		int j = nn - 1;
		for (; j >= 0; --j)
		{
			if (s[j] > s[i])
			{
				break;
			}
		}
		swap(s[i], s[j]);

		// 翻转从i+1到end 的数组
		reverse(s.begin() + i + 1, s.end());

		// 考虑int溢出的情况
		long res = stol(s);
		return res > INT_MAX ? -1 : res;
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

### [LeetCode-剑指 Offer 18. 删除链表的节点](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/)

```C++
//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
					val(x), next(NULL)
	{
	}
	ListNode(int x, ListNode *next) :
					val(x), next(next)
	{
	}
};

class Solution
{
public:
	ListNode* deleteNode(ListNode *head, int val)
	{
		if (head->val == val)
		{
			ListNode *new_haed = head->next;
			// delete head;
			return new_haed;
		}
		ListNode *previous = head, *current = head->next;
		while (current && current->val != val) // current 放在此处是为了避免空指针异常
		{
			previous = current;
			current = current->next;
		}
		if (current)
		{
			previous->next = current->next;
			// delete current;
		}
		return head;
	}
};
```



### fast-slow double pointer for linked list

labuladong [单链表的六大解题套路，你都见过么？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==\&mid=2247492022\&idx=1\&sn=35f6cb8ab60794f8f52338fab3e5cda5\&scene=21#wechat_redirect) # 单链表的中点

```java
ListNode middleNode(ListNode head) {
    // 快慢指针初始化指向 head
    ListNode slow = head, fast = head;
    // 快指针走到末尾时停止
    while (fast != null && fast.next != null) // 此处进行保护
    {
        // 慢指针走一步，快指针走两步
        slow = slow.next;
        fast = fast.next.next;
    }
    // 慢指针指向中点
    return slow;
}
```



## 循环处理两个序列

[LeetCode-415 字符串相加 # 官方解题](https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/)

```c++
class Solution {
public:
   string addStrings(string num1, string num2) {
       int i = num1.length() - 1, j = num2.length() - 1, add = 0;
       string ans = "";
       while (i >= 0 || j >= 0 || add != 0) {
           int x = i >= 0 ? num1[i] - '0' : 0;
           int y = j >= 0 ? num2[j] - '0' : 0;
           int result = x + y + add;
           ans.push_back('0' + result % 10);
           add = result / 10;
           i -= 1;
           j -= 1;
       }
       // 计算完以后的答案需要翻转过来
       reverse(ans.begin(), ans.end());
       return ans;
   }
};
```





## for while对比

[LeetCode-556. 下一个更大元素 III-中等](https://leetcode-cn.com/problems/next-greater-element-iii/)  # [c++超100的数学解法](https://leetcode-cn.com/problems/next-greater-element-iii/solution/cchao-100de-shu-xue-jie-fa-by-ffreturn-rccw/) 中给出了for的写法：

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int nextGreaterElement(int n)
	{
		string s = to_string(n);
		int nn = s.size();
		// 如果只有1个，直接返回失败
		if (nn <= 1)
		{
			return -1;
		}
		// 先找到最小的数字, 从n-2开始无必然有数字可以比较
		int i = nn - 2;
		for (; i >= 0; --i)
		{
			if (s[i] < s[i + 1])
			{
				break;
			}
		}

		// 数组已经是递增，则无法有更大数，返回失败
		if (i < 0)
		{
			return -1;
		}

		// 找到比 s[i] 稍大的 数字 s[j]
		int j = nn - 1;
		for (; j >= 0; --j)
		{
			if (s[j] > s[i])
			{
				break;
			}
		}
		swap(s[i], s[j]);

		// 翻转从i+1到end 的数组
		reverse(s.begin() + i + 1, s.end());

		// 考虑int溢出的情况
		long res = stol(s);
		return res > INT_MAX ? -1 : res;
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

它是可以和 [LeetCode-31. 下一个排列](https://leetcode-cn.com/problems/next-permutation/) 官方解题中的while循环版本进行对比的。


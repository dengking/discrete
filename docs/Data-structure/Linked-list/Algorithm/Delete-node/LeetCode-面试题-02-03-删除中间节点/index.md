# leetcode [面试题 02.03. 删除中间节点](https://leetcode.cn/problems/delete-middle-node-lcci/)

## 我的解题

这个题，意思描述地不明了。下面是总结的比较好的:

> 既然只能访问当前节点，那就只好出此下策了。杀不掉我，我就变成你，然后再干掉你，就等于杀死了自己。
>
> ```c
> void deleteNode(struct ListNode* node) {
>     node->val = node->next->val;
>     node->next = node->next->next;
> }
> ```



### 完整代码

```C++
/* Program to implement a stack
 using two queue */
#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
					val(x), next(NULL)
	{
	}
};

class Solution
{
public:
	void deleteNode(ListNode *node)
	{
		// 只知道当前节点，

		ListNode *nextNode = node->next;
		*node = *node->next;
		delete nextNode;
	}
};

// Driver code
int main()
{
	ListNode *N = new ListNode { 3 };
	N->next = new ListNode { 2 };
	N->next->next = new ListNode { 0 };
	N->next->next->next = new ListNode { 4 };
	Solution s;
	s.deleteNode(N->next);

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```


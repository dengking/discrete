# LeetCode [147. 对链表进行插入排序](https://leetcode-cn.com/problems/insertion-sort-list/) 中等



## [官方解题](https://leetcode-cn.com/problems/insertion-sort-list/solution/dui-lian-biao-jin-xing-cha-ru-pai-xu-by-leetcode-s/)

**插入排序**的基本思想是，维护一个**有序序列**，初始时有序序列只有一个元素，每次将一个新的元素插入到有序序列中，将有序序列的长度增加 1，直到**全部元素**都加入到**有序序列**中。

对于**链表**而言，插入元素时只要更新相邻节点的指针即可，不需要像数组一样将插入位置后面的元素往后移动，因此插入操作的**时间复杂度**是 $O(1)$，但是找到插入位置需要遍历链表中的节点，时间复杂度是 $O(n)$，因此链表插入排序的总时间复杂度仍然是 $O(n^2)$，其中 nn 是链表的长度。

对于单向链表而言，只有指向后一个节点的指针，因此需要从链表的头节点开始往后遍历链表中的节点，寻找插入位置。

对链表进行插入排序的具体过程如下:

一、首先判断给定的链表是否为空，若为空，则不需要进行**排序**，直接返回。

二、创建**哑节点** `dummyHead`，令 `dummyHead.next = head`。引入**哑节点**是为了便于在 **head 节点**之前插入节点。

> NOTE: 
>
> 需要结合后面的source code来进行理解

三、维护 `lastSorted` 为链表的已排序部分的最后一个节点，初始时 `lastSorted = head`。

四、维护 `curr` 为待插入的元素，初始时 `curr = head.next`。

五、比较 `lastSorted` 和 `curr` 的节点值。

1、若 `lastSorted.val <= curr.val`，说明 `curr` 应该位于 `lastSorted` 之后，将 `lastSorted` 后移一位，`curr` 变成新的 `lastSorted`。

2、否则，从链表的头节点开始往后遍历链表中的节点，寻找插入 `curr` 的位置。令 `prev` 为插入 `curr` 的位置的前一个节点，进行如下操作，完成对 `curr` 的插入：

```Java
lastSorted.next = curr.next
curr.next = prev.next
prev.next = curr
```

六、令 `curr = lastSorted.next`，此时 `curr` 为下一个待插入的元素。

七、重复第 5 步和第 6 步，直到 `curr` 变成空，排序结束。

八、返回 `dummyHead.next`，为排序后的链表的头节点。

### 完整程序

```C++
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() :
					val(0), next(nullptr)
	{
	}
	ListNode(int x) :
					val(x), next(nullptr)
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
	/**
	 * @brief 将curr插入到 [head, lastSorted] 之间
	 *
	 * @param head
	 * @return
	 */
	ListNode* insertionSortList(ListNode *head)
	{
		if (head == nullptr)
		{
			return head;
		}
		ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode *lastSorted = head;
		ListNode *curr = head->next; // 将curr插入到 [head, lastSorted] 之间
		while (curr != nullptr)
		{
			if (lastSorted->val <= curr->val)
			{
				lastSorted = lastSorted->next;
			}
			else
			{
				ListNode *prev = dummyHead;
				while (prev->next->val <= curr->val) // 找到插入位置
				{
					prev = prev->next;
				}
				/**
				 * 将curr插入到prev之后
				 */
				lastSorted->next = curr->next;
				curr->next = prev->next;
				prev->next = curr;
			}
			curr = lastSorted->next;
		}
		return dummyHead->next;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```


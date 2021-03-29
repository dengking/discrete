# [labuladong](javascript:void(0);) [双指针技巧汇总](https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg)

我认为双指针技巧还可以分为两类，一类是「快慢指针」，一类是「左右指针」。前者解决主要解决链表中的问题，比如典型的判定链表中是否包含环；后者主要解决数组（或者字符串）中的问题，比如二分查找。

> NOTE: 
>
> 1、"左右指针"其实就是range

## 一、快慢指针的常见算法

快慢指针一般都初始化指向链表的头结点 head，前进时快指针 fast 在前，慢指针 slow 在后，巧妙解决一些链表中的问题。

### *1*、判定链表中是否含有环

单链表的特点是每个节点只知道下一个节点，所以一个指针的话无法判断链表中是否含有环的。

> NOTE: 
>
> 1、double list能否判断呢？
>
> 2、leetcode [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)
>
> 3、其实这就是"「Floyd 判圈算法」（又称龟兔赛跑算法）"

经典解法就是用两个指针，一个每次前进两步，一个每次前进一步。如果不含有环，跑得快的那个指针最终会遇到 null，说明链表不含环；如果含有环，快指针最终会超慢指针一圈，和慢指针相遇，说明链表含有环。

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast=head, *slow=head;
        while(fast!=NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};
```

> NOTE: 
>
> 1、在 `while(fast!=NULL && fast->next != NULL)` 中添加 `fast->next != NULL` 的原因是:
>
> 对于长度为1的list，如果它没有环，则`fast->next`为null，则`fast->next->next;`就会发生runtime error。
>
> 2、上述是C++ code



### *2*、已知链表中含有环，返回这个环的起始位置

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lFDturGXicxrn2F0wKQPgocogUfHvrlxewYJBJRqX82AjfibQ43Gib3EYgnPricsqN5hJNlk8qdyUgDQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

这个问题其实不困难，有点类似脑筋急转弯，先直接看代码：

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lFDturGXicxrn2F0wKQPgocV3LJDqHkgI1h8Hh8XMrceyBROyn2Jic6X2oXBGAQPV7QNVwicvfwPMmw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

> NOTE: 
> 1、下面是C++ code:
>
> ```C++
> struct ListNode
> {
> 	int val;
> 	ListNode *next;
> 	ListNode(int x) :
> 					val(x), next(NULL)
> 	{
> 	}
> };
> 
> class Solution
> {
> public:
> 	ListNode* detectCircle(ListNode *head)
> 	{
> 		ListNode *fast = head, *slow = head;
> 		bool hasCircle = false; // 是否存在环
> 		while (fast != NULL && fast->next != NULL)
> 		{
> 			fast = fast->next->next;
> 			slow = slow->next;
> 			if (fast == slow)
> 			{
> 				hasCircle = true;
> 				break;
> 			}
> 		}
> 		if (hasCircle)
> 		{
> 			while (slow != fast)
> 			{
> 				fast = fast->next;
> 				slow = slow->next;
> 			}
> 			return slow;
> 		}
> 		else
> 		{
> 			return NULL;
> 		}
> 
> 	}
> };
> 
> ```
>
> 



第一次相遇时，假设慢指针 slow 走了 k 步，那么快指针 fast 一定走了 2k 步，也就是说比 slow 多走了 k 步（也就是环的长度）。

> NOTE: 
>
> 1、两者相遇的时候，fast pointer已经绕环一周了

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lFDturGXicxrn2F0wKQPgocMTLbYubOMnV8BG7fkHKw7cIKV43yOlzzuNOwvFW7eVsPbgC30FG2rQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

设相遇点距环的起点的距离为 m，那么环的起点距头结点 head 的距离为 k - m，也就是说如果从 head 前进 k - m 步就能到达环起点。

> NOTE: 
>
> 1、slow pointer走了k步，此时slow pointer也处于相遇点，因此"环的起点距头结点 head 的距离为 k - m"
>
> 2、这个算法并不关注k、m的具体值，仅仅需要的是环起点

巧的是，如果从相遇点继续前进 k - m 步，也恰好到达环起点。

所以，只要我们把快慢指针中的任一个重新指向 head，然后两个指针同速前进，k - m 步后就会相遇，相遇之处就是环的起点了。



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lFDturGXicxrn2F0wKQPgocgdhvrjrUt8ibD3PXJomkhSBk5CPubhUQCxiaw2bwJwKP7Y3ODBZc5xag/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



### *3*、寻找链表的中点

类似上面的思路，我们还可以让快指针一次前进两步，慢指针一次前进一步，当快指针到达链表尽头时，慢指针就处于链表的中间位置。



```java
ListNode slow, fast;
slow = fast = head;
while (fast != null && fast.next != null) {
    fast = fast.next.next;
    slow = slow.next;
}
// slow 就在中间位置
return slow;
```



当链表的长度是奇数时，slow 恰巧停在中点位置；如果长度是偶数，slow 最终的位置是中间偏右：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lFDturGXicxrn2F0wKQPgocU4oqZicGS6HSVIs3opkdvoRRJ34c9Vpv5QA0vjv0bbwjlMOjOjYb4Ng/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

回想数组的归并排序：求中点索引递归地把数组二分，最后合并两个有序数组。对于链表，合并两个有序链表是很简单的，难点就在于二分。

但是现在你学会了找到链表的中点，就能实现链表的二分了。关于归并排序的具体内容本文就不具体展开了。



> NOTE: 
>
> 1、leetcode [面试题 02.03. 删除中间节点](https://leetcode-cn.com/problems/delete-middle-node-lcci/)
>
> 2、

### *4*、寻找链表的倒数第 k 个元素



我们的思路还是使用快慢指针，让快指针先走 k 步，然后快慢指针开始同速前进。这样当快指针走到链表末尾 null 时，慢指针所在的位置就是倒数第 k 个链表节点（为了简化，假设 k 不会超过链表长度）：

> NOTE: 
> 1、两者之间始终相距 k个元素

```
ListNode slow, fast;
slow = fast = head;
while (k-- > 0) 
    fast = fast.next;

while (fast != null) {
    slow = slow.next;
    fast = fast.next;
}
return slow;
```



> NOTE: 
> 1、leetcode [面试题 02.02. 返回倒数第 k 个节点](https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/)
>
> 2、leetcode [剑指 Offer 22. 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)



## 二、左右指针的常用算法



左右指针在数组中实际是指两个索引值，一般初始化为 `left = 0, right = nums.length - 1` 。



### *1*、二分查找



前文 [二分查找算法详解](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247484090&idx=1&sn=5635cf1c4fd8a8570b63c7ae9b4304c2&chksm=fb3362f8cc44ebee0a19a4cfba7f2e13923e05f47e15f2e99a1f42b01aeee83b946aceac3d4c&scene=21#wechat_redirect) 有详细讲解，这里只写最简单的二分算法，旨在突出它的双指针特性：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lFDturGXicxrn2F0wKQPgocnbs4f8CILz1E9hCiahrD2sJDh1VM6w5svHWt1QRUn0iboGedhOibfEIQQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



### *2*、两数之和



直接看一道 LeetCode 题目吧：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lFDturGXicxrn2F0wKQPgocRQNTfK1rHGNTSsTv0X2qgQuFwQh02vvn8gwrxuOf4ghR8eN40EhXibg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



只要数组有序，就应该想到双指针技巧。这道题的解法有点类似二分查找，通过调节 left 和 right 可以调整 sum 的大小：

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lFDturGXicxrn2F0wKQPgocia0QjfCMnT4PytIyf6qWt7Zoia7om07CgSCNeRNkQJsjCz6KShe83Jnw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



### *3*、反转数组



```
void reverse(int[] nums) {
    int left = 0;
    int right = nums.length - 1;
    while (left < right) {
        // swap(nums[left], nums[right])
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++; right--;
    }
}
```

### *4*、滑动窗口算法



这也许是双指针技巧的最高境界了，如果掌握了此算法，可以解决一大类子字符串匹配的问题，不过「滑动窗口」算法比上述的这些算法稍微复杂些。



幸运的是，这类算法是有框架模板的，下篇文章就准备讲解「滑动窗口」算法模板，帮大家秒杀几道 LeetCode 子串匹配的问题。
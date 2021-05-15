# leetcode [23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

1、假设`k`个linked list共有`n`个元素

2、每次从各个linked list 取得它们的 `head`，然后对这个k个`head`进行排序，取得 min、max 元素。

3、然后将min/max插入到output中

4、显然上述过程需要执行n次

## [官方解题](https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/)

> NOTE: 
>
> 1、下面并没有按照原文的方式组织的，而是结合原文视频中的内容、文字内容进行的组织

### 方式一: 暴力解法

将所有的k个linked list输出到一个array中，然后对array进行排序，然后输出为linked list；



#### 完整程序 Python

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        self.nodes = []
        head = point = ListNode()
        for l in lists:
            while l:
                self.nodes.append(l.val)
                l = l.next
        for x in sorted(self.nodes):
            point.next = ListNode(x)
            point = point.next
        return head.next
```



#### 复杂度分析

![](./暴力搜索-brute-force search-合并k个有序链表的复杂度.png)

### 方式二: 顺序合并/ Iterative 2-Way merge

> NOTE: 
>
> 1、在 wanweibaike [k-way merge algorithm](https://en.wanweibaike.com/wiki-K-Way%20Merge%20Algorithms) 中，将这种方式称为 "Iterative 2-Way merge"

​	



#### 复杂度分析



### 方法三：分治合并




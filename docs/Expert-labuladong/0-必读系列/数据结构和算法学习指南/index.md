# labuladong [数据结构和算法学习指南](https://mp.weixin.qq.com/s/ZYaXOSVM3YBIeRWm7E_jcQ) 

## 一、数据结构的存储方式

**数据结构的存储方式只有两种：数组（顺序存储）和链表（链式存储）**。

> NOTE: 
>
> 1、后续将它们称为array-based、linked-list-based
>
> 2、其实还有混合两者的，比如hash table

这句话怎么理解，不是还有散列表、栈、队列、堆、树、图等等各种数据结构吗？

我们分析问题，一定要有递归的思想，自顶向下，从抽象到具体。你上来就列出这么多，那些都属于「上层建筑」，而数组和链表才是「结构基础」。因为那些多样化的数据结构，究其源头，都是在链表或者数组上的特殊操作，API 不同而已。

> NOTE: 
>
> 其实简而言之，"散列表、栈、队列、堆、树、图"等都是ADT，这些ADT往往有多重implementation，关于此，在 `ADT&Impl` 章节对其进行了介绍。

比如说**「队列」**、**「栈」**这两种数据结构既可以使用链表也可以使用数组实现。用数组实现，就要处理扩容缩容的问题；用链表实现，没有这个问题，但需要更多的内存空间存储节点指针。

**「图」**的两种表示方法，邻接表就是链表，邻接矩阵就是二维数组。邻接矩阵判断连通性迅速，并可以进行矩阵运算解决一些问题，但是如果图比较稀疏的话很耗费空间。邻接表比较节省空间，但是很多操作的效率上肯定比不过邻接矩阵。

...

#### 对比

> NOTE: 
>
> 1、扩容缩容
>
> 2、random access VS sequencial access
>
> 3、存储空间大小

综上，数据结构种类很多，甚至你也可以发明自己的数据结构，但是底层存储无非数组或者链表，**二者的优缺点如下**：

**数组**由于是紧凑连续存储,可以随机访问，通过索引快速找到对应元素，而且相对节约存储空间。但正因为连续存储，内存空间必须一次性分配够，所以说数组如果要扩容，需要重新分配一块更大的空间，再把数据全部复制过去，时间复杂度 O(N)；而且你如果想在数组中间进行插入和删除，每次必须搬移后面的所有数据以保持连续，时间复杂度 O(N)。

**链表**因为元素不连续，而是靠指针指向下一个元素的位置，所以不存在数组的扩容问题；如果知道某一元素的前驱和后驱，操作指针即可删除该元素或者插入新元素，时间复杂度 O(1)。但是正因为存储空间不连续，你无法根据一个索引算出对应元素的地址，所以不能随机访问；而且由于每个元素必须存储指向前后元素位置的指针，会消耗相对更多的储存空间。

> NOTE: 
>
> 1、还可以从cache的角度对两者的访问性能进行对比，这就是C++中的value semantic和reference semantic



## 二、数据结构的基本操作

对于任何数据结构，其基本操作无非遍历 + 访问，再具体一点就是：增删查改。

**数据结构种类很多，但它们存在的目的都是在不同的应用场景，尽可能高效地增删查改**。话说这不就是数据结构的使命么？

如何遍历 + 访问？我们仍然从最高层来看，各种数据结构的遍历 + 访问无非两种形式：**线性**的**和非线性**的。

线性就是 for/while 迭代为代表，非线性就是递归为代表。再具体一步，无非以下几种框架：

### 数组遍历框架

数组遍历框架，典型的线性迭代结构：

```C++
void traverse(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
        // 迭代访问 arr[i]
    }
}
```

### 链表遍历框架

链表遍历框架，兼具迭代和递归结构：

```C++
/* 基本的单链表节点 */
class ListNode {
    int val;
    ListNode next;
}

void traverse(ListNode head) {
    for (ListNode p = head; p != null; p = p.next) {
        // 迭代访问 p.val
    }
}

void traverse(ListNode head) {
    // 递归访问 head.val
    traverse(head.next)
}
```

### 二叉树遍历框架

二叉树遍历框架，典型的非线性递归遍历结构：

```C++
/* 基本的二叉树节点 */
class TreeNode {
    int val;
    TreeNode left, right;
}

void traverse(TreeNode root) {
    traverse(root.left)
    traverse(root.right)
}
```

你看二叉树的递归遍历方式和链表的递归遍历方式，相似不？再看看二叉树结构和单链表结构，相似不？如果再多几条叉，N 叉树你会不会遍历？

二叉树框架可以扩展为 N 叉树的遍历框架：

```C++
/* 基本的 N 叉树节点 */
class TreeNode {
    int val;
    TreeNode[] children;
}

void traverse(TreeNode root) {
    for (TreeNode child : root.children)
        traverse(child)
}
```

N 叉树的遍历又可以扩展为图的遍历，因为图就是好几 N 叉棵树的结合体。你说图是可能出现环的？这个很好办，用个布尔数组 `visited` 做标记就行了，这里就不写代码了。

**所谓框架，就是套路。不管增删查改，这些代码都是永远无法脱离的结构，你可以把这个结构作为大纲，根据具体问题在框架上添加代码就行了，下面会具体举例**。

## 三、算法刷题指南

公众号文章的阅读数据显示，大部分人对数据结构相关的算法文章不感兴趣，而是更关心动规回溯分治等等技巧。为什么要先刷二叉树呢，**因为二叉树是最容易培养框架思维的，而且大部分算法技巧，本质上都是树的遍历问题**。

> NOTE: 
>
> [LeetCode-124. 二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum/) 困难
>
> [LeetCode-105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
>
> [LeetCode-99. 恢复二叉搜索树](https://leetcode.cn/problems/recover-binary-search-tree/) 困难



### LeetCode 99 题

LeetCode 99 题，难度 Hard，恢复一棵 BST，主要代码如下：

![Image](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHFLNbFyicB9ENe5Gbt9CrrMm8NQJaFMebRAr0mxmnUkBxEZDcxFOicNTbEgiaiaIGE5dEpoKh7uDwlsg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

这不就是个中序遍历嘛，对于一棵 BST 中序遍历意味着什么，应该不需要解释了吧。

> NOTE: 
>
> 下面是完整代码:
>
> ```C++
> #include <bits/stdc++.h>
> using namespace std;
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
>  * };
>  */
> 
> //  Definition for a binary tree node.
> struct TreeNode
> {
> 	int val;
> 	TreeNode *left;
> 	TreeNode *right;
> 	TreeNode(int x) :
> 					val(x), left(NULL), right(NULL)
> 	{
> 	}
> };
> class Solution
> {
> 	TreeNode *prev { nullptr }; // 前一个被访问的节点
> 	TreeNode *x { nullptr };
> 	TreeNode *y { nullptr };
> public:
> 	void recoverTree(TreeNode *root)
> 	{
> 		inOrder(root);
> 		swap(x->val, y->val);
> 	}
> 	void inOrder(TreeNode *root)
> 	{
> 		if (root)
> 		{
> 			inOrder(root->left);
> 			if (prev && (prev->val > root->val))
> 			{
> 				y = root;
> 				if (!x)
> 				{
> 					x = prev;
> 				}
> 				else
> 				{
> 					return;
> 				}
> 			}
> 			prev = root;
> 			inOrder(root->right);
> 		}
> 		else
> 		{
> 			return;
> 		}
> 	}
> };
> 
> // Driver code
> int main()
> {
> 
> //	Solution solu;
> //	vector<int> nums = { 1, 3, 5, 4, 7 };
> //	return 0;
> }
> // g++ test.cpp --std=c++11 -pedantic -Wall -Wextra
> ```
>
> 
# Morris traversal

在 [LeetCode-恢复二叉搜索树](https://leetcode.cn/problems/recover-binary-search-tree/solution/hui-fu-er-cha-sou-suo-shu-by-leetcode-solution/) 中，提及了"Morris 中序遍历"。

cnblogs [LeetCode笔记整理3 二叉树中序遍历 Morris中序遍历](https://www.cnblogs.com/xiaoxu-xmy/p/13669850.html)

zhihu [神级遍历——morris](https://zhuanlan.zhihu.com/p/101321696)

stackoverflow [Explain Morris inorder tree traversal without using stacks or recursion](https://stackoverflow.com/questions/5502916/explain-morris-inorder-tree-traversal-without-using-stacks-or-recursion)

## gpt-4-vision Morris-traversal

Morris Traversal is an algorithm for in-order or pre-order tree traversal that uses O(1) extra space. It is a way to traverse a binary tree without using recursion or a stack. The idea is to temporarily modify the tree by adding links to ***successors*** (in the case of **in-order traversal**) or ***predecessors*** (in the case of **pre-order traversal**), traverse as far as possible, and then revert the changes to the tree structure.

The key idea of **Morris Traversal** is to use the left child's rightmost node (in-order predecessor) to keep track of the node to return to after visiting the left subtree. When we visit a node with a left child, we find its in-order predecessor and make the current node its right child. This way, when we finish with the left subtree, we can come back to the current node. Once we come back, we remove the temporary link and proceed with the right subtree.

> NOTE:
>
> 一、这段话是对核心思想的总结

Morris Pre-order Traversal is similar, with slight modifications to when the current node's value is printed (before moving to the left child, rather than after coming back from the left child).

Here's a Python implementation of Morris In-order Traversal for a binary tree:

```python
from typing import *


class TreeNode:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left: Optional[TreeNode] = left
        self.right: Optional[TreeNode] = right


def morris_inorder_traversal(root: Optional[TreeNode]):
    current = root
    while current is not None:
        if current.left is None:
            print(current.value, end=' ')  # visit current node
            current = current.right
        else:
            # Find the inorder predecessor of current
            predecessor = current.left
            while predecessor.right is not None and predecessor.right != current:
                predecessor = predecessor.right

            # Make current the right child of its inorder predecessor
            if predecessor.right is None:
                predecessor.right = current
                current = current.left
            else:
                # Revert the changes made in the 'if' part to restore the original tree
                # i.e., fix the right child of predecessor
                predecessor.right = None
                print(current.value, end=' ')
                current = current.right


if __name__ == '__main__':
    # Example usage:
    # Constructing the following binary tree
    #        1
    #       / \
    #      2   3
    #     / \   \
    #    4   5   6

    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(6)

    morris_inorder_traversal(root)

```

This code will output the in-order traversal of the binary tree: `4 2 5 1 3 6`.



> NOTE:
>
> 一、DFS-two-direction=top-down~reduce~pre-order~action+bottom-up~produce~post-order~action
>
> DFS有向下、向上的两个过程，因此一个node肯定会两次被access到。
>
> top-down:   建桥
>
> bottom-up: 过河拆桥

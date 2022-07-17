# Depth、height、width



## Depth、height

树高度=树深度

### 例题

| 题目                                                         | 算法     | 来源                                                         |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| [LeetCode-104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/) | DFS、BFS | labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) |
| [LeetCode-111. 二叉树的最小深度-简单](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) | DFS、BFS | labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) |
| [LeetCode-559. N 叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/) | DFS、BFS |                                                              |

### N叉树最大树深度

和二叉树非常类似。

#### 例题

[LeetCode-559. N 叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/) 

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr)
        {
            return 0;
        }
        int maxDepthOfChild = 0;
        for(auto&& child:root->children)
        {
            maxDepthOfChild = max(maxDepthOfChild, maxDepth(child));
        }
        return 1 + maxDepthOfChild;
    }
};
```





## Width

通过BFS应该可以实现，通过记录最大宽度即可。


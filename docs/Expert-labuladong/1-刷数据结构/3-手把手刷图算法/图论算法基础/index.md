# labuladong [图论算法基础](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect)



## 图的遍历

图怎么遍历？还是那句话，参考多叉树，多叉树的遍历框架如下：

```java
/* 多叉树遍历框架 */
void traverse(TreeNode root) {
    if (root == null) return;

    for (TreeNode child : root.children) {
        traverse(child);
    }
}
```

图和多叉树最大的区别是，图是可能包含环的，你从图的某一个节点开始遍历，有可能走了一圈又回到这个节点。

所以，如果图包含环，遍历框架就要一个`visited`数组进行辅助：

```java
// 记录被遍历过的节点
boolean[] visited;
// 记录从起点到当前节点的路径
boolean[] onPath;

/* 图遍历框架 */
void traverse(Graph graph, int s) {
    if (visited[s]) return;
    // 经过节点 s，标记为已遍历
    visited[s] = true;
    // 做选择：标记节点 s 在路径上
    onPath[s] = true;
    for (int neighbor : graph.neighbors(s)) {
        traverse(graph, neighbor);
    }
    // 撤销选择：节点 s 离开路径
    onPath[s] = false;
}
```

> NOTE: 上述是DFS

注意`visited`数组和`onPath`数组的区别，因为二叉树算是特殊的图，所以用遍历二叉树的过程来理解下这两个数组的区别：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_gif/gibkIz0MVqdFam5oRSu0VjicmiahDJShicYw30YXQRIjUWgfbQH308jiaq84ZAAqc9gOZe8VLudqr4HaqmPiaf0coJpA/640?wx_fmt=gif&wxfrom=5&wx_lazy=1&wx_co=1)

**上述 GIF 描述了递归遍历二叉树的过程，在`visited`中被标记为 true 的节点用灰色表示，在`onPath`中被标记为 true 的节点用绿色表示**，这下你可以理解它们二者的区别了吧。
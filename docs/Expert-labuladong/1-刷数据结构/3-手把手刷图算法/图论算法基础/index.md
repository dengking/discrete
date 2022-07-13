# labuladong [图论算法基础](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect)



## 图的遍历

图怎么遍历？还是那句话，参考多叉树，多叉树的遍历框架如下：

```java
/* 多叉树遍历框架 */
void traverse(TreeNode root) {
    if (root == null) return; // stop condition

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
    if (visited[s]) return; // stop condition
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



如果让你处理路径相关的问题，这个`onPath`变量是肯定会被用到的，比如 [拓扑排序](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491897&idx=1&sn=c2d77dd649548d077815af3c976b61d1&scene=21#wechat_redirect) 中就有运用。



另外，你应该注意到了，这个`onPath`数组的操作很像 [回溯算法核心套路](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484709&idx=1&sn=1c24a5c41a5a255000532e83f38f2ce4&scene=21#wechat_redirect) 中做「做选择」和「撤销选择」，区别在于位置：回溯算法的「做选择」和「撤销选择」在 for 循环里面，而对`onPath`数组的操作在 for 循环外面。

在 for 循环里面和外面唯一的区别就是对**根节点**的处理。

比如下面两种多叉树的遍历：



```java
void traverse(TreeNode root) {
    if (root == null) return;
    System.out.println("enter: " + root.val);
    for (TreeNode child : root.children) {
        traverse(child);
    }
    System.out.println("leave: " + root.val);
}

void traverse(TreeNode root) {
    if (root == null) return;
    for (TreeNode child : root.children) {
        System.out.println("enter: " + child.val);
        traverse(child);
        System.out.println("leave: " + child.val);
    }
}
```

前者会正确打印所有节点的进入和离开信息，而后者唯独会少打印整棵树根节点的进入和离开信息。

为什么回溯算法框架会用后者？因为回溯算法关注的不是节点，而是树枝，不信你看 [回溯算法核心套路](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484709&idx=1&sn=1c24a5c41a5a255000532e83f38f2ce4&scene=21#wechat_redirect) 里面的图。

显然，对于这里「图」的遍历，我们应该把`onPath`的操作放到 for 循环外面，否则会漏掉记录起始点的遍历。

当然，如果题目告诉你图中不含环，可以把`visited`数组都省掉，基本就是多叉树的遍历。

## 题目实践 [LeetCode-797. 所有可能的路径](https://leetcode.cn/problems/all-paths-from-source-to-target/)



```java
// 记录所有路径
List<List<Integer>> res = new LinkedList<>();

public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
    // 维护递归过程中经过的路径
    LinkedList<Integer> path = new LinkedList<>();
    traverse(graph, 0, path);
    return res;
}

/* 图的遍历框架 */
void traverse(int[][] graph, int s, LinkedList<Integer> path) {

    // 添加节点 s 到路径
    path.addLast(s);

    int n = graph.length;
    if (s == n - 1) {
        // 到达终点
        res.add(new LinkedList<>(path));
        path.removeLast();
        return;
    }

    // 递归每个相邻节点
    for (int v : graph[s]) {
        traverse(graph, v, path);
    }

    // 从路径移出节点 s
    path.removeLast();
}
```


# labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect)

Dijkstra 算法（一般音译成迪杰斯特拉算法）无非就是一个 BFS 算法的加强版，它们都是从二叉树的层序遍历衍生出来的。



## 二叉树层级遍历和 BFS 算法



### BFS二叉树

我们之前说过二叉树的层级遍历框架：

```Java
// 输入一棵二叉树的根节点，层序遍历这棵二叉树
void levelTraverse(TreeNode root) {
    if (root == null) return 0;
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    int depth = 1;
    // 从上到下遍历二叉树的每一层
    while (!q.isEmpty()) {
        int sz = q.size();
        // 从左到右遍历每一层的每个节点
        for (int i = 0; i < sz; i++) {
            TreeNode cur = q.poll();
            printf("节点 %s 在第 %s 层", cur, depth);

            // 将下一层节点放入队列
            if (cur.left != null) {
                q.offer(cur.left);
            }
            if (cur.right != null) {
                q.offer(cur.right);
            }
        }
        depth++;
    }
}
```

算法题经常会问二叉树的最大深度呀，最小深度呀，层序遍历结果呀，等等问题，所以记录下来这个深度`depth`是有必要的。

> NOTE:
>
> 一、LeetCode题目: 
>
> 1、LeetCode-104-二叉树的最大深度
>
> 2、LeetCode-111-二叉树的最小深度
>
> 参见 `Depth-height-width` 章节。
>
> 

### BFS多叉树

基于二叉树的遍历框架，我们又可以扩展出多叉树的层序遍历框架：

```Java
// 输入一棵多叉树的根节点，层序遍历这棵多叉树
void levelTraverse(TreeNode root) {
    if (root == null) return 0;
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    int depth = 1;
    // 从上到下遍历多叉树的每一层
    while (!q.isEmpty()) {
        int sz = q.size();
        // 从左到右遍历每一层的每个节点
        for (int i = 0; i < sz; i++) {
            TreeNode cur = q.poll();
            printf("节点 %s 在第 %s 层", cur, depth);

            // 将下一层节点放入队列
            for (TreeNode child : root.children) {
                q.offer(child);
            }
        }
        depth++;
    }
}
```

### BFS graph



基于多叉树的遍历框架，我们又可以扩展出 BFS（广度优先搜索）的算法框架：

```Java
// 输入起点，进行 BFS 搜索
int BFS(Node start) {
    Queue<Node> q; // 核心数据结构
    Set<Node> visited; // 避免走回头路

    q.offer(start); // 将起点加入队列
    visited.add(start);

    int step = 0; // 记录搜索的步数
    while (q not empty) {
        int sz = q.size();
        /* 将当前队列中的所有节点向四周扩散一步 */
        for (int i = 0; i < sz; i++) {
            Node cur = q.poll();
            printf("从 %s 到 %s 的最短距离是 %s", start, cur, step);

            /* 将 cur 的相邻节点加入队列 */
            for (Node x : cur.adj()) {
                if (x not in visited) {
                    q.offer(x);
                    visited.add(x);
                }
            }
        }
        step++;
    }
}
```

> NOTE:
>
> visited set 



如果对 BFS 算法不熟悉，可以看前文 [BFS 算法框架](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485134&idx=1&sn=fd345f8a93dc4444bcc65c57bb46fc35&scene=21#wechat_redirect)，这里只是为了让你做个对比，所谓 BFS 算法，就是把算法问题抽象成一幅「无权图」，然后继续玩二叉树层级遍历那一套罢了。

**注意，我们的 BFS 算法框架也是`while`循环嵌套`for`循环的形式，也用了一个`step`变量记录`for`循环执行的次数，无非就是多用了一个`visited`集合记录走过的节点，防止走回头路罢了**。

为什么这样呢？

所谓「无权图」，与其说每条「边」没有权重，不如说每条「边」的权重都是 1，从起点`start`到任意一个节点之间的路径权重就是它们之间「边」的条数，那可不就是`step`变量记录的值么？

> NOTE: 这个观点在 baeldung [Difference Between BFS and Dijkstra’s Algorithms](https://www.baeldung.com/cs/graph-algorithms-bfs-dijkstra)  中也是有说明的，简而言之:可以使用BFS来实现unweighted graph的shortest-path


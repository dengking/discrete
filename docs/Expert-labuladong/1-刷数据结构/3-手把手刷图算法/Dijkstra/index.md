# labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 

> NOTE: 这篇文章非常好，它循序渐进、由容易到难地进行介绍。

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
> 一、visited set 
>
> 二、需要注意的是 `step++` 的位置



如果对 BFS 算法不熟悉，可以看前文 [BFS 算法框架](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485134&idx=1&sn=fd345f8a93dc4444bcc65c57bb46fc35&scene=21#wechat_redirect)，这里只是为了让你做个对比，所谓 BFS 算法，就是把算法问题抽象成一幅「无权图」，然后继续玩二叉树层级遍历那一套罢了。

**注意，我们的 BFS 算法框架也是`while`循环嵌套`for`循环的形式，也用了一个`step`变量记录`for`循环执行的次数，无非就是多用了一个`visited`集合记录走过的节点，防止走回头路罢了**。

为什么这样呢？

所谓「无权图」，与其说每条「边」没有权重，不如说每条「边」的权重都是 1，从起点 `start` 到任意一个节点之间的路径权重就是它们之间「边」的条数，那可不就是`step`变量记录的值么？

再加上 BFS 算法利用`for`循环一层一层向外扩散的逻辑和`visited`集合防止走回头路的逻辑，当你每次从队列中拿出节点`cur`的时候，从`start`到`cur`的最短权重就是`step`记录的步数。

> NOTE: 这个观点在 baeldung [Difference Between BFS and Dijkstra’s Algorithms](https://www.baeldung.com/cs/graph-algorithms-bfs-dijkstra)  中也是有说明的，简而言之:可以使用BFS来实现unweighted graph的shortest-path

## Dijkstra 算法框架



```java
// 输入一幅图和一个起点 start，计算 start 到其他节点的最短距离
int[] dijkstra(int start, List<Integer>[] graph);
```

输入是一幅图`graph`和一个起点`start`，返回是一个记录最短路径权重的数组。

**我们也需要一个`State`类来辅助算法的运行**：

```Java
class State {
    // 图节点的 id
    int id;
    // 从 start 节点到当前节点的距离
    int distFromStart;

    State(int id, int distFromStart) {
        this.id = id;
        this.distFromStart = distFromStart;
    }
}
```



刚才说普通 BFS 算法中，根据 BFS 的逻辑和无权图的特点，第一次遇到某个节点所走的步数就是最短距离，所以用一个`visited`数组防止走回头路，每个节点只会经过一次。

> NOTE: 
>
> 两个作用:
>
> 1、防止走回头路，即可能第二次遇到这个节点
>
> 2、防止dead loop，这其实是由1保证的

加权图中的 Dijkstra 算法和无权图中的普通 BFS 算法不同，在 Dijkstra 算法中，你第一次经过某个节点时的路径权重，不见得就是最小的，所以对于同一个节点，我们可能会经过多次，而且每次的`distFromStart`可能都不一样，比如下图：



![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdGiaE70bfibhZwtP90zPlWicsgkjn8sGlD4nKzl7KqzETcYbB2d1OEzak3KEOf7nS14EvMrKkxuR8MDw/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)



我会经过节点`5`三次，每次的`distFromStart`值都不一样，那我取`distFromStart`最小的那次，不就是从起点`start`到节点`5`的最短路径权重了么？

**其实，Dijkstra 可以理解成一个带 dp table（或者说备忘录）的 BFS 算法，伪码如下**：

```Java
// 返回节点 from 到节点 to 之间的边的权重
int weight(int from, int to);

// 输入节点 s 返回 s 的相邻节点
List<Integer> adj(int s);

// 输入一幅图和一个起点 start，计算 start 到其他节点的最短距离
int[] dijkstra(int start, List<Integer>[] graph) {
    // 图中节点的个数
    int V = graph.length;
    // 记录最短路径的权重，你可以理解为 dp table
    // 定义：distTo[i] 的值就是节点 start 到达节点 i 的最短路径权重
    int[] distTo = new int[V];
    // 求最小值，所以 dp table 初始化为正无穷
    Arrays.fill(distTo, Integer.MAX_VALUE);
    // base case，start 到 start 的最短距离就是 0
    distTo[start] = 0;

    // 优先级队列，distFromStart 较小的排在前面
    Queue<State> pq = new PriorityQueue<>((a, b) -> {
        return a.distFromStart - b.distFromStart;
    });

    // 从起点 start 开始进行 BFS
    pq.offer(new State(start, 0));

    while (!pq.isEmpty()) {
        State curState = pq.poll();
        int curNodeID = curState.id;
        int curDistFromStart = curState.distFromStart;

        if (curDistFromStart > distTo[curNodeID]) {
            // 已经有一条更短的路径到达 curNode 节点了
            continue;
        }
        // 将 curNode 的相邻节点装入队列
        for (int nextNodeID : adj(curNodeID)) {
            // 看看从 curNode 达到 nextNode 的距离是否会更短
            int distToNextNode = distTo[curNodeID] + weight(curNodeID, nextNodeID);
            if (distTo[nextNodeID] > distToNextNode) {
                // 更新 dp table
                distTo[nextNodeID] = distToNextNode;
                // 将这个节点以及距离放入队列
                pq.offer(new State(nextNodeID, distToNextNode));
            }
        }
    }
    return distTo;
}
```

> NOTE: 
>
> 一、需要结合前面的例子图来运行这个算法: 
>
> |                | pop  | `priority_queue`    |
> | -------------- | ---- | ------------------- |
> | initialization |      | 0(0)                |
> | iteration-1    | 0    | 4(5)、3(8)、1(9)    |
> | iteration-2    | 4    | 3(8)、1(9)、5(11)   |
> | iteration-3    | 3    | 1(9)、5(10)、5(11)  |
> | iteration-4    | 1    | 5(10)、5(11)、2(11) |
> |                | 5    | 5(11)、2(11)        |
> |                | 5    | 2(11)               |
> |                | 2    |                     |
>
> 二、通过上述运行过程可知: 节点5多次进入了`priority_queue`，因此需要加入如下逻辑:
>
> ```java
>      if (curDistFromStart > distTo[curNodeID]) {
>          // 已经有一条更短的路径到达 curNode 节点了
>          continue;
>      }
> ```
> 需要注意的是: 由于使用的是`priority_queue`，因此权重更小的总是会更早出队，即使可能更先进队。由于存在上述逻辑，那么当它第二次出队的时候，显然会被抛弃掉。
> 需要注意的是: 上述判定条件是不能够包含等号的，这是我在做[LeetCode-1631-最小体力消耗路径](https://leetcode.cn/problems/path-with-minimum-effort/) 时发现的，这是因为对于initial node，它的dp中的值和它的state的值是相同的，如果上述带上"=="，那么就造成queue machine无法启动。
> 三、每次更新了dp table后，都会将该节点加入到`priority_queue`中
>
> 四、为什么不用`visited`集合也不会死循环？从下面的两个层面来进行分析:
>
> 一、queue machine的main loop条件是`while (!pq.isEmpty())`，Dijkstra的 `priority_queue` 是 **严进必出** 的，因此最终队列肯定为空，它是不会陷入dead loop的，因此它不需要 `visited` set
>
> 二、这是在做 [LeetCode-1631. 最小体力消耗路径](https://leetcode.cn/problems/path-with-minimum-effort/) 时总结出来的:
>
> "一个节点有多重方式可以到达，这一点是和dijkstra一样的，并且由于有四个方向移动，因此第一次思考这个问题的时候，我担心可能是会出现饶了一圈又回到原点从而成环而导致dead loop，当时我考虑使用visited set。实际上: 这个题是不需要visited array的，虽然一个节点是可以多次被访问的，但是我们要取多次的最小值，对于dijkstra算法，由于它的贪心选择特性，显然当一个节点绕过一周再次回到原处的时候，这条路径肯定不是更好的，所以此时它是不会有机会再次进入queue的，因此就不会出现成环的情况，所以就不需要visited array。"

### 为什么不用`visited`集合也不会死循环？

> NOTE: 这个问题在前面已经分析了

我们先回答第一个问题，为什么这个算法不用`visited`集合也不会**死循环**。

对于这类问题，我教你一个思考方法：

循环结束的条件是**队列**为空，那么你就要注意看什么时候往队列里放元素（调用`offer`）方法，再注意看什么时候从队列往外拿元素（调用`poll`方法）。

`while`循环每执行一次，都会往外拿一个元素，但想往队列里放元素，可就有很多限制了，必须满足下面这个条件：

```Java
// 看看从 curNode 达到 nextNode 的距离是否会更短
if (distTo[nextNodeID] > distToNextNode) {
    // 更新 dp table
    distTo[nextNodeID] = distToNextNode;
    pq.offer(new State(nextNodeID, distToNextNode));
}
```

这也是为什么我说`distTo`数组可以理解成我们熟悉的 dp table，因为这个算法逻辑就是在不断的最小化`distTo`数组中的元素：

如果你能让到达`nextNodeID`的距离更短，那就更新`distTo[nextNodeID]`的值，让你入队，否则的话对不起，不让入队。

**因为两个节点之间的最短距离（路径权重）肯定是一个确定的值，不可能无限减小下去，所以队列一定会空，队列空了之后，`distTo`数组中记录的就是从`start`到其他节点的最短距离**。

> NOTE: 
>
> 一、这个的前提条件是图中不存在负数weight
>
> 二、Dijkstra逼近最优值，这和binary-search逼近非常类似

### 为什么要用`PriorityQueue`而不是`LinkedList`实现的普通队列？

> NOTE: 简而言之: greedy algorithm



### 如果只关心起点`start`到某一个终点`end`的最短路径，是否可以修改代码提升算法效率。

肯定可以的，因为我们标准 Dijkstra 算法会算出`start`到所有其他节点的最短路径，你只想计算到`end`的最短路径，相当于减少计算量，当然可以提升效率。

需要在代码中做的修改也非常少，只要改改函数签名，再加个 if 判断就行了：

```Java
// 输入起点 start 和终点 end，计算起点到终点的最短距离
int dijkstra(int start, int end, List<Integer>[] graph) {

    // ...

    while (!pq.isEmpty()) {
        State curState = pq.poll();
        int curNodeID = curState.id;
        int curDistFromStart = curState.distFromStart;

        // 在这里加一个判断就行了，其他代码不用改
        if (curNodeID == end) {
            return curDistFromStart;
        }

        if (curDistFromStart > distTo[curNodeID]) {
            continue;
        }

        // ...
    }

    // 如果运行到这里，说明从 start 无法走到 end
    return Integer.MAX_VALUE;
}
```

因为优先级队列自动排序的性质，**每次**从队列里面拿出来的都是`distFromStart`值最小的，所以当你从队头拿出一个节点，如果发现这个节点就是终点`end`，那么`distFromStart`对应的值就是从`start`到`end`的最短距离。

这个算法较之前的实现提前 return 了，所以效率有一定的提高。

## 时间复杂度分析






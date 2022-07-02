# labuladong [二叉树的题，就那几个框架，枯燥至极](https://mp.weixin.qq.com/s/DVX2A1ha4xSecEXLxW_UsA)

PS：一般语境下，单单前序遍历结果是不能还原二叉树结构的，因为缺少空指针的信息，至少要得到前、中、后序遍历中的两种才能还原二叉树。但是这里的 `node` 列表包含空指针的信息，所以只使用 `node` 列表就可以还原二叉树。

> NOTE: 
>
> 1、参见 leetcode [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)，其中就是给出了两个不含`null`的前序、中序遍历结果来还原二叉树。

## 一、题目描述

> NOTE: 
>
> 原题: LeetCode [297. 二叉树的序列化与反序列化](https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/) 困难

力扣第 297 题「二叉树的序列化与反序列化」就是给你输入一棵二叉树的根节点 `root`，要求你实现如下一个类：

```java
public class Codec {

    // 把一棵二叉树序列化成字符串
    public String serialize(TreeNode root) {}

    // 把字符串反序列化成二叉树
    public TreeNode deserialize(String data) {}
}
```

我们可以用 `serialize` 方法将二叉树序列化成字符串，用 `deserialize` 方法将序列化的字符串反序列化成二叉树，至于以什么格式序列化和反序列化，这个完全由你决定。

比如说输入如下这样一棵二叉树：

![Image](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFJlkkg2icueWtNAuPtHuQ6vLdoBcvnXxzRTJA6LkNJJwpCD76DiaBUKuZZeAIpDDcevM7DqeJa7ia0g/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

`serialize` 方法也许会把它序列化成字符串 `2,1,#,6,3,#,#`，其中 `#` 表示 `null` 指针，那么把这个字符串再输入 `deserialize` 方法，依然可以还原出这棵二叉树。也就是说，这两个方法会成对儿使用，你只要保证他俩能够**自洽**就行了。

> NOTE: 
>
> 自洽: self consistent

想象一下，二叉树结该是一个二维平面内的结构，而序列化出来的字符串是一个线性的一维结构。**所谓的序列化不过就是把结构化的数据「打平」，其实就是在考察二叉树的遍历方式**。

> NOTE: 
>
> non-linear structure-linearization-traverse flatten

二叉树的遍历方式有哪些？递归遍历方式有**前序遍历**，**中序遍历**，**后序遍历**；迭代方式一般是层级遍历。本文就把这些方式都尝试一遍，来实现 `serialize` 方法和 `deserialize` 方法。

## 二、前序遍历解法

### `serialize`

![Image](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFJlkkg2icueWtNAuPtHuQ6vmOfpGWptTgHonJR8qH2TdSltf8jQ5mNMkQxm7gxicib8a9HBIibEibicL2Q/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

至此，我们已经可以写出序列化函数 `serialize` 的代码了：

```Java
String SEP = ",";
String NULL = "#";

/* 主函数，将二叉树序列化为字符串 */
String serialize(TreeNode root) {
    StringBuilder sb = new StringBuilder();
    serialize(root, sb);
    return sb.toString();
}

/* 辅助函数，将二叉树存入 StringBuilder */
void serialize(TreeNode root, StringBuilder sb) {
    if (root == null) {
        sb.append(NULL).append(SEP);
        return;
    }

    /****** 前序遍历位置 ******/
    sb.append(root.val).append(SEP);
    /***********************/

    serialize(root.left, sb);
    serialize(root.right, sb);
}
```

### `deserialize` 

首先我们可以把字符串转化成列表：

```Java
String data = "1,2,#,4,#,#,3,#,#,";
String[] nodes = data.split(",");
```

这样，`nodes` 列表就是二叉树的前序遍历结果，问题转化为：如何通过二叉树的前序遍历结果还原一棵二叉树？

> PS：一般语境下，单单前序遍历结果是不能还原二叉树结构的，因为缺少空指针的信息，至少要得到前、中、后序遍历中的两种才能还原二叉树。但是这里的 `node` 列表包含空指针的信息，所以只使用 `node` 列表就可以还原二叉树。

根据我们刚才的分析，`nodes` 列表就是一棵打平的二叉树：

![Image](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFJlkkg2icueWtNAuPtHuQ6vmOfpGWptTgHonJR8qH2TdSltf8jQ5mNMkQxm7gxicib8a9HBIibEibicL2Q/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

> NOTE: 
>
> 一、上述图片展示了recursive definition，它是能够帮助我们理解下面的source code
>
> 1、先完成左子树的构造，再完成右子树的构造

那么，反序列化过程也是一样，**先确定根节点 `root`，然后遵循前序遍历的规则，递归生成左右子树即可**：

```java
/* 主函数，将字符串反序列化为二叉树结构 */
TreeNode deserialize(String data) {
    // 将字符串转化成列表
    LinkedList<String> nodes = new LinkedList<>();
    for (String s : data.split(SEP)) {
        nodes.addLast(s);
    }
    return deserialize(nodes);
}

/* 辅助函数，通过 nodes 列表构造二叉树 */
TreeNode deserialize(LinkedList<String> nodes) {
    if (nodes.isEmpty()) return null;

    /****** 前序遍历位置 ******/
    // 列表最左侧就是根节点
    String first = nodes.removeFirst();
    if (first.equals(NULL)) return null;
    TreeNode root = new TreeNode(Integer.parseInt(first));
    /***********************/

    root.left = deserialize(nodes);
    root.right = deserialize(nodes);

    return root;
}
```

我们发现，根据树的递归性质，`nodes` 列表的第一个元素就是一棵树的根节点，所以只要将列表的第一个元素取出作为根节点，剩下的交给递归函数去解决即可。

> NOTE: 
>
> 一、序列化的结构是: root、left、right

## 三、后序遍历解法

![Image](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFJlkkg2icueWtNAuPtHuQ6vnQboPZnF6qr44lBms2DvX6qOwryAqHxocSbnD35oI6iaQ5EBAXeU9oA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

## 四、中序遍历解法

先说结论，中序遍历的方式行不通，因为无法实现反序列化方法 `deserialize`。

序列化方法 `serialize` 依然容易，只要把字符串的拼接操作放到中序遍历的位置就行了：

```Java
/* 辅助函数，将二叉树存入 StringBuilder */
void serialize(TreeNode root, StringBuilder sb) {
    if (root == null) {
        sb.append(NULL).append(SEP);
        return;
    }

    serialize(root.left, sb);
    /****** 中序遍历位置 ******/
    sb.append(root.val).append(SEP);
    /***********************/
    serialize(root.right, sb);
}
```

但是，我们刚才说了，要想实现反序列方法，首先要构造 `root` 节点。前序遍历得到的 `nodes` 列表中，第一个元素是 `root` 节点的值；后序遍历得到的 `nodes` 列表中，最后一个元素是 `root` 节点的值。

你看上面这段中序遍历的代码，`root` 的值被夹在两棵子树的中间，也就是在 `nodes` 列表的中间，我们不知道确切的索引位置，所以无法找到 `root` 节点，也就无法进行反序列化。

## 五、层级遍历解法

首先，先写出层级遍历二叉树的代码框架：

```Java
void traverse(TreeNode root) {
    if (root == null) return;
    // 初始化队列，将 root 加入队列
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    while (!q.isEmpty()) {
        TreeNode cur = q.poll();

        /* 层级遍历代码位置 */
        System.out.println(root.val);
        /*****************/

        if (cur.left != null) {
            q.offer(cur.left);
        }

        if (cur.right != null) {
            q.offer(cur.right);
        }
    }
}
```

**上述代码是标准的二叉树层级遍历框架**，从上到下，从左到右打印每一层二叉树节点的值，可以看到，队列 `q` 中不会存在 null 指针。



不过我们在反序列化的过程中是需要记录空指针 null 的，所以可以把标准的层级遍历框架略作修改：

```Java
void traverse(TreeNode root) {
    if (root == null) return;
    // 初始化队列，将 root 加入队列
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    while (!q.isEmpty()) {
        TreeNode cur = q.poll();

        /* 层级遍历代码位置 */
        if (cur == null) continue;
        System.out.println(root.val);
        /*****************/

        q.offer(cur.left);
        q.offer(cur.right);
    }
}
```

这样也可以完成层级遍历，只不过我们把对空指针的检验从「将元素加入队列」的时候改成了「从队列取出元素」的时候。

那么我们完全仿照这个框架即可写出序列化方法：

```Java
String SEP = ",";
String NULL = "#";

/* 将二叉树序列化为字符串 */
String serialize(TreeNode root) {
    if (root == null) return "";
    StringBuilder sb = new StringBuilder();
    // 初始化队列，将 root 加入队列
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    while (!q.isEmpty()) {
        TreeNode cur = q.poll();

        /* 层级遍历代码位置 */
        if (cur == null) {
            sb.append(NULL).append(SEP);
            continue;
        }
        sb.append(cur.val).append(SEP);
        /*****************/

        q.offer(cur.left);
        q.offer(cur.right);
    }

    return sb.toString();
}
```

层级遍历序列化得出的结果如下图：

![Image](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFJlkkg2icueWtNAuPtHuQ6vGacpwC9O4glRuaDHoEFdDcfmnNzR0jLd8ttXaF7chbz4icfjQc87GSw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

可以看到，每一个非空节点都会对应两个子节点，**那么反序列化的思路也是用队列进行层级遍历，同时用索引 `i` 记录对应子节点的位置**：

> NOTE: 
>
> 一、
>
> 构造出节点1: 它包含子节点2、3
>
> 构造出节点2: 它包含子节点#、4
>
> 构造出节点3: 它包含子节点#、#
>
> 二、`i`肯定是单调递增的
>
> 三、下面的source code展示的是自顶向下构造二叉树
>
> 四、
>
> ```Java
>     // 第一个元素就是 root 的值
>     TreeNode root = new TreeNode(Integer.parseInt(nodes[0]));
> 
>     // 队列 q 记录父节点，将 root 加入队列
>     Queue<TreeNode> q = new LinkedList<>();
>     q.offer(root);
> ```
>
> root、第0层

```Java
/* 将字符串反序列化为二叉树结构 */
TreeNode deserialize(String data) {
    if (data.isEmpty()) return null;
    String[] nodes = data.split(SEP);
    // 第一个元素就是 root 的值
    TreeNode root = new TreeNode(Integer.parseInt(nodes[0]));

    // 队列 q 记录父节点，将 root 加入队列
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    for (int i = 1; i < nodes.length; ) {
        // 队列中存的都是父节点
        TreeNode parent = q.poll();
        // 父节点对应的左侧子节点的值
        String left = nodes[i++];
        if (!left.equals(NULL)) {
            parent.left = new TreeNode(Integer.parseInt(left));
            q.offer(parent.left);
        } else {
            parent.left = null;
        }
        // 父节点对应的右侧子节点的值
        String right = nodes[i++];
        if (!right.equals(NULL)) {
            parent.right = new TreeNode(Integer.parseInt(right));
            q.offer(parent.right);
        } else {
            parent.right = null;
        }
    }
    return root;
}
```

这段代码可以考验一下你的框架思维。仔细看一看 for 循环部分的代码，发现这不就是标准层级遍历的代码衍生出来的嘛：

```Java
while (!q.isEmpty()) {
    TreeNode cur = q.poll();

    if (cur.left != null) {
        q.offer(cur.left);
    }

    if (cur.right != null) {
        q.offer(cur.right);
    }
}
```

只不过，标准的层级遍历在操作二叉树节点 `TreeNode`，而我们的函数在操作 `nodes[i]`，这也恰恰是反序列化的目的嘛。

到这里，我们对于二叉树的序列化和反序列化的几种方法就全部讲完了。

## 总结

上述所展示的各种 序列化 和 反序列化 算法，采用的是相同的逻辑，比如BFS，它的序列化 和 反序列化逻辑是相同的；

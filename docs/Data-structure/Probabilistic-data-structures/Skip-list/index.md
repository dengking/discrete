# Skip list

一、以空间换时间

二、优势:

1、简单

TODO 需要引用Redis doc中的说法

## 参考文章

### labuladong [漫画：什么是 “跳表” ？](https://mp.weixin.qq.com/s/HTRO1_wao7MzutPkCw9dSg)

其中使用"目录"来进行类比、其中给出了完整的实现。

## wikipedia [Skip list](https://en.wikipedia.org/wiki/Skip_list)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **skip list** is a [data structure](https://en.wikipedia.org/wiki/Data_structure) that allows ${{O}}(\log n)$ search complexity as well as $ {{O}}(\log n)$ insertion complexity within an [ordered sequence](https://en.wikipedia.org/wiki/Ordered_sequence) of ${n}$ elements. Thus it can get the best of [array](https://en.wikipedia.org/wiki/Array_data_structure) (for searching) while maintaining a [linked list](https://en.wikipedia.org/wiki/Linked_list)-like structure that allows insertion- which is not possible in an array. Fast search is made possible by maintaining a [linked](https://en.wikipedia.org/wiki/Linked_list) hierarchy of **subsequences**, with each successive subsequence **skipping** over fewer elements than the previous one (see the picture below on the right). Searching starts in the sparsest(稀疏的) subsequence until two consecutive elements have been found, one smaller and one larger than or equal to the element searched for. Via the linked hierarchy, these two elements link to elements of the next sparsest subsequence, where searching is continued until finally we are searching in the full sequence. The elements that are skipped over may be chosen probabilistically [[2\]](https://en.wikipedia.org/wiki/Skip_list#cite_note-pugh-2) or deterministically,[[3\]](https://en.wikipedia.org/wiki/Skip_list#cite_note-3) with the former being more common.

> NOTE:
>
> 1、subsequence的含义是子序列



| Algorithm |      | **Average**                              | **Worst case**                                               |
| :-------: | ---- | ---------------------------------------- | ------------------------------------------------------------ |
|   Space   |      | ${\displaystyle {\mathcal {O}}(n)}$      | ${\displaystyle {\mathcal {O}}(n\log n)}$[[1\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-cs.uwaterloo-1) |
|  Search   |      | ${\displaystyle {\mathcal {O}}(\log n)}$ | ${\displaystyle {\mathcal {O}}(n)}$[[1\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-cs.uwaterloo-1) |
|  Insert   |      | ${\displaystyle {\mathcal {O}}(\log n)}$ | ${\displaystyle {\mathcal {O}}(n)}$                          |
|  Delete   |      | ${\displaystyle {\mathcal {O}}(\log n)}$ |                                                              |

### Description

A **skip list** is built in **layers**. The **bottom layer** is an ordinary ordered [linked list](https://en.wikipedia.org/wiki/Linked_list). Each **higher layer** acts as an "express lane"（快车道） for the lists below, where an element in layer ${i}$ appears in layer ${i+1}$ with some fixed probability ${p}$  (two commonly used values for ${p}$  are ${1/2}$  or ${1/4}$ ). On average, each element appears in ${ 1/(1-p)}$ lists, and the **tallest element** (usually a special head element at the front of the skip list) in all the lists. The skip list contains ${\log _{1/p}n\,}$ (i.e. logarithm base ${ 1/p}$ of ${ n}$) lists.

> NOTE: 
>
> 一、layers 对应的是下面的Inserting elements to skip list图中的levels
>
> 二、
>
> 自底向上为每一层进行编号(原linked list是第0层)，假设第0层的链表中有 $n$ 个元素，则:
>
> 第1层有 $p * n$ 个元素
>
> 第2层有 $(p^2) * n$ 个元素
>
> ...
>
> 第`i`层有$p^i * n$ 个元素
>
> 三、"On average, each element appears in ${ 1/(1-p)}$ lists"
>
> ${ 1/(1-p)}$ 是如何计算得到的？
>
> 四、"The skip list contains ${\log _{1/p}n\,}$ (i.e. logarithm base ${ 1/p}$ of ${ n}$) lists"
>
> ${\log _{1/p}n\,}$ 是如何计算得到的？
>
> 初看可能看不懂，代入一个值就能够懂了，比如p=1/2，显然它就是$log_2 n$ ，这其实就是二叉树的高度、复杂度。





> Inserting elements to skip list



A search for a target element begins at the **head element** in the **top list**, and proceeds horizontally（水平的） until the current element is greater than or equal to the target. If the **current element** is equal to the target, it has been found. If the **current element** is greater than the target, or the search reaches the end of the linked list, the procedure is repeated after returning to the previous element and dropping down vertically to the next lower list. The expected number of steps in each linked list is at most ${\displaystyle 1/p}$, which can be seen by tracing the search path backwards from the target until reaching an element that appears in the next higher list or reaching the beginning of the current list. Therefore, the total *expected* cost of a search is ${\displaystyle {\tfrac {1}{p}}\log _{1/p}n}$ which is ${\displaystyle {\mathcal {O}}(\log n)\,}$, when ${\displaystyle p}$ is a constant. By choosing different values of ${\displaystyle p}$, it is possible to trade **search costs** against **storage costs**.



### Implementation details

The elements used for a skip list can contain more than one pointer since they can participate in more than one list.

Insertions and deletions are implemented much like the corresponding linked-list operations, except that "tall" elements must be inserted into or deleted from more than one linked list.

${\displaystyle {\mathcal {O}}(n)} $operations, which force us to visit every node in ascending order (such as printing the entire list), provide the opportunity to perform a behind-the-scenes derandomization of the level structure of the skip-list in an optimal way, bringing the skip list to ${\displaystyle {\mathcal {O}}(\log n)}$search time. (Choose the level of the i'th finite node to be 1 plus the number of times we can repeatedly divide i by 2 before it becomes odd. Also, i=0 for the negative infinity header as we have the usual special case of choosing the highest possible level for negative and/or positive infinite nodes.) However this also allows someone to know where all of the higher-than-level 1 nodes are and delete them.

Alternatively, we could make the level structure quasi-random in the following way:

#### Indexable skiplist

```
   1                               10
 o---> o---------------------------------------------------------> o    Top level
   1           3              2                    5
 o---> o---------------> o---------> o---------------------------> o    Level 3
   1        2        1        2              3              2
 o---> o---------> o---> o---------> o---------------> o---------> o    Level 2
   1     1     1     1     1     1     1     1     1     1     1 
 o---> o---> o---> o---> o---> o---> o---> o---> o---> o---> o---> o    Bottom level
                                         
Head  1st   2nd   3rd   4th   5th   6th   7th   8th   9th   10th  NIL
      Node  Node  Node  Node  Node  Node  Node  Node  Node  Node
```



### Usages

The "QMap" key/value dictionary (up to Qt 4) template class of [Qt](https://en.wanweibaike.com/wiki-Qt_(framework)) is implemented with skip lists.[[11\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-11)

[Redis](https://en.wanweibaike.com/wiki-Redis), an ANSI-C open-source persistent key/value store for Posix systems, uses skip lists in its implementation of ordered sets.[[12\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-12)

"leveldb" is a fast key-value storage library written at Google that provides an ordered mapping from string keys to string values[[16\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-16)



#### Concurrent data structure

Skip lists are also used in distributed applications (where the nodes represent physical computers, and pointers represent network connections) and for implementing highly scalable concurrent [priority queues](https://en.wanweibaike.com/wiki-Priority_queue) with less lock contention,[[21\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-21) or even [without locking](https://en.wanweibaike.com/wiki-Non-blocking_algorithm),[[22\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-22)[[23\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-23)[[24\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-24) as well as [lock-free](https://en.wanweibaike.com/wiki-Lock-free) concurrent dictionaries.[[25\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-25) There are also several US patents for using skip lists to implement (lockless) priority queues and concurrent dictionaries. 



## Application

1、Redis中，使用了skip list来实现 "ordered set"

2、skip list可以用于实现associate array(即dict)



## Implementation

### labuladong [漫画：什么是 “跳表” ？](https://mp.weixin.qq.com/s/HTRO1_wao7MzutPkCw9dSg)

```Java
public class SkipList{

    //结点“晋升”的概率
    private static final double PROMOTE_RATE = 0.5;
    private Node head,tail;
    private int maxLevel;

    public SkipList() {
        head = new Node(Integer.MIN_VALUE);
        tail = new Node(Integer.MAX_VALUE);
        head.right = tail;
        tail.left = head;
    }

    //查找结点
    public Node search(int data){
        Node p= findNode(data);
        if(p.data == data){
            System.out.println("找到结点：" + data);
            return p;
        }
        System.out.println("未找到结点：" + data);
        return null;
    }

    //找到值对应的前置结点
    private Node findNode(int data){
        Node node = head;
        while(true){
            while (node.right.data!=Integer.MAX_VALUE && node.right.data<=data) {
                node = node.right;
            }
            if (node.down == null) {
                break;
            }
            node = node.down;
        }
        return node;
    }

    //插入结点
    public void insert(int data){
        Node preNode= findNode(data);
        //如果data相同，直接返回
        if (preNode.data == data) {
            return;
        }
        Node node=new Node(data);
        appendNode(preNode, node);
        int currentLevel=0;
        //随机决定结点是否“晋升”
        Random random = new Random();
        while (random.nextDouble() < PROMOTE_RATE) {
            //如果当前层已经是最高层，需要增加一层
            if (currentLevel == maxLevel) {
                addLevel();
            }
            //找到上一层的前置节点
            while (preNode.up==null) {
                preNode=preNode.left;
            }
            preNode=preNode.up;
            //把“晋升”的新结点插入到上一层
            Node upperNode = new Node(data);
            appendNode(preNode, upperNode);
            upperNode.down = node;
            node.up = upperNode;
            node = upperNode;
            currentLevel++;
        }
    }

    //在前置结点后面添加新结点
    private void appendNode(Node preNode, Node newNode){
        newNode.left=preNode;
        newNode.right=preNode.right;
        preNode.right.left=newNode;
        preNode.right=newNode;
    }

    //增加一层
    private void addLevel(){
        maxLevel++;
        Node p1=new Node(Integer.MIN_VALUE);
        Node p2=new Node(Integer.MAX_VALUE);
        p1.right=p2;
        p2.left=p1;
        p1.down=head;
        head.up=p1;
        p2.down=tail;
        tail.up=p2;
        head=p1;
        tail=p2;
    }

    //删除结点
    public boolean remove(int data){
        Node removedNode = search(data);
        if(removedNode == null){
            return false;
        }

        int currentLevel=0;
        while (removedNode != null){
            removedNode.right.left = removedNode.left;
            removedNode.left.right = removedNode.right;
            //如果不是最底层，且只有无穷小和无穷大结点，删除该层
            if(currentLevel != 0 && removedNode.left.data == Integer.MIN_VALUE && removedNode.right.data == Integer.MAX_VALUE){
                removeLevel(removedNode.left);
            }else {
                currentLevel ++;
            }
            removedNode = removedNode.up;
        }

        return true;
    }

    //删除一层
    private void removeLevel(Node leftNode){
        Node rightNode = leftNode.right;
        //如果删除层是最高层
        if(leftNode.up == null){
            leftNode.down.up = null;
            rightNode.down.up = null;
        }else {
            leftNode.up.down = leftNode.down;
            leftNode.down.up = leftNode.up;
            rightNode.up.down = rightNode.down;
            rightNode.down.up = rightNode.up;
        }
        maxLevel --;
    }

    //输出底层链表
    public void printList() {
        Node node=head;
        while (node.down != null) {
            node = node.down;
        }
        while (node.right.data != Integer.MAX_VALUE) {
            System.out.print(node.right.data + " ");
            node = node.right;
        }
        System.out.println();
    }

    //链表结点类
    public class Node {
        public int data;
        //跳表结点的前后和上下都有指针
        public Node up, down, left, right;

        public Node(int data) {
            this.data = data;
        }
    }

    public static void main(String[] args) {
        SkipList list=new SkipList();
        list.insert(50);
        list.insert(15);
        list.insert(13);
        list.insert(20);
        list.insert(100);
        list.insert(75);
        list.insert(99);
        list.insert(76);
        list.insert(83);
        list.insert(65);
        list.printList();
        list.search(50);
        list.remove(50);
        list.search(50);
    }
}

```


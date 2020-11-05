# Recursion and iteration

Recursion 和 iteration 是两种**实现**方式，recursion本质上来说是自顶向下的使用[递归关系](./Recurrence-relation.md)，iteration本质上来说是自底向上地使用[递归关系](./Recurrence-relation.md)（dynamic programming、greedy algorithm都是基于iteration的）。本文就对两者进行探讨。

## Recursion VS iteration

从运行成本比较：参见维基百科[Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))第三段。

两者的相同点：参见：

- 维基百科[Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))第二段：都能够实现“repeatedly call code”。
- 维基百科[Iteration](https://en.wikipedia.org/wiki/Iteration#Computing) ，其中的[Relationship with recursion](https://en.wikipedia.org/wiki/Iteration#Relationship_with_recursion)总结地非常好。



## Recursin to iteration

### 尾递归消除

尾递归函数可以无需借助data structure就可以消除，如fibnacci。

参见维基百科[Tail call](https://en.wikipedia.org/wiki/Tail_call)。

### using user stack to replace the call stack of recursion function

其他的递归函数如tree遍历函数，不是尾递归，需要借助于data structure才能够消除。

关于此的一个典型的例子就是[Tree traversal](https://en.wikipedia.org/wiki/Tree_traversal)，以下是从这摘抄的code：

### recursion的实现

```pseudocode

preorder(node)
  if (node == null)
    return
  visit(node)
  preorder(node.left)
  preorder(node.right)
```



### iteration的实现

```c
iterativePreorder(node)
  if (node == null)
    return
  s ← empty stack
  s.push(node)
  while (not s.isEmpty())
    node ← s.pop()
    visit(node)
    //right child is pushed first so that left is processed first
    if (node.right ≠ null)
      s.push(node.right)
    if (node.left ≠ null)
      s.push(node.left)
```



### recursion的实现 VS iteration的实现

正如在《`recursion-analysis-and-representation.md`》中所描述的：

>  函数的调用过程所使用的是[Call stack](https://en.wikipedia.org/wiki/Call_stack)，每一次的函数调用都会在[Call stack](https://en.wikipedia.org/wiki/Call_stack)上push一个 **stack frame**（参见[Call stack](https://en.wikipedia.org/wiki/Call_stack)）；递归函数一直执行的是同一个函数，所以它的[Call stack](https://en.wikipedia.org/wiki/Call_stack)中的**stack frame**的执行逻辑是相同的（入参可能不同）；在递归函数执行的过程中，每执行一次递归调用就往[Call stack](https://en.wikipedia.org/wiki/Call_stack)上push（入栈）一个 **stack frame**，直到某个递归函数执行到了base case，则它会return，这就意味中它的 **stack frame**会pop（出栈），则控制会返回到调用它的函数；显然，前面所描述的过程对应着[树的深度优先遍历](https://en.wikipedia.org/wiki/Tree_traversal)，所以我们说：递归函数的执行过程是对递归调用树进行深度优先遍历。 

在递归的实现中，函数`preorder`的执行过程中，会不断地往[Call stack](https://en.wikipedia.org/wiki/Call_stack)中push stack frame，这些stack frame中就包含了一个一个的**节点**信息，直至遇到base case，[Call stack](https://en.wikipedia.org/wiki/Call_stack)中的stack frame才会出栈；现在只分析`preorder`中关于`preorder`的调用，在每一次调用中会先执行`preorder(node.left)`，这说明`preorder`会优先处理`node.left`，而将`node.right`留在stack frame中（函数暂时没有执行到这里，待`preorder(node.left)`返回后，才会执行到它），而待控制返回时才进行处理；这就是使用call stack来保存deferred node，正如[Tree traversal](https://en.wikipedia.org/wiki/Tree_traversal)中所述：

>  Traversing a tree involves iterating over all nodes in some manner. Because from a given node there is more than one possible next node (it is not a linear data structure), then, assuming sequential computation (not parallel), some nodes must be deferred—stored in some way for later visiting. This is often done via a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) (LIFO) or [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) (FIFO). As a tree is a self-referential (recursively defined) data structure, traversal can be defined by [recursion](https://en.wikipedia.org/wiki/Recursion) or, more subtly, [corecursion](https://en.wikipedia.org/wiki/Corecursion), in a very natural and clear fashion; in these cases the deferred nodes are stored implicitly in the [call stack](https://en.wikipedia.org/wiki/Call_stack). 

显然，在使用iteration的时候，就需要用户定义一个stack来充当calling stack在recursion中的角色了：在recursion中，`preorder(node.left)`的执行在`preorder(node.right)`之前，这就意味中，优先处理`node.left`，所以在iteration的实现中，要先入栈`node.right`，再入栈`node.left`（因为stack是后进先出），从而模拟了上述系统调用中将`node.right`保存在call stack中。



再来看看**中序遍历**

```pseudocode

inorder(node)
  if (node == null)
    return
  inorder(node.left)
  visit(node)
  inorder(node.right)
```

不断地将左节点压入call stack中，知道左节点为NULL，才返回（出栈），才visit节点；

```pseudocode
iterativeInorder(node)
  s ← empty stack
  while (not s.isEmpty() or node ≠ null)
    if (node ≠ null)
      s.push(node)
      node ← node.left
    else
      node ← s.pop()
      visit(node)
      node ← node.right
```

中序遍历的recursion版本要比先序遍历的复杂地多。其实对他的分析还是要从从call stack到user stack。中序遍历中，当递归函数返回到它的主调函数的时候，还需要访问节点`node`（在call stack中保存了这些信息），但是在先序遍历中，当递归函数返回到它的主调函数的时候，无需在访问节点`node`了；所以在先序遍历的iteration版本中，`node`节点在本轮使用了之后，就无需继续留在user stack中了，所以在每轮的循环开始的时候，就将它从user stack中取出；但是中序遍历的iteration版本中，就不能够这样了，只有当node没有了left node后，才能够将它从user stack中取出；



user stack的出栈对应着call stack中的从递归函数中返回，user stack中进栈则对应中调用递归函数；

对比上述代码，可以发现，如下两个语句是在一起的：

```
      node ← s.pop()
      visit(node)
```

其实这是一个理解问题本质的所在，无论哪种方式，从栈中取出元素，然后进行visit，不同的是深度优先先序遍历是在每次先从栈中取出元素进行visit。深度优先的中序遍历则是在左子树都访问完了后才从栈中取出元素进行visit。


# Tree model

在[Examples of tree structures](./Examples-of-tree-structures.md)中，我们可以看到，tree structure的广泛存在；在[Tree structure](./Tree-structure.md)中，我们总结了tree structure所具备的**nesting关系**，后面为了便于描述，我们创建“tree model”概念，它表示具备nesting关系的结构。显然，能够使用tree model描述的问题，都能够转换为与tree相关的操作，比如构建一棵树、遍历树。有的时候，需要显式地构造一棵树，有的时候，无需显式地构造树。

## 很多问题最终都转换为树操作

parsing、括号匹配、组合分析，都可以使用**nesting关系**来进行描述，对它们的相关问题的求解最终都可以转换为树的构建、树的遍历。




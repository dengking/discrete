# Dependency relation model

这是一种非常重要的relation。

在下面章节中，描述了这种relation:

1、`Function-recursion-tree-stack`

## Construct and destruction



### Construct structure

当使用dependency relation来construct structure的时候，需要遵循:

1、首先要构造current node的dependency node，只有它的dependency都被满足后，才能够完成current node的构造；因此需要找到最最被依赖的node，从它开始构造，然后依次构造依赖于它的其他node，从而构造完整的structure。

### Destruct structure

当destruction一个使用dependency relation而构造的structure的时候，和construct structure是相反的:

1、首先析构最不被依赖的node

### Example: C++ constructor、destructor的调用顺序

C++ constructor、destructor的调用顺序就是遵循前面描述的constructor structure和destructor structure规则。



## Topological sorting

对于使用dependency relation构建的structure，对其进行topological sorting是一种常见的操作，参见 `Topological-sorting` 章节。

## Example

### makefile

makefile就是典型的描述dependency relation，它所描述的最终构成了一个dependency graph。

### Dead lock

dead lock是可以使用dependency relation来进行描述的。
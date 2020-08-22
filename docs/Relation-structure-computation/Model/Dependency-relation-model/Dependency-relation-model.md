# Dependency relation model



## Example

### makefile

makefile就是典型的描述dependency relation，它所描述的最终构成了一个dependency graph。



## Circular

对于dependency relation，最最需要避免的是相互依赖，从`Relation-structure-computation\Relation\Relation\Relation.md`中的描述来看，这是典型的“同一个relation内形成circular”。

### Example

- dead lock，APUE中介绍了。
- c头文件互包含、Python互导入
- circular reference（[Reference counting](https://en.wikipedia.org/wiki/Reference_counting)）
- ......



与此相关的文章：

- [Acyclic dependencies principle](https://en.wikipedia.org/wiki/Acyclic_dependencies_principle)



### Detection algorithm

对于dependency relation，最最需要避免的是相互依赖，那如何来判定是否存在相互依赖的？显然，相互依赖就是无法拍序的典型情况，这就需要使用graph theory中的topological sorting。

#### wikipedia [Topological sorting](https://en.wikipedia.org/wiki/Topological_sorting)

在龙书的chapter 5.2 Evaluation Orders for SDD's中有关于此的讨论。
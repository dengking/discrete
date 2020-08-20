# Dependency relation model



## Ordering

对于dependency relation，最最需要避免的是相互依赖，那如何来判定是否存在相互依赖的？这就需要使用graph theory中的topological sorting。

### [Topological sorting](https://en.wikipedia.org/wiki/Topological_sorting)

在龙书的chapter 5.2 Evaluation Orders for SDD's中有关于此的讨论。

## 相互依赖

显然，相互依赖就是无法拍序的典型情况。

成环

情景：

- 死锁，APUE中介绍了。
- c头文件互包含
- Python互导入



与此相关的文章：

- [Acyclic dependencies principle](https://en.wikipedia.org/wiki/Acyclic_dependencies_principle)




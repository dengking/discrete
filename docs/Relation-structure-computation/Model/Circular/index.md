# Circular

关于relation，一个比较有趣的问题就是：circular。我们讨论两种circular：

1、同一个relation内形成circular

2、多个relation间形成circular



## 同一个relation内形成circular

沿着relation不停地进行rewrite（或者说 推导，参见前面相应的章节），通过最终到达了源点，则形成了circular。当使用graph来表示relation时，这种现象是非常任意理解的。

## 多个relation间形成circulars

在`Book-Discrete-Mathematics-and-Its-Applications\Chpater-9-Relations\Supplementary Exercises`中给出了circular的描述：

> Arelation R is called circular if `aRb` and `bRc` imply that `cRa`. Show that `R` is reflexive and circular if and only if it is an equivalence relation.



## Circular dependency

对于dependency relation，最最需要避免的是相互依赖，从`Relation-structure-computation\Relation\Relation\Relation`中的描述来看，这是典型的“同一个relation内形成circular”。

### Example

1、dead lock，APUE中介绍了。

2、c头文件互包含、Python互导入

3、circular reference（[Reference counting](https://en.wikipedia.org/wiki/Reference_counting)）

4、......



S

### wikipedia [Acyclic dependencies principle](https://en.wikipedia.org/wiki/Acyclic_dependencies_principle)



### Detection algorithm

对于dependency relation，最最需要避免的是相互依赖，那如何来判定是否存在相互依赖的？显然，相互依赖就是无法拍序的典型情况，这就需要使用graph theory中的topological sorting。

#### wikipedia [Topological sorting](https://en.wikipedia.org/wiki/Topological_sorting)

在龙书的chapter 5.2 Evaluation Orders for SDD's中有关于此的讨论。
# 关于本章

按照`Relation-structure-computation\index.md`中总结的""**基于relation来建立model**"思想，使用`Relation-structure-computation\Relation`章节中描述的relation理论来进行分析，对如下问题进行进一步的分析:

1) 在`Relation-structure-computation/index`章节提出的: **relation决定structure**

2) 在`Structure/Structure/index`章节提出的：**Relation的哪些特性决定了structure，或者说：什么样的relation可以形成什么样的结构**

## 常见relation、structure、algorithm

本节以computer science中，非常典型的relation以及它的structure、algorithm作为主要内容。

下面是我们分析的角度: 

1) 关系的性质

2) entity参与这种关系的cardinality （基数）

3) 关系形成的structure的形状

| Relation            | Structure | Cardinality | 说明                           |
| ------------------- | --------- | ----------- | ------------------------------ |
| Hierarchy relation  | graph     | `N:N`       | 根据形状来对这种relation命名的 |
| Nesting relation    | tree      | `1:N`       |                                |
| Dependency relation | graph     |             |                                |

关于graph，参见`Relation-structure-computation\Structure\Data-structure\Graph\Graph`章节；

关于tree，参见`Relation-structure-computation\Structure\Data-structure\Graph\Tree`章节；

### Chain、tree、hierarchy、graph

如果从“使用graph来表示relation”的角度来思考，chain、hierarchy、tree都是一种graph，或者说它们都是graph的退化。

它们的relation有着不同的特性，这是需要进行深入挖掘的。



## Stream

Stream是一种非常强大的抽象，在computer science中被广泛应用，本章将对它进行专门的总结。